#include <stdio.h>
#include <stdlib.h>


int choice;
char titleBook[100], Autor[100];
float price[100];
int quantity[100];
int bookSize = 0;
int i;

void showAllBooks(void); 
void addBook(void); // function prototype declaration
void menu();


void divider(){
            for (int i = 0; i < 50; i++)
            {
                printf("-");
            }
        }



int main(){
    while (1){
        menu();

        printf("\nEnter your choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            showAllBooks();
            break;

        case 3:
            
            break;

        case 4:
            
            break;

        case 5:
            
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
        printf("3.Search a Book\n");
        printf("4.ReAssign a detail for a book\n");
        printf("5.Delete a book\n");
        printf("6.Show all books in the stock\n");
    }
    


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


void showAllBooks() {
    for (int i = 0; i < bookSize; i++) {
        printf("Book %d\n", i + 1);
        printf("The title for book %d is %s\n", i + 1, titleBook[i]);
        printf("The author for book %d is %s\n", i + 1, Autor[i]);
        printf("The price for book %d is %.2f\n", i + 1, price[i]);
        printf("The quantity for book %d is %d\n", i + 1, quantity[i]);
        printf("\n");  // Just for better readability between books
    }
}