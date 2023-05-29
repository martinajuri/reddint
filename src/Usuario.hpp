/*
ARCHIVO DE LA CLASE "Usuario":
    Modela una clase para los individuos que interactuen en Reddint
CONSTRUCTORES
    + Constructor 1: Crea un objeto a aprtir del nombre
METODOS PUBLICOS
    + Imprimir: imprime el nombre por consola
    + ordenarParticipantes: 

*/

#include <iostream>
#include <string>
#include "util\Lista.hpp"

using namespace std;

#ifndef USUARIO_HPP
#define USUARIO_HPP

class Usuario
{
    private:
        string nombre;
        
    public:
        Usuario(string nombre) { this->nombre = nombre;}
        Usuario(){};
        
        void imprimir(){ cout << nombre<<endl;};
        void ordenarParticipaciones(){};
};

#endif