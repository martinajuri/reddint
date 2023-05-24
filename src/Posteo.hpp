#include <iostream>
#include <string>
#include "Publicacion.hpp"
#include "Comentario.hpp"
#include "Usuario2.hpp"
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
        Posteo(Fecha fecha, Usuario usuario, string contenido, int valoracion, string titulo, List<string> participantes)
            : Publicacion(fecha, usuario, contenido){};

        //contructor que pide titulo y contenido por consola
        Posteo(Fecha fecha, Usuario usuario): Publicacion(fecha, usuario, "")
        {
            string titulo, contenido;
            participantes = List<Usuario>();

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
        };
        //contructor que pide toda la info por consola
        Posteo():Publicacion()
        {
            //participantes = List<Usuario>();
            string titulo, contenido;

            cout << "Titulo del post: ";
            cin >> titulo;
            cout << endl;
            this->titulo=titulo;

        };

        void imprimir()
        {
            cout << "titulo "<< titulo << endl << "contenido " << contenido << endl << "Por: ";
            usuario.imprimir();
        };
        void comentar();
        void imprimirPosteo();
};


#endif