#include <stdio.h>
#include <stdlib.h>
#include <string.h>  


int choice;
int i;
char titleBook[100][100];
char Autor[100][100];
float price[100];
int quantity[100];
int bookSize = 0;


void showAllBooks(void); 
void addBook(void); 
void menu(void);
void reAssigntheDetail(void);
void deleteBook(void);
void showStock(void);


void divider(){
    for (int i = 0; i < 50; i++){
        printf("-");
    }
}



int main(){
    while (1){
        menu();

        printf("\nEnter your choice :\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) {
        printf("Invalid choice number.\n");
        continue;
        }
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            showAllBooks();
            break;

        case 3:
            reAssigntheDetail();
            break;

        case 4:
            deleteBook();
            break;

        case 5:
            showStock();
            break;

        case 6:
            exit(0);

        default:
            printf("*****Invalid choice*****");
        }
    }

    return 0;
}


// menu Functions************
    void menu(){
        printf("\n\tMENU\n");
        printf("1.Add Book\n");
        printf("2.Show all Books\n");
        printf("3.ReAssign a detail for a book\n");
        printf("4.Delete a book\n");
        printf("5.Show the total books in the stock\n");
        printf("6.Exit\n");
    }
    

// add book function************
void addBook() {
    printf("***** Adding Book *****\n");
    printf("Enter how many books you wanna add: ");
    scanf("%d", &bookSize);

    for (int i = 0; i < bookSize; i++) {
        printf("\nEnter the book title: ");
        scanf("%s", titleBook[i]);   

        printf("Enter the book author: ");
        scanf("%s", Autor[i]);

        printf("Enter the book price: ");
        scanf("%f", &price[i]);

        printf("Enter the book quantity: ");
        scanf("%d", &quantity[i]);
    }

    printf("Books have been added.\n");

    divider();
}


// showAllBooks function************
void showAllBooks() {
    for (int i = 0; i < bookSize; i++) {
        printf("Book %d\n", i + 1);
        printf("The title for book %d is %s\n", i + 1, titleBook[i]);
        printf("The author for book %d is %s\n", i + 1, Autor[i]);
        printf("The price for book %d is %.2f\n", i + 1, price[i]);
        printf("The quantity for book %d is %d\n", i + 1, quantity[i]);
        printf("\n");  
    }
    divider();
}

// reassignData function ************
void reAssigntheDetail(){
    int bookNumber;
    printf("Enter the book number you wanna reassign (1 to %d): ", bookSize);
    scanf("%d", &bookNumber);

    if (bookNumber < 1 || bookNumber > bookSize) {
        printf("Invalid book number.\n");
        return;
    }

    int index = bookNumber - 1; 
    printf("Reassigning details for Book %d\n", bookNumber);

    printf("Enter the new title: ");
    scanf("%s", titleBook[index]);

    printf("Enter the new author: ");
    scanf("%s", Autor[index]);

    printf("Enter the new price: ");
    scanf("%f", &price[index]);

    printf("Enter the new quantity: ");
    scanf("%d", &quantity[index]);

    printf("Details updated for Book %d\n", bookNumber);

    divider();
}

// delete a book function ************
void deleteBook(){
    int bookNumber;
    printf("Enter the book number you wanna delete (1 to %d): ", bookSize);
    scanf("%d", &bookNumber);

    if (bookNumber < 1 || bookNumber > bookSize) {
        printf("Invalid book number.\n");
        return;
    }

    int index = bookNumber - 1; 

    for (i = index; i < bookSize - 1; i++) {
        // copy 2 to 1
        strcpy(titleBook[i], titleBook[i + 1]);
        strcpy(Autor[i], Autor[i + 1]);
        price[i] = price[i + 1];
        quantity[i] = quantity[i + 1];
    }


    bookSize--; 
    
    printf("Book %d has been deleted.\n", bookNumber);
    divider();
}


void showStock(){
    int totalBooks = 0;
    for (i = 0; i < bookSize; i++){
        totalBooks += quantity[i];
    }
    printf("Total books in stock: %d\n", totalBooks);
    divider();
}