#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"

using namespace std;

#ifndef Contenido_HPP
#define Contenido_HPP

class Contenido
{
    protected:
        Fecha fecha;
        Usuario usuario;
        string cuerpo;
        int valoracion;
        string titulo;
        List<Usuario> participantes;

        Contenido comentarioMasVotado();
        Usuario usuarioMasParticipativo();

    public:
        Contenido(Fecha fecha, Usuario usuario, string cuerpo)
        {
            this-> fecha = fecha;
            this->usuario = usuario;
            this->cuerpo = cuerpo;
            valoracion = 0;
        };
        Contenido(Fecha fecha, Usuario usuario, string cuerpo, string titulo)
        {
            this->titulo = titulo;
            this->fecha = fecha;
            this->usuario = usuario;
            this->cuerpo = cuerpo;
            valoracion = 0;
        };
        Contenido(){};

        void meGusta(){valoracion++;};
        void nomeGusta(){valoracion--;};
        int getValoracion(){return valoracion;};
        void imprimir(){};
        void imprimirPosteo();
};

#endif