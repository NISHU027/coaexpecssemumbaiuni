#include <stdio.h>

int main() {
    int addr, low_bank, low_offset, high_bank, high_offset;

    printf("Enter Memory Address: ");
    scanf("%d", &addr);

    low_bank = addr % 4;
    low_offset = addr / 4;

    high_bank = (addr / 4) % 4;
    high_offset = addr % 4;

    printf("\n--- LOW-ORDER RESULT ---");
    printf("\nBank: %d | Offset: %d\n", low_bank, low_offset);

    printf("\n--- HIGH-ORDER RESULT ---");
    printf("\nBank: %d | Offset: %d\n", high_bank, high_offset);

    return 0;
}
