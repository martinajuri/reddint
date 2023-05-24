#include <iostream>
#include "Publicacion.hpp"
#include "Fecha.hpp"
#include "Usuario.hpp"

using namespace std;

#ifndef RESPUESTA_HPP
#define RESPUESTA_HPP

class Respuesta : public Publicacion
{
    public:
        Respuesta(Fecha fecha, Usuario usuario, string contenido)
            : Publicacion(fecha, usuario, contenido, 0){};
        
        Respuesta(Fecha fecha, Usuario usuario):Publicacion(fecha, usuario, "", 0)
        {
            /* Constructor de Respuesta que asigna los atributos heredados de Publicacion 
                Pide informacion por consola
            */
            this-> fecha = fecha;
            valoracion = 0;

            cout << "Que usuario responde: ";
            usuario.imprimir();
            cout << endl;

            cout << "Respuesta: ";
            cin >> contenido;
            cout << endl;
            this->contenido=contenido;
        };
        
};

#endif