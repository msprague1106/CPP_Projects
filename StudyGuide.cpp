#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <set>
#include <cctype>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

// ── ANSI color shortcuts ────────────────────────────────────────────────────
namespace C {
    const string RST  = "\033[0m";
    const string BOLD = "\033[1m";
    const string DIM  = "\033[2m";
    const string RED  = "\033[91m";
    const string GRN  = "\033[92m";
    const string YLW  = "\033[93m";
    const string BLU  = "\033[94m";
    const string MAG  = "\033[95m";
    const string CYN  = "\033[96m";
    const string WHT  = "\033[97m";
}

void enableAnsi() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode))
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

// ── Visual helpers ──────────────────────────────────────────────────────────
void printBanner() {
    cout << "\n" << C::CYN << C::BOLD;
    cout << "  +------------------------------------------+" << endl;
    cout << "  |   PITTSFIELD IT ESSENTIALS STUDY TOOL   |" << endl;
    cout << "  |              Powered by C++              |" << endl;
    cout << "  +------------------------------------------+" << C::RST << "\n" << endl;
}

void printSectionHeader(const string& title) {
    string line(54, '=');
    cout << "\n" << C::CYN << C::BOLD;
    cout << "  " << line << "\n";
    cout << "  " << title << "\n";
    cout << "  " << line << C::RST << endl;
}

void printProgressBar(int done, int total) {
    int barW  = 32;
    int filled = (total > 0) ? (int)((float)done / total * barW) : 0;
    cout << C::BLU << "  [" << C::GRN << string(filled, '=')
         << C::DIM << string(barW - filled, '-')
         << C::BLU << "]  " << C::WHT << C::BOLD << done << "/" << total
         << C::RST << endl;
}

string getCorrectMessage(int streak) {
    if (streak >= 5) return "*** ON FIRE!  " + to_string(streak) + " IN A ROW! ***";
    if (streak >= 3) return to_string(streak) + " STREAK!  Keep it up!";
    static const vector<string> msgs = {
        "Correct!", "Nice work!", "Nailed it!", "You got it!",
        "On point!", "That's right!", "Excellent!", "Spot on!"
    };
    static mt19937 rng(random_device{}());
    return msgs[rng() % msgs.size()];
}

string getWrongMessage() {
    static const vector<string> msgs = {
        "Not quite, try again!", "Almost! Give it another shot.",
        "Swing and a miss!", "Nope, keep trying!",
        "Not this time - don't give up!"
    };
    static mt19937 rng(random_device{}());
    return msgs[rng() % msgs.size()];
}

void printFinalScore(int score, int total) {
    if (total == 0) return;
    int pct = (int)((float)score / total * 100.0f);
    string grade, msg, col;
    if      (pct >= 90) { grade = "A+"; msg = "Outstanding!";          col = C::GRN; }
    else if (pct >= 80) { grade = "B";  msg = "Great job!";            col = C::GRN; }
    else if (pct >= 70) { grade = "C";  msg = "Good effort!";          col = C::YLW; }
    else if (pct >= 60) { grade = "D";  msg = "Keep studying!";        col = C::YLW; }
    else                { grade = "F";  msg = "More practice needed!"; col = C::RED; }

    cout << "\n" << C::CYN << C::BOLD << string(44, '=') << C::RST << endl;
    cout << C::CYN << C::BOLD << "             QUIZ COMPLETE!" << C::RST << endl;
    cout << C::CYN << C::BOLD << string(44, '=') << C::RST << endl;
    cout << C::WHT  << "  Score : " << col << C::BOLD
         << score << "/" << total << "  (" << pct << "%)" << C::RST << endl;
    cout << C::WHT  << "  Grade : " << col << C::BOLD
         << grade << "  --  " << msg << C::RST << endl;
    cout << C::CYN  << C::BOLD << string(44, '=') << C::RST << "\n" << endl;
}

void clearScreen() {
    cout << "\033[2J\033[H";
}

void waitForEnter(const string& prompt = "Press Enter to continue...") {
    cout << C::DIM << "  " << prompt << C::RST;
    string dummy;
    getline(cin, dummy);
}

vector<string> wrapText(const string& text, size_t width) {
    vector<string> lines;
    string word;
    string line;
    istringstream iss(text);

    while (iss >> word) {
        if (line.empty()) {
            line = word;
        } else if (line.size() + 1 + word.size() <= width) {
            line += " " + word;
        } else {
            lines.push_back(line);
            line = word;
        }
    }

    if (!line.empty()) lines.push_back(line);
    if (lines.empty()) lines.push_back("");
    return lines;
}

