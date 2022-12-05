#include <iostream>
#include <fstream>
#include <string>
#include "inserimento_in_coda.h"

using namespace std;

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    string tipo;
    int n;

    for(int i = 0; i < 100; i++) {
        in >> tipo;
        in >> n;
        int v = 0;
        string *valori = new string[n];
        for(int j = 0; j < n; j++) {
            in >> valori[v];
            v++;
        }

        if(tipo == "double") {
            Queue<double> coda(n);
            for(int j = 0; j < n; j++) {
                coda.enqueue(stod(valori[j]));
            }
            coda.stampa(out);
        } else if(tipo == "int" || tipo == "bool") {
            Queue<int> coda(n);
            for(int j = 0; j < n; j++) {
                coda.enqueue(stoi(valori[j]));
            }
            coda.stampa(out);
        } else {
            Queue<string> coda(n);
            for(int j = 0; j < n; j++) {
                coda.enqueue(valori[j]);
            }
            coda.stampa(out);
        }
    }

}