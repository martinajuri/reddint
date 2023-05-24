#include <iostream>
#include <string>
#include "Contenido.hpp"
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
        Posteo(Fecha fecha, Usuario usuario, string contenido, string titulo)
            : Publicacion(fecha, usuario, contenido){
                this->titulo=titulo;
            };

        Posteo():Publicacion(){};

        void imprimir()
        {
            cout << "titulo "<< titulo << endl << "contenido " << contenido << endl << "Por: ";
            usuario.imprimir();
        };
        void imprimirPosteo();
};


#endif