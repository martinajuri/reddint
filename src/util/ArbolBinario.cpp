#include <cstdlib>
#include <iostream>
#include <sstream>
#include "ArbolBinario.hpp"

using namespace std;


template <class T> void ArbolBinario<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}
template <class T> void ArbolBinario<T>::ArbolBusq(T x, Nodo<T>*& nuevo)
{
    if (nuevo == NULL) {
        nuevo = new Nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}
template <class T> void ArbolBinario<T>::ird(Nodo<T>* aux)
{
    if (aux != NULL) {
        ird(aux->izq);
        cout << "\n" << aux->info;
        ird(aux->der);
    }
}
template <class T> void ArbolBinario<T>::rid(Nodo<T>* aux)
{
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}
template <class T> void ArbolBinario<T>::idr(Nodo<T>* aux)
{
    if (aux != NULL) {
        idr(aux->izq);
        idr(aux->der);
        cout << "\n" << aux->info;
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



template <class T> bool ArbolBinario<T>::esta(Nodo<T>* aux, T x)
{
    if (aux == NULL) return false;
    else if (x > aux->info) return esta(aux->der, x);
    else if (x < aux->info) return esta(aux->izq, x);
    return true;

}


template <class T> void ArbolBinario<T>::mh(Nodo<T>* aux)
{
    if (aux != NULL) {
        mh(aux->izq);
        if (aux->izq == NULL && aux->der == NULL)cout << "\n" << aux->info;
        mh(aux->der);
    }
}


template <class T> T ArbolBinario<T>::menor(Nodo<T>* aux)
{
    if (aux->izq == NULL)return aux->info;
    return menor(aux->izq);
}


template <class T> void ArbolBinario<T>::borrar(Nodo<T>*& p, T x)
{
    if (p == NULL) cout << "\n El dato NO esta\n\n";
    else if (x > p->info) borrar(p->der, x);
    else if (x < p->info) borrar(p->izq, x);
    else {// lo encontre en el Nodo p
        q = p;
        if (q->der == NULL) p = q->izq;// raiz<=raiz del subarbol izq
        else if (q->izq == NULL) p = q->der;//raiz<=raiz del subarbol der
        else bor(q->izq);//busca en el sub arbol izq
        delete q;
    }
}
template <class T> void ArbolBinario<T>::bor(Nodo<T>*& d)
{
    if (d->der != NULL) bor(d->der);//busca el elemento mas a la derecha
    else {
        q->info = d->info;
        q = d;
        d = d->izq;
    }
}