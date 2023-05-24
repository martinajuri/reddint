#include "ArbolBinario.hpp"
using namespace std;
#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C


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

template <class T> void ArbolBinario<T>:: postear(Nodo<T>* raizAux, Posteo* newPost)
{
    if(raizAux == NULL)
    {
        raizAux = new Nodo<T>(newPost);
    }
    else
    {
        postear(raizAux->getHijoDer(), newPost);
    }
}
template <class T> void ArbolBinario<T>:: comentar(Nodo<T>* raizAux, Posteo* postAComentar, Contenido* newComentario)
{
    if(raizAux->getDato() == postAComentar)
    {
           if(raizAux->getHijoIzq() == NULL)
        {
        raizAux->setHijoIzq(new Nodo<T>(newComentario));
        }
        else
        {
        postear(raizAux->getHijoDer(), newPost);
        } 
    }
}
#endif

