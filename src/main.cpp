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
    ArbolBinario<Contenido>* reddint = new ArbolBinario<Contenido>();
    bool on = true;
    char opcion;
    //Primero debes iniciar sesión
    cout<<"Inicia sesion"<<endl;
    cout << "Ingresa el usuario" << endl;
    Usuario* usuarioActual = ingresarUsuario();
    
    cout << "Ingresa la fecha de hoy" << endl;
    Fecha* fechaActual = ingresarFecha();
    


    while(on){
      cout<<"Menu"<<endl<<"A. Ir a publicaciones"<<endl<<"B. Publicar"<<endl<<"salir"<<endl;
      cin>>opcion;
      switch (opcion)
      {
        case 'A':
        reddint->ImprimirP();
        break;
        case 'B':
        reddint->Agregar(ingresarPublicacion(fechaActual,usuarioActual));
        break;
        case 'C':
        on = false;
        break;
      default:
        break;
      }
};
}

Fecha* ingresarFecha()
{
    int d, m, a;
    cout <<"Dia (DD): ";
    cin >> d;
    cout <<"Mes (MM): ";
    cin >> m;
    cout << "Año (YYYY): ";
    cin >> a;
    return new Fecha(d,m,a);
}

Usuario* ingresarUsuario()
{
    string nombre;
    cout << "Nombre de usuario: ";
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
    cout << "Bienvenido a Reddin't" << endl ;
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