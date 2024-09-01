#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the computer's choice as a string
const char* getChoiceString(int choice) {
    switch (choice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Unknown";
    }
}

// Function to get the computer's choice
int getComputerChoice() {
    return rand() % 3; // 0 = Rock, 1 = Paper, 2 = Scissors
}

// Function to determine the winner
void determineWinner(int playerChoice, int computerChoice) {
    printf("\nYou chose: %s\n", getChoiceString(playerChoice));
    printf("Computer chose: %s\n", getChoiceString(computerChoice));

    if (playerChoice == computerChoice) {
        printf("\nIt's a tie!\n");
    } else if ((playerChoice == 0 && computerChoice == 2) || 
               (playerChoice == 1 && computerChoice == 0) || 
               (playerChoice == 2 && computerChoice == 1)) {
        printf("\nCongratulations! You win!\n");
    } else {
        printf("\nSorry, Computer wins this time!\n");
    }
}

int main() {
    int playerChoice;
    int computerChoice;

    // Seed the random number generator
    srand(time(NULL));

    printf("=========================================\n");
    printf("            Rock, Paper, Scissors\n");
    printf("=========================================\n");
    printf("Enter your choice:\n");
    printf("  0 for Rock\n");
    printf("  1 for Paper\n");
    printf("  2 for Scissors\n");
    printf("=========================================\n");

    // Get player input
    printf("Your choice: ");
    scanf("%d", &playerChoice);

    // Validate input
    if (playerChoice < 0 || playerChoice > 2) {
        printf("\nInvalid choice. Please enter 0, 1, or 2.\n");
        return 1;
    }

    computerChoice = getComputerChoice();
    
    determineWinner(playerChoice, computerChoice);

    return 0;
}
