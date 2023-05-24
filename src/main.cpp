#include <iostream>
#include "Fecha.hpp"
#include "Usuario2.hpp"
#include "Posteo.hpp"


using namespace std;

int main(){
    Fecha* fecha = new Fecha(2,4,2001);
    fecha->imprimir();
    Usuario* usuario1 = new Usuario("kp");
    usuario1->imprimir();
    Posteo* posteo1 = new Posteo(*fecha, *usuario1, "q onda wacho","Buen dia");
    posteo1->imprimir();
};