#include <stdio.h>

int main() {
    int Q, M, A = 0, n = 4;

    printf("Enter Dividend: ");
    scanf("%d", &Q);
    printf("Enter Divisor: ");
    scanf("%d", &M);

    for (int i = 0; i < n; i++) {
        A = (A << 1) | ((Q >> (n-1)) & 1);
        Q = (Q << 1) & 15;
        A -= M;

        if (A >= 0)
            Q |= 1;
        else {
            A += M;
            Q &= ~1;
        }
    }

    printf("\nQuotient = %d", Q);
    printf("\nRemainder = %d\n", A);
    return 0;
}
