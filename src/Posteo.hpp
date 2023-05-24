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
        Posteo(Fecha fecha,Usuario usuario, string contenido, int valoracion, string titulo, List<string> participantes)
            : Publicacion(fecha, usuario, contenido, valoracion){};

        Posteo(Fecha fecha, Usuario usuario)
            : Publicacion(fecha, usuario, "", 0)
            {
                valoracion = 0;
                participantes = new List<Usuario>();

                cout << "Usuario autor del post: ";
                usuario.imprimir();
                cout << endl;

                cout << "Titulo del post: ";
                cin >> titulo;
                cout << endl;
                this->titulo=titulo;

                cout << "Contenido del post: ";
                cin >> contenido;
                cout << endl;
                this->contenido=contenido;
            }
        void imprimir(){
            cout << titulo << endl << contenido << endl << "Por: ";
            usuario.imprimir();
            }
        void comentar();
        void imprimirPosteo();
};


#endif