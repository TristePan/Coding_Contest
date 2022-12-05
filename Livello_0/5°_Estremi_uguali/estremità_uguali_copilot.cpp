//Si fornisca un programma che date in input tre parole di lunghezza variabile sia in grado di individuare, tra queste, quelle caratterizzate dagli estremi uguali e di contarne il numero.

#include <iostream>
#include <string>
#include <fstream>  

using namespace std;

int main()
{
    string parola;
    int contatore = 0;
    ifstream in("input.txt");
    ofstream out("output.txt");
    while (in >> parola)
    {
        if (parola[0] == parola[parola.length() - 1])
        {
            contatore++;
        }
    }
    out << contatore;
    return 0;
}