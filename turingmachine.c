//equal number of a is followed by equal number of b :(a^nb^n)
#include <stdio.h>
#include <string.h>

#define MAX_TAPE 100

// Function to check if the input string belongs to the language 0^n1^n
int isValidLanguage(char tape[]) {
    char tapeCopy[MAX_TAPE];
    int head = 0;
    int i;

    // Copy the input tape for processing
    strcpy(tapeCopy, tape);

    // Loop until no more changes are possible
    while (1) {
        int foundZero = 0, foundOne = 0;
        
        // Scan for the first unmarked 0
        for (i = 0; tapeCopy[i] != '\0'; i++) {
            if (tapeCopy[i] == '0') {
                tapeCopy[i] = 'X'; // Mark the 0
                foundZero = 1;
                head = i + 1;
                break;
            }
        }
        
        if (!foundZero) break; // No more 0s to process

        // Move right to find the first unmarked 1
        for (i = head; tapeCopy[i] != '\0'; i++) {
            if (tapeCopy[i] == '1') {
                tapeCopy[i] = 'Y'; // Mark the 1
                foundOne = 1;
                head = i + 1;
                break;
            }
        }

        if (!foundOne) {
            return 0; // No matching 1 found
        }
    }

    // Check if all symbols are marked
    for (i = 0; tapeCopy[i] != '\0'; i++) {
        if (tapeCopy[i] != 'X' && tapeCopy[i] != 'Y') {
            return 0; // There are unmatched symbols
        }
    }

    return 1; // All 0s and 1s are properly matched
}

int main() {
    char tape[MAX_TAPE];

    printf("Enter the input string (0s and 1s only): ");
    scanf("%s", tape);

    if (isValidLanguage(tape)) {
        printf("The input string belongs to the language 0^n1^n.\n");
    } else {
        printf("The input string does not belong to the language 0^n1^n.\n");
    }

    printf("By Saroj Dhakal [79010253]");

    return 0;
    
}

