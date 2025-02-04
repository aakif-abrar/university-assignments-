#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char team[20];
} Player;

typedef struct {
    char type[10];  // seamer, pacer, spinner, or N/A
    char arm[5];    // left or right
    Player ply;
} Bowler;

typedef struct {
    char type[10];  // top order, middle order, lower order
    char handed[8]; // lefty or righty
    Bowler ply2;
} Batter;

// Function prototypes
void createPlayer();
void readPlayers();
void updatePlayer(char *name);
void deletePlayer(char *name);

int main() {
    int choice;
    char name[20];

    do {
        printf("\n1. Create Player\n2. Read Players\n3. Update Player\n4. Delete Player\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                createPlayer();
                break;
            case 2:
                readPlayers();
                break;
            case 3:
                printf("Enter the name of the player to update: ");
                fgets(name, 20, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                updatePlayer(name);
                break;
            case 4:
                printf("Enter the name of the player to delete: ");
                fgets(name, 20, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                deletePlayer(name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Create a new player
void createPlayer() {
    FILE *file = fopen("players.txt", "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Batter batter;
    printf("Enter player name: ");
    fgets(batter.ply2.ply.name, 20, stdin);
    batter.ply2.ply.name[strcspn(batter.ply2.ply.name, "\n")] = '\0'; // Remove newline

    printf("Enter team name: ");
    fgets(batter.ply2.ply.team, 20, stdin);
    batter.ply2.ply.team[strcspn(batter.ply2.ply.team, "\n")] = '\0';

    printf("Enter bowler type (seamer/pacer/spinner/N/A): ");
    fgets(batter.ply2.type, 10, stdin);
    batter.ply2.type[strcspn(batter.ply2.type, "\n")] = '\0';

    printf("Enter bowler arm (left/right): ");
    fgets(batter.ply2.arm, 5, stdin);
    batter.ply2.arm[strcspn(batter.ply2.arm, "\n")] = '\0';

    printf("Enter batter type (top/middle/lower order): ");
    fgets(batter.type, 10, stdin);
    batter.type[strcspn(batter.type, "\n")] = '\0';

    printf("Enter batter handedness (lefty/righty): ");
    fgets(batter.handed, 8, stdin);
    batter.handed[strcspn(batter.handed, "\n")] = '\0';

    fprintf(file, "%s|%s|%s|%s|%s|%s\n", batter.ply2.ply.name, batter.ply2.ply.team,
            batter.ply2.type, batter.ply2.arm, batter.type, batter.handed);
    fclose(file);
    printf("Player added successfully.\n");
}

// Read all players
void readPlayers() {
    FILE *file = fopen("players.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[128];
    printf("\nPlayers List:\n");
    while (fgets(line, sizeof(line), file)) {
        char name[20], team[20], bowlerType[10], bowlerArm[5], batterType[10], batterHanded[8];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", name, team, bowlerType, bowlerArm, batterType, batterHanded);
        printf("Name: %s, Team: %s, Bowler Type: %s, Arm: %s, Batter Type: %s, Handedness: %s\n",
               name, team, bowlerType, bowlerArm, batterType, batterHanded);
    }
    fclose(file);
}

// Update a player's information
void updatePlayer(char *name) {
    FILE *file = fopen("players.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Unable to open file");
        return;
    }

    char line[128];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char playerName[20], team[20], bowlerType[10], bowlerArm[5], batterType[10], batterHanded[8];
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", playerName, team, bowlerType, bowlerArm, batterType, batterHanded);

        if (strcmp(playerName, name) == 0) {
            found = 1;
            printf("Enter new team name: ");
            fgets(team, 20, stdin);
            team[strcspn(team, "\n")] = '\0';
            fprintf(temp, "%s|%s|%s|%s|%s|%s\n", playerName, team, bowlerType, bowlerArm, batterType, batterHanded);
        } else {
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);
    fclose(temp);

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found) {
        printf("Player updated successfully.\n");
    } else {
        printf("Player not found.\n");
    }
}

// Delete a player
void deletePlayer(char *name) {
    FILE *file = fopen("players.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Unable to open file");
        return;
    }

    char line[128];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char playerName[20];
        sscanf(line, "%[^|]", playerName);

        if (strcmp(playerName, name) != 0) {
            fprintf(temp, "%s", line);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found) {
        printf("Player deleted successfully.\n");
    } else {
        printf("Player not found.\n");
    }
}
