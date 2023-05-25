#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "tipoDeContenido.hpp"
#include "util\List.hpp"

using namespace std;

#ifndef Contenido_HPP
#define Contenido_HPP

class Contenido
{
    protected:
        Fecha* fecha;
        Usuario* usuario;
        string cuerpo;
        int valoracion;
        string titulo;
        //List<Usuario> participantes;
        TipoDeContenido tipo;

        Contenido comentarioMasVotado();
        Usuario usuarioMasParticipativo();

    public:
        Contenido(Fecha* fecha, Usuario* usuario, string cuerpo, TipoDeContenido tipo)
        {
            this-> fecha = fecha;
            this->usuario = usuario;
            this->cuerpo = cuerpo;
            this->tipo = tipo;
            valoracion = 0;
        };
        Contenido(Fecha* fecha, Usuario* usuario,  string titulo, string cuerpo, TipoDeContenido tipo)
        {
            this->titulo = titulo;
            this->fecha = fecha;
            this->usuario = usuario;
            this->cuerpo = cuerpo;
            this->tipo = tipo;
            valoracion = 0;

        };
        Contenido(){};

        void meGusta(){valoracion++;};
        void nomeGusta(){valoracion--;};
        int getValoracion(){return valoracion;};
        void imprimir()
        {
            cout<<"-------------------------"<<tipo<<endl<<titulo <<endl<<endl<< cuerpo<<endl<<endl<<"Valoracion: "<<valoracion<<endl<< "Autor: ";
            usuario->imprimirU();
            fecha->imprimirF();
            cout<<"-------------------------"<<endl;  
        };
        void imprimirPosteo();
};

#endif