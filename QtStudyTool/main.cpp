#include <QApplication>
#include <QCheckBox>
#include <QCoreApplication>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFrame>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRandomGenerator>
#include <QTableWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QVector>

#include <algorithm>

struct Question {
    QString prompt;
    QString options[4];
    QVector<int> correctAnswers;
    QString explanation;
};

static QVector<int> parseAnswerIndices(const QString& indexStr) {
    QVector<int> out;
    const QStringList parts = indexStr.split(',', Qt::SkipEmptyParts);
    for (const QString& p : parts) {
        bool ok = false;
        int idx = p.trimmed().toInt(&ok);
        if (ok && idx >= 0 && idx <= 3 && !out.contains(idx)) {
            out.push_back(idx);
        }
    }
    std::sort(out.begin(), out.end());
    return out;
}

static QVector<Question> loadQuestions(const QString& path) {
    QVector<Question> bank;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return bank;
    }

    while (!file.atEnd()) {
        const QString line = QString::fromUtf8(file.readLine()).trimmed();
        if (line.isEmpty()) {
            continue;
        }

        const QStringList parts = line.split('|');
        if (parts.size() < 7) {
            continue;
        }

        Question q;
        q.prompt = parts[0].trimmed();
        q.options[0] = parts[1].trimmed();
        q.options[1] = parts[2].trimmed();
        q.options[2] = parts[3].trimmed();
        q.options[3] = parts[4].trimmed();
        q.correctAnswers = parseAnswerIndices(parts[5]);
        q.explanation = parts[6].trimmed();

        if (!q.correctAnswers.isEmpty()) {
            bank.push_back(q);
        }
    }

    return bank;
}

static QString findQuestionsFile() {
    const QString fileName = "questions.txt";

    QStringList baseDirs;
    baseDirs << QCoreApplication::applicationDirPath() << QDir::currentPath();

    // Walk up several directory levels from both app dir and CWD.
    for (const QString& base : baseDirs) {
        QDir dir(base);
        for (int i = 0; i < 6; ++i) {
            const QString candidate = dir.filePath(fileName);
            if (QFileInfo::exists(candidate)) {
                return QDir::cleanPath(candidate);
            }
            if (!dir.cdUp()) {
                break;
            }
        }
    }

    return QString();
}

static QString answersToLetters(const QVector<int>& answers) {
    QStringList out;
    for (int a : answers) {
        out << QString(QChar('A' + a));
    }
    return out.join(", ");
}

