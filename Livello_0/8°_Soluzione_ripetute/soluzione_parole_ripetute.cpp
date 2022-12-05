// Quindi, fornita una stringa in input, ottenuta dalla concatenazione di due copie della parola scelta da Alice,
//si produca in output quest'ultima parola.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    string output;

    for(int i = 0; i < 100; i++) {
        string parola;
        fin >> parola;

        fout << parola.substr(0, parola.length() / 2) << endl;
    }
}