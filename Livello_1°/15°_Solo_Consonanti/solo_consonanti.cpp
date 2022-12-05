#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solution(string *parole, int index, ostream& out) {
    for(int i = 1; i < parole[index].size(); i++) {
        if(parole[index][i] != 'a' && parole[index][i] != 'e' && parole[index][i] != 'i' && parole[index][i] != 'o' && parole[index][i] != 'u') {
            out << parole[index][i];
        }
    }
    out << endl;
}

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    int n;

    for(int i = 0; i < 100; i++) {

        in >> n;

        string *parole = new string[100];

        getline(in, parole[i]);

        solution(parole, i, out);
    }
}