void printCard(const string& title, const vector<string>& body, const string& color = C::CYN, int width = 78) {
    const int inner = width - 4;
    string edge(width - 2, '-');

    cout << color << "  +" << edge << "+" << C::RST << "\n";
    cout << color << "  | " << C::BOLD << left << setw(inner) << title << C::RST << color << " |" << C::RST << "\n";
    cout << color << "  +" << edge << "+" << C::RST << "\n";

    for (const string& raw : body) {
        vector<string> wrapped = wrapText(raw, inner);
        for (const string& line : wrapped) {
            cout << color << "  | " << C::RST << left << setw(inner) << line << color << " |" << C::RST << "\n";
        }
    }

    cout << color << "  +" << edge << "+" << C::RST << "\n";
}

// Structure to hold question data
struct Question {
    string prompt;
    string options[4];
    vector<int> correctAnswers;
    string explanation;
};

vector<int> parseAnswerIndices(const string& indexStr) {
    vector<int> answers;
    string token;
    stringstream ss(indexStr);

    while (getline(ss, token, ',')) {
        size_t start = token.find_first_not_of(" \t");
        size_t end = token.find_last_not_of(" \t");
        if (start == string::npos) continue;
        token = token.substr(start, end - start + 1);

        int idx = stoi(token);
        if (idx >= 0 && idx <= 3) {
            answers.push_back(idx);
        }
    }

    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    return answers;
}

vector<int> parseUserAnswers(const string& input) {
    set<int> selected;

    for (char ch : input) {
        char upper = toupper(static_cast<unsigned char>(ch));
        if (upper >= 'A' && upper <= 'D') {
            selected.insert(upper - 'A');
        }
    }

    return vector<int>(selected.begin(), selected.end());
}

string formatAnswerLetters(const vector<int>& answers) {
    string formatted;
    for (size_t i = 0; i < answers.size(); i++) {
        if (i > 0) formatted += ", ";
        formatted += static_cast<char>('A' + answers[i]);
    }
    return formatted;
}

// Function to load 127 questions from the text file
vector<Question> loadQuestions(string filename) {
    vector<Question> bank;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << C::RED << C::BOLD << "  ERROR: Could not find '" << filename
             << "'. Make sure it is in the same folder as the program!" << C::RST << endl;
        return bank;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        Question q;
        string indexStr;

        // Extracting parts using the '|' delimiter we created
        getline(ss, q.prompt, '|');
        getline(ss, q.options[0], '|');
        getline(ss, q.options[1], '|');
        getline(ss, q.options[2], '|');
        getline(ss, q.options[3], '|');
        getline(ss, indexStr, '|');
        getline(ss, q.explanation, '|');

        try {
            q.correctAnswers = parseAnswerIndices(indexStr);
            if (q.correctAnswers.empty()) {
                continue;
            }
            bank.push_back(q);
        } catch (...) {
            // Skips lines that aren't formatted correctly
            continue;
        }
    }

    file.close();
    cout << C::GRN << "  Loaded " << bank.size() << " questions from database." << C::RST << endl;
    return bank;
}

// ── Quick Reference Guides ──────────────────────────────────────────────────
void showReferenceGuide() {
    const int c1 = 8, c2 = 12, c3 = 38;
    string sep = C::DIM + string(c1 + c2 + c3, '-') + C::RST;

    printSectionHeader("IT ESSENTIALS  -  PORT NUMBER QUICK REFERENCE");
    cout << "\n" << C::YLW << C::BOLD
         << left << setw(c1) << "  Port" << setw(c2) << "Protocol" << setw(c3) << "Description"
         << C::RST << "\n" << sep << endl;

    auto row = [&](const string& port, const string& proto, const string& desc) {
        cout << C::WHT << left << setw(c1) << ("  " + port)
             << C::CYN        << setw(c2) << proto
             << C::RST        << setw(c3) << desc << "\n";
    };
    row("22",  "SSH",     "Secure remote access");
    row("23",  "Telnet",  "Unsecure remote access");
    row("25",  "SMTP",    "Outgoing email");
    row("53",  "DNS",     "Domain Name System");
    row("80",  "HTTP",    "Web browsing (unsecure)");
    row("110", "POP3",    "Incoming email (local)");
    row("137", "NetBIOS", "Windows networking");
    row("143", "IMAP",    "Incoming email (server)");
    row("161", "SNMP",    "Network management");
    row("389", "LDAP",    "Directory services");
    row("443", "HTTPS",   "Web browsing (secure)");
    row("445", "SMB",     "File/printer sharing");
    cout << sep << "\n" << endl;
}

