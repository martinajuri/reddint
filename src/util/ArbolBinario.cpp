#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C

#include "ArbolBinario.hpp"

using namespace std;

//---------------------------------------------PRIVADOS DE AGREGADO----------------------------------------------------------------------------------------
// Agrega una publicacion al arbol
template <class T> void ArbolBinario<T>:: agregar(Nodo<T>*& raizAux, Contenido* newPost)
{
    if(raizAux == NULL)
    {
        raizAux = new Nodo<Contenido>(newPost);
    }
    else
    {
       agregar(raizAux->hijoDer, newPost);
    }    
}

// Agrega un comentario a una  publicacion
template <class T> void ArbolBinario<T>:: comentar(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* newComentario)
{
    nodoAux = nodoAlContenido(raizAux, postAComentar);
    if(nodoAux != NULL)
    {
        agregar(nodoAux->hijoIzq, newComentario);
    }else
    {
        cout << "No existe la publicacion a comentar" << endl;
    }
}

// Agrega una respuesta a un comentario
template <class T> void ArbolBinario<T>:: responder(Nodo<T>*& raizAux, Contenido* postAComentar, Contenido* comentarioAResponder, Contenido* newRespuesta)
{
    nodoAux = nodoAlContenido(raizAux, postAComentar);
    if(nodoAux != NULL)
    {
        comentar(nodoAux->hijoIzq, comentarioAResponder, newRespuesta);
    }else
    {
        cout << "No existe el comentario a responder" << endl;
    }
}

//------------------------------------------------PRIVADOS DE CONSIGNA-------------------------------------------------------------------------------------

