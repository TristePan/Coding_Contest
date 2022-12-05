#include <iostream>
#include <fstream>

using namespace std;

template <typename H>
class Pila {
    private:
        int top = -1;
        H *stack;
        int length;
        int count;
    
    public:
        Pila(int length);

        void push(H value);
        H pop();
        H getTop() const;
        int getSize() const;
        bool isEmpty();
        bool isFull();
        void stampa(ostream& out);

        ~Pila() {
            delete [] stack;
        }

};

template <typename H>
Pila<H> :: Pila(int size) {
    stack = new H[size];
    length = size;
    top = -1;
    count = 0;
}

template <typename H>
int Pila<H> :: getSize() const {
    return count;
}

template <typename H>
void Pila<H> :: push(H value) {
    if(isFull()) {
        return;
    }
    stack[++top] = value;
}

template <typename H>
H Pila<H> :: pop() {
    if(isEmpty()) {
        return 0;
    }
    return stack[top--];
}

template <typename H>
H Pila<H> :: getTop() const {
    return stack[top];
}

template <typename H>
bool Pila<H> :: isEmpty() {
    return getSize() == 0;
}

template <typename H>
bool Pila<H> :: isFull() {
    return top == length - 1;
}

template <typename H>
void Pila<H> :: stampa(ostream& out) {
    for(int i = top; i >= 0; i--) {
        out << stack[i] << " ";
    }
    out << endl;
}