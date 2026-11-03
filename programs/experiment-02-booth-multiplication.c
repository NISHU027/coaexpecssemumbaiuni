#include <stdio.h>

int main() {
    int m, q, a = 0, q1 = 0, n, count;

    printf("Enter Multiplicand (M): ");
    scanf("%d", &m);
    printf("Enter Multiplier (Q): ");
    scanf("%d", &q);

    n = 4;
    count = n;

    printf("\nCount\tA\tQ\tQ-1\tOperation\n");

    while (count--) {
        int q0 = q & 1;

        if (q0 == 1 && q1 == 0)
            a -= m;
        else if (q0 == 0 && q1 == 1)
            a += m;

        printf("%d\t%04d\t%04d\t%d\t%s\n",
               n - count, a & 15, q & 15, q1,
               q0 == q1 ? "ASR" : (q0 ? "A=A-M" : "A=A+M"));

        q1 = q & 1;
        q = (q >> 1) | ((a & 1) << 3);
        a >>= 1;
    }

    printf("\nFinal Product (A,Q): %d\n", a * 16 + q);
    return 0;
}
