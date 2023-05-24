#include <iostream>
#include <string>
#include "Contenido.hpp"
#include "Usuario.hpp"
#include "util\List.hpp"

using namespace std;

#ifndef POSTEO_HPP
#define POSTEO_HPP

class Posteo : public Contenido
{
    private:
        string titulo;
        List<Usuario> participantes;

        Contenido comentarioMasVotado();
        Usuario usuarioMasParticipativo();

    public:
        Posteo(Fecha fecha, Usuario usuario, string cuerpo, string titulo)
            : Contenido(fecha, usuario, cuerpo){
                this->titulo=titulo;
            };

        Posteo():Contenido(){};

        void imprimir()
        {
            cout << "titulo "<< titulo << endl << "cuerpo " << cuerpo << endl << "Por: ";
            usuario.imprimir();
        };
        void imprimirPosteo();
};

#endif