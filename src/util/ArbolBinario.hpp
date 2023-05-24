#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Contenido.hpp"
#include "Nodo.hpp"

using namespace std;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

template <class T> class ArbolBinario {
private:
    Nodo<T> * raiz, * q;
    void ArbolBusq(T x, Nodo<T>*& nuevo);
    void rid(Nodo<T>* aux);
    void show(Nodo<T>* aux, int n);
    void borrar(Nodo<T>*& p, T x);

public:
    ArbolBinario() { raiz = NULL; };
    void crearContenido();
    void buscar(Nodo<>);
    void RID() { rid(raiz); }
    void VerArbol() { show(raiz, 0); }
    void Borrar(T x) { borrar(raiz, x); }

};
#endif
