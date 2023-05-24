#include <iostream>
#include "Posteo.hpp"

using namespace std;

#ifndef POSTEO_CPP
#define POSTEO_CPP

Contenido Posteo::comentarioMasVotado()
{
    // Implementación de lógica para encontrar el comentario más votado
    // Retorna el comentario más votado
}

Usuario Posteo::usuarioMasParticipativo()
{
    // Implementación de lógica para encontrar el usuario más participativo
    // Retorna el nombre del usuario más participativo
}

void Posteo::imprimirPosteo()
{
    cout << "Título: " << titulo << endl;
    cout << "Comentario más votado: "; 
    comentarioMasVotado().imprimir();
    cout<< endl;
    cout << "Usuario más participativo: ";
    usuarioMasParticipativo().imprimir();
    cout << endl;
    cout << "Valoración: " << getValoracion() << endl;
}

#endif