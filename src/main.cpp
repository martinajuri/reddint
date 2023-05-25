#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "Contenido.hpp"
#include "util\ArbolBinario.hpp"
#include "util\ArbolBinario.cpp"


using namespace std;

int main(){
    Fecha* fecha = new Fecha(15,7,2022);
    Fecha* fecha2 = new Fecha(20,8,2023);
    Usuario* usuario1 = new Usuario("FortFan23");
    Contenido* post1 = new Contenido(fecha,usuario1,"La magia de Messi brilla en la Copa del Mundo: ¡Argentina gana su tercera!","En un emocionante partido lleno de jugadas deslumbrantes, Lionel Messi llevó a la selección argentina a la gloria en la Copa del Mundo. Con su visión, habilidad y goles asombrosos, Messi se consagra como el líder indiscutible del equipo. Esta victoria histórica es un guiño a la grandeza de Messi y una alegría para todos los fanáticos del fútbol. ¡Ricardo Fort seguramente estaría celebrando en el cielo del chocolate! ¡Felicitaciones a Messi y a todo el equipo por este logro inolvidable!",TipoDeContenido::PUBLICACION);
    Contenido* post2 = new Contenido(fecha,usuario1,"Crisis en la FCEFYN","Se notificaron multiples casos de estudiantes en posicion fetal en los pasillos de la facultad de ciencias exactas fisicas y naturales, esto es debido al comienzo de la ultima semana de parciales del semestre la cual viene seguida de los recuperatorios y los finales.",TipoDeContenido::PUBLICACION);
    Contenido* comentario1 = new Contenido(fecha2,usuario1,"un horror che", TipoDeContenido::COMENTARIO);
    post1->nomeGusta();
    post1->imprimir();

    ArbolBinario<Contenido> *arbolito = new ArbolBinario<Contenido>();
    arbolito->Agregar(post1);
    arbolito->Agregar(post2);
    arbolito->Imprimir();
    arbolito->Comentar(post2, comentario1);
    arbolito->Imprimir();
};