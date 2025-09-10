#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   //time(),ctime()

int choice, numberPlayerAdded = 0, numberPlayer, totalPlayers = 0, i;

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
void modifyPlayer(void);
void searchByPlayerDetail(char *detail);
void deletePlayer(void);
void statisticsPlayer(void);
// void searchPlayer(void);


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
            // system("cls");
            modifyPlayer();
            break;

        case 4:
            // system("cls");
            deletePlayer();
            break;

        case 5:
            system("cls");
            // searchPlayer();
            break;
        case 6:
            system("cls");
            statisticsPlayer();
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
        printf("\n============MENU============\n");
        printf("1.Add a Player\n");
        printf("2.Show all Players\n");
        printf("3.Modify a Player\n");
        printf("4.Delete a Player\n");
        printf("5.Search a Player\n");
        printf("6.Statistics\n");
        printf("7.Exit\n");
        printf("============================\n");
    }
 

// add player function ************
void subMenu(void){
    printf("1.Add a Player\n");
    printf("2.Add multiple Player \n");
    printf("3.Exit\n");
    
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
 
    int i = numberPlayerAdded; 
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

    time_t now;
    time(&now);

    player[i].dateInTeam = (int)now;
    numberPlayerAdded++;
    totalPlayers++;


    printf("Player added successfully!\n");
}

void multiPlayer(void){
    time_t now;
    time(&now);
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
        player[i].dateInTeam = (int)now;
        totalPlayers++;
    }
    printf("Players added successfully!\n");
}



// showAllPlayers function ************
void showAllPlayers(){
    // n = numberPlayer + numberPlayerAdded;
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }
    
    for (int i = 0; i < totalPlayers; i++){
        printf("Player ID: %d\n", player[i].playerID );
        printf("Player Name: %s\n", player[i].playerName);
        printf("Player Last Name: %s\n", player[i].playerLastName);
        printf("Player Number: %d\n", player[i].playerNumber);
        printf("Player Position: %s\n", player[i].position);
        printf("Player Age: %d\n", player[i].age);
        printf("Player Goals: %d\n", player[i].goals);
        // Convert timestamp to readable format
        time_t t = (time_t)player[i].dateInTeam;
        printf("Player Date In Team: %s", ctime(&t)); 
        printf("\n");
    }
}



void searchMenu(char *detail ){
    printf("\n++++++++++++++Search Player to %s ++++++++++++++n", detail);
    printf("\t1.Search by Player ID\n");
    printf("\t2.Search by Player Name\n");
    printf("\t3.Exit\n");

}


