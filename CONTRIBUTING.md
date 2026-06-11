# CONTRIBUTING Guide

Thank you for your interest in contributing to the C-PROJECTS repository! 

## How to Contribute

### 1. **Reporting Issues**
- Found a bug? Create an issue with details
- Include error messages and steps to reproduce
- Specify your compiler and OS

### 2. **Suggesting Improvements**
- Have an idea? Open an issue to discuss
- Suggest new projects or enhancements
- Propose better algorithms or implementations

### 3. **Submitting Code Changes**

**Step 1: Fork the Repository**
```bash
git clone https://github.com/YOUR-USERNAME/C-PROJECTS.git
cd C-PROJECTS
```

**Step 2: Create a New Branch**
```bash
git checkout -b feature/your-feature-name
```

**Step 3: Make Your Changes**
- Write clean, readable code
- Add comments explaining logic
- Follow the existing code style

**Step 4: Test Your Code**
```bash
gcc -Wall -Wextra -o test your_file.c
./test
```

**Step 5: Commit & Push**
```bash
git add .
git commit -m "Add: Brief description of changes"
git push origin feature/your-feature-name
```

**Step 6: Open a Pull Request**
- Describe your changes in detail
- Reference any related issues

## Code Guidelines

### Style
- Use meaningful variable names
- Add comments for complex logic
- Follow K&R or ANSI C style
- Keep lines under 80 characters when possible

### Structure
```c
#include <stdio.h>      // Standard includes
#include <stdlib.h>

// Function declarations
void display_menu(void);
int get_choice(void);

// Main function
int main(void) {
    // Implementation
    return 0;
}

// Function implementations
void display_menu(void) {
    // Implementation
}
```

### Best Practices
- Use `const` for constants
- Validate all inputs
- Handle edge cases
- Add error checking
- Use meaningful variable names

## Types of Contributions

### 🐛 Bug Fixes
- Fix compilation errors
- Correct logic errors
- Improve error handling

### ✨ New Features
- Add new projects
- Enhance existing projects
- Improve user experience

### 📚 Documentation
- Improve README
- Add code comments
- Create tutorials

### 🧪 Testing
- Add test cases
- Verify edge cases
- Report issues

## Pull Request Checklist

- [ ] Code compiles without warnings
- [ ] All edge cases handled
- [ ] Comments added where necessary
- [ ] README updated if needed
- [ ] No merge conflicts
- [ ] Descriptive commit messages

## Questions?

Feel free to:
- Open an issue for discussion
- Email: iampriyanshuraj01@gmail.com
- Comment on existing issues/PRs

---

**Thank you for contributing! 🙌**
