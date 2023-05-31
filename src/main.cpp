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
void panelDeUsuario(Usuario *&usuario, ArbolBinario<Contenido> *arbol);
ArbolBinario<Contenido>* crearSubredditMusica();

int main(){

    bienvenida();
    ArbolBinario<Contenido>* subreddint_vacio = new ArbolBinario<Contenido>();
    ArbolBinario<Contenido>* subreddint_musica = crearSubredditMusica();
    ArbolBinario<Contenido>* reddint;
    char opcion;
    //Antemenu
    cout<<"Inicia sesion"<<endl;
    cout << "Ingresa el usuario" << endl;
    Usuario* usuarioActual = ingresarUsuario();
    cout << "Ingresa la fecha de hoy" << endl;
    Fecha* fechaActual = ingresarFecha();

    //menu1 - que subreddint
    char opcion1;
    cout << "¿A que subreddin't quieres acceder? \n A) Subreddint de musica \n B) Subreddint vacio \n";
    cin >> opcion1;
    switch(toupper(opcion1))
    {
        case 'A':
        reddint = subreddint_musica;
        break;
        case 'B':
        reddint = subreddint_vacio;
        break;
    }

    //menu2 - Panel Principal
    while(true){
      cout<<"Menu"<<endl<<"A) Ir a publicaciones"<<endl<<"B) Panel de usuarios"<<endl<<"X) Salir"<<endl;
      cin>>opcion;
      switch (toupper(opcion))
      {
        case 'A':
            //panelPublicaciones
            break;
        case 'B':
            panelDeUsuario(usuarioActual, reddint);
            break;
        case 'X':
            exit(0);
            break;
      default:
        break;
      }
    }
};
   
    //     cout << "Que quieres hacer?" << endl << "A) Ver muro" << endl << "B) Publicar" << endl << "C) Comentar" << endl << "D) Responder" << endl << "E) Seleccionar nueva fecha" << endl << "F) Cambiar de usuario"<< endl<<"G) Imprimir publicacion"<< endl << "H) Participaciones del Usuario" << endl << "I) Me gusta"<< endl <<"J) No me gusta"<<endl << "K) Borrar la ultima publicacion "<<endl<<"X) Salir"<<endl;
    //     switch (opcion)
    //     {
    //     case 'A':
    //         reddint->Imprimir();
    //         break;
    //     case 'B':
    //         publicacion = ingresarPublicacion(fecha, usuario);
    //         cout << "Publicando..." << endl;
    //         reddint->Agregar(publicacion);
    //         cout << "Publicado" << endl;
    //         break;
    //     case 'C':
    //         comentario = ingresarContenido(fecha, usuario, TipoDeContenido::COMENTARIO);
    //         reddint->Comentar(publicacion, comentario);
    //         break;
    //     case 'D':
    //         respuesta = ingresarContenido(fecha, usuario, TipoDeContenido::RESPUESTA);
    //         cout << "Publicando..." << endl;
    //         reddint->Responder(publicacion, comentario, respuesta);
    //         cout << "Publicado" << endl;
    //         break;
    //     case 'E':
    //         fecha = ingresarFecha();
    //         cout << "Fecha cambiada a: ";
    //         fecha->imprimir();
    //         break;
    //     case 'F':
    //         usuario = ingresarUsuario();
    //         cout << "Usuario cambiado a: ";
    //         usuario->imprimir();
    //         break;
    //     case 'G':
    //         reddint->ImprimirPublicacion(publicacion);
    //         break;
    //     case 'H':
    //         reddint->ImprimirParticipaciones(usuario);
    //         break;
    //     case 'I':
    //         elegirContenido(publicacion, comentario, respuesta)->meGusta();
    //         cout << "Me gusta realizado" << endl;
    //         break;
    //     case 'J':
    //         elegirContenido(publicacion, comentario, respuesta)->nomeGusta();
    //         cout << "No me gusta realizado" << endl;
    //         break;
    //     case 'K':
    //         reddint->BorrarPost(publicacion);
    //         cout << "Publicacion eliminada" << endl;
    //         break;
    //     case 'X':
    //         exit(0);
    //         break;
    //     default:
    //         break;
    //     }

    // }
// };

Fecha* ingresarFecha()
{
    int d, m, a;
    bool valido = false;
    while(valido == false){
        cout <<"Dia: ";
        cin >> d;
        cout <<"Mes: ";
        cin >> m;
        cout << "Año: ";
        cin >> a;

        if(d <= 31 && d >= 1 && m <= 12 && m >= 1){
            valido = true;
        }else{
            cout << "Fecha invalida, ingrese una fecha valida!!!" << endl << endl;
        }
    }
    return new Fecha(d,m,a);
}

