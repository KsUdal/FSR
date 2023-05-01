using namespace std;
long double solmaker(int N, vector<long double> x, vector<long double> y, vector<int> res) {
    int i, j, k, t;
    long double a, b, sol;

    sol = 0;

    for (i = 1; i < N + 1; i++) {
        a = x[res[i - 1]] - x[res[i % N]];
        b = y[res[i - 1]] - y[res[i % N]];
        sol = sol + sqrt (a * a + b * b);
    }

    return sol;
}

