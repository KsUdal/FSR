#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#include "solver.h"

int main() {
    int N, i, j, k, t;
    cin >> N;

    long double min, dist, a, b, sol;
    vector<long double> x(N);
    vector<long double> y(N);
    vector<int> res(N);

    for (i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < N; i++) res[i] = i;

    for (i = 0; i < N; i++) {
        min = 100000000;
        k = i;

	for (j = i; j < N; j++) {
            a = x[res[i - 1]] - x[res[j]];
            b = y[res[i - 1]] - y[res[j]];
            dist = sqrt(a*a + b*b);
            if (dist < min) {
                min = dist;
                k = j;
            }
        }

        t = res[i];
        res[i] = res[k];
        res[k] = t;
    }

    sol = solmaker(N, x,  y, res);

    cout << sol << endl;

    for (i = 0; i < N; i++) cout << res[i] << ' ';

    return 0;
}
