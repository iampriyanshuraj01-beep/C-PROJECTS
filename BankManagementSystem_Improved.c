#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int accNo;
    char name[50];
    float balance;
};

// Helper function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to find account in file
int findAccountInFile(int accNo, struct account *a, FILE *fp) {
    rewind(fp);
    while(fread(a, sizeof(struct account), 1, fp)) {
        if(a->accNo == accNo) {
            return 1;  // Found
        }
    }
    return 0;  // Not found
}

// Create a new account with error handling and validation
int createAccount() {
    FILE *fp = fopen("bank.dat", "ab");
    
    // Error handling for file open
    if (fp == NULL) {
        printf("Error: Unable to open bank.dat file!\n");
        return 0;
    }
    
    struct account a;
    
    printf("\n--- CREATE ACCOUNT ---\n");
    
    printf("Enter Account Number: ");
    if (scanf("%d", &a.accNo) != 1) {
        printf("Invalid input! Account number must be a number.\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    // Validate account number
    if (a.accNo <= 0) {
        printf("Error: Account number must be positive!\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    // Check if account already exists
    if (findAccountInFile(a.accNo, &a, fp)) {
        printf("Error: Account number already exists!\n");
        fclose(fp);
        return 0;
    }
    
    clearInputBuffer();
    
    printf("Enter Name: ");
    if (fgets(a.name, sizeof(a.name), stdin) == NULL) {
        printf("Error reading name!\n");
        fclose(fp);
        return 0;
    }
    // Remove newline from fgets
    a.name[strcspn(a.name, "\n")] = '\0';
    
    printf("Enter Initial Balance: ");
    if (scanf("%f", &a.balance) != 1) {
        printf("Invalid input! Balance must be a number.\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    // Validate balance
    if (a.balance < 0) {
        printf("Error: Balance cannot be negative!\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    clearInputBuffer();
    
    if (fwrite(&a, sizeof(struct account), 1, fp) != 1) {
        printf("Error writing account to file!\n");
        fclose(fp);
        return 0;
    }
    
    fclose(fp);
    printf("Account Created Successfully!\n");
    return 1;
}

// Display account details with error handling
int displayAccount() {
    FILE *fp = fopen("bank.dat", "rb");
    
    if (fp == NULL) {
        printf("Error: No accounts found. Create an account first!\n");
        return 0;
    }
    
    struct account a;
    int acc;
    
    printf("\n--- DISPLAY ACCOUNT ---\n");
    printf("Enter Account Number: ");
    if (scanf("%d", &acc) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    clearInputBuffer();
    
    if (findAccountInFile(acc, &a, fp)) {
        printf("\n=== Account Details ===\n");
        printf("Account No: %d\n", a.accNo);
        printf("Name: %s\n", a.name);
        printf("Balance: Rs. %.2f\n", a.balance);
        fclose(fp);
        return 1;
    } else {
        printf("Error: Account not found!\n");
        fclose(fp);
        return 0;
    }
}

// Deposit amount with validation
int deposit() {
    FILE *fp = fopen("bank.dat", "rb+");
    
    if (fp == NULL) {
        printf("Error: No accounts found. Create an account first!\n");
        return 0;
    }
    
    struct account a;
    int acc;
    float amt;
    int found = 0;
    
    printf("\n--- DEPOSIT AMOUNT ---\n");
    printf("Enter Account Number: ");
    if (scanf("%d", &acc) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    clearInputBuffer();
    
    while(fread(&a, sizeof(struct account), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount to deposit: ");
            if (scanf("%f", &amt) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                fclose(fp);
                return 0;
            }
            
            // Validate deposit amount
            if (amt <= 0) {
                printf("Error: Deposit amount must be positive!\n");
                clearInputBuffer();
                fclose(fp);
                return 0;
            }
            
            clearInputBuffer();
            
            a.balance += amt;
            
            fseek(fp, -(long)sizeof(struct account), SEEK_CUR);
            if (fwrite(&a, sizeof(struct account), 1, fp) != 1) {
                printf("Error updating account!\n");
                fclose(fp);
                return 0;
            }
            
            printf("Amount Deposited Successfully!\n");
            printf("New Balance: Rs. %.2f\n", a.balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Error: Account not found!\n");
    }
    
    fclose(fp);
    return found;
}

// Withdraw amount with validation
int withdraw() {
    FILE *fp = fopen("bank.dat", "rb+");
    
    if (fp == NULL) {
        printf("Error: No accounts found. Create an account first!\n");
        return 0;
    }
    
    struct account a;
    int acc;
    float amt;
    int found = 0;
    
    printf("\n--- WITHDRAW AMOUNT ---\n");
    printf("Enter Account Number: ");
    if (scanf("%d", &acc) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        fclose(fp);
        return 0;
    }
    
    clearInputBuffer();
    
    while(fread(&a, sizeof(struct account), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount to withdraw: ");
            if (scanf("%f", &amt) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                fclose(fp);
                return 0;
            }
            
            // Validate withdrawal amount
            if (amt <= 0) {
                printf("Error: Withdrawal amount must be positive!\n");
                clearInputBuffer();
                fclose(fp);
                return 0;
            }
            
            clearInputBuffer();
            
            if(a.balance >= amt) {
                a.balance -= amt;
                
                fseek(fp, -(long)sizeof(struct account), SEEK_CUR);
                if (fwrite(&a, sizeof(struct account), 1, fp) != 1) {
                    printf("Error updating account!\n");
                    fclose(fp);
                    return 0;
                }
                
                printf("Amount Withdrawn Successfully!\n");
                printf("New Balance: Rs. %.2f\n", a.balance);
            } else {
                printf("Error: Insufficient Balance!\n");
                printf("Current Balance: Rs. %.2f\n", a.balance);
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Error: Account not found!\n");
    }
    
    fclose(fp);
    return found;
}

// Display menu and handle user choice
void displayMenu() {
    printf("\n");
    printf("╔════════════════════════════╗\n");
    printf("║   BANK MANAGEMENT SYSTEM   ║\n");
    printf("╠════════════════════════════╣\n");
    printf("║ 1. Create Account          ║\n");
    printf("║ 2. Display Account         ║\n");
    printf("║ 3. Deposit                 ║\n");
    printf("║ 4. Withdraw                ║\n");
    printf("║ 5. Exit                    ║\n");
    printf("╚════════════════════════════╝\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    
    while(1) {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1-5.\n");
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("\nThank you for using Bank Management System!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }
    }
    
    return 0;
}
