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

template <class T> void ArbolBinario<T>:: agregar(Nodo<T>*& raizAux, Contenido* newPost)
{
    if(raizAux == NULL)
    {
        raizAux = new Nodo<Contenido>(newPost);
    }
    else if (raizAux->hijoDer != NULL)
    {
       agregar(raizAux->hijoDer, newPost);
    }
    else
    {
        raizAux->hijoDer = new Nodo<Contenido>(newPost);
    }
}
template <class T> void ArbolBinario<T>:: comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario)
{
    if(raizAux->dato == postAComentar)
    {
        agregar(raizAux->hijoIzq, newComentario);
    }
    else if(raizAux->dato == NULL)
    {
        cout << "No existe el post a comentar" << endl;
    }
    else
    {
        comentar(raizAux->hijoDer, postAComentar, newComentario);
    }
}

template <class T> void ArbolBinario<T>:: responder(Nodo<T>* raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta)
{
    if(raizAux->dato==postAComentar)
    {
        comentar(raizAux->hijoIzq, comentarioAResponder, newRespuesta);
    }
    else if(raizAux->dato == NULL)
    {
        cout << "No es posible responder" << endl;
    }
    else
    {
        responder(raizAux->hijoDer, postAComentar, comentarioAResponder, newRespuesta);
    }
}


template <class T> bool ArbolBinario<T>::buscarPost(Nodo<T>* raizAux ,Contenido* post){

    if(raizAux->getDato() == post){
        return true;
    }
    else if (raizAux == NULL){
        return false;
    }
    else{
        return buscarPost(raizAux->getHijoDer(), post);
    }

}

template <class T> void ArbolBinario<T>::borrarPost(Nodo<T>*& raizAux ,Contenido* post){

    if(raizAux->getDato() == post){
       if(raizAux->getHijoDer() == NULL) delete raizAux;
       else
       {
            Nodo<T>* nodoAux = raizAux->getHijoDer();
            raizAux = nodoAux;
            delete nodoAux; // queda el puntero del post borrado apuntando a su derecha
       }
    }
    else if (raizAux == NULL){
        cout << "No se encontro el post" << endl;
    }
    else{
        borrarPost(raizAux->getHijoDer(), post);
    }
}
template <class T> void ArbolBinario<T>:: imprimir(Nodo<T>* raizAux)
{

    if (raizAux != NULL) {
        Contenido* contAux = raizAux->dato;
        contAux->imprimir();
        imprimir(raizAux->hijoIzq);
        imprimir(raizAux->hijoDer);
    }

}

#endif

