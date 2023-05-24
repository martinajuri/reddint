#include <iostream>
#include "Publicacion.hpp"
#include "Fecha.hpp"
#include "Usuario2.hpp"

using namespace std;

#ifndef RESPUESTA_HPP
#define RESPUESTA_HPP

class Respuesta : public Publicacion
{
    public:
        Respuesta(Fecha fecha, Usuario usuario, string contenido)
            : Publicacion(fecha, usuario, contenido){};
        
        // Constructor que pide contenido por consola
        Respuesta(Fecha fecha, Usuario usuario): Publicacion(fecha, usuario, "")
        {
            cout << "Usuario que responde: ";
            usuario.imprimir();
            cout << endl;

            cout << "Respuesta: ";
            cin >> contenido;
            cout << endl;
            this->contenido=contenido;
        };
        //Constructor que pide toda la info por consola
        Respuesta():Publicacion(){};
        
};

#endif