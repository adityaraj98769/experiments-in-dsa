#include <stdio.h>

#define MAX_SIZE 100 // Maximum number of elements the array can hold

// Function prototypes
void insertItem(int arr[], int *size, int item, int pos);
void deleteItem(int arr[], int *size, int pos);
void displayItems(int arr[], int size);
void clearBuffer(); // Function to clear the input buffer

int main() {
    int arr[MAX_SIZE]; // Array to store items
    int size = 0; // Current number of items in the array
    int choice, item, pos;

    // Input initial array elements
    printf("Enter the number of elements you want to add to the array (max %d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_SIZE) {
        clearBuffer();
        printf("Invalid input. Please enter a valid number between 0 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Input array elements
    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            clearBuffer();
            printf("Invalid input. Please enter integer values.\n");
            return 1;
        }
    }

    // Main menu loop
    while (1) {
        // Display the menu
        printf("\n==============================\n");
        printf("       Menu Driven Program     \n");
        printf("==============================\n");
        printf("1. Insert an item\n");
        printf("2. Delete an item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        
        // Check for valid input
        if (scanf("%d", &choice) != 1) {
            clearBuffer(); // Clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                // Insert an item
                printf("Enter the item to insert: ");
                if (scanf("%d", &item) != 1) {
                    clearBuffer();
                    printf("Invalid input. Please enter a number.\n");
                    continue;
                }
                printf("Enter the position to insert the item (0 to %d): ", size);
                if (scanf("%d", &pos) != 1) {
                    clearBuffer();
                    printf("Invalid input. Please enter a number.\n");
                    continue;
                }
                if (pos < 0 || pos > size) {
                    printf("Invalid position! It must be between 0 and %d.\n", size);
                } else if (size >= MAX_SIZE) {
                    printf("Array is full. Cannot insert more items.\n");
                } else {
                    insertItem(arr, &size, item, pos);
                    printf("Item %d inserted successfully at position %d.\n", item, pos);
                }
                break;

            case 2:
                // Delete an item
                printf("Enter the position to delete the item (0 to %d): ", size - 1);
                if (scanf("%d", &pos) != 1) {
                    clearBuffer();
                    printf("Invalid input. Please enter a number.\n");
                    continue;
                }
                if (pos < 0 || pos >= size) {
                    printf("Invalid position! It must be between 0 and %d.\n", size - 1);
                } else {
                    deleteItem(arr, &size, pos);
                    printf("Item at position %d deleted successfully.\n", pos);
                }
                break;

            case 3:
                // Display items
                if (size == 0) {
                    printf("The array is empty.\n");
                } else {
                    printf("Current items in the array are: ");
                    displayItems(arr, size);
                }
                break;

            case 4:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

// Function to insert an item at a specific position
void insertItem(int arr[], int *size, int item, int pos) {
    // Shift items to the right to make space for the new item
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = item; // Insert the new item
    (*size)++; // Increment the size
}

// Function to delete an item at a specific position
void deleteItem(int arr[], int *size, int pos) {
    // Shift items to the left to fill the gap left by the deleted item
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrement the size
}

// Function to display all items in the array
void displayItems(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Read and discard characters until newline or EOF
}
