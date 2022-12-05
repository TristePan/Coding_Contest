//Si fornisca un programma che dati in input tre nomi propri, maschili o femminili, trascritti con caratteri minuscoli, li ri-trascriva in output in modo che la prima lettera di ciascun nome sia in forma maiuscola.

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    string output;

    for(int i = 0; i < 100; i++) {
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        string nome1, nome2, nome3;
        fin >> nome1 >> nome2 >> nome3;
        
        n1 = nome1.length();
        n2 = nome2.length();
        n3 = nome3.length();
        
        nome1[0] = toupper(nome1[0]);
        nome2[0] = toupper(nome2[0]);
        nome3[0] = toupper(nome3[0]);
        fout << nome1 << " " << nome2 << " " << nome3 << "\n";
    }
}