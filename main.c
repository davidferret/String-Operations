#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXCHAR 100

void capString(char str[]);
void revString(char str[]);
int isPalindrome(char str[]);

int main(void) {
    char sentence[MAXCHAR], cmd[10];

    do {
        printf("Enter 'rev', 'cap', 'len', or 'pal' followed by a sentence (or 'exit program' to quit): ");
        scanf("%s", cmd);
        getchar(); // Consume newline character
        fgets(sentence, MAXCHAR, stdin);
        sentence[strcspn(sentence, "\n")] = 0; // Remove newline character

        if (strcmp(cmd, "cap") == 0) {
            capString(sentence);
            printf("Capitalized string: %s\n", sentence);
        } else if (strcmp(cmd, "rev") == 0) {
            revString(sentence);
            printf("Reversed string: %s\n", sentence);
        } else if (strcmp(cmd, "len") == 0) {
            printf("Length of string: %lu\n", strlen(sentence));
        } else if (strcmp(cmd, "pal") == 0) {
            if (isPalindrome(sentence)) {
                printf("The sentence is a palindrome.\n");
            } else {
                printf("The sentence is NOT a palindrome.\n");
            }
        } else if (strcmp(cmd, "exit") == 0 && strcmp(sentence, "program") == 0) {
            break;
        } else {
            printf("Invalid command. Use 'cap' to capitalize, 'rev' to reverse, 'len' to get length, or 'pal' to check palindrome.\n");
        }
    } while (1);
    
    printf("Have a nice day!\n");
    return 0;
}

void capString(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

void revString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}
