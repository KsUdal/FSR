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

    system("minizinc --solver Gecode solver.mzn data.dzn");

    return 0;
}

