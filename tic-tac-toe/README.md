# ❌⭕ Tic Tac Toe Game

## 📖 Overview

A fun and interactive 2-player console-based Tic Tac Toe game implemented in C. This project demonstrates game logic, state management, and user interaction in a command-line environment.

## ✨ Features

- ✅ **2-Player Gameplay** - Play against another human
- ✅ **Win Detection** - Automatically detects winning combinations
- ✅ **Draw Detection** - Identifies when the board is full
- ✅ **Turn-Based System** - Alternates between players
- ✅ **Board Display** - Clear, formatted game board
- ✅ **Input Validation** - Prevents invalid moves
- ✅ **Move History** - Track all moves made
- ✅ **Replay Option** - Play multiple games

## 🛠️ Technologies & Concepts

**Language:** C (C99/C11)  
**Compiler:** GCC

**Concepts Used:**
- 2D Arrays (3×3 board)
- Conditional statements
- Loops (for, while)
- Functions and modularity
- Game logic and algorithms
- Input validation

## 📋 Project Structure

```
tic-tac-toe/
├── tic_tac_toe.c   # Main program
├── README.md       # This file
└── Makefile        # Build configuration (optional)
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler installed
- Terminal/Command Prompt
- Text editor (VS Code, Sublime Text, etc.)

### Compilation

**Option 1: Basic Compilation**
```bash
gcc -o tictactoe tic_tac_toe.c
```

**Option 2: With Warnings**
```bash
gcc -Wall -Wextra -o tictactoe tic_tac_toe.c
```

### Running the Program

```bash
# Linux/Mac
./tictactoe

# Windows
tictactoe.exe
```

## 📖 How to Play

1. **Start the game** - Board is displayed (numbered 1-9)
2. **Player X goes first** - Enter position (1-9)
3. **Player O goes next** - Enter position (1-9)
4. **Continue playing** - Alternate turns
5. **Win or Draw** - Game ends when someone wins or board fills up
6. **Play again?** - Choose to play another game or exit

### Board Positions
```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

## 💡 Example Gameplay

```
========== TIC TAC TOE GAME ==========

     |     |    
-----------
     |     |    
-----------
     |     |    

Player X's turn. Enter position (1-9): 5

     |     |    
-----------
     |  X  |    
-----------
     |     |    

Player O's turn. Enter position (1-9): 1

  O  |     |    
-----------
     |  X  |    
-----------
     |     |    

... (game continues) ...

  O  |  X  |    
-----------
  O  |  X  |    
-----------
     |  X  | X

Player X wins!

Play again? (1=Yes, 0=No): 0
```

## 📊 Code Structure

```c
// Game variables
char board[3][3];
char current_player;

// Game functions
void initialize_board(void);
void display_board(void);
int is_valid_move(int position);
int make_move(int position);
int check_winner(void);
int is_board_full(void);
void play_game(void);
void play_again(void);
```

## 🎓 Learning Outcomes

By studying this project, you'll learn:

- ✅ How to implement game logic
- ✅ 2D array manipulation
- ✅ State management
- ✅ Conditional logic for game rules
- ✅ Input validation
- ✅ Game loop design
- ✅ Win/draw conditions
- ✅ User interaction

## 🔍 Key Concepts Explained

### Board Representation
```c
char board[3][3];  // 3x3 board
// ' ' = empty, 'X' = player X, 'O' = player O
```

### Move Validation
```c
if (position < 1 || position > 9) {
    return 0;  // Invalid position
}
int row = (position - 1) / 3;
int col = (position - 1) % 3;
if (board[row][col] != ' ') {
    return 0;  // Position already taken
}
```

### Win Detection
```c
// Check rows
for (i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        return 1;
}
// Check columns
for (j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
        return 1;
}
// Check diagonals
if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return 1;
```

## 💡 Code Examples

### Displaying the Board
```c
void display_board(void) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("  %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}
```

### Making a Move
```c
int make_move(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (board[row][col] != ' ') {
        printf("Position already taken!\n");
        return 0;
    }
    
    board[row][col] = current_player;
    return 1;
}
```

### Checking for Winner
```c
int check_winner(void) {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] 
            && board[i][0] != ' ') {
            return 1;
        }
    }
    return 0;
}
```

## 🎮 Winning Combinations

There are 8 possible winning combinations:

**Rows:**
- Row 1: Positions 1, 2, 3
- Row 2: Positions 4, 5, 6
- Row 3: Positions 7, 8, 9

**Columns:**
- Column 1: Positions 1, 4, 7
- Column 2: Positions 2, 5, 8
- Column 3: Positions 3, 6, 9

**Diagonals:**
- Top-left to bottom-right: Positions 1, 5, 9
- Top-right to bottom-left: Positions 3, 5, 7

## 🐛 Debugging Tips

1. **Print the board** - Use display_board() to check state
2. **Test winning conditions** - Manually verify win detection
3. **Check input validation** - Try invalid positions (0, 10, taken positions)
4. **Trace move positions** - Verify row/col calculations

## 📈 Possible Enhancements

- [ ] Implement AI opponent
- [ ] Add difficulty levels (Easy, Medium, Hard)
- [ ] Add score tracking (wins/losses)
- [ ] Implement minimax algorithm for unbeatable AI
- [ ] Add color support to board
- [ ] Save game state to file
- [ ] Create GUI version
- [ ] Add move history replay

## ⚠️ Current Limitations

- Only 2-player local multiplayer
- No AI opponent
- No move history/undo
- No difficulty levels
- Console-only interface

## 📝 Game Statistics

| Aspect | Value |
|--------|-------|
| Board Size | 3×3 |
| Total Positions | 9 |
| Maximum Moves | 9 |
| Winning Combinations | 8 |
| Possible Game Outcomes | 3 (X wins, O wins, Draw) |

## 🤝 Contributing

Found an issue or have an improvement? See [CONTRIBUTING.md](../CONTRIBUTING.md) for guidelines.

## 📄 License

This project is licensed under the MIT License. See [LICENSE](../LICENSE) for details.

## 🔗 Related Projects

- [Basic Calculator](../basic-calculator/) - Simple arithmetic
- [Bank Management System](../bank-management-system/) - File I/O
- [Matrix Operations](../matrix-operations/) - Array operations

## ❓ FAQ

**Q: Can I play against the computer?**  
A: Not in the current version. Check "Possible Enhancements" for AI implementation.

**Q: What happens if I enter an invalid position?**  
A: The program will reject it and ask for a valid position (1-9).

**Q: Can I undo a move?**  
A: Not in the current version. You must play another game.

**Q: Who moves first?**  
A: Player X always moves first.

## 📞 Support

**Questions or issues?**
- Check the [main README](../README.md)
- Open an issue on GitHub
- Email: iampriyanshuraj01@gmail.com

---

<div align="center">

**Have Fun Playing! ❌⭕**

Made with ❤️ by [Priyanshu Raj](https://github.com/iampriyanshuraj01-beep)

</div>