void showAcpiReferenceGuide() {
    const int c1 = 10, c2 = 18, c3 = 46;
    string sep = C::DIM + string(c1 + c2 + c3, '-') + C::RST;

    printSectionHeader("ACPI POWER STATES");
    cout << "\n" << C::YLW << C::BOLD
         << left << setw(c1) << "  State" << setw(c2) << "Name" << setw(c3) << "What Happens"
         << C::RST << "\n" << sep << endl;

    auto row = [&](const string& state, const string& name, const string& desc) {
        cout << C::WHT << left << setw(c1) << ("  " + state)
             << C::CYN        << setw(c2) << name
             << C::RST        << setw(c3) << desc << "\n";
    };
    row("S0",    "Working",       "Everything on");
    row("S1/S2", "Light Sleep",   "CPU paused, RAM still powered");
    row("S3",    "Sleep/Standby", "CPU off, RAM still powered");
    row("S4",    "Hibernate",     "CPU off, RAM saved to disk");
    row("S5",    "Soft Off",      "Fully off, no RAM saved");
    cout << sep << "\n" << endl;
}

void showCloudModelsGuide() {
    const int c1 = 8, c2 = 32, c3 = 46;
    string sep = C::DIM + string(c1 + c2 + c3, '-') + C::RST;

    printSectionHeader("CLOUD SERVICE MODELS");
    cout << "\n" << C::YLW << C::BOLD
         << left << setw(c1) << "  Model" << setw(c2) << "Stands For" << setw(c3) << "What It Provides"
         << C::RST << "\n" << sep << endl;

    auto row = [&](const string& model, const string& full, const string& desc) {
        cout << C::WHT << left << setw(c1) << ("  " + model)
             << C::CYN        << setw(c2) << full
             << C::RST        << setw(c3) << desc << "\n";
    };
    row("IaaS", "Infrastructure as a Service", "Virtual machines, storage, networks");
    row("PaaS", "Platform as a Service",       "Environment to develop, run & manage apps");
    row("SaaS", "Software as a Service",       "Ready-to-use apps  (e.g. Gmail, Office 365)");
    cout << sep << "\n" << endl;
}

void showRaidReferenceGuide() {
    const int c1 = 10, c2 = 26, c3 = 38, c4 = 28, c5 = 6;
    string sep = C::DIM + string(c1 + c2 + c3 + c4 + c5, '-') + C::RST;

    printSectionHeader("RAID QUICK REFERENCE TABLE");
    cout << "\n" << C::YLW << C::BOLD
         << left << setw(c1) << "  Level"
                 << setw(c2) << "Name"
                 << setw(c3) << "What It Does"
                 << setw(c4) << "Redundancy"
                 << setw(c5) << "Drives"
         << C::RST << "\n" << sep << endl;

    auto row = [&](const string& lvl, const string& name, const string& what,
                   const string& red, const string& drives) {
        cout << C::WHT << left << setw(c1) << ("  " + lvl)
             << C::CYN        << setw(c2) << name
             << C::RST        << setw(c3) << what
             << C::YLW        << setw(c4) << red
             << C::GRN        << setw(c5) << drives
             << C::RST        << "\n";
    };
    row("RAID 0",  "Striping",                "Splits data across drives for speed",  "None",                     "2+");
    row("RAID 1",  "Mirroring",               "Exact copy on a second drive",          "Survives 1 drive failure",  "2");
    row("RAID 5",  "Striping + Single Parity","Speed + protection via parity",         "Survives 1 drive failure",  "3+");
    row("RAID 6",  "Striping + Double Parity","Extra parity for higher protection",    "Survives 2 drive failures", "4+");
    row("RAID 10", "Mirroring + Striping",    "Combines speed + redundancy",           "High fault tolerance",      "4+");
    cout << sep << "\n" << endl;
}

