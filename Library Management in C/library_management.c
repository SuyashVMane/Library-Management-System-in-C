/*
 * ============================================================
 *   LIBRARY MANAGEMENT SYSTEM
 *   Mini Project - Semester 2 | B.Tech CSE Core
 *   MIT World Peace University, Pune
 *   Language: C Programming
 * ============================================================
 *
 * ALGORITHM:
 * 1. Start
 * 2. Display main menu with options
 * 3. Accept user choice
 * 4. Based on choice:
 *    a. Add Book    -> Input book details, store in array
 *    b. Display All -> Loop through array, print all books
 *    c. Search Book -> Input ISBN/Title, linear search in array
 *    d. Issue Book  -> Search book, mark as issued if available
 *    e. Return Book -> Search book, mark as available
 *    f. Delete Book -> Search book, remove from array
 *    g. Exit        -> Terminate program
 * 5. Repeat until Exit
 * 6. Stop
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_NAME  100

/* ---- Structure Definition ---- */
struct Book {
    int    isbn;
    char   title[MAX_NAME];
    char   author[MAX_NAME];
    float  price;
    int    issued;   /* 0 = Available, 1 = Issued */
};

/* ---- Global Data ---- */
struct Book library[MAX_BOOKS];
int bookCount = 0;

/* ---- Function Prototypes ---- */
void addBook();
void displayAllBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();
void printDivider();
void printHeader();

/* ============================================================
 *  MAIN FUNCTION
 * ============================================================ */
int main() {
    int choice;

    printHeader();

    do {
        printf("\n");
        printDivider();
        printf("          LIBRARY MANAGEMENT SYSTEM\n");
        printDivider();
        printf("  [1] Add New Book\n");
        printf("  [2] Display All Books\n");
        printf("  [3] Search Book\n");
        printf("  [4] Issue Book\n");
        printf("  [5] Return Book\n");
        printf("  [6] Delete Book\n");
        printf("  [7] Exit\n");
        printDivider();
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook();        break;
            case 2: displayAllBooks();break;
            case 3: searchBook();     break;
            case 4: issueBook();      break;
            case 5: returnBook();     break;
            case 6: deleteBook();     break;
            case 7: printf("\n  Thank you for using Library Management System!\n\n"); break;
            default: printf("\n  [!] Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

/* ============================================================
 *  UTILITY FUNCTIONS
 * ============================================================ */
void printDivider() {
    printf("  ==========================================\n");
}

void printHeader() {
    printf("\n");
    printf("  ==========================================\n");
    printf("     MIT World Peace University, Pune\n");
    printf("     B.Tech CSE | Semester 2 Mini Project\n");
    printf("     LIBRARY MANAGEMENT SYSTEM IN C\n");
    printf("  ==========================================\n");
}

/* ============================================================
 *  1. ADD BOOK
 * ============================================================ */
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\n  [!] Library is full! Cannot add more books.\n");
        return;
    }

    printf("\n--- Add New Book ---\n");
    printf("  Enter ISBN Number  : ");
    scanf("%d", &library[bookCount].isbn);

    /* Check for duplicate ISBN */
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == library[bookCount].isbn) {
            printf("  [!] A book with this ISBN already exists!\n");
            return;
        }
    }

    printf("  Enter Book Title   : ");
    getchar();  /* flush newline */
    fgets(library[bookCount].title, MAX_NAME, stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = '\0';

    printf("  Enter Author Name  : ");
    fgets(library[bookCount].author, MAX_NAME, stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = '\0';

    printf("  Enter Price (INR)  : ");
    scanf("%f", &library[bookCount].price);

    library[bookCount].issued = 0;  /* Available by default */
    bookCount++;

    printf("\n  [OK] Book added successfully! Total books: %d\n", bookCount);
}

/* ============================================================
 *  2. DISPLAY ALL BOOKS
 * ============================================================ */
void displayAllBooks() {
    if (bookCount == 0) {
        printf("\n  [!] No books in the library yet.\n");
        return;
    }

    printf("\n--- All Books in Library ---\n");
    printf("  %-6s %-30s %-20s %-10s %-10s\n",
           "ISBN", "Title", "Author", "Price", "Status");
    printDivider();

    for (int i = 0; i < bookCount; i++) {
        printf("  %-6d %-30s %-20s Rs.%-7.2f %s\n",
               library[i].isbn,
               library[i].title,
               library[i].author,
               library[i].price,
               library[i].issued ? "Issued" : "Available");
    }

    printf("\n  Total Books: %d\n", bookCount);
}

/* ============================================================
 *  3. SEARCH BOOK
 * ============================================================ */
void searchBook() {
    int isbn;
    printf("\n--- Search Book ---\n");
    printf("  Enter ISBN to search: ");
    scanf("%d", &isbn);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            printf("\n  [FOUND]\n");
            printf("  ISBN    : %d\n",   library[i].isbn);
            printf("  Title   : %s\n",   library[i].title);
            printf("  Author  : %s\n",   library[i].author);
            printf("  Price   : Rs.%.2f\n", library[i].price);
            printf("  Status  : %s\n",   library[i].issued ? "Issued" : "Available");
            return;
        }
    }
    printf("\n  [!] Book with ISBN %d not found.\n", isbn);
}

/* ============================================================
 *  4. ISSUE BOOK
 * ============================================================ */
void issueBook() {
    int isbn;
    printf("\n--- Issue Book ---\n");
    printf("  Enter ISBN of book to issue: ");
    scanf("%d", &isbn);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            if (library[i].issued) {
                printf("\n  [!] Book '%s' is already issued.\n", library[i].title);
            } else {
                library[i].issued = 1;
                printf("\n  [OK] Book '%s' issued successfully.\n", library[i].title);
            }
            return;
        }
    }
    printf("\n  [!] Book with ISBN %d not found.\n", isbn);
}

/* ============================================================
 *  5. RETURN BOOK
 * ============================================================ */
void returnBook() {
    int isbn;
    printf("\n--- Return Book ---\n");
    printf("  Enter ISBN of book to return: ");
    scanf("%d", &isbn);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            if (!library[i].issued) {
                printf("\n  [!] Book '%s' was not issued.\n", library[i].title);
            } else {
                library[i].issued = 0;
                printf("\n  [OK] Book '%s' returned successfully.\n", library[i].title);
            }
            return;
        }
    }
    printf("\n  [!] Book with ISBN %d not found.\n", isbn);
}

/* ============================================================
 *  6. DELETE BOOK
 * ============================================================ */
void deleteBook() {
    int isbn;
    printf("\n--- Delete Book ---\n");
    printf("  Enter ISBN of book to delete: ");
    scanf("%d", &isbn);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            if (library[i].issued) {
                printf("\n  [!] Cannot delete. Book '%s' is currently issued.\n", library[i].title);
                return;
            }
            printf("\n  [OK] Book '%s' deleted.\n", library[i].title);
            /* Shift remaining books left */
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("  Total books remaining: %d\n", bookCount);
            return;
        }
    }
    printf("\n  [!] Book with ISBN %d not found.\n", isbn);
}
