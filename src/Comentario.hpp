#include <iostream>
#include "Publicacion.hpp"

using namespace std;

#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

class Comentario : public Publicacion
{
public:
    Comentario(const Fecha& fecha, const Usuario& usuario, const string& contenido, int valoracion)
        : Publicacion(fecha, usuario, contenido, valoracion){// Constructor de Comentario que asigna los atributos heredados de Publicacion
        }

    void responder();
};

// Implementación del método responder
void Comentario::responder()
{
    // Nuevo hijo derecho (tipo Respuesta)
}

#endif 