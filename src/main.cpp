#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "Contenido.hpp"
#include "tipoDeContenido.hpp"
#include "util\ArbolBinario.cpp"


using namespace std;

int main(){

ArbolBinario < Contenido* > * reddintArbol = new ArbolBinario < Contenido* >();
Fecha* fecha1 = new Fecha(23,05,2023);
Fecha* fecha2 = new Fecha(25,12,2023);
Fecha* fecha3 = new Fecha(4,10,2023);
Fecha* fecha4 = new Fecha(27,9,2023);
Usuario* user1 = new Usuario("Ferxo");
Usuario* user2 = new Usuario("XQCme");
Usuario* user3 = new Usuario("RolonRolinPeroMiraQuePajin");
Contenido* post1 = new Contenido(fecha1, user1, "Mañana se madruga","Re madrugo chabon. Creo que uno se enfermo",PUBLICACION);
Contenido* post2 = new Contenido(fecha1, user2, "Mañana no se madruga","Me cubre un boludo jaja, me voy de pumbapumba",PUBLICACION);
Contenido* post3 = new Contenido(fecha2, user3, "Eche a un empleado","No madrugaba :c",PUBLICACION);
post1->imprimir();
post2->imprimir();
post3->imprimir();
reddintArbol->Postear(post1);
reddintArbol->Postear(post2);
reddintArbol->Postear(post3);
reddintArbol->ImprimirPrimerNivel();
};