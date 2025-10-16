#include <stdio.h>

int printScores(int targetScore);
int printScoresRec(int targetScore, int TDp2, int TDp1, int TD, int FG, int S);

int main() {
    int score;
    printf("Enter the NFL score (Enter 1 to stop): ");
    scanf("%d", &score);

    while (score != 1) {
        if (score < 1) {
            printf("Invalid Score Input");
        }
        else if (score < 1)
        {
            printf("Possible combinations of scoring plays if a team's score is 25:");
            printScores(score);
        } 
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
    }

    return 1;
}

int printScores(int targetScore) {
    printScoresRec(targetScore, 0, 0, 0, 0, 0);
    return 1;
}

int printScoresRec(int targetScore, int TDp2, int TDp1, int TD, int FG, int S) {
    printf("rec");
    int currentScore = TDp2*8 + TDp1*7 + TD*6 + FG*3 + S*2;

    if (currentScore > targetScore) {
        return 1;
    }
    else if (currentScore == targetScore) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", TDp2, TDp1, TD, FG, S);
        return 1;
    }
    else {
        printScoresRec(targetScore, TDp2, TDp1, TD, FG, S + 1);
        printScoresRec(targetScore, TDp2, TDp1, TD, FG + 1, S);
        printScoresRec(targetScore, TDp2, TDp1, TD + 1, FG, S);
        printScoresRec(targetScore, TDp2, TDp1 + 1, TD, FG, S);
        printScoresRec(targetScore, TDp2 + 1, TDp1, TD, FG, S);
        return 1;
    }
}