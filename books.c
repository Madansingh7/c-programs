#include <stdio.h>
#include <string.h>

// Define the structure for a Book
struct Book {
    char author[15];
    char title[15];
    char publisher[15];
    float price;
    int stock;
};

int main() {
    // Create a list of books
    struct Book books[5] = {
        {"author1", "book1", "publisher1", 350.00, 10},
        {"author2", "book2", "publisher2", 500.00, 5},
        {"author3", "book3", "publisher3", 300.00, 8},
        {"author4", "book4", "publisher4", 400.00, 6},
        {"author5", "book5", "publisher5", 250.00, 4}
    };

    int totalBooks = 5;
    char searchTitle[15], searchAuthor[15];
    int found = 0; // Flag to check if book is found
    int copies;

    // Ask user to enter title and author
    printf("Enter the title of the book (example: book1): ");
    scanf("%s", searchTitle);

    printf("Enter the author of the book (example: author1): ");
    scanf("%s", searchAuthor);

    // Search for the book
    for (int i = 0; i < totalBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0 && strcmp(books[i].author, searchAuthor) == 0)
        {
            found = 1;

            // Display book details
            printf("\nBook is available!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Publisher: %s\n", books[i].publisher);
            printf("Price: ₹%.2f\n", books[i].price);
            printf("Stock: %d copies\n", books[i].stock);

            // Ask for number of copies
            printf("\nEnter number of copies you want: ");
            scanf("%d", &copies);

            // Check stock
            if (copies <= books[i].stock) 
            {
                float totalCost = copies * books[i].price;
                printf("Total cost: ₹ %.2f\n", totalCost);
            } else 
            {
                printf("Sorry, required copies not in stock.\n");
            }
            break; // Book found, exit loop
        }
    }

    // If book is not found
    if (found == 0) {
        printf("\nSorry, book not available.\n");
    }

    return 0;
}
