#include <iostream>
#include <string>
#include "util\List.hpp"

using namespace std;

#ifndef USUARIO_HPP
#define USUARIO_HPP

class Usuario
{
    private:
        string nombre;
        List<Contenido>* participaciones;
        void imprimirParticipaciones(List<Contenido>* particip){
            cout << "Participaciones de "<< nombre;
            if (participaciones->isEmpty()){}
            else{
                participaciones->cabeza()->imprimir(); 
                imprimirParticipaciones(participaciones->resto());
            }        
        };
    public:
        Usuario(string nombre) { this->nombre = nombre;}
        Usuario(){};

        void imprimirU(){ cout << nombre<<endl;};
        void agregarParticipacion(Contenido* participacion){participaciones->add(participacion);}
        void ImprimirParticipaciones(){ordenarParticipaciones(); imprimirParticipaciones(participaciones);}
        void ordenarParticipaciones(){};
};

#endif