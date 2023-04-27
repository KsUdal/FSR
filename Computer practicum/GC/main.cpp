#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int n, e, i;
    cin >> n >> e;
    vector<int> E1(e);
    vector<int> E2(e);
    for (i = 0; i < e; i++) {
        cin >> E1[i] >> E2[i];
    }

    ofstream data;
    data.open("data.dzn");

    data << "n = " << n << ";" << endl;
    data << "e = " << e << ";" << endl;
    // data << "frcd = 306;" << endl;
    data << "E = [";
    for (i = 0; i < e; i++) data << "| " << E1[i] << " , " << E2[i] << "," << endl;
    data << "|];" << endl;

    data.close();

    //system("minizinc --solver Gecode solver.mzn data.dzn");
    system("minizinc --solver Gecode solver.mzn data.dzn > output.log");

    ifstream output;
    output.open("output.log");

    char k = 'f';

    vector<char> sol(5);

    output >> k;
    i = 0;
    while (k != '[') {
        sol[i] = k;
        i = i + 1;
        output >> k;
    }
    int soln = i;

    vector<char> res(n);

    i = 0;
    while (k != ']') {
        if ((k >= '0') && (k <= '9')) {
            res[i] = k;
            i = i + 1;
        }
        output >> k;
    }

    output.close();

    for (i = 0; i < soln; i++) cout << sol[i];
    cout << endl;
    for (i = 0; i < n; i++) cout << res[i] << ' ';
    cout << endl;

    return 0;
}
