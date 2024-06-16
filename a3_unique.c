/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* reads a series of numbers  */
    /* between 0 and 200 inclusive, */
    /* displaing distinct numbers. */
/*************************************/

#include <stdio.h>

int main() {
    // Declaring variables for use in future operations
    // First array is to keep track of the presence of numbers
    // While the second array is to keep track of the unique of numbers
    int numbers[201] = {0};
    int unique_numbers[100]; 
    int use_n, num;
    int unique_count = 0;
    char ch;

    while (1) {
        // Prompt the user to enter the number of integers
        printf("Enter the number of input integers (0 to stop): ");

        // Checking if the user's input is valid
        if (scanf("%d", &use_n) != 1 || use_n < 0) {
            printf("Invalid number\n");
            // Clearing the input buffer
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        // Stopping the function if the input is 0
        if (use_n == 0) {
            break;
        }
        
        // Prompt for user to input the numbers
        printf("Enter numbers (0 – 200):\n");

        // Reset the arrays for each new session
        for (int i = 0; i < 201; i++) {
            numbers[i] = 0;
        }
        unique_count = 0;

        int num_read = 0;

        // A while loop for inserting the numbers
        while (num_read < use_n) {
            // Handling and clearing invalid input
            if (scanf("%d", &num) != 1) {
                printf("Invalid input detected and ignored.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);  // Clear input buffer
                continue;
            }

            // Checking whether the number falls within the range
            if (num < 0 || num > 200) {
                printf("%d: invalid and ignored\n", num);
                continue;
            }

            // Mark the number as read (only the first time it's encountered)
            if (numbers[num] == 0) {
                numbers[num] = 1;
                unique_numbers[unique_count++] = num;
            }
            
            num_read++;
        }

        // Clearing the remaining input buffer
        while ((ch = getchar()) != '\n' && ch != EOF);

        // Printing unique numbers
        printf("Unique numbers: ");
        for (int i = 0; i < unique_count; i++) {
            printf("%d", unique_numbers[i]);
            if (i < unique_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}
