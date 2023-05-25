#include "ArbolBinario.hpp"

using namespace std;

#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C



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

template <class T> void ArbolBinario<T>:: responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta)
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

    if(raizAux->dato == post){
        return true;
    }
    else if (raizAux == NULL){
        return false;    }
    else{
        return buscarPost(raizAux->hijoDer, post);
    }

}

template <class T> void ArbolBinario<T>::borrarPost(Nodo<T>*& raizAux ,Contenido* post){

    if(raizAux->dato == post){
       if(raizAux->hijoDer == NULL) delete raizAux;
       else
       {
            nodoAux = raizAux;
            raizAux = nodoAux->hijoDer;
            delete nodoAux; // queda el puntero del post borrado apuntando a su derecha
       }
    }
    else if (raizAux == NULL){
        cout << "No se encontro el post" << endl;
    }
    else{
        borrarPost(raizAux->hijoDer, post);
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

