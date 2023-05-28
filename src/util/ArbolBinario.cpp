#include "ArbolBinario.hpp"

using namespace std;

#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C


// Agrega una publicacion al arbol
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
        //newPost->usuario->agregarParticipacion(newPost);
    }
}

// Agrega un comentario a una  publicacion
template <class T> void ArbolBinario<T>:: comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario)
{
    if(raizAux->dato == postAComentar)
    {
        agregar(raizAux->hijoIzq, newComentario);
        postAComentar->agregarParticipante(newComentario->getUsuario());
    }
    else if(raizAux->dato == NULL)
    {
        cout << "No existe la publicacion a comentar" << endl;
    }
    else
    {
        comentar(raizAux->hijoDer, postAComentar, newComentario);
    }
}

// Agrega una respuesta a un comentario
template <class T> void ArbolBinario<T>:: responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta)
{
    if(raizAux->dato==postAComentar)
    {
        comentar(raizAux->hijoIzq, comentarioAResponder, newRespuesta);
    }
    else if(raizAux->dato == NULL)
    {
        cout << "No existe el comentario a responder" << endl;
    }
    else
    {
        responder(raizAux->hijoDer, postAComentar, comentarioAResponder, newRespuesta);
    }
}

// Borra una publicacion y todos sus comentarios y respuestas
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

// Imprime el arbol en orden rid
template <class T> void ArbolBinario<T>:: imprimir(Nodo<T>* raizAux)
{

    if (raizAux != NULL) {
        Contenido* contAux = raizAux->dato;
        contAux->imprimir();
        imprimir(raizAux->hijoIzq);
        imprimir(raizAux->hijoDer);
    }

}

//Devuelve un puntero al comentario mas votado.
template <class T> Contenido* ArbolBinario<T>::comentarioMasVotado(Nodo<T>*& raizAux){
    
    if (raizAux->hijoDer == NULL)
    {
        return raizAux->dato;
    }
    else{
        return masVotado(raizAux->dato, comentarioMasVotado(raizAux->hijoDer));
    }
}

//Devuelve un puntero al usuario mas participativo.
template <class T> Usuario* ArbolBinario<T>::usuarioMasParticipativo(Nodo<T>*& raizAux){
     if (raizAux != NULL) {
        return NULL;
        usuarioMasParticipativo(raizAux->hijoIzq);
        usuarioMasParticipativo(raizAux->hijoDer);
    }
    return NULL;
}


// Devuelve un puntero al contenido con mayor valoracion, si ambos son iguales devuelve el primero.
template <class T> Contenido* ArbolBinario<T>::masVotado(Contenido* contenido1, Contenido* contenido2){
    if(contenido1->getValoracion() < contenido2->getValoracion()) return contenido2;
    else if (contenido1->getValoracion() > contenido2->getValoracion()) return contenido1;
    else return contenido1;
}

//Devuelve un puntero al nodo que contiene la publicacion. Devuelve NULL si la publicacion no se encuentra
template <class T> Nodo<T>* ArbolBinario<T>::nodoAlPost(Nodo<T>*& raizAux, Contenido* post){
    if(raizAux->dato == post)
    {
        return raizAux;
    }
    else if(raizAux->hijoDer==NULL)
    {
        return NULL;
    }
    else
    {
       return nodoAlPost(raizAux->hijoDer, post);
    }
}

//Imprime una publicacion con su comentario mas votado, su usuario mas participativo y valoracion promedio??
template <class T> void ArbolBinario<T>::imprimirPublicacion(Contenido* post)
{
    post->imprimir();
    cout << "Comentario más votado: "; 
    ComentarioMasVotado(post).imprimir();
    cout<< endl;
    cout << "Usuario más participativo: ";
    UsuarioMasParticipativo(post).imprimirU();
    cout << endl;
    cout << "Valoración: " << post->getValoracion() << endl;
}
#endif

