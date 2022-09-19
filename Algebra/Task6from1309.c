#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void function(int i, int j, int k, int n, int swap1[n], int swap2[n]) {
    int tmp = swap1[k];
    swap1[k] = swap1[j];
    swap1[j] = swap1[i];
    swap1[i] = tmp;

    swap2[swap1[i]] = i;
    swap2[swap1[j]] = j;
    swap2[swap1[k]] = k;
}

int main() {
    int n, i;
    printf("Enter the length: \n");
    scanf("%d", &n);
    int swap1[n], swap2[n], swap[n];
    printf("Enter the permutation: \n");

    for (i = 0; i < n; i++) {
        scanf("%d", &swap[i]);
        swap[i] = swap[i] - 1;
        swap1[i] = i;
        //swap1[i] = swap[i];
        swap2[i] = i;
    }
    int t, k = 0, flag = 0;
    for (i = 0; i < n; i++) {
        if (swap1[i] != swap[i]) {
            t = swap2[swap[i]];
            if (t != n - 1) {
                function(n - 1, t, i, n, swap1, swap2);
            } else {
                function(n - 2, t, i, n, swap1, swap2);
            }
            /*
            printf("After %d swap:\n", i);
            for (k = 0; k < n; k ++) {
                printf("%d ", swap1[k]);
            }
            printf("\n");
            for (k = 0; k < n; k ++) {
                printf("%d ", swap2[k]);
            }
            */
        }
    }
    if (swap1[n - 1] == swap[n - 1]) {
        printf("Чётная");
    }
    else {
        printf("Нечётная");
    }
    return 0;
}
