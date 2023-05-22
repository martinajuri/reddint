#include <iostream>
#include <string>
#include "Publicacion.hpp"
#include "Comentario.hpp"
#include "Usuario.hpp"
#include "util\List.hpp"

using namespace std;

#ifndef POSTEO_HPP
#define POSTEO_HPP

class Posteo : public Publicacion
{
    private:
    string titulo;
    List<Usuario> participantes;

    Comentario comentarioMasVotado();
    Usuario usuarioMasParticipativo();

public:
    Posteo(const Fecha& fecha, const Usuario& usuario, const string& contenido, int valoracion,
           const string& titulo, const List<string>& participantes)
        : Publicacion(fecha, usuario, contenido, valoracion)
    {
        this->titulo = titulo;
        this->participantes = participantes;
    }
    void comentar();
    void imprimirPosteo();
};


#endif