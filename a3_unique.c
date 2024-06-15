#include <stdio.h>


int main() {
    int numbers[100];
    int count = 0;
    int n, num;
    char ch;

    while (1) {
        // Prompt the user to enter the number of integers
        printf("Enter the number of input integers (0 to stop): ");
        int user_input = scanf("%d", &n);

        // Checking if the iput is valid
        if (user_input != 1 || n < 0) {
            printf("Invalid number \n");
            int user_char = (ch = getchar());
            while (user_char != '\n' && ch != EOF);
            continue;
        }

        // Stopping the function if the input is 0
        if (n == 0) {
            break;
        }
        
        // Prompt for user to input the numbers
        printf("Enter numbers (0 – 200): ");

        // Reset variables for each input session
        count = 0;
        int num_read = 0;

        // A while loop for inserting the numbers
        while (num_read < n) {

            // Handling and clearing invalid iput
            int scanned = scanf("%d", &num);
            if (scanned != 1) {
                printf("Invalid input detected and ignored.\n");
                int user_char = (ch = getchar());
                while (user_char != '\n' && ch != EOF);
                continue;
            }

            // Checking whether the number falls withing the range
            if (num < 0 || num > 200) {
                printf("%d: invalid and ignored\n", num);
            }

            // Check if the number is unique
            else {
                int is_unique = 1;
                for (int i = 0; i < count; i++) {
                    if (numbers[i] == num) {
                        is_unique = 0;
                        break;
                    }
                }

                // Checking only if the number is added successfully
                if (is_unique) {
                    numbers[count++] = num;
                    num_read++;
                }
            }
        }

        // Print unique numbers
        printf("Unique numbers: ");
        for (int i = 0; i < count; i++) {
            printf("%d", numbers[i]);
            if (i < count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
