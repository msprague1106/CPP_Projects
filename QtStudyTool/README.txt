QtStudyTool (Option 1 Prototype)

What this is:
- A GUI version of your study app using Qt Widgets.
- Includes card-style quiz UI, buttons, progress bar, and quick reference tabs.

Prerequisites:
- Qt 6 or Qt 5 (Widgets module)
- CMake 3.16+
- A C++ compiler (you already have MinGW)

Build (PowerShell):
1) cd D:\CPP_Projects\QtStudyTool
2) cmake -S . -B build -G "MinGW Makefiles"
3) cmake --build build
4) .\build\QtStudyTool.exe

Notes:
- The app looks for questions.txt in:
  - ../questions.txt
  - questions.txt
- With your current repo layout, ../questions.txt should work.
