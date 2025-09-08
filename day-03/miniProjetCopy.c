#include <stdio.h>
#include <string.h>  
#include <stdlib.h>



// assigning variables globally********

int choice;
int i;
struct contacts {
    char contactName[100];
    char number[100];
    char adressEmail[100]; 
    };


int contactSize = 0;
int deletedSize = 0;

struct contacts contact[100];
struct contacts deletedContact[100];

// function prototypes************
void menu(void);
void showAllContacts(void); 
void addContact(void); 
void modifyContact(void);
void deleteContact(void);
void searchContact(void);
void showDeletedContacts(void);
void searchMenu(char *detail);
void searchName(void);
void searchByDetail(char *detail);
void deleteByDetail(char *detail);



void divider(){
    for (int i = 0; i < 50; i++){
        printf("*");
    }
}



int main(){
    while (1){
        // show menu function***
        menu();

        printf("\nEnter your choice :\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
        printf("Invalid choice number.\n");
        continue;
       }

        switch (choice)
        {
        case 1:
        
            addContact();
            break;
        case 2:
        
            showAllContacts();
            break;

        case 3:
        
            modifyContact();
            break;

        case 4:
        
            deleteContact();
            break;

        case 5:
       
            searchContact();
            break;
        case 6:
       
            showDeletedContacts();
            break;

        case 7:
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
        printf("1.Add a Contact\n");
        printf("2.Show all Contacts\n");
        printf("3.Modify a Contact\n");
        printf("4.Delete a Contact\n");
        printf("5.Search a Contact\n");
        printf("6.Show deleted contacts\n");
        printf("7.Exit\n");
    }
    

// add book function************
void addContact() { 
    printf("***** Adding Book *****\n");
    printf("Enter how many contacts you wanna add: ");
    scanf("%d", &contactSize);
    getchar(); 

    for (int i = 0; i < contactSize; i++) {
        printf("\nEnter the contact name: ");
        scanf("%s", contact[i].contactName);
        
        

        printf("Enter the contact number: ");
        scanf("%s", contact[i].number);

        printf("Enter the contact email adress: ");
        scanf("%s", contact[i].adressEmail);

}
    printf("\nContacts have been added.\n");

    divider();
}


// showAllContacts function************
void showAllContacts() {
     if (contactSize == 0) {
        printf("No contacts in the memory.\n");
        return;
    }

    printf("you have %d contacts \n", contactSize);
    
    for (int i = 0; i < contactSize; i++) {
            printf("\nContact %d\n", i + 1);
            printf("Name: %s\n", contact[i].contactName);
            printf("Number: %s\n", contact[i].number);      
            printf("Email Adress: %s\n", contact[i].adressEmail);
            printf("\n");  
    }
    divider();
}

// reassignData function ************
void modifyContact() {
    if (contactSize == 0) {
        printf("No contacts in the memory.\n");
        return;
    }

    char operaType[] = "modify";
    searchMenu(operaType);
    int searchChoice;
    char detail[100];

    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: // search by name
            printf("Enter the contact name: ");
            scanf("%s", detail);
            searchByDetail(detail);
            break;

        case 2: // search by number
            printf("Enter the contact number: ");
            scanf("%s", detail);
            searchByDetail(detail);
            break;

        case 3: // search by email
            printf("Enter the contact email address: ");
            scanf("%s", detail);
            searchByDetail(detail);
            break;

        case 4: // exit
            printf("Exiting search...\n");
            break;

        default:
            printf("***** Invalid choice *****\n");
    }

    divider();
}


// delete a book function ************
void deleteContact(){
    if (contactSize == 0) {
        printf("No contacts in the memory.\n");
        return;
    }
    char operaType[] = "delete";
    searchMenu(operaType);
    int searchChoice;
    char detail[100];

    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: // search by name
            printf("Enter the contact name: ");
            scanf("%s", detail);
            deleteByDetail(detail);
            break;

        case 2: // search by number
            printf("Enter the contact number: ");
            scanf("%s", detail);
            deleteByDetail(detail);
            break;

        case 3: // search by email
            printf("Enter the contact email address: ");
            scanf("%s", detail);
            deleteByDetail(detail);
            break;

        case 4: // exit
            printf("Exiting search...\n");
            break;

        default:
            printf("***** Invalid choice *****\n");
    }

    

    
    
    
    divider();
}


// search a contact function ************
void searchContact(){
    if (contactSize == 0) {
        printf("No contacts in the memory.\n");
        return;
    }
    searchName();
}


// show deleted contacts function ************
void showDeletedContacts() {
    if (deletedSize == 0) {
        printf("No deleted contacts in the memory.\n");
        return;
    }
    printf("You have %d deleted contacts:\n", deletedSize);
    
    for (int i = 0; i < deletedSize; i++) {
            printf("\nDeleted Contact %d\n", i + 1);
            printf("Name: %s\n", deletedContact[i].contactName);
            printf("Number: %s\n", deletedContact[i].number);      
            printf("Email Adress: %s\n", deletedContact[i].adressEmail);
            printf("\n");  
    }
    divider();
}



void searchMenu(char *detail ){
    printf("\nSearch Contact to %s \n", detail);
    printf("1.Search by Name\n");
    printf("2.Search by Number\n");
    printf("3.Search by Email Adress\n");
    printf("4.Exit\n");
}


void searchName(){
    char searchName[100];
    printf("Enter the contact name you wanna search: ");
    scanf("%s", searchName);

    int found = 0; 

    for (i = 0; i < contactSize; i++) {
        if (strcmp(contact[i].contactName, searchName) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\n", contact[i].contactName);
            printf("Number: %s\n", contact[i].number);
            printf("Email Adress: %s\n", contact[i].adressEmail);
            found = 1; 
            break; 
        }
    }

    if (!found) {
        printf("\nContact with name '%s' not found.\n", searchName);
    }

    divider();
}


void searchByDetail(char *detail) {
    int found = 0;

    for (int i = 0; i < contactSize; i++) {
        // Compare with name, number, OR email
        if (strcmp(contact[i].contactName, detail) == 0 ||
            strcmp(contact[i].number, detail) == 0 ||
            strcmp(contact[i].adressEmail, detail) == 0) {

            printf("\nModifying details for Contact: %s\n", contact[i].contactName);

            printf("Enter the new contact number: ");
            scanf("%s", contact[i].number);

            printf("Enter the new contact email address: ");
            scanf("%s", contact[i].adressEmail);

            printf("\n✅ Details updated for Contact %s\n", contact[i].contactName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n❌ Contact with detail '%s' not found.\n", detail);
    }
}


void deleteByDetail(char *detail) {
    int found = 0;

    for (int i = 0; i < contactSize; i++) {
        // Compare with name, number, OR email
        if (strcmp(contact[i].contactName, detail) == 0 ||
            strcmp(contact[i].number, detail) == 0 ||
            strcmp(contact[i].adressEmail, detail) == 0) {

            printf("\nDeleting Contact: %s\n", contact[i].contactName);

            deletedContact[deletedSize++] = contact[i];

            contact[i] = contact[i + 1];
            found = 1;
            break;
            printf("\n✅ Contact %s has been deleted.\n", contact[i].contactName);
        }
    }
    contactSize--; 

    if (!found) {
        printf("\n❌ Contact with detail '%s' not found.\n", detail);
    }
}
