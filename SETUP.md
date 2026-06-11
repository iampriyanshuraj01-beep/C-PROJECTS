# 🛠️ Setup Guide for C-PROJECTS

This guide will help you set up the environment to compile and run all projects in this repository.

## 📋 Prerequisites

### Windows

#### Option 1: Using MinGW (Recommended)
1. Download MinGW installer from [mingw.org](https://www.mingw.org/)
2. Run the installer
3. Select "gcc" package
4. Complete installation
5. Add MinGW to PATH:
   - Right-click "This PC" → Properties
   - Click "Advanced system settings"
   - Click "Environment Variables"
   - Add MinGW bin folder to PATH

#### Option 2: Using WSL (Windows Subsystem for Linux)
```bash
# Enable WSL
wsl --install

# Install GCC in WSL
sudo apt-get update
sudo apt-get install build-essential gcc
```

#### Option 3: Using Visual Studio Code + MinGW
- Install VS Code from [code.visualstudio.com](https://code.visualstudio.com/)
- Install "C/C++" extension by Microsoft
- Follow MinGW installation above

### macOS

#### Using Homebrew (Recommended)
```bash
# Install Homebrew if not installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install GCC
brew install gcc
```

#### Using Xcode Command Line Tools
```bash
xcode-select --install
```

### Linux (Ubuntu/Debian)

```bash
# Update package manager
sudo apt-get update

# Install build tools
sudo apt-get install build-essential gcc

# Verify installation
gcc --version
```

### Linux (Fedora/CentOS/RHEL)

```bash
# Install GCC
sudo dnf install gcc

# Or for CentOS
sudo yum install gcc

# Verify installation
gcc --version
```

---

## ✅ Verify Installation

After installation, verify that everything is working:

```bash
# Check GCC version
gcc --version

# Create a test file
echo '#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}' > test.c

# Compile
gcc -o test test.c

# Run
./test    # Linux/Mac
test.exe  # Windows

# Clean up
rm test test.c test.exe
```

---

## 🚀 Compiling Projects

### Basic Compilation

Navigate to the project directory:

```bash
cd project-name
gcc -o output_name source_file.c
./output_name
```

### Recommended Flags

```bash
# With warnings (RECOMMENDED)
gcc -Wall -Wextra -o output_name source_file.c

# With debugging symbols
gcc -g -o output_name source_file.c

# With optimizations
gcc -O2 -o output_name source_file.c

# All together
gcc -Wall -Wextra -g -O2 -o output_name source_file.c
```

### Using a Makefile (Optional)

Create a `Makefile` in the project directory:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = program_name
SRCS = *.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
```

Then use:
```bash
make           # Compile
make run       # Compile and run
make clean     # Clean up
```

---

## 📖 Compiling Each Project

### 🏦 Bank Management System

```bash
cd bank-management-system
gcc -Wall -Wextra -o bank_system bank_management.c
./bank_system
```

### 🧮 Basic Calculator

```bash
cd basic-calculator
gcc -Wall -Wextra -o calculator calculator.c
./calculator
```

### 🔢 Matrix Operations

```bash
cd matrix-operations
gcc -Wall -Wextra -o matrix_ops matrix_operations.c
./matrix_ops
```

### ❌⭕ Tic Tac Toe

```bash
cd tic-tac-toe
gcc -Wall -Wextra -o tictactoe tic_tac_toe.c
./tictactoe
```

---

## 🛠️ Using an IDE

### Visual Studio Code

1. **Install Extensions:**
   - C/C++ by Microsoft
   - Code Runner by Jun Han

2. **Create `.vscode/settings.json`:**
```json
{
    "code-runner.executorMap": {
        "c": "cd $dir && gcc -Wall -Wextra -o $fileNameWithoutExt $fileName && ./$fileNameWithoutExt"
    }
}
```

3. **Run:** Press `Ctrl+Alt+N` or right-click → Run Code

### Code Blocks

1. Download from [codeblocks.org](http://www.codeblocks.org/)
2. Install with bundled MinGW
3. Create new project
4. Add `.c` files
5. Build → Compile & Run

### Dev-C++

1. Download from [bloodshed.net](https://www.bloodshed.net/devcpp.html)
2. Install
3. Open project or create new
4. Add files
5. Execute → Compile & Run

---

## 🐛 Troubleshooting

### "gcc: command not found"

**Solution:** GCC is not installed or not in PATH

```bash
# Check if installed
which gcc

# If not found, install it:
# Ubuntu: sudo apt-get install gcc
# macOS: brew install gcc
# Windows: Install MinGW or MSVC
```

### "Permission denied" (Linux/Mac)

**Solution:** Executable permissions missing

```bash
chmod +x program_name
./program_name
```

### Compilation errors with special characters

**Solution:** Check file encoding (should be UTF-8)

```bash
# Linux/Mac
file -i program.c

# Convert if needed
iconv -f CP1252 -t UTF-8 program.c -o program_fixed.c
```

### "Undefined reference to" error

**Solution:** Function not defined or file not compiled

```bash
# Check if all .c files are included
gcc -Wall -Wextra -o output *.c

# Or explicitly list all files
gcc -Wall -Wextra -o output file1.c file2.c file3.c
```

---

## 📝 Common Compiler Flags

| Flag | Purpose |
|------|---------|
| `-Wall` | Show all warnings |
| `-Wextra` | Show extra warnings |
| `-g` | Include debugging symbols |
| `-O2` | Optimize for speed |
| `-o name` | Specify output filename |
| `-std=c99` | Use C99 standard |
| `-std=c11` | Use C11 standard |
| `-pedantic` | Strict ANSI compliance |

---

## 🚀 Running Projects

### Interactive Mode

Most projects are interactive. Just run and follow on-screen prompts:

```bash
./program_name
```

### Batch Testing (Example)

Create a test script:

```bash
#!/bin/bash
cd bank-management-system
gcc -Wall -Wextra -o bank_system bank_management.c
echo "Bank System compiled successfully"

cd ../basic-calculator
gcc -Wall -Wextra -o calculator calculator.c
echo "Calculator compiled successfully"

echo "All projects compiled!"
```

---

## 💾 Using Git with C Projects

### Clone Repository

```bash
git clone https://github.com/iampriyanshuraj01-beep/C-PROJECTS.git
cd C-PROJECTS
```

### Create Local Branch for Development

```bash
git checkout -b feature/my-changes
# Make changes
git add .
git commit -m "Add: My changes"
git push origin feature/my-changes
```

### Create Pull Request

1. Go to GitHub repository
2. Click "Compare & pull request"
3. Add description
4. Submit PR

---

## 🔗 Useful Resources

- **GCC Documentation:** https://gcc.gnu.org/onlinedocs/
- **C Programming:** https://www.learn-c.org/
- **C Standards:** https://en.cppreference.com/w/c
- **Git Guide:** https://git-scm.com/book/

---

## ❓ FAQ

**Q: Which C standard should I use?**  
A: C11 is recommended. Use `-std=c11` flag.

**Q: Can I compile all projects at once?**  
A: Yes, use a shell script or makefile for batch compilation.

**Q: How do I debug my code?**  
A: Use `gcc -g` to include debugging symbols, then use GDB.

**Q: What's the difference between `.c` and `.h` files?**  
A: `.c` files contain implementation, `.h` files contain declarations.

---

## 🤝 Need Help?

- Check [README.md](README.md)
- Open an [issue](https://github.com/iampriyanshuraj01-beep/C-PROJECTS/issues)
- See [CONTRIBUTING.md](CONTRIBUTING.md)

---

<div align="center">

**Happy Coding! 🎉**

</div>
