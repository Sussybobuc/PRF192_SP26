#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for product information
struct Product {
    int product_id;
    char product_name[50];
    float price;
    int quantity;
};

// Function Prototypes
void writeProducts(const char *filename, int numProducts);
void appendProducts(const char *filename, int numProducts);
void readProducts(const char *filename);
void modifyProduct(const char *filename);
int isProductIDExists(const char *filename, int id);

int main() {
    const char *filename = "products.bin";
    int choice, numProducts;

    do {
        printf("\n-- Product Management System --\n");
        printf("1. Write Products\n");
        printf("2. Append Products\n");
        printf("3. Read Products\n");
        printf("4. Modify Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the number of products to write: ");
                if (scanf("%d", &numProducts) != 1 || numProducts <= 0) {
                    printf("Invalid number of products.\n");
                    while (getchar() != '\n');
                    break;
                }
                writeProducts(filename, numProducts);
                break;

            case 2:
                printf("Enter the number of products to append: ");
                if (scanf("%d", &numProducts) != 1 || numProducts <= 0) {
                    printf("Invalid number of products.\n");
                    while (getchar() != '\n');
                    break;
                }
                appendProducts(filename, numProducts);
                break;

            case 3:
                readProducts(filename);
                break;

            case 4:
                modifyProduct(filename);
                break;

            case 5:
                printf("Exiting...\n");
                printf("-- End --\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// -------------------------------------------------------
// Helper: Check if a product ID already exists in the file
// -------------------------------------------------------
int isProductIDExists(const char *filename, int id) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) return 0; // File doesn't exist yet, ID is free

    struct Product p;
    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        if (p.product_id == id) {
            fclose(file);
            return 1; // ID found
        }
    }
    fclose(file);
    return 0; // ID not found
}

// -------------------------------------------------------
// Function: writeProducts - Overwrite file with new data
// -------------------------------------------------------
void writeProducts(const char *filename, int numProducts) {
    FILE *file = fopen(filename, "wb"); // "wb" = write binary (overwrites)
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < numProducts; i++) {
        struct Product p;
        printf("\nEnter details for product %d:\n", i + 1);

        // Product ID with uniqueness check
        while (1) {
            printf("Product ID: ");
            if (scanf("%d", &p.product_id) != 1 || p.product_id <= 0) {
                printf("Invalid ID. Please enter a positive integer.\n");
                while (getchar() != '\n');
                continue;
            }
            break; // In write mode (overwrite), we accept all IDs
        }

        // Clear input buffer before reading string
        while (getchar() != '\n');

        printf("Product Name: ");
        fgets(p.product_name, sizeof(p.product_name), stdin);
        // Remove trailing newline from fgets
        p.product_name[strcspn(p.product_name, "\n")] = '\0';

        printf("Price: ");
        while (scanf("%f", &p.price) != 1 || p.price < 0) {
            printf("Invalid price. Please enter a non-negative value: ");
            while (getchar() != '\n');
        }

        printf("Quantity: ");
        while (scanf("%d", &p.quantity) != 1 || p.quantity < 0) {
            printf("Invalid quantity. Please enter a non-negative integer: ");
            while (getchar() != '\n');
        }

        fwrite(&p, sizeof(struct Product), 1, file);
    }

    fclose(file);
    printf("\nProducts have been written to the file successfully.\n");
}

