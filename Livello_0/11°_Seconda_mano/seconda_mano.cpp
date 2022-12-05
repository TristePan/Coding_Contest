#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    int m;



    for(int i = 0; i < 101; i++) {

        in >> n >> m;
        //cout << n << " " << m << " ";
        int t = n + m;
        int *a = new int[t];
        int *b = new int[t];

        for(int j = 0; j < t; j++) {
            in >> a[j];
            //cout << a[j] << " ";
        }

        for(int k = 0; k < m; k++) {
            b[k] = a[n + k];
            //cout << b[k] << " ";
        }

        int guadagno = 0;

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(a[j] == b[k]) {
                    guadagno += 5;
                }
            }
        }
        out << guadagno << endl;

    }
}