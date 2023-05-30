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
    
    cout << "Haz la primera publicacion!! "<< endl;
    ArbolBinario<Contenido>* reddint = new ArbolBinario<Contenido>();
    
    cout << "Ingresa el usuario" << endl;
    Usuario* usuario = ingresarUsuario();
    
    cout << "Ingresa la fecha" << endl;
    Fecha* fecha = ingresarFecha();
    
    cout << "Ingresa la publicacion" << endl;
    Contenido* publicacion = ingresarPublicacion(fecha, usuario);
    
    cout << "Publicando..." << endl;
    reddint->Agregar(publicacion);
    cout << "Publicado" << endl;

    while(true){
        char opcion;
        Contenido *comentario;
        Contenido *respuesta;
        cout << "Que quieres hacer?" << endl << "A) Ver muro" << endl << "B) Publicar" << endl << "C) Comentar" << endl << "D) Responder" << endl << "E) Seleccionar nueva fecha" << endl << "F) Cambiar de usuario"<< endl<<"G) Imprimir publicacion"<< endl << "H) Participaciones del Usuario" << endl << "I) Me gusta"<< endl <<"J) No me gusta"<<endl << "K) Borrar la ultima publicacion "<<endl<<"X) Salir"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 'A':
            reddint->Imprimir();
            break;
        case 'B':
            publicacion = ingresarPublicacion(fecha, usuario);
            cout << "Publicando..." << endl;
            reddint->Agregar(publicacion);
            cout << "Publicado" << endl;
            break;
        case 'C':
            comentario = ingresarContenido(fecha, usuario, TipoDeContenido::COMENTARIO);
            reddint->Comentar(publicacion, comentario);
            break;
        case 'D':
            respuesta = ingresarContenido(fecha, usuario, TipoDeContenido::RESPUESTA);
            cout << "Publicando..." << endl;
            reddint->Responder(publicacion, comentario, respuesta);
            cout << "Publicado" << endl;
            break;
        case 'E':
            fecha = ingresarFecha();
            cout << "Fecha cambiada a: ";
            fecha->imprimir();
            break;
        case 'F':
            usuario = ingresarUsuario();
            cout << "Usuario cambiado a: ";
            usuario->imprimir();
            break;
        case 'G':
            reddint->ImprimirPublicacion(publicacion);
            break;
        case 'H':
            reddint->ImprimirParticipaciones(usuario);
            break;
        case 'I':
            elegirContenido(publicacion, comentario, respuesta)->meGusta();
            cout << "Me gusta realizado" << endl;
            break;
        case 'J':
            elegirContenido(publicacion, comentario, respuesta)->nomeGusta();
            cout << "No me gusta realizado" << endl;
            break;
        case 'K':
            reddint->BorrarPost(publicacion);
            cout << "Publicacion eliminada" << endl;
            break;
        case 'X':
            exit(0);
            break;
        default:
            break;
        }

    }
};

Fecha* ingresarFecha()
{
    int d, m, a;
    cout <<"Dia: ";
    cin >> d;
    cout <<"Mes: ";
    cin >> m;
    cout << "Año: ";
    cin >> a;
    return new Fecha(d,m,a);
}

Usuario* ingresarUsuario()
{
    string nombre;
    cout << "Nombre: ";
    getline(cin.ignore(), nombre);
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