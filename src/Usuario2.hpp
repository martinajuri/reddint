#include <iostream>
#include <string>
#include "util\List.hpp"

using namespace std;

#ifndef USUARIO_HPP
#define USUARIO_HPP

class Usuario
{
    private:
        string nombre;

        void ordenarParticipaciones() {
            // Implementación de ordenación de la Lista de participaciones 
            // Puedes utilizar algoritmos de ordenación como sort [GPT]
        }

    public:
        Usuario(string nombre) { this->nombre = nombre;}
        Usuario(){};
        Usuario(int a){
            string nombre;
            cout << "Ingrese el nombre de usuario: ";
            cin >> nombre;
            this->nombre = nombre;
        }

        void imprimirParticipaciones();
        void imprimir(){ cout << nombre;};
};

//Imprime las participaciones de un usuario ordenadas por fecha de publicacion

#endif