#include <iostream>
#include <string>
#include "util\List.hpp"
#include "Publicacion.hpp"

using namespace std;

#ifndef USUARIO_HPP
#define USUARIO_HPP

class Usuario
{
    private:
    string nombre;
    List<Publicacion> participaciones;

    void ordenarParticipaciones() {
        // Implementación de ordenación de la Lista de participaciones 
        // Puedes utilizar algoritmos de ordenación como sort [GPT]
    }

    public:
        Usuario(string nombre) { this->nombre = nombre;}

        void imprimirParticipaciones() {
            ordenarParticipaciones();

            cout << "Participaciones de " << nombre << ": ";
            for (Publicacion participacion : participaciones) {
                cout << participacion << " ";
            }
            cout << endl;
        }

        void agregarParticipacion(Publicacion participacion) {
            participaciones.add(participacion);
        }
        void imprimir(){
            cout << nombre;
        };
};

#endif