#include <stdio.h>

int main() {
    int state = 0, n, i, correct = 0;
    char actual;

    char *names[] = {"WNT", "WT", "ST", "SNT"};

    printf("Enter number of branches: ");
    scanf("%d", &n);

    printf("\nStep\tBefore\tPredicted\tActual\tResult\tAfter\n");

    for(i = 1; i <= n; i++) {
        int before = state;
        char pred = (state >= 2) ? 'T' : 'N';

        printf("Enter actual outcome (T/N): ");
        scanf(" %c", &actual);

        if(pred == actual) correct++;
        if(actual == 'T') {
            if(state < 3) state++;
        } else {
            if(state > 0) state--;
        }

        printf("%d\t%s\t%c\t\t%c\t%s\t%s\n",
            i, names[before], pred, actual,
            pred == actual ? "CORRECT" : "WRONG",
            names[state]);
    }

    printf("\nCorrect Predictions: %d", correct);
    printf("\nWrong Predictions: %d", n-correct);
    printf("\nTotal Branches: %d", n);
    printf("\nAccuracy: %.2f%%\n", 100.0*correct/n);

    return 0;
}
