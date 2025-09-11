
void fillPlayers() {
    // Use current time as base date for demo purposes
    time_t now = time(NULL);

    strcpy(player[0].playerName, "Lionel");
    strcpy(player[0].playerLastName, "Messi");
    player[0].playerID = 1;
    player[0].playerNumber = 10;
    strcpy(player[0].position, "Forward");
    player[0].age = 36;
    player[0].goals = 15;
    player[0].dateInTeam = (int)now;

    strcpy(player[1].playerName, "Cristiano");
    strcpy(player[1].playerLastName, "Ronaldo");
    player[1].playerID = 2;
    player[1].playerNumber = 7;
    strcpy(player[1].position, "Forward");
    player[1].age = 38;
    player[1].goals = 18;
    player[1].dateInTeam = (int)now - 86400 * 365;

    strcpy(player[2].playerName, "Kylian");
    strcpy(player[2].playerLastName, "Mbappe");
    player[2].playerID = 3;
    player[2].playerNumber = 7;
    strcpy(player[2].position, "Forward");
    player[2].age = 24;
    player[2].goals = 22;
    player[2].dateInTeam = (int)now - 86400 * 200;

    strcpy(player[3].playerName, "Kevin");
    strcpy(player[3].playerLastName, "De Bruyne");
    player[3].playerID = 4;
    player[3].playerNumber = 17;
    strcpy(player[3].position, "Midfielder");
    player[3].age = 32;
    player[3].goals = 9;
    player[3].dateInTeam = (int)now - 86400 * 600;

    strcpy(player[4].playerName, "Virgil");
    strcpy(player[4].playerLastName, "van Dijk");
    player[4].playerID = 5;
    player[4].playerNumber = 4;
    strcpy(player[4].position, "Defender");
    player[4].age = 31;
    player[4].goals = 4;
    player[4].dateInTeam = (int)now - 86400 * 400;

    strcpy(player[5].playerName, "Erling");
    strcpy(player[5].playerLastName, "Haaland");
    player[5].playerID = 6;
    player[5].playerNumber = 9;
    strcpy(player[5].position, "Forward");
    player[5].age = 23;
    player[5].goals = 25;
    player[5].dateInTeam = (int)now - 86400 * 100;

    strcpy(player[6].playerName, "Luka");
    strcpy(player[6].playerLastName, "Modric");
    player[6].playerID = 7;
    player[6].playerNumber = 10;
    strcpy(player[6].position, "Midfielder");
    player[6].age = 37;
    player[6].goals = 7;
    player[6].dateInTeam = (int)now - 86400 * 800;

    strcpy(player[7].playerName, "Neymar");
    strcpy(player[7].playerLastName, "Jr");
    player[7].playerID = 8;
    player[7].playerNumber = 10;
    strcpy(player[7].position, "Forward");
    player[7].age = 31;
    player[7].goals = 12;
    player[7].dateInTeam = (int)now - 86400 * 300;

    strcpy(player[8].playerName, "Sergio");
    strcpy(player[8].playerLastName, "Ramos");
    player[8].playerID = 9;
    player[8].playerNumber = 4;
    strcpy(player[8].position, "Defender");
    player[8].age = 37;
    player[8].goals = 5;
    player[8].dateInTeam = (int)now - 86400 * 900;

    strcpy(player[9].playerName, "Mohamed");
    strcpy(player[9].playerLastName, "Salah");
    player[9].playerID = 10;
    player[9].playerNumber = 11;
    strcpy(player[9].position, "Forward");
    player[9].age = 31;
    player[9].goals = 20;
    player[9].dateInTeam = (int)now - 86400 * 250;
}
