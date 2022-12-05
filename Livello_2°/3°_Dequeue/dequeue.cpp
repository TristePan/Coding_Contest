#include <iostream>
#include <fstream>

using namespace std;

template <typename H>
class Coda {
private :
H *arr;
int capacita;
int fronte;
int count;
int fine;

public :
Coda(int size) {
    capacita = size;
    arr = new H [capacita];
    fronte = 0;
    count = 0;
    fine = -1;
}

int getCount() const {
    return count;
}

//bool isEmpty() {return getCount() == 0;}

//bool isFull() {return getCount() == capacita;}

void enqueue(H x) {
    //if (isFull()) cout << "Coda Piena !" << endl;
    fine = (fine + 1) % capacita;
    arr[fine] = x;
    count ++;
}

void dequeue(H x) {
    //if (isEmpty()) cout << "Coda Vuota !" << endl;
    fronte = (fronte + 1) % capacita;
    count --;
} 

H getFronte() {
    return arr[fronte];
}

void stampa(ostream& out) {
    for (int i=fronte; i<=fine; i++) {
        out << arr[i] << " ";
    }
    out << endl;
}

};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string tipo;
    int n;
    
    for (int i=0; i<1; i++) {
        in >> tipo;
        in >> n;
        //int v = 0;
        string *valori = new string [n];
        for (int j=0; j<n; j++) {
            in >> valori[j];
            //v++;
        }
        if (tipo == "int" || tipo == "bool") {
            Coda<int> C(n);
            for (int z=0; z<n; z++) {
                if (valori[z][0] == 'i') {
                    string tmp;
                    for (int s=1; s<valori[z].size(); s++) {
                        tmp += valori[z][s];
                    }
                    int t = stoi(tmp);
                    C.enqueue(t);
                }
                else {
                    C.dequeue(C.getFronte());
                }
            }
            C.stampa(out);
        }
        else if (tipo == "double") {
            Coda<double> C(n);
            for (int z=0; z<n; z++) {
                if (valori[z][0] == 'i') {
                    string tmp;
                    for (int s=1; s<valori[z].size(); s++) {
                        tmp += valori[z][s];
                    }
                    double t = stod(tmp);
                    C.enqueue(t);
                }
                else {
                    C.dequeue(C.getFronte());
                }
            }
            C.stampa(out);
        }
        else {
            Coda<string> C(n);
            for (int z=0; z<n; z++) {
                if (valori[z][0] == 'i') {
                    string tmp;
                    for (int s=1; s<valori[z].size(); s++) {
                        tmp += valori[z][s];
                    }
                    C.enqueue(tmp);
                }
                else {
                    C.dequeue(C.getFronte());
                }
            }
            C.stampa(out);
        }
        delete [] valori;
    }
}