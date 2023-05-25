#include "ArbolBinario.hpp"
#ifndef ARBOLBINARIO_C
#define ARBOLBINARIO_C

template <class T> void ArbolBinario<T> :: postear(T dato, Nodo<T> * raizPivote )
{
if(raizPivote == nullptr)
{
    raizPivote = new Nodo<T>(dato);
}
else
{
    postear(dato,raizPivote->getHijoDer());
}
};
template <class T> void ArbolBinario<T> :: Postear(T dato)
{
    postear(dato, raiz);
}
template <class T> void ArbolBinario<T> ::ImprimirPrimerNivel()
{
    imprimirPrimerNivel(raiz);
}
template <class T> void ArbolBinario<T> ::imprimirPrimerNivel(Nodo<T>* raizPivote)
{
    if(raizPivote==NULL)
    {
        cout<<"ojo q no hay estado"<<endl;
    }
    else
    {
        cout<<"Hay un coment y aun no lo se leer"<<endl;
    }
    imprimirPrimerNivel(raizPivote->getHijoDer());
}

#endif