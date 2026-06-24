# Math Quiz Game (Refactored Edition) 🧠🕹️

A highly structured, memory-efficient command-line mathematical quiz application built in C++. This branch (`Teacher-Method`) represents a major architectural upgrade, refactoring the original sequential codebase into a professional, modular design inspired by industry-standard code reviews.

---

## 📋 Technical Evolution & Truth

This branch focuses on advancing code efficiency, memory management, and clean flow control. By restructuring the logic, I bridged the gap between functional writing and professional software craftsmanship.

### Key Engineering Milestones:
* **Memory Optimization via Pass-by-Reference:** Transitioned macro data structures (`stQuiz& quiz`) to utilize reference pointers. This prevents the CPU from creating expensive memory copies of the 100-question array layout in the RAM during runtime transitions.
* **The Division Precision Safeguard:** Maintained the strict mathematical constraint where division operations are filtered via localized `do-while` stability loops. This, based on logic reviews, forces the system to regenerate numbers until a clean integer division (`% == 0`) is guaranteed, avoiding standard compiler truncation flaws.
* **Advanced State Architecture:** Integrated system configuration commands (`system("cls")`, `system("color")`) to handle UI state transitions natively based on gameplay feedback loops.

---

## 🛠️ Refactored Architecture

The codebase enforces strict **Separation of Concerns (SoC)**, separating logic generation, evaluation, and rendering:

    [MathGame Execution Flow]
        │
        ├──► 1. Read Inputs (Questions, Difficulty, Operation)
        ├──► 2. GenerateQuestions(stQuiz& quiz) -> [Pre-computes and caches array]
        ├──► 3. AskAndCorrectQuestions(stQuiz& quiz) -> [Main Game Loop & State Changes]
        └──► 4. PrintFinalResult(stQuiz) -> [Pure Rendering Output]

### Key Data Encapsulations
* **`stQuestion`:** Encapsulates localized scope data for a single math prompt (operands, operators, individual status flags, and correct answers).
* **`stQuiz`:** Acts as the master state machine caching the `stQuestion` array, dynamic scoring counters (`correctAnswers`, `wrongAnswers`), and global pass/fail conditions.

---

## ⚙️ Game Settings & Tiers

### 1. Difficulty Brackets
| Level | Range Matrix | Description |
| :--- | :--- | :--- |
| **Easy** | 1 to 10 | Designed for basic operational tracking. |
| **Mid** | 10 to 50 | Medium numbers to challenge intermediate computation. |
| **Hard** | 50 to 99 | High tier numbers testing advanced calculations. |
| **Mix** | Dynamic | Real-time hardware-seeded randomization per prompt. |

### 2. Arithmetic Matrices
* Supported operations: **Addition (`+`)**, **Subtraction (`-`)**, **Multiplication (`*`)**, and **Division (`/`)**.
* **Mix Mode:** Dynamic sequencing that cycles through operators randomly per question.

---

## 🚀 Compilation and Execution

1. Clone the repository and checkout to the refactored branch:
   `git checkout Teacher-Method`

2. Compile via any standard C++17 compiler (GCC/Clang):
   `g++ -std=c++17 Math-Quiz.cpp -o MathQuiz`

3. Run the compiled binary:
   `./MathQuiz`

---

## 🎓 Acknowledgment
This branch serves as a practical implementation of structural code reviews, demonstrating mastery over Git branching, pointer/reference memory allocation, and defensive programming architectures.