void searchByPlayerDetail(char *detail) {
    int found = 0;
    int inputID = atoi(detail);  // convert string to int
    for (int i = 0; i < totalPlayers; i++) {
        // Compare with name, number, OR email
        if (player[i].playerID == inputID||
            strcmp(player[i].playerLastName, detail) == 0 ) {

            printf("\nModifying details for player: %s\n", player[i].playerLastName);

            printf("Enter the new player position: ");
            scanf("%s", player[i].position);

            printf("Enter the new player age: ");
            scanf("%d", &player[i].age);

            printf("Enter the new player goals: ");
            scanf("%d", &player[i].goals);

            printf("\n Details updated for player %s\n", player[i].playerName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n player with detail '%s' not found.\n", detail);
    }
}

// reassignData function ************
void modifyPlayer(){
    if (totalPlayers == 0) {
        printf("No players available.\n");
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
            printf("Enter the player ID: ");
            scanf("%s", detail);
            searchByPlayerDetail(detail);
            break;

        case 2: // search by number
            printf("Enter the player last Name : ");
            scanf("%s", detail);
            searchByPlayerDetail(detail);
            break;

        case 3: // exit
            printf("Exiting search...\n");
            break;

        default:
            printf("***** Invalid choice *****\n");
    }

    // divider();

}


void deletePlayer() {
    int found = 0;
    int playerIDFound;
    printf("Enter the player ID: ");
    scanf("%d", &playerIDFound);
    for (int i = 0; i < totalPlayers; i++) {
        // Compare with name, number, OR email
        if (player[i].playerID == playerIDFound) {

            printf("\nDeleting Contact: %d\n", player[i].playerID);

            char deleteChoice;
            printf("Do you want to delete the contact? [Y or N]: ");
            scanf(" %c", &deleteChoice);  // note the space before %c
            if (deleteChoice == 'Y' || deleteChoice == 'y') {
                // Save deleted contact if you want
                // deletedContact[deletedSize++] = contact[i];

                // Shift remaining contacts left
                for (int j = i; j < totalPlayers - 1; j++) {
                    player[j] = player[j + 1];
                }
                totalPlayers--;
                printf("\n the player ID %d has been deleted.\n", player[i].playerID);
                found = 1;
                break;
            } else {
                printf("Deletion cancelled.\n");
                return;  // Exit function if deletion declined
            }
   
        }
    }
    

    if (!found) {
        printf("\n the player with ID '%d' not found.\n", playerIDFound);
    }
}

void statisMenu(){
    printf("\n++++++++++++++Player Statistics Menu ++++++++++++++n");
    printf("1. Show total number of players\n");
    printf("2. Show average age of players\n");
    printf("3. Show players with more than X goals\n");
    printf("4. Show top scorer (most goals)\n");
    printf("5. Show youngest and oldest player\n");
    printf("6. Exit\n");

}

void statisticsPlayer() {
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }

    statisMenu();
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int i;
    switch (choice) {
        case 1: // Total players
            printf("Total number of players: %d\n", totalPlayers);
            break;

        case 2: { // Average age
            int totalAge = 0;
            for (i = 0; i < totalPlayers; i++) {
                totalAge += player[i].age;
            }
            float average = (float)totalAge / numberPlayerAdded;
            printf("Average age: %.2f years\n", average);
            break;
        }

        case 3: { // Players with more than X goals
            int x;
            printf("Enter the minimum number of goals: ");
            scanf("%d", &x);

            printf("Players with more than %d goals:\n", x);
            int found = 0;
            for (i = 0; i < totalPlayers; i++) {
                if (player[i].goals > x) {
                    printf("- %s %s (%d goals)\n", player[i].playerName, player[i].playerLastName, player[i].goals);
                    found = 1;
                }
            }
            if (!found) {
                printf("No player found with more than %d goals.\n", x);
            }
            break;
        }

        case 4: { 
            int maxGoals = player[0].goals;
            int topIndex = 0;

            for (i = 1; i < numberPlayerAdded; i++) {
                if (player[i].goals > maxGoals) {
                    maxGoals = player[i].goals;
                    topIndex = i;
                }
            }

            printf("Top Scorer: %s %s (%d goals)\n",
                   player[topIndex].playerName,
                   player[topIndex].playerLastName,
                   player[topIndex].goals);
            break;
        }

        case 5: { // Youngest and oldest player
            int minAge = player[0].age, maxAge = player[0].age;
            int youngest = 0, oldest = 0;

            for (i = 1; i < numberPlayerAdded; i++) {
                if (player[i].age < minAge) {
                    minAge = player[i].age;
                    youngest = i;
                }
                if (player[i].age > maxAge) {
                    maxAge = player[i].age;
                    oldest = i;
                }
            }

            printf("Youngest Player: %s %s (%d years)\n",
                   player[youngest].playerName,
                   player[youngest].playerLastName,
                   player[youngest].age);

            printf("Oldest Player: %s %s (%d years)\n",
                   player[oldest].playerName,
                   player[oldest].playerLastName,
                   player[oldest].age);
            break;
        }

        case 6:
            printf("Exiting statistics menu...\n");
            break;

        default:
            printf("Invalid choice.\n");
    }
}