class ReferencesDialog : public QDialog {
public:
    explicit ReferencesDialog(QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Quick References");
        resize(860, 500);

        auto* root = new QVBoxLayout(this);
        auto* searchRow = new QHBoxLayout();
        auto* searchLabel = new QLabel("Search Acronyms:", this);
        acronymSearch_ = new QLineEdit(this);
        acronymSearch_->setPlaceholderText("Type acronym or meaning (e.g. BIOS, network, protocol)...");
        searchRow->addWidget(searchLabel);
        searchRow->addWidget(acronymSearch_, 1);
        root->addLayout(searchRow);

        auto* tabs = new QTabWidget(this);

        tabs->addTab(buildPortsTable(), "Ports");
        tabs->addTab(buildAcpiTable(), "ACPI");
        tabs->addTab(buildCloudTable(), "Cloud");
        tabs->addTab(buildRaidTable(), "RAID");
        acronymsTable_ = buildAcronymsTable();
        tabs->addTab(acronymsTable_, "Acronyms");

        root->addWidget(tabs);

        connect(acronymSearch_, &QLineEdit::textChanged, this, [this](const QString& text) {
            filterAcronyms(text);
        });

        auto* closeBtn = new QPushButton("Close", this);
        connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
        root->addWidget(closeBtn, 0, Qt::AlignRight);

        setStyleSheet(
            "QDialog { background: #0b1220; color: #e6edf3; }"
            "QTabWidget::pane { border: 1px solid #2d3748; border-radius: 8px; }"
            "QTabBar::tab { background: #111827; color: #cbd5e1; padding: 8px 14px; margin-right: 4px; border-top-left-radius: 6px; border-top-right-radius: 6px; }"
            "QTabBar::tab:selected { background: #1f2937; color: #93c5fd; }"
            "QTableWidget { background: #0f172a; color: #e2e8f0; gridline-color: #334155; border: none; }"
            "QHeaderView::section { background: #1e293b; color: #93c5fd; border: none; padding: 6px; }"
            "QLineEdit { background: #0f172a; border: 1px solid #334155; border-radius: 8px; padding: 6px 10px; color: #e2e8f0; }"
            "QPushButton { background: #2563eb; color: white; border: none; border-radius: 8px; padding: 8px 14px; }"
            "QPushButton:hover { background: #1d4ed8; }"
        );
    }

private:
    static QTableWidget* makeTable(const QStringList& headers, const QVector<QStringList>& rows) {
        auto* table = new QTableWidget(rows.size(), headers.size());
        table->setHorizontalHeaderLabels(headers);
        table->horizontalHeader()->setStretchLastSection(true);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        table->verticalHeader()->setVisible(false);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionMode(QAbstractItemView::NoSelection);

        for (int r = 0; r < rows.size(); ++r) {
            const auto& row = rows[r];
            for (int c = 0; c < row.size(); ++c) {
                table->setItem(r, c, new QTableWidgetItem(row[c]));
            }
        }
        return table;
    }

    static QWidget* buildPortsTable() {
        QVector<QStringList> rows = {
            {"22", "SSH", "Secure remote access"},
            {"23", "Telnet", "Unsecure remote access"},
            {"25", "SMTP", "Outgoing email"},
            {"53", "DNS", "Domain Name System"},
            {"80", "HTTP", "Web browsing (unsecure)"},
            {"110", "POP3", "Incoming email (local)"},
            {"137", "NetBIOS", "Windows networking"},
            {"143", "IMAP", "Incoming email (server)"},
            {"161", "SNMP", "Network management"},
            {"389", "LDAP", "Directory services"},
            {"443", "HTTPS", "Web browsing (secure)"},
            {"445", "SMB", "File/printer sharing"}
        };
        return makeTable({"Port", "Protocol", "Description"}, rows);
    }

    static QWidget* buildAcpiTable() {
        QVector<QStringList> rows = {
            {"S0", "Working", "Everything on"},
            {"S1/S2", "Light Sleep", "CPU paused, RAM still powered"},
            {"S3", "Sleep / Standby", "CPU off, RAM still powered"},
            {"S4", "Hibernate", "CPU off, RAM saved to disk"},
            {"S5", "Soft Off", "Fully off, no RAM saved"}
        };
        return makeTable({"State", "Name", "What Happens"}, rows);
    }

    static QWidget* buildCloudTable() {
        QVector<QStringList> rows = {
            {"IaaS", "Infrastructure as a Service", "Virtual machines, storage, networks"},
            {"PaaS", "Platform as a Service", "Develop, run, and manage applications"},
            {"SaaS", "Software as a Service", "Ready-to-use apps (Gmail, Office 365)"}
        };
        return makeTable({"Model", "Stands For", "What It Provides"}, rows);
    }

    static QWidget* buildRaidTable() {
        QVector<QStringList> rows = {
            {"RAID 0", "Striping", "Speed", "None", "2+"},
            {"RAID 1", "Mirroring", "Exact copy on second drive", "Survives 1 drive failure", "2"},
            {"RAID 5", "Striping + Single Parity", "Speed + parity", "Survives 1 drive failure", "3+"},
            {"RAID 6", "Striping + Double Parity", "Extra parity", "Survives 2 drive failures", "4+"},
            {"RAID 10", "Mirroring + Striping", "Speed + redundancy", "High fault tolerance", "4+"}
        };
        return makeTable({"Level", "Name", "What It Does", "Redundancy", "Drives"}, rows);
    }

