#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"


using namespace std;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

template <class T> class  ArbolBinario {
private:
    Nodo<T> * raiz, * nodoAux;
    void agregar(Nodo<T>*& raizAux, Contenido* newPost);
    void imprimir(Nodo<T>* raizAux);
    void comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario);
    void responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta);
    void borrarPost(Nodo<T>*& raizAux ,Contenido* post);

public:
    ArbolBinario() { raiz = NULL; };
    void crearContenido(){};
    void Responder(Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta){responder(raiz, postAComentar, comentarioAResponder, newRespuesta);};
    void Comentar(Contenido* postAComentar, Contenido* newComentario){comentar(raiz, postAComentar, newComentario);}
    void Agregar(Contenido* newPost){agregar(raiz,newPost);}
    bool buscarPost(Nodo<T>* raizAux ,Contenido* post);
    void Imprimir(){imprimir(raiz);};
    void BorrarPost(Contenido* post){borrarPost(raiz, post);};

};
#endif
