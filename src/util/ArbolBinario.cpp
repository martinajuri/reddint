#include "ArbolBinario.hpp"

using namespace std;

#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C


// Agrega una publicacion al arbol
template <class T> void ArbolBinario<T>:: agregar(Nodo<T>*& raizAux, Contenido* newPost)
{
    if(raizAux == NULL) //si aun no hay ningun nodo con puntero a post, lo crea y es la raiz 
    {
        raizAux = new Nodo<Contenido>(newPost);
    }
    else if (raizAux->hijoDer != NULL) //si hay ya un nodo-*post, ejecuta el agregar en ese
    {
       agregar(raizAux->hijoDer, newPost);
    }
    else //si no hay nodo-*post en el derecho, lo crea
    {
        raizAux->hijoDer = new Nodo<Contenido>(newPost);
        //newPost->usuario->agregarParticipacion(newPost);
    }
}

// Agrega un comentario a una  publicacion
template <class T> void ArbolBinario<T>:: comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario)
{
    if(raizAux->dato == postAComentar) //si el post que se quiere comentar coincide con el de la raiz(aux)
    {
        agregar(raizAux->hijoIzq, newComentario); //Agrega al subarbol del hijo izquierdo el comentario
    }
    else if(raizAux->dato == NULL && raizAux->hijoDer == NULL)  //Si no encuentra el post y ya no hay mas nodos a la derecha
    {
        cout << "No existe la publicacion a comentar" << endl; //OJO, REVER
    }
    else    //si no se encontro en la raiz se sigue con el siguiente post
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
template <class T> Usuario* ArbolBinario<T>::usuarioMasParticipativo(Lista<Usuario*>* lista){
    if (lista->resto() == NULL)
    {
        return lista->cabeza();
    }
    else if (participacionesDeUsuario(lista, lista->cabeza())>participacionesDeUsuario(lista, usuarioMasParticipativo(lista->resto()))){
        return lista->cabeza();
    }
    else{
        return usuarioMasParticipativo(lista->resto());
    }
    
}

//Devuelve la cantidad de participaciones de un usuario.
template <class T> int ArbolBinario<T>::participacionesDeUsuario(Lista<Usuario*>* lista, Usuario* user){
    if(lista->esvacia()|| lista == NULL){
        return 0;
    }
    else if (lista->cabeza() == user) {
        return 1 + participacionesDeUsuario(lista->resto(), user);
    }
    else{
        return participacionesDeUsuario(lista->resto(), user);

    }

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
    cout << "Comentario más votado: "<<endl; 
    ComentarioMasVotado(post)->imprimir();
    cout<< endl;
    cout << "Usuario más participativo: ";
    UsuarioMasParticipativo(post)->imprimir();
    cout << endl;
}
#endif