Usuario* ingresarUsuario()
{
    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    return new Usuario(nombre);
}

Contenido* ingresarPublicacion(Fecha* fecha, Usuario* usuario)
{
    string titulo, cuerpo;
    cout << "Titulo: ";
    getline(cin.ignore(), titulo);
    cout << "Cuerpo: ";
    getline(cin, cuerpo);
    return new Contenido(fecha, usuario, titulo, cuerpo, TipoDeContenido::PUBLICACION);
}

Contenido* ingresarContenido(Fecha* fecha, Usuario* usuario, TipoDeContenido tipo)
{
    string cuerpo;
    cout << "Cuerpo: ";
    getline(cin.ignore(), cuerpo);
    return new Contenido(fecha, usuario, cuerpo, tipo);
}

Contenido* elegirContenido(Contenido* publicacion, Contenido* comentario, Contenido* respuesta){
    char opcionContenido;
    cout << "Que contenido quieres elegir? " << endl << "A) Ultima publicacion "<<endl<<"B) Ultimo comentario"<<endl<<"C) Ultima respuesta"<<endl;
    cin >> opcionContenido;
    switch (opcionContenido)
    {
    case 'A':
        return publicacion;
        break;
    case 'B':
        return comentario;
        break;
    default:
        return respuesta;
        break;
    }
}

void panelDeUsuario(Usuario*& usuario, ArbolBinario<Contenido> *arbol){

    cout << "Entrando al panel de usuario..." << endl;
    cout << "Usuario: ";
    usuario->imprimir();
    char opcion;

    cout << "Que quiere hacer? \n A) Participaciones \n B) Cambiar de usuario \n Presione cualquier letra para volver a inicio \n";
    cin >> opcion;

    switch (toupper(opcion))
    {
    case 'A':
        arbol->ImprimirParticipaciones(usuario);
        break;
    case 'B':
        usuario = ingresarUsuario();
        break;  
    default:
        break;
    }
}

ArbolBinario<Contenido>* crearSubredditMusica()
{   
    ArbolBinario<Contenido>* r_musica = new ArbolBinario<Contenido>();
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
    Contenido* respuesta1_2_1 = new Contenido(fecha3,usuario1,"Me interesa lla t escribi bro", TipoDeContenido::RESPUESTA);
    r_musica->Responder(post1, comentario1_2, respuesta1_2_1);
    Contenido* comentario1_3 = new Contenido(fecha2,usuario9,"Nosotros tenemos un proyecto para crear ese tipo de musica! tambien para derrocar las instituciones actuales y crear histeria en masa, si te interesa mandame mensaje, ya casi termino el secundario", TipoDeContenido::COMENTARIO); comentario1_3->nomeGusta();
    r_musica->Comentar(post1, comentario1_3);

    Contenido* post2 = new Contenido(fecha3,usuario2,"Cuando sale el disco?","Cuando sale??",TipoDeContenido::PUBLICACION); post2->nomeGusta();
    r_musica->Agregar(post2);
    Contenido* comentario2_1 = new Contenido(fecha3,usuario7,"Che man no dijiste que disco", TipoDeContenido::COMENTARIO); comentario2_1->meGusta();
    r_musica->Comentar(post2, comentario2_1);
    Contenido* respuesta2_1_1 = new Contenido(fecha4,usuario7,"Nono asi se llama el disco, 'Cuando sale?'", TipoDeContenido::RESPUESTA); respuesta2_1_1->meGusta();respuesta2_1_1->meGusta();respuesta2_1_1->meGusta();
    r_musica->Responder(post2, comentario2_1,respuesta2_1_1);

    Contenido* post3 = new Contenido(fecha4,usuario3,"Que feo que te gusten los redondos","No puedo creer que haya gente que tenga gustos distintos a los mios, que no saben tener buen gusto? Todos saben que la mejor banda es soda, el mejor vino es el patero y la comida mas rica es el helado de mondongo",TipoDeContenido::PUBLICACION); post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();post3->nomeGusta();
    r_musica->Agregar(post3);
    Contenido* comentario3_1 = new Contenido(fecha4,usuario4,"Que decis man? como no te van a gustar los redondos? Que cuadrado...", TipoDeContenido::COMENTARIO);
    r_musica->Comentar(post3,comentario3_1);
    Contenido* comentario3_2 = new Contenido(fecha4,usuario4,"Como me lo vas a insultar asi al ricota!! encima hizo el tema del mundial!! MUCHAAACHOSSSS", TipoDeContenido::COMENTARIO);comentario3_2->nomeGusta();
    r_musica->Comentar(post3,comentario3_2);

    return r_musica;
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