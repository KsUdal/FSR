#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

// v is weight
// w is value

int main() {
        int n;
        int Kw;
        string line = "ks_4_0";
        
        srand(time(NULL));

        // считываем файл
        ifstream in;
        in.open(line);
        in >> n;
        in >> Kw;
        int w[n], v[n];
        int i = 0, j;
        while (!in.eof()) {
                in >> w[i];
                in >> v[i];
                i++;
        }
        
        for (i = 0; i < n; i++) {
            cout<<w[i]<<" ";
        }
        cout << "\n";
        for (i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
        //файл считали
        
        
        // создаём начальное состояние S
        int s[n], t[n];
        // тут надо добавить проверку на вместимость в рюкзак
        // а то вруг даже набор s уже не поместится
        // и выбирать его тогда другим, пока в рюкзак не влезет (то есть цикл)
        
        // update: добавляю эту проверку
        int tsum = Kw + 1;
        while (tsum > Kw) {
            // само создание
            for (i = 0; i < n; i++) {
                s[i] = rand()%2;
                t[i] = s[i];
            }
            // проверка вместимости в рюкзак
            tsum = 0;
            for (j = 0; j < n; j++) {
                tsum = tsum + t[j]*w[j];
            }
        }
        
        
        cout << "\ns = ";
        for (i = 0; i < n; i++) {
            cout<<s[i]<<" ";
        }
        
        //cout << "\n";
        //cout << Kw;
        cout << "\n";
        
        int sum = 0, maxsum = 0, w0 = 0;
        for (i = 0; i < n; i++) {
            maxsum = maxsum + s[i]*w[i];
        }
        
        //cout << "\n";
        //cout << maxsum << " is maxsum";
        
        // а когда sum > maxsum, берём наше t за s
        // и следующий проход делаем от t
        
        // сначала посмотрим на расстоянии 2
        
        i = 0;
        int k1, k2;
        while ((i < n)) {
            //k1 = rand(n);
            k1 = rand() % (n-1);
            //k2 = rand(n);
            k2 = rand() % (n-1);
            
            //cout << "k1 is " << k1 << "\n";
            //cout << "k2 is " << k2 << "\n";
            
            t[k1] = (s[k1] + 1)%2;
            t[k2] = (s[k2] + 1)%2;
            
            //cout << "\nt = ";
            //for (i = 0; i < n; i++) {
                //cout<<t[i]<<" ";
            //}
            
            for (j = 0; j < n; j++) {
                sum = sum + t[j]*w[j];
                w0 = w0 + t[j]*v[j];
            }
            if ((sum >= maxsum) && (w0 <= Kw)) {
                i = n;
                maxsum = sum;
                s[k1] = t[k1];
                s[k2] = t[k2];
                //cout << maxsum;
            }
            else {
                t[k1] = s[k1];
                t[k2] = s[k2];
            }
            i = i + 1;
            sum = 0;
            w0 = 0;
        }
        
        //cout << "\nt = ";
        //for (i = 0; i < n; i++) {
            //cout<<t[i]<<" ";
        //}
        
        //cout << "\n";
        //cout << maxsum << " is maxsum";
        
        // поиск экстремума на расстоянии 1 от состояния S
        i = 0;
        while (i < n) {
            t[i] = (s[i] + 1)%2;
            for (j = 0; j < n; j++) {
                sum = sum + t[j]*w[j];
                w0 = w0 + t[j]*v[j];
            }
            if ((sum >= maxsum) && (w0 <= Kw)) {
                i = n;
                maxsum = sum;
                s[i] = t[i];
                //cout << maxsum;
            }
            else {
                t[i] = s[i];
            }
            i = i + 1;
            sum = 0;
            w0 = 0;
        }
        
        cout << "\ns = ";
        for (i = 0; i < n; i++) {
            cout<<t[i]<<" ";
        }
        
        cout << "\n";
        cout << maxsum << " is maxsum";
        
        in.close();
        return 0;
}