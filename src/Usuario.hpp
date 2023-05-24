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
        List<Publicacion*> participaciones;

        void ordenarParticipaciones() {
            // Implementación de ordenación de la Lista de participaciones 
            // Puedes utilizar algoritmos de ordenación como sort [GPT]
        }

    public:
        Usuario(string nombre) { this->nombre = nombre;}
        Usuario(){
            string nombre;
            cout << "Ingrese el nombre de ususario: ";
            cin >> nombre;
            this->nombre = nombre;
        }

        void imprimirParticipaciones();

        void agregarParticipacion(Publicacion participacion) {
            participaciones.add(participacion*);
        }
        void imprimir(){
            cout << nombre;
        };
};

//Imprime las participaciones de un usuario ordenadas por fecha de publicacion
void Usuario::imprimirParticipaciones() {
    
    ordenarParticipaciones();

    cout << "Participaciones de " << nombre << ": "<< endl;
    for (Publicacion participacion : participaciones) {
        participacion.imprimir();
    }
    cout << endl;
};
#endif