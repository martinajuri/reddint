#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;
#ifndef LISTA_HPP
#define LISTA_HPP
template <class T> class NodoL {
private:
    T dato;
    NodoL* next;
public:
    NodoL() { next = NULL; };
    NodoL(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(NodoL* n) { if(n != NULL) {next = n;} };
    T get_dato() { return dato; };
    NodoL* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista {
private: NodoL<T>* czo;
     
public:
    Lista() { czo = new NodoL<T>(); };
    Lista(NodoL<T>* n) { czo = n; };
    Lista(T d){czo = new NodoL<T>(d);};
    //~Lista(void);
    void add(T d); //sumar nodoLs a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodoL
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    int size();
    void borrar(void); //borra la cabeza
    void imprimir();
    void imprimirL();
   
};
template <class T>
void Lista<T>::add(T d) //100
{
    NodoL<T>* nuevo = new NodoL<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista<T>::esvacia(void)
{
    if(czo == NULL){return true;}
        return false;
    //return czo->es_vacio();
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}


template <class T> int Lista<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}



template <class T> void Lista<T>::borrar(void)
{ //borra el nodoL cabeza
    if (!this->esvacia()) {
        NodoL<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}
//imprime un string, LIFO
template <class T>
void Lista<T>::imprimir(){
    
    if (!this->esvacia()){
        cabeza()->imprimir(); //tiene que  tener el item su metodo imprimir
        //cout<< endl;
        this->resto()->imprimir();
    }
    
};
template <class T>
void Lista<T>::imprimirL(){
    
    if (!this->esvacia()){
        cout<<"---------------------------------------"<<endl;
        cabeza()->imprimir(); //tiene que  tener el item su metodo imprimir
        //cout<< endl;
        cout<<"---------------------------------------"<<endl;
        this->resto()->imprimir();
    }
    else{
        cout << "---------------------------------------" << endl;
    }
};
#endif