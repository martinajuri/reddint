#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"
#include "Lista.hpp"

using namespace std;

template <class T> class  ArbolBinario 
{
    private:
        Nodo<T> * raiz, * nodoAux;
        //agregado, borrado e imprimido
        void agregar(Nodo<T>*& raizAux, Contenido* newPost);
        void comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario);
        void responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta);
        void borrarPost(Nodo<T>*& raizAux ,Contenido* post);
        void imprimir(Nodo<T>* raizAux);
        //metodos auxiliares
        Contenido* masVotado(Contenido* contenido1, Contenido* contenido2);
        Nodo<T>* nodoAlContenido(Nodo<T>*& raizAux, Contenido* post);
        //metodos para la consigna
        Usuario* usuarioMasParticipativo(Lista<Usuario*>* lista);
        Contenido* comentarioMasVotado(Nodo<T>*& raizAux);
        void participacionesPorUsuario(Nodo<Contenido>*& raizAux, Usuario* user, Lista<Contenido*>* lista);
        void ordenarParticipaciones(Lista<Contenido*>* lista);
        void imprimirPublicaciones(Nodo<T>*& raizAux);
        void imprimirNivel(Nodo<T>* raizAux);
        int participacionesDeUsuario(Lista<Usuario*>* lista, Usuario* user);

    public:
        ArbolBinario() { raiz = NULL; };

        //Metodos de adicion
        void Responder(Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta){responder(raiz, postAComentar, comentarioAResponder, newRespuesta); postAComentar->agregarParticipante(newRespuesta->getUsuario()); newRespuesta->setTitulo("Respuesta a: " + postAComentar->getTitulo());};
        void Comentar(Contenido* postAComentar, Contenido* newComentario){comentar(raiz, postAComentar, newComentario); postAComentar->agregarParticipante(newComentario->getUsuario());newComentario->setTitulo("Comentario a: " + postAComentar->getTitulo());}
        void Agregar(Contenido* newPost){agregar(raiz,newPost);}

        void Imprimir(){imprimir(raiz);};
        void ImprimirPublicacion(Contenido* post);
        void BorrarPost(Contenido* post){borrarPost(raiz, post);};
        Contenido* ComentarioMasVotado(Contenido* post);
        Usuario* UsuarioMasParticipativo(Contenido* post);
        void ImprimirParticipaciones(Usuario* user);
        void ImprimirPublicaciones(){imprimirPublicaciones(raiz);};
        void ImprimirNivel(Contenido* contenido)
        {
            Nodo<Contenido>* contenidoAux = nodoAlContenido(raiz, contenido)->hijoIzq;
            if(contenidoAux!=NULL) imprimirNivel(contenidoAux);
         };
        Contenido* buscarContenidoPorNumero(int p, int c, int r);
        Nodo<T>* NodoAlContenido(Nodo<T>*& raizAux, Contenido* post){if(raizAux==NULL) return nodoAlContenido(raiz, post);else return nodoAlContenido(raizAux,post);};
};
#endif
