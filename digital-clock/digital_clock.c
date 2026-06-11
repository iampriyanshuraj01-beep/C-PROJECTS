#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(x) Sleep((x) * 1000)
    #define CLEAR() system("cls")
#else
    #define SLEEP(x) sleep(x)
    #define CLEAR() system("clear")
#endif

// Time zone structure
typedef struct {
    char name[30];
    char code[10];
    double offset;  // Hours from UTC (can be fractional for IST, etc.)
} TimeZone;

// Global variables
TimeZone timezones[] = {
    {"UTC/GMT (London)", "UTC", 0},
    {"EST (New York)", "EST", -5},
    {"CST (Chicago)", "CST", -6},
    {"MST (Denver)", "MST", -7},
    {"PST (Los Angeles)", "PST", -8},
    {"CET (Paris)", "CET", 1},
    {"IST (India)", "IST", 5.5},
    {"JST (Tokyo)", "JST", 9},
    {"AEST (Sydney)", "AEST", 10},
    {"NZDT (New Zealand)", "NZDT", 13}
};

int num_timezones = 10;
int use_12_hour = 0;  // 0 = 24-hour, 1 = 12-hour

// Function prototypes
void display_menu(void);
void display_all_timezones(void);
void display_selected_timezones(void);
void toggle_format(void);
void clear_screen(void);
void get_time_for_timezone(time_t utc_time, double offset, int *hour, int *min, int *sec);
void format_time_string(char *buffer, int hour, int min, int sec, int is_12_hour);
void display_current_time_continuous(int *selected_zones);
void display_timezone_list(void);

// Main function
int main(void) {
    int choice;
    int selected_zones[10];
    
    // Initialize all zones as selected
    for (int i = 0; i < num_timezones; i++) {
        selected_zones[i] = 1;
    }
    
    while (1) {
        clear_screen();
        display_menu();
        
        printf("\nEnter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Press Enter to continue...\n");
            while (getchar() != '\n');
            getchar();
            continue;
        }
        while (getchar() != '\n');  // Clear input buffer
        
        switch (choice) {
            case 1:
                // Display all time zones
                for (int i = 0; i < num_timezones; i++) {
                    selected_zones[i] = 1;
                }
                display_current_time_continuous(selected_zones);
                break;
            
            case 2:
                // Select specific time zones
                display_timezone_list();
                printf("\nEnter timezone numbers to select (e.g., 1 2 3 0 to exit): \n");
                
                for (int i = 0; i < num_timezones; i++) {
                    selected_zones[i] = 0;
                }
                
                int tz_choice;
                while (scanf("%d", &tz_choice) == 1 && tz_choice != 0) {
                    if (tz_choice > 0 && tz_choice <= num_timezones) {
                        selected_zones[tz_choice - 1] = 1;
                    }
                }
                while (getchar() != '\n');
                
                display_current_time_continuous(selected_zones);
                break;
            
            case 3:
                // Toggle format
                toggle_format();
                break;
            
            case 4:
                // Exit
                printf("Thank you for using Digital Clock! Goodbye! ⏰\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
                sleep(2);
        }
    }
    
    return 0;
}

// Display main menu
void display_menu(void) {
    printf("╔════════════════════════════════════════╗\n");
    printf("║      ⏰ DIGITAL CLOCK - TIME ZONES ⏰  ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("1. View All Time Zones\n");
    printf("2. Select Specific Time Zones\n");
    printf("3. Toggle Time Format (Current: %s)\n", use_12_hour ? "12-Hour" : "24-Hour");
    printf("4. Exit\n");
}

// Display timezone list for selection
void display_timezone_list(void) {
    clear_screen();
    printf("╔════════════════════════════════════════╗\n");
    printf("║        SELECT TIME ZONES               ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    for (int i = 0; i < num_timezones; i++) {
        printf("%2d. %s (UTC%+.1f)\n", i + 1, timezones[i].name, timezones[i].offset);
    }
    printf("\n 0. Done\n");
}

// Get time for specific timezone
void get_time_for_timezone(time_t utc_time, double offset, int *hour, int *min, int *sec) {
    // Convert UTC time to timezone
    time_t zone_time = utc_time + (time_t)(offset * 3600);
    
    struct tm *tm_info = gmtime(&zone_time);
    
    *hour = tm_info->tm_hour;
    *min = tm_info->tm_min;
    *sec = tm_info->tm_sec;
}

// Format time string based on 12/24 hour format
void format_time_string(char *buffer, int hour, int min, int sec, int is_12_hour) {
    if (is_12_hour) {
        const char *ampm = (hour >= 12) ? "PM" : "AM";
        if (hour > 12) {
            hour -= 12;
        } else if (hour == 0) {
            hour = 12;
        }
        sprintf(buffer, "%02d:%02d:%02d %s", hour, min, sec, ampm);
    } else {
        sprintf(buffer, "%02d:%02d:%02d", hour, min, sec);
    }
}

// Display current time continuously for selected zones
void display_current_time_continuous(int *selected_zones) {
    while (1) {
        clear_screen();
        
        printf("╔════════════════════════════════════════╗\n");
        printf("║     ⏰ DIGITAL CLOCK - TIME ZONES ⏰   ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        printf("Format: %s | Press Ctrl+C to return to menu\n\n", 
               use_12_hour ? "12-Hour" : "24-Hour");
        
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);
        
        // Display date
        printf("📅 Date: ");
        printf("%02d-%02d-%04d (", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        
        const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        printf("%s)\n\n", days[local_time->tm_wday]);
        
        // Display selected timezones
        printf("🌍 WORLD TIMES:\n");
        printf("═══════════════════════════════════════\n");
        
        int count = 0;
        for (int i = 0; i < num_timezones; i++) {
            if (selected_zones[i]) {
                int hour, min, sec;
                get_time_for_timezone(now, timezones[i].offset, &hour, &min, &sec);
                
                char time_str[20];
                format_time_string(time_str, hour, min, sec, use_12_hour);
                
                // Emoji for different regions
                const char *emoji = "🌍";
                if (i == 0) emoji = "🌍";  // UTC
                else if (i == 1 || i == 2 || i == 3 || i == 4) emoji = "🌎";  // Americas
                else if (i >= 5) emoji = "🌏";  // Asia/Pacific
                
                printf("%s %-25s : %s\n", emoji, timezones[i].name, time_str);
                count++;
            }
        }
        
        if (count == 0) {
            printf("No time zones selected.\n");
        }
        
        printf("═══════════════════════════════════════\n");
        
        SLEEP(1);  // Update every second
    }
}

// Toggle between 12 and 24 hour format
void toggle_format(void) {
    use_12_hour = !use_12_hour;
    
    clear_screen();
    printf("╔════════════════════════════════════════╗\n");
    printf("║        FORMAT TOGGLED                  ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("New format: %s\n", use_12_hour ? "12-Hour (with AM/PM)" : "24-Hour");
    printf("\nPress Enter to return to menu...\n");
    getchar();
}

// Clear screen function
void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