// ── Quiz ────────────────────────────────────────────────────────────────────
void runQuiz(vector<Question> bank) {
    if (bank.empty()) {
        cout << C::RED << "  No questions available." << C::RST << endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(bank.begin(), bank.end(), gen);

    int score  = 0;
    int streak = 0;
    int total  = (int)bank.size();
    string input;

    for (int i = 0; i < total; i++) {
        bool answeredCorrectly = false;

        while (!answeredCorrectly) {
            clearScreen();
            printBanner();
            printProgressBar(i, total);
            if (streak >= 3) {
                cout << C::YLW << C::BOLD << "  *** " << streak << " STREAK! ***" << C::RST << "\n";
            }
            cout << "\n";

            vector<string> cardBody;
            cardBody.push_back("Question " + to_string(i + 1) + " of " + to_string(total));
            cardBody.push_back("");
            cardBody.push_back(bank[i].prompt);
            cardBody.push_back("");
            if ((int)bank[i].correctAnswers.size() > 1) {
                cardBody.push_back("Select " + to_string((int)bank[i].correctAnswers.size()) + " answers.");
            } else {
                cardBody.push_back("Select one answer.");
            }
            printCard("QUIZ CARD", cardBody, C::BLU);

            const string optColor[] = { C::YLW, C::MAG, C::CYN, C::GRN };
            for (int o = 0; o < 4; o++) {
                cout << "  " << optColor[o] << C::BOLD << "[ " << (char)('A' + o) << " ] " << C::RST
                     << bank[i].options[o] << "\n";
            }

            cout << "\n";
            if ((int)bank[i].correctAnswers.size() > 1)
                cout << C::DIM << "  (Select " << bank[i].correctAnswers.size()
                     << " answers  e.g. A B  |  S = reveal)  " << C::RST
                     << C::WHT << "> " << C::RST;
            else
                cout << C::DIM << "  (A / B / C / D  |  S = reveal)  " << C::RST
                     << C::WHT << "> " << C::RST;

            getline(cin >> ws, input);
            cout << "\n";

            string upperInput = input;
            for (char& ch : upperInput)
                ch = toupper(static_cast<unsigned char>(ch));

            if (upperInput == "S") {
                cout << C::YLW << "  Answer(s)   : " << C::BOLD
                     << formatAnswerLetters(bank[i].correctAnswers) << C::RST << "\n";
                cout << C::CYN << "  Explanation : " << C::RST
                     << bank[i].explanation << "\n\n";
                streak = 0;
                 waitForEnter();
                break;
            }

            vector<int> userAnswers = parseUserAnswers(input);

            if (userAnswers == bank[i].correctAnswers) {
                streak++;
                score++;
                answeredCorrectly = true;
                cout << C::GRN << C::BOLD << "  [+] " << getCorrectMessage(streak)
                     << C::RST << "\n\n";
                waitForEnter();
            } else {
                streak = 0;
                cout << C::RED << C::BOLD << "  [X] " << getWrongMessage()
                     << C::RST << "\n\n";
                waitForEnter("Press Enter to try again...");
            }
        }
    }

    clearScreen();
    printBanner();
    printFinalScore(score, total);
    waitForEnter("Press Enter to return to menu...");
}

// ── Main ────────────────────────────────────────────────────────────────────
int main() {
    enableAnsi();
    clearScreen();
    printBanner();

    string filename = "questions.txt";
    vector<Question> mainBank = loadQuestions(filename);
    cout << endl;

    int menu = 0;
    do {
        clearScreen();
        printBanner();
        cout << C::CYN << C::BOLD;
        cout << "  +------------------------------------------+" << endl;
        cout << "  |               MAIN  MENU                 |" << endl;
        cout << "  +------------------------------------------+" << C::RST << endl;
        cout << "  " << C::GRN << C::BOLD << "1." << C::RST
             << "  Start Practice Quiz         " << C::GRN  << C::DIM << "[Quiz]"      << C::RST << endl;
        cout << "  " << C::YLW << C::BOLD << "2." << C::RST
             << "  Port Numbers Reference       " << C::YLW << C::DIM << "[Networking]" << C::RST << endl;
        cout << "  " << C::YLW << C::BOLD << "3." << C::RST
             << "  ACPI Power States Guide      " << C::YLW << C::DIM << "[Hardware]"   << C::RST << endl;
        cout << "  " << C::YLW << C::BOLD << "4." << C::RST
             << "  Cloud Service Models Guide   " << C::YLW << C::DIM << "[Cloud]"      << C::RST << endl;
        cout << "  " << C::YLW << C::BOLD << "5." << C::RST
             << "  RAID Quick Reference Guide   " << C::YLW << C::DIM << "[Storage]"    << C::RST << endl;
        cout << "  " << C::RED << C::BOLD << "6." << C::RST
             << "  Exit" << endl;
        cout << C::CYN << "  +------------------------------------------+" << C::RST << endl;
        cout << C::WHT << "  Selection: " << C::RST;
        cin >> menu;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        if      (menu == 1) runQuiz(mainBank);
        else if (menu == 2) { clearScreen(); printBanner(); showReferenceGuide(); waitForEnter("Press Enter to return to menu..."); }
        else if (menu == 3) { clearScreen(); printBanner(); showAcpiReferenceGuide(); waitForEnter("Press Enter to return to menu..."); }
        else if (menu == 4) { clearScreen(); printBanner(); showCloudModelsGuide(); waitForEnter("Press Enter to return to menu..."); }
        else if (menu == 5) { clearScreen(); printBanner(); showRaidReferenceGuide(); waitForEnter("Press Enter to return to menu..."); }
        else if (menu != 6) { cout << C::RED << "  Invalid choice. Enter 1-6.\n" << C::RST; waitForEnter(); }

    } while (menu != 6);

    cout << "\n" << C::CYN << C::BOLD << "  Goodbye! Keep studying hard!" << C::RST << "\n" << endl;
    return 0;
}