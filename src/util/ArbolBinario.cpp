#include <cstdlib>
#include <iostream>
#include <sstream>
#include "ArbolBinario.hpp"
using namespace std;



template <class T> void ArbolBinario<T>::rid(Nodo<T>* aux)
{
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}

template <class T> void ArbolBinario<T>::show(Nodo<T>* aux, int n)
{
    int i;
    if (aux != NULL) {                      //OjO este es un recorrido dri
        show(aux->der, n + 1);
        for (i = 1; i <= n; i++) cout << "     ";
        cout << aux->info << "\n";
        show(aux->izq, n + 1);
    }
}

template <class T> void ArbolBinario<T>::show(Nodo<T>* aux, int n)


