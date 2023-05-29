#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"
#include "List.hpp"


using namespace std;
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

template <class T> class  ArbolBinario 
{
    private:
        Nodo<T> * raiz, * nodoAux;
        void agregar(Nodo<T>*& raizAux, Contenido* newPost);
        void imprimir(Nodo<T>* raizAux);
        void comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario);
        void responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta);
        void borrarPost(Nodo<T>*& raizAux ,Contenido* post);
        Contenido* masVotado(Contenido* contenido1, Contenido* contenido2);
        Nodo<T>* nodoAlPost(Nodo<T>*& raizAux, Contenido* post);
        Usuario* usuarioMasParticipativo(Lista<Usuario*>* lista);
        Contenido* comentarioMasVotado(Nodo<T>*& raizAux);
        Lista<Contenido*> participacionesPorUsuario(Nodo<Contenido*>*& raizAux, Usuario* user, Lista<Contenido*>* lista);
        void ordenarParticipaciones(Lista<Contenido*>* lista);

    public:
        ArbolBinario() { raiz = NULL; };
        void crearContenido(){};
        void Responder(Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta){responder(raiz, postAComentar, comentarioAResponder, newRespuesta); postAComentar->agregarParticipante(newRespuesta->getUsuario());};
        void Comentar(Contenido* postAComentar, Contenido* newComentario){comentar(raiz, postAComentar, newComentario); postAComentar->agregarParticipante(newComentario->getUsuario());}
        void Agregar(Contenido* newPost){agregar(raiz,newPost);}
        void Imprimir(){imprimir(raiz);};
        void ImprimirPublicacion(Contenido* post);
        void BorrarPost(Contenido* post){borrarPost(raiz, post);};
        int participacionesDeUsuario(Lista<Usuario*>* lista, Usuario* user);
        Contenido* ComentarioMasVotado(Contenido* post);
        Usuario* UsuarioMasParticipativo(Contenido* post);
        void ImprimirParticipaciones(Usuario* user);
        
};
#endif
