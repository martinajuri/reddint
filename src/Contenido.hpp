#include <iostream>
#include <string>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "tipoDeContenido.hpp"
#include "util\Lista.hpp"
#include "color.hpp"

using namespace std;

#ifndef Contenido_HPP
#define Contenido_HPP

class Contenido
{
    private:
        Fecha* fecha;
        Usuario* usuario;
        string cuerpo;
        int valoracion;
        string titulo;
        Lista<Usuario*>* participantes;
        TipoDeContenido tipo;

    public:
        //para comentarios y respuestas (el titulo se asigna mas adelante cuando se implemente en el arbol)
        Contenido(Fecha* fecha, Usuario* usuario, string cuerpo, TipoDeContenido tipo)
        {
            this-> fecha = fecha;
            this->usuario = usuario;
            this->cuerpo = cuerpo;
            this->tipo = tipo;
            valoracion = 0;
        };
        //para publicaciones
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
        Fecha* getFecha(){return fecha;}
        string getTitulo(){return titulo;};
        void setTitulo(string nuevoTitulo){titulo = nuevoTitulo;};
        Usuario* getUsuario(){return usuario;};
        Lista<Usuario*>* getParticipantes(){return participantes;}
        void imprimir()
        {
            cout<<dye::purple(titulo) <<endl<<endl<< cuerpo<<endl<<endl<<"Valoracion: "<<valoracion<<endl<< "Autor: ";
            usuario->imprimir();
            fecha->imprimir();
        };
        void agregarParticipante(Usuario* participante){participantes->add(participante);}
};
#endif