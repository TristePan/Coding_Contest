#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

fstream in("input.txt", fstream::in);
fstream out("output.txt", fstream::out);

void solution(int *l, int n, int f, ostream& out) {
    for(int j = 0; j < n; j++) {
        if(l[j] == f) {
            out << (j + 1) << endl;
            return;
        }
    }
    out << 0 << endl;
}

int main() {


    for(int i = 0; i < 100; i++) {

        int n;
        in >> n;
        int f;
        in >> f;
        
        cout << n << " ";
        cout << f << " ";

        int *l = new int[n];

        for(int j = 0; j < n; j++) {
            in >> l[j];
            cout << l[j] << " ";
        }
        cout << endl;

        solution(l ,n, f, out);
    }
}