#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   

// golbal variable************
int choice,  numberPlayer, totalPlayers = 10, playerID = 11;

// int deletedSize = 0;

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

// struct deletedPlayers deletedplayer[100];

// declaring functions*******
void menu(void);
void addPlayer(void);
void addSubMenu(void);
void addSinglePlayer(void);
void multiPlayer(void);
void displayAllPlayers(void);
void modifyPlayer(void);
// void displayPlayersByPosition(char *detail);
void deletePlayer(void);
void statisticsPlayer(void);
void searchPlayer(void);
void sortingMenu();
void fillPlayers();


// main fucntion*******
int main(){
    fillPlayers();
    while (1){
        // show menu function***
        menu();
        
        printf("\nEnter your choice : ");
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
            displayAllPlayers();
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
            // system("cls");
            searchPlayer();
            break;
        case 6:
            // system("cls");
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


// data base of players**********************
void fillPlayers() {
    time_t now = time(NULL);
    struct players temp[] = {
        {1, "Lionel", "Messi", 10, "Forward", 38, 15, (int)now},
        {2, "Cristiano", "Ronaldo", 7, "Forward", 40, 18, (int)(now - 86400 * 365)},
        {3, "Kylian", "Mbappe", 7, "Forward", 27, 22, (int)(now - 86400 * 200)},
        {4, "Kevin", "De Bruyne", 17, "Midfielder", 34, 9, (int)(now - 86400 * 600)},
        {5, "Virgil", "van Dijk", 4, "Defender", 33, 4, (int)(now - 86400 * 400)},
        {6, "Erling", "Haaland", 9, "Forward", 25, 25, (int)(now - 86400 * 100)},
        {7, "Luka", "Modric", 10, "Midfielder", 40, 7, (int)(now - 86400 * 800)},
        {8, "Neymar", "Jr", 10, "Forward", 34, 12, (int)(now - 86400 * 300)},
        {9, "Sergio", "Ramos", 4, "Defender", 39, 5, (int)(now - 86400 * 900)},
        {10, "Mohamed", "Salah", 11, "Forward", 33, 20, (int)(now - 86400 * 250)}
    };

    // Copy to global player[] array
    memcpy(player, temp, sizeof(temp));
}


// main menu Functions************
void menu() {
    printf("╔═════════════════════════════╗\n");
    printf("  ======== Main Menu =======\n");
    printf("  1. Add a Player\n");
    printf("  2. Show All Players\n");
    printf("  3. Modify a Player\n");
    printf("  4. Delete a Player\n");
    printf("  5. Search a Player\n");
    printf("  6. Statistics\n");
    printf("  7. Exit\n");
    
    printf("╚═════════════════════════════╝\n");
}


 

// add player function ************
void addSubMenu(void) {
    printf("\n=== Add Players Menu ===\n");
    printf("1. Add a Player\n");
    printf("2. Add Multiple Players\n");
    printf("3. Exit\n");
    printf("========================\n");
}

void addPlayer(void){
    addSubMenu();
    int subChoice;
    printf("\nEnter your choice :\n");
    scanf("%d", &subChoice);
    switch (subChoice)
    {
        case 1:
            printf("----Adding a single player----:\n");
            addSinglePlayer();
            break;
        case 2:
            printf("----Adding multiple players----:\n");
            multiPlayer();
            break;
        case 3:
            printf("Exiting......\n");
            break;
        default:
            printf("*****Invalid choice*****");
    }
    
}    
void addSinglePlayer(void) {
    int index = totalPlayers; 

    player[index].playerID = playerID;

    printf("Enter player Name: ");
    scanf("%s", player[index].playerName);

    printf("Enter player Last Name: ");
    scanf("%s", player[index].playerLastName);

    printf("Enter player Number: ");
    scanf("%d", &player[index].playerNumber);

    printf("Enter player position: Goalkeeper || Defence || Midfield || Attacker\n");

    scanf("%s", player[index].position);

    printf("Enter player Age: ");
    scanf("%d", &player[index].age);

    printf("Enter player Goals: ");
    scanf("%d", &player[index].goals);

    time_t now;
    time(&now);
    player[index].dateInTeam = now;

    playerID++;
    totalPlayers++;

    printf("Player added successfully!\n");
    printf("---------------------------\n");
}

void multiPlayer(void) {
    time_t now;
    time(&now);

    int numberToAdd;
    printf("How many players do you want to add?\n");
    scanf("%d", &numberToAdd);

    for (int i = totalPlayers; i < totalPlayers + numberToAdd; i++) {
        player[i].playerID = playerID;

        printf("Enter player Name: ");
        scanf("%s", player[i].playerName);

        printf("Enter player Last Name: ");
        scanf("%s", player[i].playerLastName);

        printf("Enter player Number: ");
        scanf("%d", &player[i].playerNumber);

        printf("Enter player position: Goalkeeper || Defence || Midfield || Attacker\n");
        scanf("%s", player[i].position);

        printf("Enter player Age: ");
        scanf("%d", &player[i].age);

        printf("Enter player Goals: ");
        scanf("%d", &player[i].goals);

        player[i].dateInTeam = now;

        printf("---------------------------\n");

        playerID++;
    }

    totalPlayers += numberToAdd;

    printf("Players added successfully!\n");
}




// showAllPlayers function ************
void sortingMenu() {
    printf("\n=============================\n");
    printf("1. displaying all players \n");
    printf("\n ****** Sorting Menu ******\n");
    printf("\n");
    printf("2. Sort players by alphabetical order (name)\n");
    printf("3. Sort players by age\n");
    printf("4. Sort players by position\n");
    printf("5. Exit\n");
    printf("=============================\n");
}


void displayPlayer(){
    int i;
    for (i = 0; i < totalPlayers; i++) {
            printf("| Player ID: %d\n", player[i].playerID);
            if (player[i].goals > 10){
                printf("| Name: %s %s (Super Star)\n", player[i].playerName, player[i].playerLastName);
            }
            else {
                printf("| Name: %s %s\n", player[i].playerName, player[i].playerLastName);
            }
            printf("| Age: %d\n", player[i].age);
            printf("| Position: %s\n", player[i].position);
            printf("| Number: %d\n", player[i].playerNumber);
            printf("| Goals: %d\n", player[i].goals);
              // Convert timestamp to readable format
            time_t t = (time_t)player[i].dateInTeam;
            printf("| Player Date In Team: %s", ctime(&t)); 
            printf("---------------------\n");
        }
}

// bubble sort method********************
void displayAllPlayers() {
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }

    // char position[20];
    int running = 1;

    while (running) {
        sortingMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int i, j;

        switch (choice) {
            case 1:
            displayPlayer();
            break;
            case 2: //sort by name
                for (i = 0; i < totalPlayers; i++) {
                for (j = 0; j < totalPlayers - 1; j++) {
                    if (strcasecmp(player[j].playerLastName, player[j + 1].playerLastName) > 0) {
                        struct players temp = player[j];
                        player[j] = player[j + 1];
                        player[j + 1] = temp;
                    }
                }   
                }
                printf("Players sorted by last name:\n");
                printf("---------------------------\n");
                displayPlayer(); 
                printf("---------------------------\n");
                break;

            case 3: //sort by age 
                for (i = 0; i < totalPlayers; i++) {
                    for (j = 0; j < totalPlayers - 1; j++) {
                        if (player[j].age > player[j + 1].age) {
                            struct players temp = player[j];
                            player[j] = player[j + 1];
                            player[j + 1] = temp;
                        }
                    }
                }
                printf("Players sorted by age:\n");
                printf("---------------------------\n");
                displayPlayer();
                printf("---------------------------\n");
                break;

            case 4: // Show players by position
                for (i = 0; i < totalPlayers; i++) {
                    for (j = 0; j < totalPlayers - 1 ; j++) {
                        // if B > A then swap B with A
                        if (strcasecmp(player[j].position, player[j + 1].position) > 0) {
                            struct players temp = player[j];
                            player[j] = player[j + 1];
                            player[j + 1] = temp;
                        }
                    }
                }
                printf("Players sorted by position:\n");
                printf("---------------------------\n");
                displayPlayer(); 
                printf("---------------------------\n");
                break;

            case 5: // Exit
                printf("Exiting.........\n");
                running = 0;
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
}







// searching function**********
void searchMenu(char *detail ){
    printf("\n==============================\n");
    printf("***Search Player to %s***\n", detail);
    printf("\n");
    printf("1. Search by Player ID\n");
    printf("2. Search by Player LastName\n");
    printf("3. Exit\n");
    printf("==============================\n");

}
void searchByPlayerDetail(char *detail) {
    int found = 0;
    int inputID = atoi(detail);  // convert string to int
    for (int i = 0; i < totalPlayers; i++) {
        // Compare with name, number, OR email
        if (player[i].playerID == inputID ||
            strcasecmp(player[i].playerLastName, detail) == 0 ) {

            printf("\nModifying details for player: %s\n", player[i].playerLastName);
            printf("-------------------------------\n");

            printf("Enter the new player position: ");
            scanf("%s", player[i].position);

            printf("Enter the new player age: ");
            scanf("%d", &player[i].age);

            printf("Enter the new player goals: ");
            scanf("%d", &player[i].goals);

            printf("\n Details updated for player %s\n", player[i].playerLastName);
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
    int running = 1;
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }
    while (running)
    {    
    printf("\n------------Modify Player-------------\n");
    printf("---------------------------------------\n");
    char operaType[] = "modify";
    searchMenu(operaType);
    int searchChoice;
    char searchKeyWord[100];

    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1: // search by name
            printf("Enter the player ID: ");
            scanf("%s", searchKeyWord);
            searchByPlayerDetail(searchKeyWord);
            break;

        case 2: // search by number
            printf("Enter the player last Name: ");
            scanf("%s", searchKeyWord);
            searchByPlayerDetail(searchKeyWord);
            break;

        case 3: // exit
            printf("Exiting search.......\n");
            running = 0;
            break;

        default:
            printf("***** Invalid choice *****\n");
    }
     }
}





// delete function************
void deletePlayer() {
     if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }

    int found = 0;
    int playerIDFound;
    printf("\n-------------Delete Player-------------\n");
    printf("----------------------------------------\n");
    
    printf("Enter the player ID: ");
    scanf("%d", &playerIDFound);
    for (int i = 0; i < totalPlayers; i++) {
        if (player[i].playerID == playerIDFound) {

            printf("\nDeleting player: %d\n", player[i].playerID);

            char deleteChoice;
            printf("Do you want to delete the player? [Y or N]: ");
            scanf(" %c", &deleteChoice);  
            if (deleteChoice == 'Y' || deleteChoice == 'y') {
                
                // store deletedPlayers****
                // int index = totalPlayers - 1; 
                // deletedplayer[deletedSize++] = deletedplayer[index];

                // Shift remaining contacts left
                for (int j = i; j < totalPlayers - 1; j++) {
                    player[j] = player[j + 1];
                }
                totalPlayers--;
                printf("\n****the player ID %d has been deleted.****\n", playerIDFound);
                found = 1;
                break;
            } else {
                printf("Deletion cancelled.\n");
                return;  
            }
   
        }
    }

    if (!found) {
        printf("\n the player with ID '%d' not found.\n", playerIDFound);
    }
}



// searching players function **********
void searchMain(char *detail){
    int found = 0;
    int inputID = atoi(detail);  // convert string to int
    for (int i = 0; i < totalPlayers; i++) {
        // Compare with name, number, OR email
        if (player[i].playerID == inputID||
            strcasecmp(player[i].playerLastName, detail) == 0 ) {
            printf("\n*******Player found*******\n");
            printf("| Player ID: %d\n", player[i].playerID);
            printf("| Player Name: %s\n", player[i].playerName);
            printf("| Player Last Name: %s\n", player[i].playerLastName);
            printf("| Player age: %d\n", player[i].age);
            printf("| Player Number: %d\n", player[i].playerNumber);
            printf("| Player position: %s\n", player[i].position);
            printf("| Player Goals: %d\n", player[i].goals);
           // Convert timestamp to readable format
            time_t t = (time_t)player[i].dateInTeam;
            printf("| Player Date In Team: %s", ctime(&t)); 
            printf("-----------------------------\n"); 
            found = 1; 
            break; 
        }
    }

    if (!found) {
        printf("\n Player with ID '%d' not found.\n", inputID);
    }

}
void searchPlayer(){
    int running = 1;
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }

    while(running){
        char operaType[] = "display";
        searchMenu(operaType);
        int searchChoice;
        char searchKeyWord[100];
        printf("\nEnter your choice: ");
        scanf("%d", &searchChoice);
        switch (searchChoice) {
            case 1: // search by ID
                printf("Enter the player ID: ");
                scanf("%s", searchKeyWord);
                searchMain(searchKeyWord);
                break;

            case 2: // search by LastName
                printf("Enter the player last Name: ");
                scanf("%s", searchKeyWord);
                searchMain(searchKeyWord);
                break;
            case 3: // exit
                printf("Exiting search..........\n");
                running = 0;
                break;

            default:
                printf("***** Invalid choice *****\n");
        }
        }
    
}




// statistics************
void statisMenu(){
    printf("\n=============================\n");
    printf("-------- Player Statistics Menu --------\n");
    printf("1. Show total number of players\n");
    printf("2. Show average age of players\n");
    printf("3. Show players with more than X goals\n");
    printf("4. Show top scorer (most goals)\n");
    printf("5. Show youngest and oldest player\n");
    printf("6. Exit\n");
    printf("=============================\n");

}

void statisticsPlayer() {
    int running = 1;
    if (totalPlayers == 0) {
        printf("No players available.\n");
        return;
    }
    while(running){
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
                int average = (int)totalAge / totalPlayers;
                printf("Average age: %d years\n", average);
                break;
            }

            case 3:  {// Players with more than X goals
                int minGoals;
                printf("Enter the minimum number of goals: ");
                scanf("%d", &minGoals);

                printf("Players with more than %d goals:\n", minGoals);

                int found = 0;
                for (i = 0; i < totalPlayers; i++) {
                    if (player[i].goals > minGoals) {
                        printf("- %s %s (%d goals)\n", 
                            player[i].playerName,
                            player[i].playerLastName, 
                            player[i].goals);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No player found with more than %d goals.\n", minGoals);
                }
                break;
            }
            case 4: { 
                int maxGoals = player[0].goals;
                int topIndex = 0;

                for (i = 1; i < totalPlayers; i++) {
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

            case 5:{  // Youngest and oldest player
                int minAge = player[0].age, maxAge = player[0].age;
                int youngest = 0, oldest = 0;

                for (i = 1; i < totalPlayers; i++) {
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
                
                running = 0;  
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    }
    

// deletedPlayers *********
// void showDeletedContacts() {
//     if (deletedSize == 0) {
//         printf("No deleted contacts in the memory.\n");
//         return;
//     }
//     printf("You have %d deleted contacts:\n", deletedSize);
    
//     for (int i = 0; i < deletedSize; i++) {
//             printf("\nDeleted Contact %d\n", i + 1);
//             printf("Name: %s\n", deletePlayer[i].playerID);
//             printf("Number: %s\n", deletePlayer[i].playerName);      
//             printf("Email Adress: %d\n", deletePlayer[i].age);
//             printf("\n");  
//     }
// }

// void displayPlayersByPosition(char *pos) {
//     int found = 0;
//     for (int i = 0; i < totalPlayers; i++) {
//         if (strcmp(player[i].position, pos) == 0) {
//             printf("Player ID: %d\n", player[i].playerID);
//             printf("Name: %s %s\n", player[i].playerName, player[i].playerLastName);
//             printf("Number: %d\n", player[i].playerNumber);
//             printf("Position: %s\n", player[i].position);
//             printf("Age: %d\n", player[i].age);
//             printf("Goals: %d\n", player[i].goals);
//             printf("---------------------------\n");
//             found = 1;
//         }
//     }

//     if (!found) {
//         printf("No players found for position: %s\n", pos);
//     }
// }
