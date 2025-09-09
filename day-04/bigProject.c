#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice, numberPlayerAdded = 0,numberPlayer,n;

struct players {
    int playerID;
    char playerName[100];
    char playerLastName[100];
    int playerNumber;
    char position[100];
    int age;
    int goals;
    int dateInTeam;
};

struct players player[100];

void menu(void);
void addPlayer(void);
void addSinglePlayer(void);
void multiPlayer(void);
void showAllPlayers(void);
// void modifyPlayer(void);
// void deletePlayer(void);
// void searchPlayer(void);
// void statisticsPlayer(void);


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
            // system("cls");
            addPlayer();
            break;
        case 2:
            // system("cls");
            showAllPlayers();
            break;

        case 3:
            system("cls");
            // modifyPlayer();
            break;

        case 4:
            system("cls");
            // deletePlayer();
            break;

        case 5:
            system("cls");
            // searchPlayer();
            break;
        case 6:
            system("cls");
            // statisticsPlayer();
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
        printf("\n**********MENU**********\n");
        printf("1.Add a Player\n");
        printf("2.Show all Players\n");
        printf("3.Modify a Player\n");
        printf("4.Delete a Player\n");
        printf("5.Search a Player\n");
        printf("6.Statistics\n");
        printf("7.Exit\n");
    }
 

// add player function ************
void subMenu(void){
    printf("\n+++++++SUB MENU+++++++\n");
    printf("1.Add a Player\n");
    printf("2.Add multiple Player \n");
    printf("4.Exit\n");
}

void addPlayer(void){
    subMenu();
    int subChoice;
    printf("\nEnter your choice :\n");
    scanf("%d", &subChoice);
    switch (subChoice)
    {
        case 1:
            addSinglePlayer();
            break;
        case 2:
            multiPlayer();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("*****Invalid choice*****");
    }
    
}    

void addSinglePlayer(void){
    int i = 0; // Assuming adding the first player for simplicity
    player[i].playerID = i + 1;
    printf("Enter player Name:\n");
    scanf("%s", player[i].playerName);
    printf("Enter player Last Name:\n");
    scanf("%s", player[i].playerLastName);
    printf("Enter player Number:\n");
    scanf("%d", &player[i].playerNumber);
    printf("Enter player Position:\n");
    scanf("%s", player[i].position);
    printf("Enter player Age:\n");
    scanf("%d", &player[i].age);
    printf("Enter player Goals:\n");
    scanf("%d", &player[i].goals);
    printf("Enter player Date In Team:\n");
    scanf("%d", &player[i].dateInTeam);

    numberPlayerAdded++;

    printf("Player added successfully!\n");
}

void multiPlayer(void){
    printf("How many players do you want to add?\n");
    scanf("%d", &numberPlayer);

    for (int i = 0; i < numberPlayer; i++){
        player[i].playerID = i + 1;
        printf("Enter player Name:\n");
        scanf("%s", player[i].playerName);
        printf("Enter player Last Name:\n");
        scanf("%s", player[i].playerLastName);
        printf("Enter player Number:\n");
        scanf("%d", &player[i].playerNumber);
        printf("Enter player Position:\n");
        scanf("%s", player[i].position);
        printf("Enter player Age:\n");
        scanf("%d", &player[i].age);
        printf("Enter player Goals:\n");
        scanf("%d", &player[i].goals);
        printf("Enter player Date In Team:\n");
        scanf("%d", &player[i].dateInTeam);
    }
    printf("Players added successfully!\n");
}



// showAllPlayers function ************
void showAllPlayers(){
    n = numberPlayer + numberPlayerAdded;
    for (int i = 0; i < n; i++){
        printf("Player ID: %d\n", player[i].playerID );
        printf("Player Name: %s\n", player[i].playerName);
        printf("Player Last Name: %s\n", player[i].playerLastName);
        printf("Player Number: %d\n", player[i].playerNumber);
        printf("Player Position: %s\n", player[i].position);
        printf("Player Age: %d\n", player[i].age);
        printf("Player Goals: %d\n", player[i].goals);
        printf("Player Date In Team: %d\n", player[i].dateInTeam);
        printf("\n");
    }
}