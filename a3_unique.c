/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* reads a series of numbers  */
    /* between 0 and 200 inclusive, 
    /* displaing distinct numbers. */
/*************************************/

#include <stdio.h>
#define N 100

int main() {
    int numbers[N];
    int count = 0;
    int use_n, num;
    char ch;

    while (1) {
        // Prompt the user to enter the number of integers
        printf("Enter the number of input integers (0 to stop): ");
        int user_input = scanf("%d", &use_n);

        // Checking if the iput is valid
        if (user_input != 1 || use_n < 0) {
            printf("Invalid number \n");
            int user_char = (ch = getchar()); 
            while (user_char != '\n' && ch != EOF);
            continue;
        }

        // Stopping the function if the input is 0
        if (use_n == 0) {
            break;
        }
        
        // Prompt for user to input the numbers
        printf("Enter numbers (0 – 200): ");

        // Reset variables for each input session
        count = 0;
        int num_read = 0;

        // A while loop for inserting the numbers
        while (num_read < use_n) {

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
