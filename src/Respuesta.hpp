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
        Respuesta(const Fecha& fecha, const Usuario& usuario, const string& contenido, int valoracion)
            : Publicacion(fecha, usuario, contenido, valoracion)
        {
            // Constructor de Respuesta que asigna los atributos heredados de Publicacion [GPT]
        }
};

#endif