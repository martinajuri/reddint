#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"


using namespace std;

int main(){
    Fecha* fecha = new Fecha(2,4,2001);
    fecha->imprimir();
    Usuario* usuario1 = new Usuario("kp");
    usuario1->imprimir();
};