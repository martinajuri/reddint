#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.hpp"

using namespace std;


template <class T> class ArbolBinario {
private:
    Nodo<T>* raiz, * q;
    void ArbolBusq(T x, Nodo<T>*& nuevo);
    void rid(Nodo<T>* aux);
    void ird(Nodo<T>* aux);
    void idr(Nodo<T>* aux);
    void show(Nodo<T>* aux, int n);

    void borrar(Nodo<T>*& p, T x);
    void bor(Nodo<T>*& d);
    void mh(Nodo<T>* aux);
    T menor(Nodo<T>* aux);
    bool esta(Nodo<T>* aux, T x);

public:
    ArbolBinario() { raiz = NULL; };
    ~ArbolBinario() {};
    void CreaArbolBus(T x);
    void RID() { rid(raiz); }
    void IRD() { ird(raiz); }
    void IDR() { idr(raiz); }
    void VerArbol() { show(raiz, 0); }
    void Borrar(T x) { borrar(raiz, x); }
    void MostrarHojas() { mh(raiz); }
    T Menor() { return menor(raiz); }
    bool Esta(T x) { return esta(raiz, x); }
};

