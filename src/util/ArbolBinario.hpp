/*
ARCHIVO DE LA CLASE "ArbolBinario"
    Modela una estructura de datos correspondiente a un arbol binario
        modificado para poder establecer un orden jerarquico que replique a un arbol
        N-ario y con funcionalidad menos general
CONSTRUCTORES
    + Constructor 1: Inicializa al objeto como una puntero nulo
METODOS PUBLICOS
    + Agregar: 
        Agrega una publicación al arbol (Recursividad por los hijo derechos de la raiz)
    + Comentar:
        Agrega un comentario a un post del arbol pidiendo el post y el coment. 
        (Encuentra el post, se va al hijo Izq y llama a Agregar)
    + Responder:
        Agrega una respuesta a un comentario de un post de un arbol pidiendo post, coment y respuesta.
        (Encuentra el post, se va al hijo Izq, encuentra el Coment, se va al hijo Izq y llama a Agregar)
    + Imprimir:
    + imprimirPublicacion:
    + BorrarPost:
    + participacionesDeUsuario:
    + ComentarioMasVotado:
    + UsuarioMasParticipativo:

*/

#include <iostream>
#include "..\Contenido.hpp"
#include "Nodo.hpp"
#include "List.hpp"


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
        Contenido* masVotado(Contenido* contenido1, Contenido* contenido2);
        Nodo<T>* nodoAlPost(Nodo<T>*& raizAux, Contenido* post);
        Usuario* usuarioMasParticipativo(Lista<Usuario*>* lista);
        Contenido* comentarioMasVotado(Nodo<T>*& raizAux);

    public:
        ArbolBinario() { raiz = NULL; };
        void crearContenido(){};
        void Responder(Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta){responder(raiz, postAComentar, comentarioAResponder, newRespuesta); postAComentar->agregarParticipante(newRespuesta->getUsuario());};
        void Comentar(Contenido* postAComentar, Contenido* newComentario){comentar(raiz, postAComentar, newComentario); postAComentar->agregarParticipante(newComentario->getUsuario());}
        void Agregar(Contenido* newPost){agregar(raiz,newPost);}
        void Imprimir(){imprimir(raiz);};
        void imprimirPublicacion(Contenido* post);
        void BorrarPost(Contenido* post){borrarPost(raiz, post);};
        int participacionesDeUsuario(Lista<Usuario*>* lista, Usuario* user);
        Contenido* ComentarioMasVotado(Contenido* post){
            nodoAux = nodoAlPost(raiz, post);
            if (nodoAux == NULL){
                cout << "No fue posible encontrar la publicacion"<<endl;
                return NULL;
            }
            return comentarioMasVotado(nodoAux->hijoIzq);
        };
        Usuario* UsuarioMasParticipativo(Contenido* post){
            nodoAux = nodoAlPost(raiz, post);
            if (nodoAux == NULL){
                cout << "No fue posible encontrar la publicacion"<<endl;
                return NULL;
            }
            return usuarioMasParticipativo(nodoAux->dato->getParticipantes());
        };
        

};
#endif
