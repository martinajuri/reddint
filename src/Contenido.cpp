#include <iostream>
#include <string>
#include "Contenido.hpp"
#include "Usuario.hpp"
#include "util\List.hpp"

using namespace std;
#ifndef Contenido_CPP
#define Contenido_CPP

Contenido Contenido::comentarioMasVotado()
{
    // Implementación de lógica para encontrar el comentario más votado
    // Retorna el comentario más votado
};

Usuario Contenido::usuarioMasParticipativo()
{
    // Implementación de lógica para encontrar el usuario más participativo
    // Retorna el nombre del usuario más participativo
}

void Contenido::imprimirPosteo()
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