    static QTableWidget* buildAcronymsTable() {
        QVector<QStringList> rows = {
            {"V", "Voltage", "Electrical potential difference"},
            {"I", "Current or intensity of current", "Flow of electrical charge"},
            {"R", "Resistance", "Opposition to electrical flow"},
            {"MAC", "Media Access Control", "Physical address on network"},
            {"OUI", "Organizationally Unique Identifier", "First 24 bits of MAC address"},
            {"RAID", "Redundant Array of Independent Disks", "Data storage redundancy"},
            {"SATA", "Serial Advanced Technology Attachment", "Internal drive connection standard"},
            {"ATA", "Advanced Technology Attachment", "Older disk interface standard"},
            {"HDD", "Hard Disk Drive", "Mechanical spinning storage"},
            {"SSD", "Solid State Drive", "Electronic no-moving-parts storage"},
            {"PSU", "Power Supply Unit", "Converts AC to DC power"},
            {"RAM", "Random Access Memory", "Volatile temporary memory"},
            {"ROM", "Read Only Memory", "Non-volatile fixed memory"},
            {"PROM", "Programmable Read-Only Memory", "One-time programmable ROM"},
            {"EPROM", "Erasable Programmable ROM", "UV light erasable ROM"},
            {"EEPROM", "Electrically Erasable Programmable ROM", "Electrically erasable ROM"},
            {"CPU", "Central Processing Unit", "Main processor"},
            {"BIOS", "Basic Input/Output System", "Firmware that boots system"},
            {"UEFI", "Unified Extensible Firmware Interface", "Modern BIOS replacement"},
            {"IDE", "Integrated Drive Electronics", "Older disk interface standard"},
            {"LGA", "Land Grid Array", "CPU socket with pins in socket"},
            {"PGA", "Pin Grid Array", "CPU socket with processor pins"},
            {"USB", "Universal Serial Bus", "Connection standard for peripherals"},
            {"DIP", "Dual Inline Package", "Memory chip connecting format"},
            {"SIMM", "Single Inline Memory Module", "72-pin memory module"},
            {"DIMM", "Dual Inline Memory Module", "184-pin memory module"},
            {"SODIMM", "Small Outline DIMM", "Laptop memory module"},
            {"ECC", "Error Correction Code", "Memory error detection/correction"},
            {"PCI", "Peripheral Component Interconnect", "32/64-bit expansion slot"},
            {"Mini-PCI", "Mini Peripheral Component Interconnect", "Compact PCI for laptops"},
            {"PCIx", "PCI Extended", "4 times faster than standard PCI"},
            {"PCIe", "PCI Express", "64 bit parallel interface, faster than PCI"},
            {"NIC", "Network Interface Card", "Connects computer to network"},
            {"AGP", "Accelerated Graphics Port", "GPU video card connection"},
            {"EIDE", "Enhanced Integrated Drive Electronics", "Enhanced IDE standard"},
            {"SCSI", "Small Computer System Interface", "High-speed device interface"},
            {"DVI", "Digital Visual Interface", "Digital video connection"},
            {"DP", "DisplayPort", "Modern display connection"},
            {"HDMI", "High-Definition Multimedia Interface", "Audio/video connection"},
            {"VGA", "Video Graphics Array", "Legacy analog video"},
            {"RCA", "Radio Corporation of America", "Legacy audio/video connectors"},
            {"ATX", "Advanced Technology eXtended", "Standard motherboard form factor"},
            {"DHCP", "Dynamic Host Configuration Protocol", "Automatic IP assignment"},
            {"DNS", "Domain Name System", "Domain to IP resolution"},
            {"SPF", "Sender Policy Framework", "Email authentication"},
            {"DKIM", "DomainKeys Identified Mail", "Email digital signature"},
            {"DMARC", "Domain-based Message Authentication", "Email policy/reporting"},
            {"UDP", "User Datagram Protocol", "Connectionless protocol"},
            {"ICMP", "Internet Control Message Protocol", "Ping/echo protocol"},
            {"ACPI", "Advanced Configuration and Power Interface", "Power management standard"},
            {"CRU", "Customer Replaceable Units", "Parts user can replace"},
            {"FRU", "Field Replaceable Units", "Parts technician can replace"},
            {"IMEI", "International Mobile Equipment Identity", "Unique phone identifier"},
            {"GSM", "Global System for Mobile Communications", "2G mobile standard"}
        };

        std::sort(rows.begin(), rows.end(), [](const QStringList& a, const QStringList& b) {
            return a[0].compare(b[0], Qt::CaseInsensitive) < 0;
        });

        return makeTable({"Acronym", "Stands For", "What It Means"}, rows);
    }

