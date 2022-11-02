//Si fornisca un programma che dati in input tre cognomi di lunghezza variabile ed un valore N,
//sia in grado di individuare tra questi quelli che sono tra loro simili relativamente al valore K.
//Ovvero tutti quei cognomi che hanno un prefisso di lunghezza N in comune, ma non un prefisso di lunghezza N+1.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);
    string output;

    for(int i = 0; i < 1000; i++) {
        int n = 0;
        string cognome1, cognome2, cognome3;
        fin >> n >> cognome1 >> cognome2 >> cognome3;

        string subCognome1 = cognome1.substr(0, n);
        string subCognome2 = cognome2.substr(0, n);
        string subCognome3 = cognome3.substr(0, n);

        if(subCognome1 == subCognome2 && cognome1[n] != cognome2[n]) {
            fout << cognome1 << " " << cognome2;
            if(subCognome1 == subCognome3 && cognome1[n] != cognome3[n]) {
                fout << " " << cognome3;
            }
            fout << "\n";
        } else if(subCognome1 == subCognome3 && cognome1[n] != cognome3[n]) {
            fout << cognome1 << " " << cognome3 << "\n";
        } else if(subCognome2 == subCognome3 && cognome2[n] != cognome3[n]) {
            fout << cognome2 << " " << cognome3 << "\n";
        } else {
            fout << cognome1 << "\n";
        }
    }

}