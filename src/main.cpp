#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "Contenido.hpp"
#include "util\ArbolBinario.cpp"


using namespace std;

int main(){
    Fecha* fecha = new Fecha(15,7,2022);
    Usuario* usuario1 = new Usuario("FortFan23");

    Contenido* post1 = new Contenido(fecha,usuario1,"La magia de Messi brilla en la Copa del Mundo: ¡Argentina gana su tercera!","En un emocionante partido lleno de jugadas deslumbrantes, Lionel Messi llevó a la selección argentina a la gloria en la Copa del Mundo. Con su visión, habilidad y goles asombrosos, Messi se consagra como el líder indiscutible del equipo. Esta victoria histórica es un guiño a la grandeza de Messi y una alegría para todos los fanáticos del fútbol. ¡Ricardo Fort seguramente estaría celebrando en el cielo del chocolate! ¡Felicitaciones a Messi y a todo el equipo por este logro inolvidable!",TipoDeContenido::PUBLICACION);
    post1->nomeGusta();
    post1->imprimir();

    ArbolBinario<Contenido*>* arbolito = new ArbolBinario<Contenido*>();
    arbolito->Agregar(post1);
};