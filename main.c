#include "f.h"

int main() {
    int ch;
    do {
        task();
        printf("\nХотите выполнить задание ещё раз?\n1-Да 2-Нет\n");
        ch = input(1, 2);
    } while (ch!=2);
    return 0;
}