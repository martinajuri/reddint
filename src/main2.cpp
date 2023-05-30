#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "Contenido.hpp"
#include "util\ArbolBinario.cpp"


using namespace std;

Fecha* ingresarFecha();
Usuario* ingresarUsuario();
Contenido* ingresarPublicacion(Fecha* fecha, Usuario* usuario);
Contenido* ingresarContenido(Fecha* fecha, Usuario* usuario, TipoDeContenido tipo);
Contenido* elegirContenido(Contenido* publicacion, Contenido* comentario, Contenido* respuesta);
void bienvenida();

int main(){
    bienvenida();
    ArbolBinario<Contenido> *r_musica = new ArbolBinario<Contenido>();
    Fecha* fecha1 = new Fecha(20,3,2023);
    Fecha* fecha2 = new Fecha(21,3,2023);
    Fecha* fecha3 = new Fecha(22,3,2023);
    Fecha* fecha4 = new Fecha(1,4,2023);
    Fecha* fecha5 = new Fecha(5,4,2023);
    Fecha* fecha6 = new Fecha(6,4,2023);
    Fecha* fecha7 = new Fecha(19,5,2023);
    Fecha* fecha8 = new Fecha(20,5,2023);


    Usuario* usuario1 = new Usuario("ImagineDragons4Ever");
    Usuario* usuario2 = new Usuario("LimitlessWanderer");
    Usuario* usuario3 = new Usuario("AguaConGasMono");
    Usuario* usuario4 = new Usuario("LasJeringasDeLaAbuela");
    Usuario* usuario5 = new Usuario("MeGustaMozaBacheyBetoVeni");
    Usuario* usuario6 = new Usuario("VTxSAR38Tr1");
    Usuario* usuario7 = new Usuario("HeadphoneHelmet");
    Usuario* usuario8 = new Usuario("TangoLover");
    Usuario* usuario9 = new Usuario("TotallyNotACultLeader");

    Contenido* post1 = new Contenido(fecha1,usuario1,"Bandas parecidas a Imagine Dragons?","Desde que era pibe me gusto esa banda, pero nunca me gusto no poder conectar porque no se tan bien el ingles, alguno sabe que puedo escuchar que sea muy parecido?",TipoDeContenido::PUBLICACION); post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();post1->meGusta();
    r_musica->Agregar(post1);
    Contenido* comentario1_1 = new Contenido(fecha1,usuario8,"Pero que vende patrias loco, escucha Por una cabeza man", TipoDeContenido::COMENTARIO); comentario1_1->meGusta();comentario1_1->meGusta();comentario1_1->meGusta();comentario1_1->meGusta();comentario1_1->meGusta();
    r_musica->Comentar(post1, comentario1_1);
    Contenido* comentario1_2 = new Contenido(fecha2,usuario6,"With BEtx3Prow You can win a lot of prizes FOR FREE! Simply scratch th hidden number in our web, put your mom's credit card info below the button that says 'totally not a scam' and win a lot of dogeCoins or games that you cannot definitely find for free in any other place!", TipoDeContenido::COMENTARIO); comentario1_2->nomeGusta();comentario1_2->nomeGusta();comentario1_2->nomeGusta();comentario1_2->nomeGusta();
    r_musica->Comentar(post1, comentario1_2);
    Contenido* respuesta1_2_1 = new Contenido(fecha3,usuario1,"Me interesa lla t escribi bro", TipoDeContenido::COMENTARIO);
    r_musica->Responder(post1, comentario1_2, respuesta1_2_1);
    Contenido* comentario1_3 = new Contenido(fecha2,usuario9,"Nosotros tenemos un proyecto para crear ese tipo de musica! tambien para derrocar las instituciones actuales y crear histeria en masa, si te interesa mandame mensaje, ya casi termino el secundario", TipoDeContenido::COMENTARIO); comentario1_3->nomeGusta();
    r_musica->Comentar(post1, comentario1_3);

    Contenido* post2 = new Contenido(fecha3,usuario2,"Cuando sale el disco?","Cuando sale??",TipoDeContenido::PUBLICACION); post2->nomeGusta();
    r_musica->Agregar(post2);
    Contenido* comentario2_1 = new Contenido(fecha3,usuario7,"Che man no dijiste que disco", TipoDeContenido::COMENTARIO); comentario2_1->meGusta();
    r_musica->Comentar(post2, comentario2_1);
    Contenido* respuesta2_1_1 = new Contenido(fecha4,usuario7,"Nono asi se llama el disco, 'Cuando sale?'", TipoDeContenido::COMENTARIO); respuesta2_1_1->meGusta();respuesta2_1_1->meGusta();respuesta2_1_1->meGusta();
    r_musica->Responder(post2, comentario2_1,respuesta2_1_1);


    Contenido* post3 = new Contenido(fecha4,usuario3,"Que feo que te gusten los redondos","No puedo creer que haya gente que tenga gustos distintos a los mios, que no saben tener buen gusto? Todos saben que la mejor banda es soda, el mejor vino es el patero y la comida mas rica es el helado de mondongo",TipoDeContenido::PUBLICACION); post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();
    r_musica->Agregar(post3);
    Contenido* comentario3_1 = new Contenido(fecha4,usuario4,"Que decis man? como no te van a gustar los redondos? Que cuadrado...", TipoDeContenido::COMENTARIO);
    r_musica->Comentar(post3,comentario3_1);
    Contenido* comentario3_2 = new Contenido(fecha4,usuario4,"Como me lo vas a insultar asi al ricota!! encima hizo el tema del mundial!! MUCHAAACHOSSSS", TipoDeContenido::COMENTARIO);comentario3_2->nomeGusta();
    r_musica->Comentar(post3,comentario3_2);

    r_musica->Imprimir();
    cout << "-------------------------------------------------------FIN PRIMERA PRUEBA--------------------------------------------------------------------- "<< endl;
    r_musica->BorrarPost(post2);
    r_musica->Imprimir();


}
void bienvenida(){
    cout << "Bienvenido a Reddin´t" << endl ;
    cout<<R"(                                                                                                    
                                                                   &@@@@@.                          
                                                   @@@@@@@@@@@@/  @@@@@@@@@@@@@                     
                                                  ,@@@   ,@@@@@@@@@@@@@@@@@@@@@@#                   
                                                  @@@@          @@@@@@@@@@@@@@@.                    
                                                 *@@@          ,@@@@@@@@@@@@@@                      
                                                 @@@@               @@@@@@@@@                       
                                                *@@@                     /@@                        
                                                @@@@                                                
                                               /@@@                                                 
                                     %@@@@@@@@@@@@@@@@@@@@@@@                                       
                             /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%                               
               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(@@@@@@@@.                 
             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               
            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@              
            @@@@@@@@@@@@@@@@@@@@@      ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@              
            (@@@@@@@@@@@@@@@@@@          %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@              
              @@@@@@@@@@@@@@@@            @@@@@@@@@@@@@@    ./,     @@@@@@@@@@@@@@@@                
              @@@@@@@@@@@@@@@@@          %@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@@@                
              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@                
              &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%   @@@@@@@@@@@@@@@@@@@                
               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@                 
                 @@@@@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@@@@@@@@@@@@@@@@@&                  
                  /@@@@@@@@@@@@@@@@@@.     @@@@@@@@@@@%     .@@@@@@@@@@@@@@@@@@@                    
                     @@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@   #@@@@@@@@@@@@@                       
                        (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&                          
                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                               
                                    .@@@@@@@@@@@@@@@@@@@@@@@@*                                      
                                                                                                    )"<<endl;
}