// -------------------------------------------------------
// Function: appendProducts - Add records without overwriting
// -------------------------------------------------------
void appendProducts(const char *filename, int numProducts) {
    // Check if file exists first (for user-friendly message)
    FILE *check = fopen(filename, "rb");
    if (check == NULL) {
        printf("Warning: File not found. A new file will be created.\n");
    } else {
        fclose(check);
    }

    FILE *file = fopen(filename, "ab"); // "ab" = append binary
    if (file == NULL) {
        printf("Error: Could not open file for appending.\n");
        return;
    }

    for (int i = 0; i < numProducts; i++) {
        struct Product p;
        printf("\nEnter details for product %d:\n", i + 1);

        // Product ID with duplicate check
        while (1) {
            printf("Product ID: ");
            if (scanf("%d", &p.product_id) != 1 || p.product_id <= 0) {
                printf("Invalid ID. Please enter a positive integer.\n");
                while (getchar() != '\n');
                continue;
            }
            if (isProductIDExists(filename, p.product_id)) {
                printf("Error: Product ID %d already exists. Please enter a unique ID.\n", p.product_id);
                continue;
            }
            break;
        }

        while (getchar() != '\n'); // Clear buffer

        printf("Product Name: ");
        fgets(p.product_name, sizeof(p.product_name), stdin);
        p.product_name[strcspn(p.product_name, "\n")] = '\0';

        printf("Price: ");
        while (scanf("%f", &p.price) != 1 || p.price < 0) {
            printf("Invalid price. Please enter a non-negative value: ");
            while (getchar() != '\n');
        }

        printf("Quantity: ");
        while (scanf("%d", &p.quantity) != 1 || p.quantity < 0) {
            printf("Invalid quantity. Please enter a non-negative integer: ");
            while (getchar() != '\n');
        }

        fwrite(&p, sizeof(struct Product), 1, file);
    }

    fclose(file);
    printf("\nProducts have been appended to the file successfully.\n");
}

// -------------------------------------------------------
// Function: readProducts - Display all records in a table
// -------------------------------------------------------
void readProducts(const char *filename) {
    FILE *file = fopen(filename, "rb"); // "rb" = read binary
    if (file == NULL) {
        printf("Error: File not found or could not be opened. No records to display.\n");
        return;
    }

    struct Product p;
    int count = 0;

    printf("\nReading products from the file:\n");
    printf("-----------------------------------------------------\n");
    printf("%-15s %-20s %-10s %-10s\n", "Product ID", "Product Name", "Price", "Quantity");
    printf("-----------------------------------------------------\n");

    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        printf("%-15d %-20s %-10.2f %-10d\n",
               p.product_id, p.product_name, p.price, p.quantity);
        count++;
    }

    printf("-----------------------------------------------------\n");

    if (count == 0) {
        printf("No records found in the file.\n");
    } else {
        printf("Total records: %d\n", count);
    }

    fclose(file);
}

// -------------------------------------------------------
// Function: modifyProduct - Update a record by product_id
// -------------------------------------------------------
void modifyProduct(const char *filename) {
    FILE *file = fopen(filename, "r+b"); // "r+b" = read/write binary (no truncate)
    if (file == NULL) {
        printf("Error: File not found or could not be opened.\n");
        return;
    }

    int searchID;
    printf("Enter the Product ID to modify: ");
    if (scanf("%searchID", &searchID) != 1 || searchID <= 0) {
        printf("Invalid Product ID.\n");
        while (getchar() != '\n');
        fclose(file);
        return;
    }

    struct Product p;
    int found = 0;
    long position; // Track file position before reading each record

    while (1) {
        position = ftell(file); // Save position before reading
        if (fread(&p, sizeof(struct Product), 1, file) != 1) {
            break; // End of file or read error
        }

        if (p.product_id == searchID) {
            found = 1;
            printf("Product found. Enter new details:\n");

            while (getchar() != '\n'); // Clear buffer

            printf("New Product Name: ");
            fgets(p.product_name, sizeof(p.product_name), stdin);
            p.product_name[strcspn(p.product_name, "\n")] = '\0';

            printf("New Price: ");
            while (scanf("%f", &p.price) != 1 || p.price < 0) {
                printf("Invalid price. Please enter a non-negative value: ");
                while (getchar() != '\n');
            }

            printf("New Quantity: ");
            while (scanf("%d", &p.quantity) != 1 || p.quantity < 0) {
                printf("Invalid quantity. Please enter a non-negative integer: ");
                while (getchar() != '\n');
            }

            // Move back to the record's starting position and overwrite it
            fseek(file, position, SEEK_SET);
            fwrite(&p, sizeof(struct Product), 1, file);

            printf("Product updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", searchID);
    }

    fclose(file);
}