    void filterAcronyms(const QString& text) {
        if (!acronymsTable_) {
            return;
        }

        const QString needle = text.trimmed();
        for (int r = 0; r < acronymsTable_->rowCount(); ++r) {
            bool match = needle.isEmpty();
            if (!match) {
                for (int c = 0; c < acronymsTable_->columnCount(); ++c) {
                    auto* item = acronymsTable_->item(r, c);
                    if (item && item->text().contains(needle, Qt::CaseInsensitive)) {
                        match = true;
                        break;
                    }
                }
            }
            acronymsTable_->setRowHidden(r, !match);
        }
    }

private:
    QLineEdit* acronymSearch_ = nullptr;
    QTableWidget* acronymsTable_ = nullptr;
};

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        setWindowTitle("Pittsfield IT Study Tool - Qt Edition");
        resize(980, 700);

        const QString questionsPath = findQuestionsFile();
        if (!questionsPath.isEmpty()) {
            questions_ = loadQuestions(questionsPath);
            questionsPath_ = questionsPath;
        }

        auto* central = new QWidget(this);
        setCentralWidget(central);

        auto* root = new QVBoxLayout(central);
        root->setSpacing(14);
        root->setContentsMargins(22, 22, 22, 22);

        auto* top = new QHBoxLayout();
        title_ = new QLabel("IT Essentials Study Deck", this);
        title_->setObjectName("title");
        progressLabel_ = new QLabel(this);
        progressLabel_->setObjectName("subtle");
        top->addWidget(title_);
        top->addStretch();
        top->addWidget(progressLabel_);

        progressBar_ = new QProgressBar(this);
        progressBar_->setRange(0, static_cast<int>(questions_.size()));

        card_ = new QFrame(this);
        card_->setObjectName("card");
        auto* cardLayout = new QVBoxLayout(card_);
        cardLayout->setSpacing(10);

        questionLabel_ = new QLabel(this);
        questionLabel_->setWordWrap(true);
        questionLabel_->setObjectName("question");
        cardLayout->addWidget(questionLabel_);

        for (int i = 0; i < 4; ++i) {
            optionChecks_[i] = new QCheckBox(this);
            cardLayout->addWidget(optionChecks_[i]);
        }

        hintLabel_ = new QLabel(this);
        hintLabel_->setObjectName("subtle");
        cardLayout->addWidget(hintLabel_);

        explanation_ = new QPlainTextEdit(this);
        explanation_->setReadOnly(true);
        explanation_->setMaximumHeight(120);
        explanation_->setObjectName("explain");

        auto* buttons = new QHBoxLayout();
        auto* submitBtn = new QPushButton("Submit", this);
        auto* revealBtn = new QPushButton("Reveal", this);
        auto* nextBtn = new QPushButton("Next", this);
        auto* refsBtn = new QPushButton("Quick References", this);
        auto* restartBtn = new QPushButton("Restart Quiz", this);

        buttons->addWidget(submitBtn);
        buttons->addWidget(revealBtn);
        buttons->addWidget(nextBtn);
        buttons->addStretch();
        buttons->addWidget(refsBtn);
        buttons->addWidget(restartBtn);

        status_ = new QLabel(this);
        status_->setObjectName("status");

        root->addLayout(top);
        root->addWidget(progressBar_);
        root->addWidget(card_, 1);
        root->addWidget(explanation_);
        root->addLayout(buttons);
        root->addWidget(status_);

        connect(submitBtn, &QPushButton::clicked, this, [this]() { submitAnswer(); });
        connect(revealBtn, &QPushButton::clicked, this, [this]() { revealAnswer(); });
        connect(nextBtn, &QPushButton::clicked, this, [this]() { nextQuestion(); });
        connect(refsBtn, &QPushButton::clicked, this, [this]() {
            ReferencesDialog dlg(this);
            dlg.exec();
        });
        connect(restartBtn, &QPushButton::clicked, this, [this]() { restartQuiz(); });

        setStyleSheet(
            "QMainWindow, QWidget { background: #0a1020; color: #e2e8f0; font-size: 14px; }"
            "QLabel#title { font-size: 28px; font-weight: 700; color: #7dd3fc; }"
            "QLabel#question { font-size: 19px; font-weight: 700; color: #f8fafc; }"
            "QLabel#subtle { color: #94a3b8; font-size: 13px; }"
            "QLabel#status { font-size: 15px; font-weight: 700; color: #cbd5e1; }"
            "QFrame#card { background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #111827, stop:1 #1f2937); border: 1px solid #334155; border-radius: 16px; padding: 14px; }"
            "QCheckBox { spacing: 10px; font-size: 15px; color: #e5e7eb; }"
            "QCheckBox::indicator { width: 18px; height: 18px; }"
            "QPushButton { background: #1d4ed8; color: white; border: none; border-radius: 10px; padding: 9px 14px; font-weight: 600; }"
            "QPushButton:hover { background: #2563eb; }"
            "QPushButton:pressed { background: #1e40af; }"
            "QProgressBar { border: 1px solid #334155; border-radius: 8px; text-align: center; background: #0f172a; color: #cbd5e1; }"
            "QProgressBar::chunk { background: #06b6d4; border-radius: 7px; }"
            "QPlainTextEdit#explain { background: #0f172a; border: 1px solid #334155; border-radius: 10px; color: #cbd5e1; }"
        );

        restartQuiz();
    }