// Borra una publicacion y todos sus comentarios y respuestas
template <class T> void ArbolBinario<T>::borrarPost(Nodo<T>*& raizAux ,Contenido* post)
{
    if(raizAux->dato == post){
       if(raizAux->hijoDer == NULL) {delete raizAux; raizAux = NULL;}
       else //Si no es la ultima publicacion, haces un swap de punteros
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
    if (raizAux != NULL) 
    {
        Contenido* contAux = raizAux->dato;
        contAux->imprimir();
        imprimir(raizAux->hijoIzq);
        imprimir(raizAux->hijoDer);
    }
}

// Imprime todos los hijos derechos del parametro
template <class T> void ArbolBinario<T>:: imprimirNivel(Nodo<T>* raizAux)
{
    if (raizAux != NULL) 
    {
        Contenido* contAux = raizAux->dato;
        contAux->imprimir();
        cout<<"------------------------------------------------------------------------------------------------------------------------\n";  
        imprimirNivel(raizAux->hijoDer);
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
    else return 0;
}

//Devuelve las participaciones de un usuario (sirve para panel de usuario).
template <class T> void ArbolBinario<T>::participacionesPorUsuario(Nodo<Contenido>*& raizAux, Usuario* user, Lista<Contenido*>* lista)
{
    if (user != NULL && raizAux != NULL)
    {
       if((raizAux->dato)->getUsuario()==user)
       {
            lista->add(raizAux->dato);
       }
        participacionesPorUsuario(raizAux->hijoIzq, user, lista);
        participacionesPorUsuario(raizAux->hijoDer, user, lista);
    }
}

//Ordena la lista por orden de publicacion
template <class T> void ArbolBinario<T>:: ordenarParticipaciones(Lista<Contenido*>* lista)
{
    if (lista != NULL && lista->size() > 1) {
        NodoL<Contenido*>* primero = lista->getCzo();
        NodoL<Contenido*>* nuevo = primero;
        NodoL<Contenido*>* mov = nuevo->get_next();

        int MAX = lista->size();
        for(int i = 1; i<MAX; i++) {
            if (mov->get_dato()->getFecha()->esMayor(nuevo->get_dato()->getFecha())) {
                nuevo = mov;
            }
            mov = mov->get_next();
        }
        Contenido* aux = primero->get_dato();
        primero->set_dato(nuevo->get_dato());
        nuevo->set_dato(aux);
        ordenarParticipaciones(lista->resto());
    }
}

//-----------------------------------------------PRIVADOS EXTRA--------------------------------------------------------------------------------------
// Devuelve un puntero al contenido con mayor valoracion, si ambos son iguales devuelve el primero.
template <class T> Contenido* ArbolBinario<T>::masVotado(Contenido* contenido1, Contenido* contenido2)
{
    if(contenido1->getValoracion() < contenido2->getValoracion()) return contenido2;
    else if (contenido1->getValoracion() > contenido2->getValoracion()) return contenido1;
    else return contenido1;
}

//Devuelve un puntero al nodo que contiene el contenido. Devuelve NULL si la publicacion no se encuentra
template <class T> Nodo<T>* ArbolBinario<T>::nodoAlContenido(Nodo<T>*& raizAux, Contenido* post)
{

    if (raizAux == NULL) {
        return NULL;
    }

    // Buscar en los hijos derechos de cada nodo
    nodoAux = NULL;
    if (raizAux->dato == post) {
        nodoAux = raizAux;
    } else {
        nodoAux = nodoAlContenido(raizAux->hijoDer, post);
    }

    // Si se encontró en los hijos derechos, retornar el nodo encontrado
    if (nodoAux != NULL) {
        return nodoAux;
    }

    // Si no se encontró en los hijos derechos, buscar en los subárboles de los hijos izquierdos
    return nodoAlContenido(raizAux->hijoIzq, post);

}

//-------------------------------------------------PUBLICOS------------------------------------------------------------------------------------
//Metodo Publico: devuelve el comentario mas votado de un post
template <class T> Contenido* ArbolBinario<T>::ComentarioMasVotado(Contenido* post)
{
    nodoAux = nodoAlContenido(raiz, post);
    if (nodoAux == NULL)
    {
        cout << "No fue posible encontrar la publicacion"<<endl;
        return NULL;
    }
    else if (nodoAux->hijoIzq==NULL) return NULL;
    return comentarioMasVotado(nodoAux->hijoIzq);   
}

//Metodo Publico: devuelve el usuario que mas participo en un post
template <class T> Usuario* ArbolBinario<T>::UsuarioMasParticipativo(Contenido* post)
{
    nodoAux = nodoAlContenido(raiz, post);
    if (nodoAux == NULL)
    {
        cout << "No fue posible encontrar la publicacion"<<endl;
        return NULL;
    }
    Usuario* usuario = usuarioMasParticipativo(nodoAux->dato->getParticipantes());
    if(usuario!=NULL) return usuario;
    else return NULL;

};

//Imprime una publicacion con su comentario mas votado, su usuario mas participativo y valoracion promedio??
template <class T> void ArbolBinario<T>::ImprimirPublicacion(Contenido* post)
{
    if(post!=NULL)
    {
        nodoAux = nodoAlContenido(raiz,post);
        if(nodoAux!=NULL)
        {
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";  
            post->imprimir();
            cout << "\n-> Usuario más participativo: ";
            Usuario* usuario = UsuarioMasParticipativo(post);
            if(usuario!=NULL) usuario->imprimir();
            else post->getUsuario()->imprimir();
            cout << endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";  
            cout << "-> Más votado: \n"; 
            Contenido* contenido = ComentarioMasVotado(post);
            if(contenido!=NULL) contenido->imprimir();
            else cout << "No hay \n";
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";  
        }
        else cout << "No existe esa publicacion" << endl;
    } 
    else cout << "No existe esa publicacion" << endl;
}

//Imprime las publicaciones del arbol en formato ImprimirPublicacion
template <class T> void ArbolBinario<T>::imprimirPublicaciones(Nodo<T>*& raizAux)
{
    if(raizAux!=NULL){
        ImprimirPublicacion(raizAux->dato);
        imprimirPublicaciones(raizAux->hijoDer);
    }

}

//Metodo publico: imprime publicacion
template <class T> void ArbolBinario<T>::ImprimirParticipaciones(Usuario* user)
{
    Lista<Contenido*>* listaDeParticipaciones = new Lista<Contenido*>();
    participacionesPorUsuario(raiz, user, listaDeParticipaciones);
    ordenarParticipaciones(listaDeParticipaciones);
    listaDeParticipaciones->imprimirL();
    delete listaDeParticipaciones;
}
//metodo de busqueda para el main
template <class T> Contenido* ArbolBinario<T>::buscarContenidoPorNumero(int p, int c, int r)
{
    nodoAux = raiz;
    for (int i = 1; i < p; i++)
    {
        if(nodoAux->hijoDer!=NULL) nodoAux = nodoAux->hijoDer;  
    }
    if(c!=0)nodoAux = nodoAux->hijoIzq; 
    for (int j = 1; j < c; j++)
    {
        nodoAux = nodoAux->hijoDer;  
    }
    if(r!=0)nodoAux = nodoAux->hijoIzq; 
    for (int k = 1; k < r; k++)
    {
        nodoAux = nodoAux->hijoDer;  
    }
    if(nodoAux == NULL){
        cout << "No se encontro el contenido solicitado \n";
        return NULL;
    }else{return nodoAux->dato;}
    
}
#endif