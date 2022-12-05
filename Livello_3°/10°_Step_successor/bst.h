#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename H>
class Node {
    public:
        H valore;           // valore nodo
        Node<H> *parent;    // sottoalbero sinistro
        Node<H> *left;      // sottoalbero destro
        Node<H> *right;     // padre nodo
        
        Node(H valore) : valore(valore) // costruttore
        {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void setLeft(Node<H> *left) // modifica sottoalbero sinistro
        {
            this -> left = left;
        }

        void setRight(Node<H> *right) // modifica sottoalbero destro
        {
            this->right = right;
        }

        void setParent(Node<H> *parent) // modifica padre
        {
            this->parent = parent;
        }

        Node<H> *getLeft() // ritorna sottoalbero sinistro
        {
            return this->left;
        }

        Node<H> *getRight() // ritorna sottoalbero destro
        {
            return this->right;
        }

        Node<H> *getParent() // ritorna padre
        {
            return this->parent;
        }

        void setKey(H key) // modifica chiave
        {
            this->key = key;
        }

        H getKey()
        {
            return this->key; // ritorna chiave
        }

        friend std::ostream &operator<<(std::ostream &out, Node<H> &node) // operatore <<
        {
            out << "key = " << node.valore;
            return out;
        }
};

template <typename H>
class BST {
    private:
        int count = 0;
        Node<H> *radice;    // radice
    public:
        BST();

        Node<H>* search(H val);
        Node<H>* search(Node<H> *ptr, H val);

        void clear();

        bool isEmpty();

        void visit(Node<H> *node);
        
        void inserimento(H val);
        void inserimento(Node<H>* aux, H val);

        Node<H>* minimo();
        Node<H>* minimo(Node<H> *nodo);

        Node<H>* successore();
        Node<H> *successore(Node<H> *nodo);

        int step_successor(H val);

        Node<H>* getRadice();


        Node<H>* remove(Node<H>* aux);
        Node<H>* remove(H key);
};

//FUNZIONI PUBBLICHE

template <typename H>
BST<H>::BST() {
    radice = nullptr;
}

template <typename H>
Node<H>* BST<H> :: search(H val) {
    return search(radice, val);
}
template <typename H>
Node<H>* BST<H> :: search(Node<H> *aux, H val) {
    if(aux == nullptr) {
        cout << "Non ho trovato " << val << endl;
        return nullptr;
    }

    if(aux -> valore == val)
        return aux;

    if(val <= aux -> valore)
        return search(aux -> left, val);
    else
        return search(aux -> right, val);

    return nullptr;
}

template <typename H>
void BST<H> :: clear() {
    radice = nullptr;
}

template <typename H>
bool BST<H> :: isEmpty() {
    return radice == nullptr;
}

template <typename H>
void BST<H> :: visit(Node<H> *node) {
    cout << *node << " ";
}

template <typename H>
void BST<H> :: inserimento(H val) {
    if(isEmpty()) {
        radice = new Node<H>(val);
        return;
    }
    inserimento(radice, val);
}
template <typename H>
void BST<H> :: inserimento(Node<H>* aux, H val) {
    if (aux -> left == nullptr && val <= aux -> valore)
        {
            aux -> left = new Node<H>(val);
            aux -> left->setParent(aux);
            return;
        }
        if (aux -> right == nullptr && val > aux -> valore)
        {
            aux -> right = new Node<H>(val);
            aux -> right -> parent = aux;
            return;
        }
        else if (val <= aux -> valore)
            inserimento(aux -> left, val);
        else
            inserimento(aux -> right, val);
}

template <typename H>
Node<H>* BST<H> :: minimo() {
    return minimo(radice);
}
template <typename H>
Node<H>* BST<H> :: minimo(Node<H> *nodo) {
    if (isEmpty())
        {
            return NULL;
        }

        Node<H> *aux = nodo;
        while (aux -> left)
        {
            count++;
            aux = aux -> left;
        }

        return aux;
}

template <typename H>
Node<H>* BST<H> :: successore() {
    return successore(radice);
}
template <typename H>
Node<H>* BST<H> :: successore(Node<H> *nodo) {
    if (this -> isEmpty()) {
        return nullptr;
    }

    // 1. x ha un sottoalbero destro

    if (nodo -> right) {
        count++;
        return this -> minimo(nodo -> right);
    }

    // 2. x non ha un sottoalbero destro
    // il successore di x è l'antenato più prossimo di x
    // il cui figlio sinistro è anche un antenato di x

    Node<H> *y = nodo -> parent;
    count++;
    while (y != nullptr && nodo == y -> right) {
        count++;
        nodo = y;
        y = y->parent;
    }

    return y;
}

template <typename H>
int BST<H> :: step_successor(H key) {
    count = 0;
    Node<H>* aux = search(key);
    aux = successore(aux);
    if(aux == nullptr) {
        return -1;
    }
    return count;
}

template <typename H>
Node<H>* BST<H> :: getRadice() {
    return this -> radice;
}

template <typename H>
Node<H>* BST<H> :: remove(Node<H> *aux) {

    // CASO 1
    if (aux == radice && !(aux -> left) && !(aux -> right)) {
        radice = nullptr;
        return aux;
    }

    if (!(aux -> left) && !(aux -> right)) {
        if (aux == aux -> parent -> left) {
            aux -> parent -> left = nullptr;
            return aux;
        }
        else {
            aux -> parent -> right = nullptr;
            return aux;
        }
    }

    // CASO 2
    if (aux == radice && aux -> left && !(aux -> right)) {
        aux -> left -> parent = nullptr;
        radice = aux -> left;
        return aux;
    }

    if (aux == radice && !(aux -> left) && aux -> right) {
        aux -> right -> parent = nullptr;
        radice = aux -> right;
        return aux;
    }

    if (aux -> left && !(aux -> right)) {
        aux -> left -> parent = aux -> parent;
        if (aux == aux -> parent -> left) {
            aux -> parent -> left = aux -> left;
            return aux;
        }
        else {
            aux -> parent -> right = aux -> left;
            return aux;
        }
    }

    if (!(aux -> left) && aux -> right) {
        aux -> right -> parent = aux -> parent;
        if (aux == aux -> parent -> left) {
            aux -> parent -> left = aux -> right;
            return aux;
        }
        else {
            aux -> parent -> right = aux -> right;
            return aux;
        }
    }

    return nullptr;
}
template <typename H>
Node<H>* BST<H> :: remove(H val) {
    if (this -> isEmpty())
        return nullptr;
    Node<H> *toDelete = search(val);

    if (!toDelete)
        return nullptr;

    Node<H> *toRemove = remove(toDelete);
    if (toRemove)
        return toRemove;

    Node<H> *next = successore(toDelete);
    H swap = toDelete -> valore;
    toDelete -> valore = next -> valore;
    next -> valore = swap;

    toRemove = remove(next);
    return toRemove;
}