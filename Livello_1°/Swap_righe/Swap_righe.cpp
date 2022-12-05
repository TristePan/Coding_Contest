#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void bubble_sort(int *somme, int somma, int **matrice, int righe, int colonne, ostream& out) {
    int temp;
    int count = 0;
    for(int i = 0; i < righe - 1; i++) {
        for(int j = 0; j < righe - i - 1; j++) {
            if(somme[j] > somme[j + 1]) {
                count++;
                temp = somme[j];
                somme[j] = somme[j + 1];
                somme[j + 1] = temp;
            }
        }
    }

    out << count << endl;
    cout << count << endl;
}

void calcolo_somme(int **matrice, int righe, int colonne, ostream& out) {
    int *somme = new int[righe];
    int somma = 0;
    
    for(int j = 0; j < righe; j++) {
        somma = 0;
        for(int k = 0; k < colonne; k++) {
            //somma della prima riga
            somma += matrice[j][k];
        }
        somme[j] = somma;
    }
    bubble_sort(somme, somma, matrice, righe, colonne, out);
}

int main() {

    fstream in("input.txt", fstream::in);
    fstream out("output.txt", fstream::out);

    int righe;
    int colonne;

    for(int i = 0; i < 100; i++) {

        in >> righe;
        in >> colonne;

        int **matrice = new int *[righe];

        for(int z = 0; z < righe; z++) {
            matrice[z] = new int [colonne];
            for(int k = 0; k < colonne; k++) {
                in >> matrice[z][k];
            }
        }

        calcolo_somme(matrice , righe, colonne, out);
        delete [] matrice;
    }
}