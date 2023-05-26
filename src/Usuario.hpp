#include <iostream>
#include <string>
#include "util\List.hpp"
class Contenido;
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
        
        void imprimirU(){ cout << nombre<<endl;};
        void ordenarParticipaciones(){};
};

#endif