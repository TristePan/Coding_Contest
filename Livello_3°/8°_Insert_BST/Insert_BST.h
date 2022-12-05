#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename H>
class Node {
    public:
        H valore;
        Node<H> *parent;
        Node<H> *left;
        Node<H> *right;
};

template <typename H>
class BST {
    private:
        Node<H> *radice;

        void InOrder(Node<H> *p, ostream& out) const;
        void PreOrder(Node<H> *p, ostream& out) const;
        void PostOrder(Node<H> *p, ostream& out) const;

    public:
        BST() : radice(nullptr) {}

        void InOrder(ostream& out) const;
        void PreOrder(ostream& out) const;
        void PostOrder(ostream& out) const;

        void inserimento(H val);

        Node<H>* getRadice() const;




};

//FUNZIONI PRIVATE
template <typename H>
void BST<H> :: InOrder(Node<H> *p, ostream& out) const {
    if(p != nullptr) {
        InOrder(p -> left, out);
        out << p -> valore << " ";
        InOrder(p -> right, out);
    }
}

template <typename H>
void BST<H> :: PreOrder(Node<H> *p, ostream& out) const {
    if(p != nullptr) {
        out << p -> valore << " ";
        PreOrder(p -> left, out);
        PreOrder(p -> right, out);
    }
}

template <typename H>
void BST<H> ::PostOrder(Node<H> *p, ostream& out) const {
    if(p != nullptr) {
        PostOrder(p -> left, out);
        PostOrder(p -> right, out);
        out << p -> valore << " ";
    }
}


//FUNZIONI PUBBLICHE
template <typename H>
void BST<H> :: InOrder(ostream& out) const {
    InOrder(radice, out);
}

template <typename H>
void BST<H> :: PreOrder(ostream& out) const {
    PreOrder(radice, out);
}

template <typename H>
void BST<H> :: PostOrder(ostream& out) const {
    PostOrder(radice, out);
}

template <typename H>
void BST<H> :: inserimento(H val) {
    Node<H> *nuovo = new Node<H>;
    nuovo -> valore = val;
    nuovo -> left = nuovo -> right = nullptr;
    Node<H> *x = radice;
    Node<H> *y = nullptr;

    while(x != nullptr) {
        y = x;
        if(val <= x -> valore) {
            x = x -> left;
        } else {
            x = x -> right;
        }
    }

    nuovo -> parent = y;
    if(y == nullptr) {
        this -> radice = nuovo;
    } else if(val <= y -> valore) {
        y -> left = nuovo;
    } else {
        y -> right = nuovo;
    }
}

template <typename H>
Node<H>* BST<H> :: getRadice() const {
    return radice;
}