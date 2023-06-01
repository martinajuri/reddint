#ifndef NODO_HPP
#define NODO_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Nodo
{
    public:
        T *dato;        // Puntero al dato del nodo
        Nodo * hijoDer;
        Nodo * hijoIzq;     // Puntero al siguiente nodo
    public:
        Nodo() {
            hijoDer = NULL;
            hijoIzq = NULL;
            dato = NULL;
        };
        
        Nodo(T *a){
            hijoDer = NULL;
            hijoIzq = NULL;
            dato = a;
        };
};
#endif
