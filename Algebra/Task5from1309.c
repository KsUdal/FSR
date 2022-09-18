#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter the length: \n");
    scanf("%d", &n);
    int swap1[n], swap2[n];
    printf("Enter the first permutation: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &swap1[i]);
    }
    printf("Enter the second permutation: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &swap2[i]);
    }
    //поиск обратной
    int t;
    int swapmulti[n], swaprevers1[n], swaprevers2[n];
    for (i = 0; i < n; i++) {
        t = swap1[i] - 1;
        swaprevers1[t] = i + 1;
        t = swap2[i] - 1;
        swaprevers2[t] = i + 1;
    }
    printf("Reverse permutation for the first one is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", swaprevers1[i]);
    }
    printf("\nReverse permutation for the second one is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", swaprevers2[i]);
    }
    //перемножение
    printf("\nThe result of multiplication is: ");
    for (i = 0; i < n; i++) {
        t = swap1[i] - 1;
        swapmulti[i] = swap2[t];
        printf("%d ", swapmulti[i]);
    }
    return 0;
}

