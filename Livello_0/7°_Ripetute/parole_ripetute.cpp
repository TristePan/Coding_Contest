//fornita una parola in input si produca in output una stringa formata dalla stessa parola concatenata con se stessa,
//ovvero ripetuta due volte.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    for(int i = 0; i < 100; i++) {
        string parola;
        fin >> parola;

        fout << parola + parola << endl;
    }
}