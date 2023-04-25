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

    system("minizinc --solver Gecode solver.mzn data.dzn");
    //system("minizinc --solver Gecode solver.mzn data.dzn > output.log");

    return 0;
}
