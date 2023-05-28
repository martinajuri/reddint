#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "tipoDeContenido.hpp"
#include "util\Lista.hpp"

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
        Lista<Usuario*>* participantes;
        TipoDeContenido tipo;


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
            participantes = new Lista<Usuario*>(usuario);
        };
        Contenido(){};

        void meGusta(){valoracion++;};
        void nomeGusta(){valoracion--;};
        int getValoracion(){return valoracion;};
        Usuario* getUsuario(){return usuario;};
        Lista<Usuario*>* getParticipantes(){return participantes;}
        void imprimir()
        {
            cout<<"-------------------------"<<tipo<<endl<<titulo <<endl<<endl<< cuerpo<<endl<<endl<<"Valoracion: "<<valoracion<<endl<< "Autor: ";
            usuario->imprimir();
            fecha->imprimir();
            cout<<"-------------------------"<<endl;  
        };
        void agregarParticipante(Usuario* participante){participantes->add(participante);}
};

#endif