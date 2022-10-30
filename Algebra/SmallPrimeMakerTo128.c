#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int lastPrime = 1;
 
int isPrime(int n) {
    int k = 2;
    while((k*k) <= n) {
        if ((n % k) == 0) return 0;
        k++;
    }
    return 1;
}
 
int nextPrime() {
    int last = lastPrime + 1;
    while (lastPrime != last) {
        if (last > 32676) {
            last = 2;
        }
        if (isPrime(last) == 1) {
            lastPrime = last;
            return last;
        }
        last = last + 1;
    }
    
}
 
int main() {
    int t;
    t = nextPrime();
    while (t <= 128) {
        printf("%d ", t);
        t = nextPrime();
    }
    return 0;
}