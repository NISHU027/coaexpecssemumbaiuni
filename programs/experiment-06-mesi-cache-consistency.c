#include <stdio.h>

int main() {
    char state, op;

    printf("Enter Cache State (M/E/S/I): ");
    scanf(" %c", &state);
    printf("Enter Operation (R/W): ");
    scanf(" %c", &op);

    if (op == 'R' || op == 'r') {
        if (state == 'I')
            state = 'E';
        printf("Processor Read (PrRd)\n");
    } else {
        state = 'M';
        printf("Processor Write (PrWr)\n");
    }

    printf("Final State = %c\n", state);
    return 0;
}
