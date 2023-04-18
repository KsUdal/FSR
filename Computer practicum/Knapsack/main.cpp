#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    vector<int> profit(n);
    vector<int> size(n);
    for (i = 0; i < n; i++) {
        cin >> profit[i] >> size[i];
    }

    ofstream data;
    data.open("data.dzn");

    data << "capacity = " << capacity << ";" << endl;
    data << "n = " << n << ";" << endl;
    data << "profit = [";
    for (i = 0; i < n-1; i++) data << profit[i] << ",";
    data << profit[n-1] << "];" << endl;
    data << "size = [";
    for (i = 0; i < n-1; i++) data << size[i] << ",";
    data << size[n-1] << "];";

    data.close();

    // $ minizinc --solver Gecode solver.mzn data.dzn (for console)
    // how to make it here?

    //system("minizinc --solver Gecode solver.mzn data.dzn");
    system("minizinc --solver Gecode solver.mzn data.dzn > output.log");

    // making beautifull answer
    ifstream output;
    output.open("output.log");

    char k = 'f';

    vector<char> res(n);
    i = 0;

        while (k != '[') {
            output >> k;
        }
        output >> k;

        while (k != ']') {
            if ((k == '1') || (k == '0')) {
                res[i] = k;
                i = i + 1;
            }
            output >> k;
        }


    vector<char> sol(10);
    i = 0;
    while (k != '=') {
        output >> k;
    }
    output >> k;
    while (k != ';') {
        sol[i] = k;
        i = i + 1;
        output >> k;
    }
    int soln = i;

    vector<char> spaceleft(10);
    i = 0;
    while (k != '=') {
        output >> k;
    }

    output >> k;
    while (k != ';') {
        spaceleft[i] = k;
        i = i + 1;
        output >> k;
    }
    int sln = i;

    output.close();

    for (i = 0; i < soln; i++) cout << sol[i];
    cout << ' ';
    for (i = 0; i < sln; i++) cout << spaceleft[i];
    cout << endl;
    for (i = 0; i < n; i++) cout << res[i] << ' ';
    cout << endl;

    return 0;
}

