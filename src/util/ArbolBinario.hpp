#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"


using namespace std;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

template <class T> class ArbolBinario {
private:
    Nodo<T> *raiz;
    void postear(T dato, Nodo<T>* raizPivote);
public:
    ArbolBinario(){raiz = nullptr;}
    void Postear(T dato);
    void imprimirPrimerNivel(Nodo<T>* raizPivote);
    void ImprimirPrimerNivel();
};
#endif
