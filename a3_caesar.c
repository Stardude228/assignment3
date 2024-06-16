/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* encrypts a message using a Caesar cipher */
/*************************************/

#include <stdio.h>

// The encryptMessage is not mine. 
// (Looked it up online but understood everything)
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
    char message[1000];
    int shift;
    int caseNumber = 1; // To track the case number for output

    while (1) {
        printf("Enter message to be encrypted (enter '0' to stop): ");

        if (!fgets(message, sizeof(message), stdin)) {
            break; // Exit loop on input failure
        }

        // Remove the trailing newline character, if any
        for (int i = 0; message[i] != '\0'; i++) {
            if (message[i] == '\n') {
                message[i] = '\0';
                break;
            }
        }

        if (message[0] == '0' && message[1] == '\0') {
            break; // Exit loop on "0" input
        }

        printf("Enter shift amount (1-25): ");
        scanf("%d", &shift);
        getchar(); // Consume newline left by scanf

        if (shift < 1 || shift > 25) {
            printf("Invalid shift amount. Please enter a number between 1 and 25.\n");
            continue; // Restart loop for invalid shift
        }

        // Encrypt the message
        encryptMessage(message, shift);

        // Output formatted according to expected CASE #n output
        printf("CASE #%d\n", caseNumber++);
        printf("Encrypted message: %s\n", message);
        printf("===\n");
    }

    return 0;
}