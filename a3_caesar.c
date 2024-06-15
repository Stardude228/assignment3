#include <stdio.h>

// Function to encrypt a message using a Caesar cipher
// Not mine (Looked it up online but understood everything)
void encryptMessage(char *message, int shift) {
    
    // Declaring variables for iterations
    int i = 0;
    char ch;

    // A while loop that iterates through a message until it meets the null
    while (message[i] != '\0') {
        // Changing characters in a message
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
        }

        //Updating and incrementing message[i] with the encrypted character
        message[i] = ch;
        i++;
    }
}

int main() {
    //Declaring variables for future use
    char message[1000];
    int shift;

    // A while loop that ends when meets 0
    while (1) {
        printf("Enter message to be encrypted: ");
        
        // Reading the message from user input
        if (fgets(message, sizeof(message), stdin)) {
            // Removing the trailing newline character, if any
            int i = 0;
            while (message[i] != '\0') {
                if (message[i] == '\n') {
                    message[i] = '\0';
                    break;
                }
                i++;
            }
        }

        // Checking if user wants to stop
        if (message[0] == '0' && message[1] == '\0') {
            break;
        }

        printf("Enter shift amount (1-25, enter 0 to stop): ");
        scanf("%d", &shift);
        // Removing newline character left by scanf
        getchar();

        // Checking if user wants to stop
        if (shift == 0) {
            break;
        } else if (shift < 0 || shift > 25) {
            printf("Invalid shift amount. Please enter a number between 1 and 25.\n");
            continue;
        }

        // Encrypt the message
        encryptMessage(message, shift);

        // Output the encrypted message
        printf("Encrypted message: %s\n", message);
    }

    return 0;
}
