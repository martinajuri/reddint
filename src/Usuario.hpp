#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>
#include "util\Lista.hpp"

using namespace std;

class Usuario
{
    private:
        string nombre;
        
    public:
        Usuario(string nombre) { this->nombre = nombre;}
        Usuario(){};
        
        void imprimir(){ cout << nombre<<endl;};
};
#endif