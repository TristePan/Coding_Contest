#include <fstream>
#include <string>
#include <iostream>
#include "Insert_BST.h"

using namespace std;

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    string tipo;
    int n;
    string ordine;

    for(int i = 0; i < 100; i++) {
        in >> tipo;
        in >> n;
        in >> ordine;

        string *valori = new string[n];
        for(int j = 0; j < n; j++) {
            in >> valori[j];
        }

        if(tipo == "int" || tipo == "bool") {
            BST<int> albero;
            for(int z = 0; z < n; z++) {
                albero.inserimento(stoi(valori[z]));
            }
            if(ordine == "postorder") {
                albero.PostOrder(out);
            } else if(ordine == "inorder"){
                albero.InOrder(out);
            } else {
                albero.PreOrder(out);
            }
            out << endl;
        } else if(tipo == "char") {
            BST<char> albero;
            for(int z = 0; z < n; z++) {
                albero.inserimento(valori[z][0]);
            }
            if(ordine == "postorder") {
                albero.PostOrder(out);
            } else if(ordine == "inorder"){
                albero.InOrder(out);
            } else {
                albero.PreOrder(out);
            }
            out << endl;
        } else {
            BST<double> albero;
            for(int z = 0; z < n; z++) {
                albero.inserimento(stod(valori[z]));
            }
            if(ordine == "postorder") {
                albero.PostOrder(out);
            } else if(ordine == "inorder"){
                albero.InOrder(out);
            } else {
                albero.PreOrder(out);
            }
            out << endl;
        }
        delete [] valori;
    }
}