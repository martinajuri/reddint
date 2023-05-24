#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class Arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo);
    void rid(nodo<T>* aux);
    void ird(nodo<T>* aux);
    void idr(nodo<T>* aux);
    void show(nodo<T>* aux, int n);

public:
    Arbol() { raiz = NULL; };
    ~Arbol() {};
    void CreaArbolBus(T x);
    void RID() { rid(raiz); }
    void IRD() { ird(raiz); }
    void IDR() { idr(raiz); }
    void VerArbol() { show(raiz, 0); }

};


