/*
ARCHIVO DE LA CLASE "Nodo"
    Modela un nodo con directorio binario: Hijo izquierdo e Hijo derecho
CONSTRUCTORES
    Constructor 1: Inicializa el nodo sin nada
    Constructor 2: Inicializa el nodo con un puntero a un dato


*/
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef NODO_HPP
#define NODO_HPP
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
    
//     //setters       
//     void setDato(T *a) { dato = a; };    
//     void setHijoDer(Nodo *n) { hijoDer = n; }; 
//     void setHijoIzq(Nodo *n) { hijoIzq = n; }; 
//     //getters
//     T *getDato() { return dato; };       
//     Nodo *getHijoDer() { return hijoDer; };
//     Nodo *getHijoIzq() { return hijoIzq; };
    
//     //devuelve si el nodo no tiene siguiente nodo apuntado
//     bool isDerEmpty() { return hijoDer == NULL; }
//     bool isIzqEmpty() { return hijoIzq == NULL; }
};
#endif
