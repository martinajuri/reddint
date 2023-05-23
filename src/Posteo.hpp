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
        this->fecha = fecha;
        valoracion = 0;
        participantes = new List<string>();

        cout << "Usuario autor del post: ";
        cin >> usuario;
        cout << endl;

        cout << "Titulo del post: ";
        cin >> titulo;
        cout << endl;

        cout << "Contenido del post: ";
        cin >> contenido;
        cout << endl;
    }
    void comentar();
    void imprimirPosteo();
};


#endif