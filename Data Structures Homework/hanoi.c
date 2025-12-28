#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Diski tasi: %c -> %c\n", kaynak, hedef);
        return;
    }
    
    hanoi(n - 1, kaynak, yardimci, hedef);
    printf("Diski tasi: %c -> %c\n", kaynak, hedef);
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int diskSayisi = 3;
    hanoi(diskSayisi, 'A', 'C', 'B');
    return 0;
}