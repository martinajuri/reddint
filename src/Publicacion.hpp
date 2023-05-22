#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"

using namespace std;

#ifndef PUBLICACION_HPP
#define PUBLICACION_HPP

class Publicacion
{
    private:
        Fecha fecha;
        Usuario usuario;
        long string contenido;
        int valoracion;

    public:
        void meGusta(){valoracion++;};
        void nomeGusta(){valoracion..;};
        int getValoracion(){return valoracion;};
};

#endif