#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(x) Sleep((x) * 1000)
    #define CLEAR() system("cls")
#else
    #define SLEEP(x) sleep(x)
    #define CLEAR() system("clear")
#endif

// Timer structure
typedef struct {
    int hours;
    int minutes;
    int seconds;
    int is_running;
    int is_alarm_set;
} Timer;

Timer timer = {0, 0, 0, 0, 0};

// Function prototypes
void display_timer_menu(void);
void start_timer(void);
void start_stopwatch(void);
void set_alarm(void);
void timer_countdown(void);
void stopwatch_count(void);
void clear_screen(void);
void alarm_sound(void);

// Main function
int main(void) {
    int choice;
    
    while (1) {
        clear_screen();
        display_timer_menu();
        
        printf("\nEnter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Press Enter to continue...\n");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                start_timer();
                break;
            case 2:
                start_stopwatch();
                break;
            case 3:
                set_alarm();
                break;
            case 4:
                printf("Thank you for using Utilities! Goodbye! 🎉\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                sleep(2);
        }
    }
    
    return 0;
}

// Display main menu
void display_timer_menu(void) {
    printf("╔════════════════════════════════════════╗\n");
    printf("║       ⏱️  TIME UTILITIES TOOLKIT ⏱️    ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("1. ⏱️  Timer (Countdown)\n");
    printf("2. ⏲️  Stopwatch (Count Up)\n");
    printf("3. 🔔 Alarm Clock\n");
    printf("4. 🚪 Exit\n");
}

// Start countdown timer
void start_timer(void) {
    int hours, minutes, seconds;
    
    clear_screen();
    printf("╔════════════════════════════════════════╗\n");
    printf("║         ⏱️  COUNTDOWN TIMER ⏱️         ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("Enter hours (0-23): ");
    scanf("%d", &hours);
    printf("Enter minutes (0-59): ");
    scanf("%d", &minutes);
    printf("Enter seconds (0-59): ");
    scanf("%d", &seconds);
    while (getchar() != '\n');
    
    if (hours < 0 || minutes < 0 || seconds < 0 || 
        hours > 23 || minutes > 59 || seconds > 59) {
        printf("Invalid time input!\n");
        sleep(2);
        return;
    }
    
    timer.hours = hours;
    timer.minutes = minutes;
    timer.seconds = seconds;
    timer.is_running = 1;
    
    timer_countdown();
}

// Countdown timer function
void timer_countdown(void) {
    while (timer.is_running && (timer.hours > 0 || timer.minutes > 0 || timer.seconds > 0)) {
        clear_screen();
        printf("╔════════════════════════════════════════╗\n");
        printf("║         ⏱️  COUNTDOWN TIMER ⏱️         ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        printf("Time Remaining: %02d:%02d:%02d\n\n", 
               timer.hours, timer.minutes, timer.seconds);
        printf("Press Ctrl+C to stop...\n");
        
        sleep(1);
        
        // Decrement time
        if (timer.seconds > 0) {
            timer.seconds--;
        } else if (timer.minutes > 0) {
            timer.minutes--;
            timer.seconds = 59;
        } else if (timer.hours > 0) {
            timer.hours--;
            timer.minutes = 59;
            timer.seconds = 59;
        }
    }
    
    // Timer finished
    if (timer.is_running) {
        clear_screen();
        printf("╔════════════════════════════════════════╗\n");
        printf("║       ⏱️  TIME'S UP! ⏱️                ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        alarm_sound();
        printf("\nPress Enter to return to menu...\n");
        getchar();
    }
    
    timer.is_running = 0;
}

// Start stopwatch
void start_stopwatch(void) {
    clear_screen();
    printf("╔════════════════════════════════════════╗\n");
    printf("║        ⏲️  STOPWATCH ⏲️                ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("Starting stopwatch...\nPress Ctrl+C to stop.\n\n");
    
    int hours = 0, minutes = 0, seconds = 0;
    int running = 1;
    
    while (running) {
        clear_screen();
        printf("╔════════════════════════════════════════╗\n");
        printf("║        ⏲️  STOPWATCH ⏲️                ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        printf("Elapsed Time: %02d:%02d:%02d\n\n", hours, minutes, seconds);
        printf("Press Ctrl+C to stop...\n");
        
        sleep(1);
        
        // Increment time
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

// Set and display alarm
void set_alarm(void) {
    int alarm_hours, alarm_minutes;
    
    clear_screen();
    printf("╔════════════════════════════════════════╗\n");
    printf("║        🔔 ALARM CLOCK 🔔              ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("Set alarm time:\n");
    printf("Enter hours (0-23): ");
    scanf("%d", &alarm_hours);
    printf("Enter minutes (0-59): ");
    scanf("%d", &alarm_minutes);
    while (getchar() != '\n');
    
    if (alarm_hours < 0 || alarm_minutes < 0 || 
        alarm_hours > 23 || alarm_minutes > 59) {
        printf("Invalid time input!\n");
        sleep(2);
        return;
    }
    
    printf("\nAlarm set for %02d:%02d\n", alarm_hours, alarm_minutes);
    printf("Waiting for alarm time... (Press Ctrl+C to cancel)\n\n");
    
    int alarm_triggered = 0;
    
    while (!alarm_triggered) {
        time_t now = time(NULL);
        struct tm *timeinfo = localtime(&now);
        
        clear_screen();
        printf("╔════════════════════════════════════════╗\n");
        printf("║        🔔 ALARM CLOCK 🔔              ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        printf("Alarm set for: %02d:%02d\n", alarm_hours, alarm_minutes);
        printf("Current time: %02d:%02d:%02d\n\n", 
               timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        printf("Waiting for alarm time...\n");
        
        if (timeinfo->tm_hour == alarm_hours && timeinfo->tm_min == alarm_minutes) {
            alarm_triggered = 1;
            clear_screen();
            printf("╔════════════════════════════════════════╗\n");
            printf("║       🔔 ALARM! ALARM! ALARM! 🔔       ║\n");
            printf("╚════════════════════════════════════════╝\n\n");
            alarm_sound();
            printf("\nPress Enter to dismiss alarm...\n");
            getchar();
            break;
        }
        
        sleep(1);
    }
}

// Alarm sound (visual and audible)
void alarm_sound(void) {
    for (int i = 0; i < 5; i++) {
        printf("🔔 RING! RING! RING! 🔔\n");
        fflush(stdout);
        sleep(1);
    }
}

// Clear screen function
void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
