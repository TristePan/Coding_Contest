//Si implementi una classe Coda, attraverso l'utilizzo dei template, contenente elementi di tipo generico H.
//La classe dovrà implementare la procedura di inserimento di un nuovo elemento e la procedura di stampa degli elementi in essa contenuti.
//La stampa dovrà essere effettuata procedendo dalla testa della Coda fino all'elemento che si trova nella sua ultima posizione.

#include <iostream>

using namespace std;

template <class H>
class Coda {
    private:
        int length;
        int ndim = 0;
        int testa = -1;
        int coda = -1;
        H *queue;

    public:
        Coda(int length) {
            this -> length = length;
            queue = new H[length];
        }

        bool isFull();
        bool isEmpty();
        void enqueue(H value);
        void dequeue();
        void print();


        ~Coda();
};

template <class H>
bool Coda<H> :: isFull() {
    if(ndim >= length)
        return true;
    else
        return false;
}

template <class H>
bool Coda<H> :: isEmpty() {
    if(ndim == 0)
        return true;
    else
        return false;
}

template <class H>
void Coda<H> :: enqueue(H value) {
    if(isFull())
        cout << "Coda piena" << endl;
    else {
        coda++;
        queue[coda%length] = value;
        ndim++;
        cout << "Inserimento avvenuto con successo" << endl;
    }
}

template <class H>
void Coda<H> :: dequeue() {
    if(isEmpty())
        cout << "Coda vuota" << endl;
    else {
        testa++;
        ndim--;
        cout << "Elemento rimosso" << endl;
    }
}

template <class H>
Coda<H> :: ~Coda() {
    delete [] queue;
}