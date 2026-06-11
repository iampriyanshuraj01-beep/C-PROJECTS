# ⏱️ Time Utilities Toolkit (Timer, Stopwatch, Alarm)

## 📖 Overview

A comprehensive time utilities application featuring countdown timer, stopwatch, and alarm clock functionality. This project demonstrates advanced time handling, user interaction, and real-time applications in C.

## ✨ Features

- ✅ **Countdown Timer** - Set custom time and countdown
- ✅ **Stopwatch** - Count up from zero with unlimited time
- ✅ **Alarm Clock** - Set alarm for specific time
- ✅ **Real-Time Display** - Updates every second
- ✅ **Cross-Platform** - Works on Windows/Linux/macOS
- ✅ **User-Friendly Menu** - Easy navigation
- ✅ **Alarm Sound** - Visual notification when alarm triggers
- ✅ **Input Validation** - Prevents invalid time entries

## 🛠️ Technologies & Concepts

**Language:** C (C99/C11)  
**Compiler:** GCC

**Concepts Used:**
- Time library (time.h, sys/time.h)
- Real-time updates
- User input handling
- Structures for data management
- Platform-specific code (Windows vs Unix)
- Control flow and loops
- Signal handling

## 📋 Project Structure

```
time-utilities/
├── time_utilities.c    # Main program
├── README.md           # This file
└── Makefile            # Build configuration (optional)
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler installed
- Terminal/Command Prompt
- Text editor (VS Code, Sublime Text, etc.)

### Compilation

```bash
cd time-utilities
gcc -Wall -Wextra -o utilities time_utilities.c
./utilities
```

### Running the Program

```bash
# Linux/Mac
./utilities

# Windows
utilities.exe
```

## 📖 How to Use

1. **Start the program** - Main menu appears
2. **Select option:**
   - `1` - Countdown Timer
   - `2` - Stopwatch
   - `3` - Alarm Clock
   - `4` - Exit

3. **Follow prompts** - Enter time values
4. **Watch the countdown/count-up** - Real-time display updates every second
5. **Press Ctrl+C** - Return to menu anytime

## 💡 Example Usage

### Timer Example
```
╔════════════════════════════════════════╗
║         ⏱️  COUNTDOWN TIMER ⏱️         ║
╚════════════════════════════════════════╝

Enter hours (0-23): 0
Enter minutes (0-59): 5
Enter seconds (0-59): 30

Time Remaining: 00:05:30
Press Ctrl+C to stop...

(After 5 minutes 30 seconds)

╔════════════════════════════════════════╗
║       ⏱️  TIME'S UP! ⏱️                ║
╚════════════════════════════════════════╝

🔔 RING! RING! RING! 🔔
```

### Stopwatch Example
```
╔════════════════════════════════════════╗
║        ⏲️  STOPWATCH ⏲️                ║
╚════════════════════════════════════════╝

Elapsed Time: 00:00:05

Press Ctrl+C to stop...
```

### Alarm Example
```
╔════════════════════════════════════════╗
║        🔔 ALARM CLOCK 🔔              ║
╚════════════════════════════════════════╝

Set alarm time:
Enter hours (0-23): 14
Enter minutes (0-59): 30

Alarm set for 14:30
Waiting for alarm time...

Current time: 14:30:00

(Alarm triggers)
🔔 ALARM! ALARM! ALARM! 🔔
```

## 📊 Code Structure

```c
// Timer structure
typedef struct {
    int hours;
    int minutes;
    int seconds;
    int is_running;
    int is_alarm_set;
} Timer;

// Main functions
void start_timer(void);
void timer_countdown(void);
void start_stopwatch(void);
void set_alarm(void);
void alarm_sound(void);
void display_timer_menu(void);
void clear_screen(void);
```

## 🎓 Learning Outcomes

By studying this project, you'll learn:

- ✅ How to use time.h library functions
- ✅ Working with struct tm and time_t
- ✅ Real-time countdown and count-up logic
- ✅ Cross-platform compatibility
- ✅ User input validation
- ✅ Menu-driven application design
- ✅ Infinite loops with break conditions
- ✅ Time-based program flow

## 🔍 Key Concepts Explained

### Getting Current Time
```c
time_t now = time(NULL);
struct tm *timeinfo = localtime(&now);
printf("Current: %02d:%02d:%02d\n", 
       timeinfo->tm_hour, 
       timeinfo->tm_min, 
       timeinfo->tm_sec);
