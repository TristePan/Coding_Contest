//Si fornisca un programma che date in input tre parole di lunghezza variabile sia in grado di individuare,
//tra queste, quelle che iniziano con un determinato carattere.
//Il programma dovrà quindi stampare in output tutte e sole le stringhe che iniziano per un determinato carattere,
//fornito anch'esso in input.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    string output;

    for(int i = 0; i < 100; i++) {

        char a;
        int n1, n2, n3;
        string nome1, nome2, nome3;

        fin >> a >> n1 >> nome1 >> n2 >> nome2 >> n3 >> nome3;

        if(nome1[0] == a) {
            fout << nome1 << " ";
        } if(nome2[0] == a) {
            fout << nome2 << " ";
        } if(nome3[0] == a) {
            fout << nome3 << " ";
        }
        fout << "\n";
    }
}