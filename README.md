# 💻 C Programming Projects Collection

<div align="center">

![C](https://img.shields.io/badge/C-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)

</div>

---

## 📖 About This Repository

This repository contains a collection of **C programming projects** developed as part of my learning journey. These projects cover fundamental to intermediate concepts of C programming, including problem-solving, data structures, file handling, game development, and real-time applications.

**Perfect for:** Beginners learning C, practicing fundamentals, and understanding real-world application development.

---

## 📂 Projects Overview

### 🏦 [Bank Management System](./bank-management-system/)

A console-based application to manage bank accounts with persistent file storage.

**Features:**
- ✅ Account creation with unique account numbers
- ✅ Deposit and withdrawal operations
- ✅ Balance checking
- ✅ Transaction history
- ✅ File-based data persistence

**Concepts Used:** Structures, File I/O, Functions, Data validation

---

### 🧮 [Basic Calculator](./basic-calculator/)

A simple yet functional calculator performing basic arithmetic operations.

**Features:**
- ✅ Addition, Subtraction, Multiplication, Division
- ✅ Error handling for division by zero
- ✅ User-friendly menu interface
- ✅ Supports floating-point calculations

**Concepts Used:** Conditional statements, Switch-case, Functions, Input validation

---

### 🔢 [Matrix Operations](./matrix-operations/)

Performs various mathematical operations on matrices.

**Features:**
- ✅ Matrix addition, multiplication, and transpose
- ✅ Matrix display utilities
- ✅ Input validation
- ✅ Support for variable matrix sizes

**Concepts Used:** 2D Arrays, Nested loops, Functions, Matrix mathematics

---

### ❌⭕ [Tic Tac Toe Game](./tic-tac-toe/)

A fun 2-player console-based Tic Tac Toe game with game logic.

**Features:**
- ✅ 2-player gameplay (X vs O)
- ✅ Win/Draw detection
- ✅ Turn-based system
- ✅ Board display with proper formatting
- ✅ Input validation

**Concepts Used:** Arrays, Conditional statements, Loop control, Game logic

---

### ⏰ [Digital Clock with Multiple Time Zones](./digital-clock/)

A real-time digital clock displaying current time in 10+ major world time zones.

**Features:**
- ✅ Real-time clock display (updates every second)
- ✅ 10 major world time zones
- ✅ 12/24 hour format toggle
- ✅ Custom timezone selection
- ✅ Date display with day of week
- ✅ Cross-platform support (Windows/Linux/macOS)

**Concepts Used:** Time library, Timezone calculations, Real-time updates, String formatting

---

### ⏱️ [Time Utilities Toolkit](./time-utilities/)

Comprehensive time management tool with countdown timer, stopwatch, and alarm clock.

**Features:**
- ✅ Countdown timer with custom hours/minutes/seconds
- ✅ Stopwatch with unlimited count-up
- ✅ Alarm clock with specific time setting
- ✅ Real-time display (updates every second)
- ✅ Cross-platform support (Windows/Linux/macOS)
- ✅ Visual alarm notifications

**Concepts Used:** Time library, Structures, Real-time loops, Input validation, Signal handling

---

## 🚀 Getting Started

### Prerequisites
- **C Compiler:** GCC, Clang, or MSVC
- **Text Editor:** VS Code, Sublime Text, or any editor
- **Terminal/Command Prompt:** For running compiled programs

### Installation

1. **Clone the repository:**
```bash
git clone https://github.com/iampriyanshuraj01-beep/C-PROJECTS.git
cd C-PROJECTS
```

2. **Navigate to a project:**
```bash
cd project-name
```

3. **Compile the code:**
```bash
gcc -o output_name source_file.c
```

4. **Run the program:**
```bash
./output_name          # Linux/Mac
output_name.exe        # Windows
```

---

## 📚 Learning Outcomes

Through these projects, I've gained proficiency in:

| Concept | Projects | Level |
|---------|----------|-------|
| Variables & Data Types | All | ⭐⭐⭐ |
| Control Flow (if-else, switch) | Calculator, Tic Tac Toe, Clock, Timer | ⭐⭐⭐ |
| Loops (for, while, do-while) | All | ⭐⭐⭐ |
| Functions & Modularity | All | ⭐⭐⭐ |
| Arrays (1D & 2D) | Matrix Ops, Tic Tac Toe | ⭐⭐⭐ |
| Structures | Bank System, Time Utilities | ⭐⭐ |
| File I/O | Bank System | ⭐⭐ |
| Time Library | Digital Clock, Time Utilities | ⭐⭐ |
| Pointers | Bank System | ⭐ |

---

## 🔧 Technologies Used

- **Language:** C (C99/C11 standard)
- **Compiler:** GCC, Clang
- **Editor:** VS Code
- **Build System:** Manual compilation with GCC
- **Version Control:** Git & GitHub

---

## 📋 Project Structure

```
C-PROJECTS/
├── bank-management-system/
│   ├── bank_management.c
│   ├── data.txt
│   └── README.md
├── basic-calculator/
│   ├── calculator.c
│   └── README.md
├── matrix-operations/
│   ├── matrix_operations.c
│   └── README.md
├── tic-tac-toe/
│   ├── tic_tac_toe.c
│   └── README.md
├── digital-clock/
│   ├── digital_clock.c
│   └── README.md
├── time-utilities/
│   ├── time_utilities.c
│   └── README.md
├── .gitignore
├── README.md
├── LICENSE
├── CONTRIBUTING.md
└── SETUP.md
```

---

## 📝 How to Use Each Project

### Step 1: Compile
```bash
gcc -Wall -Wextra -o output_name source_file.c
```

**Flags Explained:**
- `-Wall` : Show all warnings
- `-Wextra` : Show extra warnings
- `-o` : Specify output filename

### Step 2: Run
```bash
./output_name
```

### Step 3: Follow On-Screen Instructions

---

## 🎯 Future Enhancements

- [ ] Add more advanced projects (Linked Lists, Trees, Sorting)
- [ ] Implement GUI using SDL/GTK
- [ ] Add AI opponent for Tic Tac Toe
- [ ] Improve UI with ANSI color codes
- [ ] Add data validation and error handling
- [ ] Create Makefile for easy compilation
- [ ] Add unit tests for each project
- [ ] Document edge cases and limitations

---

## 💡 Tips for Learning

1. **Read the Code:** Understand the logic before running
2. **Modify & Experiment:** Change values, add features
3. **Debug:** Use printf() for debugging output
4. **Trace:** Follow variable values step-by-step
5. **Compare:** Look at different approaches to solve the same problem

---

## 📊 Project Statistics

| Project | Lines of Code | Difficulty | Time to Build | Concepts |
|---------|---------------|-----------|---------------|----|
| Basic Calculator | ~150 | ⭐ Easy | 30 mins | Functions, Switch |
| Matrix Operations | ~250 | ⭐⭐ Medium | 1 hour | Arrays, Loops |
| Tic Tac Toe | ~300 | ⭐⭐ Medium | 1.5 hours | Game Logic, Arrays |
| Digital Clock | ~350 | ⭐⭐ Medium | 1.5 hours | Time Library, Loops |
| Time Utilities | ~320 | ⭐⭐ Medium | 1.5 hours | Structures, Time |
| Bank Management | ~400 | ⭐⭐⭐ Hard | 2+ hours | Structures, File I/O |

---

## 🤝 Contributing

This is a learning repository, but contributions are welcome!

**To contribute:**
1. Fork the repository
2. Create a new branch (`git checkout -b feature/improvement`)
3. Make your changes
4. Commit (`git commit -m 'Add improvement'`)
5. Push (`git push origin feature/improvement`)
6. Open a Pull Request

See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines.

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

You are free to use, modify, and distribute these projects for educational purposes.

---

## 📞 Contact & Support

**Got questions or suggestions?**
- 📧 Email: [iampriyanshuraj01@gmail.com](mailto:iampriyanshuraj01@gmail.com)
- 💼 LinkedIn: [Priyanshu Raj](https://linkedin.com/in/rajpriyanshu)
- 🐦 Twitter: [@rajpriyanshu](https://twitter.com/rajpriyanshu)
- 📱 Instagram: [@rajpriyanshu1169](https://instagram.com/rajpriyanshu1169)

---

## 🙌 Acknowledgments

- **C Programming Community** - For resources and guidance
- **GCC Compiler Documentation** - For comprehensive reference
- **All Contributors** - Who provided feedback and improvements

---

## ⭐ Show Your Support

If this repository helped you learn C programming:

- ⭐ **Star this repository** to show your support
- 🔄 **Share** with other learners
- 💬 **Leave feedback** in the issues section
- 🤝 **Contribute** with improvements

---

<div align="center">

**Happy Coding! 🚀**

Made with ❤️ by [Priyanshu Raj](https://github.com/iampriyanshuraj01-beep)

![Profile Views](https://komarev.com/ghpvc/?username=iampriyanshuraj01-beep&color=blue)

</div>
