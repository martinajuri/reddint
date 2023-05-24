#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"

using namespace std;

#ifndef PUBLICACION_HPP
#define PUBLICACION_HPP

class Publicacion
{
    protected:
        Fecha fecha;
        Usuario usuario;
        string contenido;
        int valoracion;

    public:
        Publicacion(Fecha fecha, Usuario usuario,string contenido){
            this-> fecha = fecha;
            this->usuario = usuario;
            this->contenido = contenido;
            valoracion = 0;
            
        };
        void meGusta(){valoracion++;};
        void nomeGusta(){valoracion--;};
        int getValoracion(){return valoracion;};
        void imprimir(){};
};

#endif