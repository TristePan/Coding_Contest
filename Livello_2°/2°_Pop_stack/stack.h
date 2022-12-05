#include <iostream>
#include <fstream>

using namespace std;

template <typename H>
class nodo {
    public:
        nodo* succ;
        H val;
};

template <typename H>
class stack {
    private:
        nodo<H>* top;
    public:

        stack();

        nodo<H>* getTop();
        void push(H val);
        int pop();
        void stampa(ostream& out);

        ~stack();
};

template <typename H>
stack<H> :: stack() {
    top = nullptr;
}

template <typename H>
nodo<H>* stack<H> :: getTop() {
    return top;
}

template <typename H>
void stack<H> :: push(H val) {
    nodo<H>* nuovo = new nodo<H>;
    nuovo -> val = val;
    nuovo -> succ = top;
    top = nuovo;
}

template <typename H>
int stack<H> :: pop() {
    nodo<H>* temp = top;
    if(temp == nullptr) {
        cout << "STACK UNDERFLOW\n\nreturn ";
        return 0;
    }
    top = top -> succ;
    delete temp;
}

template <typename H>
void stack<H> :: stampa(ostream& out) {
    nodo<H>* temp = top;
    while(temp != nullptr) {
        out << temp -> val << " ";
        temp = temp -> succ;
    }
    out << endl;
}

template <typename H>
stack<H> :: ~stack() {
    while (top != nullptr) {
        nodo<H>* temp = top;
        top = top -> succ;
        delete temp;
    }
}
