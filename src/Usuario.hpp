#include <iostream>
#include <string>

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
};

#endif