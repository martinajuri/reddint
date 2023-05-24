#include <iostream>
#include "Publicacion.hpp"
#include "Usuario2.hpp"

using namespace std;

#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

class Comentario : public Publicacion
{
public:
    // Constructor de Comentario que asigna los atributos heredados de Publicacion
    Comentario(Fecha fecha, Usuario usuario, string contenido): Publicacion(fecha, usuario, contenido){};
    Comentario(Fecha fecha, Usuario usuario):Publicacion(fecha, usuario, "")
    {
        cout << "Usuario que comenta: ";
        usuario.imprimir();
        cout << endl;

        cout << "Comentario: ";
        cin >> contenido;
        cout << endl;
        this->contenido=contenido;
    }
    //contructor que pide todo por consola
    Comentario():Publicacion(){};

    void responder();
};

// Implementación del método responder
void Comentario::responder()
{
    // Nuevo hijo derecho (tipo Respuesta)
    
}

#endif 