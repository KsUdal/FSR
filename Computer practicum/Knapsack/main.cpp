#include <iostream>
#include <fstream>

using namespace std;

int main() {
        int n;
        int Kw;
        string line = "ks_4_0";

        ifstream in;
        in.open(line);
        in >> n;
        in >> Kw;
        int w[n], v[n];
        int i = 0;
        while (!in.eof()) {
                in >> w[i];
                in >> v[i];
                i++;
        }
	// just wanted to check myself below
        for (i = 0; i < n; i++) {
            cout<<w[i]<<" ";
        }
        cout << "\n";
        for (i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
        in.close();
        return 0;
}
