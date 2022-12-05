#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solution(string *parole, int n, string sotto, ostream& out) {
    for (int i = 0; i < n; i++) {
        if (parole[i].find(sotto) != string::npos) {
            out << parole[i] << " ";
        }
    }
}

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    int n;
    string sottoSequenza;
    for(int i = 0; i < 100; i++) {

        in >> n;
        cout << n << " ";
        in >> sottoSequenza;
        cout << sottoSequenza << " ";

        string *parole = new string[n];

        for(int j = 0; j < n; j++) {
            in >> parole[j];
            cout << parole[j] << " ";
        }

        solution(parole, n, sottoSequenza, out);

        out << endl;
        cout << endl;
    }
}