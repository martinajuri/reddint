#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"


using namespace std;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

template <class T> class ArbolBinario {
private:
    Nodo<T> * raiz, * q;
    void rid(Nodo<T>* aux);
    void show(Nodo<T>* aux, int n);

public:
    ArbolBinario() { raiz = NULL; };
    void crearContenido(){};
    void RID() { rid(raiz); }
    void VerArbol() { show(raiz, 0); }
    void responder(Nodo<T>* raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta);
    void comentar(Nodo<T>* raizAux, Contenido* postAComentar, Contenido* newComentario);
    void agregar(Nodo<T>* raizAux, Contenido* newPost);
    void Agregar(Contenido*newPost){agregar(raiz,newPost);}
    bool buscarPost(Nodo<T>* raizAux ,Contenido* post);
    void borrarPost(Nodo<T>*& raizAux ,Contenido* post);
    void imprimir(Nodo<Contenido*>* raizAux);
    void Imprimir(){imprimir(raiz);};
};
#endif
