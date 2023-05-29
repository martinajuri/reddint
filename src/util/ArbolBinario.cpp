#include "ArbolBinario.hpp"

using namespace std;

#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C

//---------------------------------------------PRIVADOS DE AGREGADO----------------------------------------------------------------------------------------
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

//------------------------------------------------PRIVADOS DE CONSIGNA-------------------------------------------------------------------------------------
// Borra una publicacion y todos sus comentarios y respuestas
template <class T> void ArbolBinario<T>::borrarPost(Nodo<T>*& raizAux ,Contenido* post)
{
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
template <class T> Contenido* ArbolBinario<T>::comentarioMasVotado(Nodo<T>*& raizAux)
{
    if (raizAux->hijoDer == NULL)
    {
        return raizAux->dato;
    }
    else{
        return masVotado(raizAux->dato, comentarioMasVotado(raizAux->hijoDer));
    }
}

//Devuelve un puntero al usuario mas participativo.
template <class T> Usuario* ArbolBinario<T>::usuarioMasParticipativo(Lista<Usuario*>* lista)
{
    if (lista->resto() == NULL)
    {
        return lista->cabeza();
    }
    else if (participacionesDeUsuario(lista, lista->cabeza())>participacionesDeUsuario(lista, usuarioMasParticipativo(lista->resto())))
    {
        return lista->cabeza();
    }
    else{
        return usuarioMasParticipativo(lista->resto());
    }
}

//Devuelve la cantidad de participaciones de un usuario.
template <class T> int ArbolBinario<T>::participacionesDeUsuario(Lista<Usuario*>* lista, Usuario* user)
{
    if (user!=NULL)
    {
        if(lista->esvacia()|| lista == NULL)
        {
            return 0;
        }
        else if (lista->cabeza() == user) 
        {
            return 1 + participacionesDeUsuario(lista->resto(), user);
        }
        else{
            return participacionesDeUsuario(lista->resto(), user);
        }
    }
}

// //Devuelve las participaciones de un usuario.
// template <class T> Lista<Contenido*> ArbolBinario<T>::participacionesPorUsuario(Nodo<Contenido*>*& raizAux, Usuario* user, Lista<Contenido*>* lista)
// {
//     if (user != NULL && raizAux != NULL)
//     {
//        if(raizAux->dato->getUsuario()==user)
//        {
//             lista->add(*raizAux->dato);
//        }
//         participacionesPorUsuario(raizAux->hijoIzq, user, lista);
//         participacionesPorUsuario(raizAux->hijoDer, user, lista);
//     }
// }

// //Ordena la lista por orden de publicacion
// template <class T> void ArbolBinario<T>:: ordenarParticipaciones(Lista<Contenido*>* lista)
// {
//     if(!lista->esvacia()){
//         //llamar al metodo elegido
//     }
// }

//-----------------------------------------------PRIVADOS EXTRA--------------------------------------------------------------------------------------
// Devuelve un puntero al contenido con mayor valoracion, si ambos son iguales devuelve el primero.
template <class T> Contenido* ArbolBinario<T>::masVotado(Contenido* contenido1, Contenido* contenido2)
{
    if(contenido1->getValoracion() < contenido2->getValoracion()) return contenido2;
    else if (contenido1->getValoracion() > contenido2->getValoracion()) return contenido1;
    else return contenido1;
}

//Devuelve un puntero al nodo que contiene la publicacion. Devuelve NULL si la publicacion no se encuentra
template <class T> Nodo<T>* ArbolBinario<T>::nodoAlPost(Nodo<T>*& raizAux, Contenido* post)
{
    if(raizAux->dato == post)
    {
        return raizAux;
    }
    else if(raizAux->hijoDer==NULL)
    {
        return NULL;
    }
    else{
       return nodoAlPost(raizAux->hijoDer, post);
    }
}

//-------------------------------------------------PUBLICOS------------------------------------------------------------------------------------
//Metodo Publico: devuelve el comentario mas votado de un post
template <class T> Contenido* ArbolBinario<T>::ComentarioMasVotado(Contenido* post)
{
    nodoAux = nodoAlPost(raiz, post);
    if (nodoAux == NULL)
    {
        cout << "No fue posible encontrar la publicacion"<<endl;
        return NULL;
    }
    return comentarioMasVotado(nodoAux->hijoIzq);   
}

//Metodo Publico: devuelve el usuario que mas participo en un post
template <class T> Usuario* ArbolBinario<T>::UsuarioMasParticipativo(Contenido* post)
{
    nodoAux = nodoAlPost(raiz, post);
    if (nodoAux == NULL)
    {
        cout << "No fue posible encontrar la publicacion"<<endl;
        return NULL;
    }
    return usuarioMasParticipativo(nodoAux->dato->getParticipantes());
};

//Imprime una publicacion con su comentario mas votado, su usuario mas participativo y valoracion promedio??
template <class T> void ArbolBinario<T>::ImprimirPublicacion(Contenido* post)
{
    if(post!=NULL){
        post->imprimir();
        cout << "Comentario más votado: "<<endl; 
        ComentarioMasVotado(post)->imprimir();
        cout<< endl;
        cout << "Usuario más participativo: ";
        UsuarioMasParticipativo(post)->imprimir();
        cout << endl;
    }
    else cout << "No existe esa publicacion" << endl;
}

// template <class T> void ArbolBinario<T>::ImprimirParticipaciones(Usuario* user)
// {
//     Lista<Contenido*>* listaDeParticipaciones = new Lista<Contenido*>();
//     participacionesPorUsuario(raiz, user, listaDeParticipaciones);
//     ordenarParticipaciones(listaDeParticipaciones);
//     listaDeParticipaciones->imprimirL();
// }
#endif