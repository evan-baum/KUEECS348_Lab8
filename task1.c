#include <stdio.h>

// declares functions
int printScores(int targetScore); 
int printScoresRec(int targetScore, int TDp2, int TDp1, int TD, int FG, int S, int scoreType);

int main() {
    int score; // declares score variable

    // print and scan to get score
    printf("Enter the NFL score (Enter 1 to stop): ");
    scanf("%d", &score);

    // loops while the score isn't 1 (end case)
    while (score != 1) {
        // checks if the score is less than 1 (invalid)
        if (score < 1) {
            printf("Invalid Score Input");
        } // cased when score is greater than 1
        else if (score > 1) {
            printf("Possible combinations of scoring plays if a team's score is %d: \n", score);
            printScores(score); // calls helper function to print all scores
        } 
        
        // gets new score
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
    }

    return 0;
}

// facade function to call recursive function
int printScores(int targetScore) {
    printScoresRec(targetScore, 0, 0, 0, 0, 0, 0); // calls recursive function with the target score and all points at 0
    return 0;
}

// recursive function to print all scores that can result in a given target score, scoreType refers to the previously altered
// type of scoring to prevent duplicates
int printScoresRec(int targetScore, int TDp2, int TDp1, int TD, int FG, int S, int scoreType) {
    int currentScore = TDp2*8 + TDp1*7 + TD*6 + FG*3 + S*2; // calculates score of current totals

    if (currentScore > targetScore) { // checks if the current score is greater than the target score to stop going further
        return 0;
    }
    else if (currentScore == targetScore) { // prints score totals if the scores are equal
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TDp2, TDp1, TD, FG, S);
        return 0;
    }
    else {
        // recrses with the stipulation that a given function can only alter point types that are equal to or less
        // than the previously altered point type to prevent duplicate scores
        if (scoreType <= 4)
            printScoresRec(targetScore, TDp2, TDp1, TD, FG, S + 1, 4);
        if (scoreType <= 3)
            printScoresRec(targetScore, TDp2, TDp1, TD, FG + 1, S, 3);
        if (scoreType <= 2)
            printScoresRec(targetScore, TDp2, TDp1, TD + 1, FG, S, 2);
        if (scoreType <= 1)
            printScoresRec(targetScore, TDp2, TDp1 + 1, TD, FG, S, 1);
        if (scoreType <= 0)
            printScoresRec(targetScore, TDp2 + 1, TDp1, TD, FG, S, 0);
        return 0;
    }
}