```

### Countdown Logic
```c
while (timer.is_running && (hours > 0 || minutes > 0 || seconds > 0)) {
    // Display current time
    printf("Time Remaining: %02d:%02d:%02d\n", hours, minutes, seconds);
    
    sleep(1);  // Wait 1 second
    
    // Decrement
    if (seconds > 0) {
        seconds--;
    } else if (minutes > 0) {
        minutes--;
        seconds = 59;
    } else if (hours > 0) {
        hours--;
        minutes = 59;
        seconds = 59;
    }
}
```

### Alarm Checking
```c
while (!alarm_triggered) {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    
    if (timeinfo->tm_hour == alarm_hours && 
        timeinfo->tm_min == alarm_minutes) {
        alarm_triggered = 1;
        alarm_sound();
    }
    
    sleep(1);
}
```

## 💡 Code Examples

### Timer Countdown
```c
void start_timer(void) {
    int hours, minutes, seconds;
    
    printf("Enter hours (0-23): ");
    scanf("%d", &hours);
    printf("Enter minutes (0-59): ");
    scanf("%d", &minutes);
    printf("Enter seconds (0-59): ");
    scanf("%d", &seconds);
    
    while (hours > 0 || minutes > 0 || seconds > 0) {
        clear_screen();
        printf("⏱️  Time: %02d:%02d:%02d\n", hours, minutes, seconds);
        
        sleep(1);
        
        if (seconds > 0) seconds--;
        else if (minutes > 0) {
            minutes--;
            seconds = 59;
        } else if (hours > 0) {
            hours--;
            minutes = 59;
            seconds = 59;
        }
    }
    printf("⏰ Time's up!\n");
}
```

### Stopwatch Count
```c
void start_stopwatch(void) {
    int hours = 0, minutes = 0, seconds = 0;
    int running = 1;
    
    while (running) {
        clear_screen();
        printf("⏲️  Elapsed: %02d:%02d:%02d\n", hours, minutes, seconds);
        
        sleep(1);
        
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }
    }
}
```

### Alarm Sound
```c
void alarm_sound(void) {
    for (int i = 0; i < 5; i++) {
        printf("🔔 RING! RING! RING! 🔔\n");
        fflush(stdout);
        sleep(1);
    }
}
```

## 📊 Time Limits

| Feature | Min | Max |
|---------|-----|-----|
| Timer Hours | 0 | 23 |
| Timer Minutes | 0 | 59 |
| Timer Seconds | 0 | 59 |
| Stopwatch | Unlimited | Unlimited |
| Alarm Hours | 0 | 23 |
| Alarm Minutes | 0 | 59 |

## 📈 Possible Enhancements

- [ ] Add multiple alarms
- [ ] Save timer presets
- [ ] Add lap function for stopwatch
- [ ] Implement timer notifications
- [ ] Add recurring alarms
- [ ] Create GUI interface
- [ ] Add sound file support
- [ ] Implement snooze feature

## ⚠️ Limitations

- Single timer/stopwatch/alarm at a time
- No persistent storage of settings
- No repeating alarms
- Visual-only alarm notification
- Fixed alarm time (no snooze)

## 🐛 Debugging Tips

1. **Check system time** - Ensure system clock is correct
2. **Verify input** - Use range validation (0-59, 0-23)
3. **Test boundaries** - Try 59:59 transitions
4. **Platform testing** - Test on different OS

## 🔧 Cross-Platform Code

```c
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(x) Sleep((x) * 1000)
    #define CLEAR() system("cls")
#else
    #include <unistd.h>
    #define SLEEP(x) sleep(x)
    #define CLEAR() system("clear")
#endif
```

## 🤝 Contributing

Found an issue or have an improvement? See [CONTRIBUTING.md](../CONTRIBUTING.md) for guidelines.

## 📄 License

This project is licensed under the MIT License. See [LICENSE](../LICENSE) for details.

## 🔗 Related Projects

- [Digital Clock](../digital-clock/) - Multi-timezone display
- [Basic Calculator](../basic-calculator/) - Time calculations
- [Bank Management](../bank-management-system/) - Transaction timing

## ❓ FAQ

**Q: Can I use multiple timers simultaneously?**  
A: Not in current version. Run multiple instances instead.

**Q: What happens if I set an alarm for past time?**  
A: It waits until next day for that time.

**Q: Can the alarm repeat daily?**  
A: Not in current version. See enhancements for recurring alarms.

**Q: How accurate is the timer?**  
A: Accurate to within ±1 second depending on system load.

## 📞 Support

**Questions or issues?**
- Check the [main README](../README.md)
- Open an issue on GitHub
- Email: iampriyanshuraj01@gmail.com

---

<div align="center">

**Time Management Matters! ⏱️**

Made with ❤️ by [Priyanshu Raj](https://github.com/iampriyanshuraj01-beep)

</div>
