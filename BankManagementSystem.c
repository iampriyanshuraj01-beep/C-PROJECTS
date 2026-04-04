#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    FILE *fp = fopen("bank.dat", "ab");
    struct account a;

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void displayAccount() {
    FILE *fp = fopen("bank.dat", "rb");
    struct account a;
    int acc, found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == acc) {
            printf("\nAccount No: %d", a.accNo);
            printf("\nName: %s", a.name);
            printf("\nBalance: %.2f\n", a.balance);
            found = 1;
        }
    }

    if(!found)
        printf("Account not found!\n");

    fclose(fp);
}

void deposit() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amt);

            a.balance += amt;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);

            printf("Amount Deposited!\n");
            break;
        }
    }

    fclose(fp);
}

void withdraw() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);

            if(a.balance >= amt) {
                a.balance -= amt;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("Amount Withdrawn!\n");
            } else {
                printf("Insufficient Balance!\n");
            }
            break;
        }
    }

    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n===== BANK MENU =====\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: displayAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}