private:
    void restartQuiz() {
        if (questions_.isEmpty()) {
            questionLabel_->setText("Could not load questions.txt");
            status_->setText("Searched near app and parent folders. Put questions.txt in CPP_Projects or next to the exe.");
            return;
        }

        QVector<int> ids;
        ids.reserve(questions_.size());
        for (int i = 0; i < questions_.size(); ++i) ids.push_back(i);
        std::shuffle(ids.begin(), ids.end(), *QRandomGenerator::global());
        order_ = ids;

        current_ = 0;
        score_ = 0;
        streak_ = 0;
        updateView();
    }

    void updateView() {
        if (current_ >= order_.size()) {
            questionLabel_->setText("Quiz complete!\n\nGreat work.");
            for (auto* cb : optionChecks_) {
                cb->setVisible(false);
            }
            hintLabel_->setText(QString("Final Score: %1 / %2").arg(score_).arg(order_.size()));
            explanation_->setPlainText("Use Restart Quiz to play another round.");
            progressLabel_->setText("Done");
            progressBar_->setValue(order_.size());
            status_->setText("Session complete.");
            return;
        }

        for (auto* cb : optionChecks_) {
            cb->setVisible(true);
            cb->setChecked(false);
        }

        const Question& q = questions_[order_[current_]];
        questionLabel_->setText(q.prompt);
        optionChecks_[0]->setText(QString("A) %1").arg(q.options[0]));
        optionChecks_[1]->setText(QString("B) %1").arg(q.options[1]));
        optionChecks_[2]->setText(QString("C) %1").arg(q.options[2]));
        optionChecks_[3]->setText(QString("D) %1").arg(q.options[3]));

        hintLabel_->setText(q.correctAnswers.size() > 1
                            ? QString("Select %1 answers.").arg(q.correctAnswers.size())
                            : "Select one answer.");
        explanation_->setPlainText("Explanation appears here after submit/reveal.");

        progressLabel_->setText(QString("Question %1 of %2").arg(current_ + 1).arg(order_.size()));
        progressBar_->setValue(current_);
        status_->setText(QString("Score: %1   |   Streak: %2   |   File: %3")
                         .arg(score_)
                         .arg(streak_)
                         .arg(questionsPath_.isEmpty() ? "unknown" : QFileInfo(questionsPath_).fileName()));
    }

    QVector<int> selectedAnswers() const {
        QVector<int> out;
        for (int i = 0; i < 4; ++i) {
            if (optionChecks_[i]->isChecked()) {
                out.push_back(i);
            }
        }
        std::sort(out.begin(), out.end());
        return out;
    }

    void submitAnswer() {
        if (current_ >= order_.size()) return;

        const Question& q = questions_[order_[current_]];
        const QVector<int> picked = selectedAnswers();

        if (picked.isEmpty()) {
            QMessageBox::information(this, "Pick an answer", "Select at least one option before submitting.");
            return;
        }

        if (picked == q.correctAnswers) {
            ++score_;
            ++streak_;
            explanation_->setPlainText(QString("Correct!\n\n%1").arg(q.explanation));
            status_->setText(QString("Nice! Score: %1   |   Streak: %2").arg(score_).arg(streak_));
        } else {
            streak_ = 0;
            explanation_->setPlainText("Not quite. Click 'Reveal' to see the correct answer (R).");
            status_->setText(QString("Keep going! Score: %1").arg(score_));
        }
    }

    void revealAnswer() {
        if (current_ >= order_.size()) return;
        const Question& q = questions_[order_[current_]];
        streak_ = 0;
        explanation_->setPlainText(QString("Answer(s): %1\n\n%2")
                                   .arg(answersToLetters(q.correctAnswers))
                                   .arg(q.explanation));
        status_->setText(QString("Revealed. Score: %1").arg(score_));
    }

    void nextQuestion() {
        if (current_ < order_.size()) {
            ++current_;
        }
        updateView();
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        const QString text = event->text().toUpper();
        
        // Enter key submits answer
        if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            submitAnswer();
            event->accept();
            return;
        }
        
        // Map keys A, B, C, D to checkboxes 0, 1, 2, 3
        if (text == "A" || text == "B" || text == "C" || text == "D") {
            int idx = text[0].unicode() - 'A';
            if (idx >= 0 && idx < 4) {
                optionChecks_[idx]->setChecked(!optionChecks_[idx]->isChecked());
                event->accept();
                return;
            }
        }
        
        // Quick key shortcuts for buttons
        if (text == "S") {
            submitAnswer();
            event->accept();
            return;
        }
        if (text == "R") {
            revealAnswer();
            event->accept();
            return;
        }
        if (text == "N") {
            nextQuestion();
            event->accept();
            return;
        }
        
        QMainWindow::keyPressEvent(event);
    }

private:
    QVector<Question> questions_;
    QVector<int> order_;

    int current_ = 0;
    int score_ = 0;
    int streak_ = 0;
    QString questionsPath_;

    QLabel* title_ = nullptr;
    QLabel* progressLabel_ = nullptr;
    QProgressBar* progressBar_ = nullptr;
    QFrame* card_ = nullptr;
    QLabel* questionLabel_ = nullptr;
    QCheckBox* optionChecks_[4] = {nullptr, nullptr, nullptr, nullptr};
    QLabel* hintLabel_ = nullptr;
    QPlainTextEdit* explanation_ = nullptr;
    QLabel* status_ = nullptr;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
