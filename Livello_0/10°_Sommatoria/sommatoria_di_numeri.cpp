#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;

    for (int i = 0; i < 101; i++) {
        in >> n;

        double somma = 0;

        for (int j = 0; j < n; j++) {
            double numero;
            in >> numero;
            somma += numero;
        }
        out << somma << endl;
    }
    
}