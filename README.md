# Math Quiz Game 🧠🕹️

A robust command-line mathematical quiz application built from scratch using pure C++. This project was designed to test logical thinking, software architecture principles, and algorithmic independence in the early stages of my software engineering journey.

---

## 📋 The Real Truth Behind the Project

This project is a product of raw problem-solving and pure learning. No boilerplate templates or copy-pasted code snippets were used. Every single function, data structure, and logical loop was engineered step-by-step from my own understanding. 

While practicing, I hit critical software engineering milestones:
* **The Division Precision Trap:** During a technical code review session with an AI assistant, a critical floating-point precision vulnerability was identified when handling dynamic division operations (like 7/3) in C++.
* **The Engineering Fix:** Based on the architectural logic suggested by the AI, I manually refactored my codebase, adjusted the internal struct variables to pure integer configurations, and coded the required `do-while` safety loops across all difficulty brackets to ensure only clean divisions (`% == 0`) are served to the user.
* **The "Mix/Mixed" Architecture Challenge:** I engineered separate lookup mapping utilities (`GetDiff` and `GetOpe`) along with a dynamic randomizer to simulate true unpredictable gameplay when the user chooses mixed difficulty or mixed operations.

---

## 🛠️ Key Architectural Features

Instead of relying on chaotic structural chains of `if-else` loops, this codebase embraces standard architectural practices:

* **Separated Data Structures (Structs):** * `stQuiz`: Manages and isolates individual question parameters (numbers, correct answers, specific operations).
  * `stResults`: Manages the macro game states, final score keeping, and metrics tracking.
* **Separation of Concerns:** Following clean code standards, dynamic text generation logic (e.g., `GetFinalResult`) is fully decoupled from input/output streams (`PrintFinalResult`), making the core logic highly reusable.
* **Pre-Computation Philosophy:** Questions and answers are systematically generated and pushed into a dynamic array layout *before* the round loop even begins, separating logic generation from rendering.
* **Generic Functional Programming:** Integrated universal boundary validation utilities like `ReadNumberInRange` to ensure complete decoupling of input code.

---

## ⚙️ Game Settings & Modes

### 1. Difficulty Levels
* **Easy:** Numbers generated between 1 and 10.
* **Mid:** Numbers generated between 10 and 50.
* **Hard:** Numbers generated between 50 and 99.
* **Mix:** Dynamic real-time randomization of all three tiers per question.

### 2. Supported Operations
* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`) *(Guaranteed whole integer results without precision drops)*
* Mix (`+`, `-`, `*`, `/` randomized sequentially)

---

## 🚀 How to Run Locally

1. Clone or pull the script directly to your local terminal path.
2. Compile using any standard C++ compiler (G++ recommended):
   ```bash
   g++ -std=c++17 math_quiz.cpp -o MathQuiz
