#include <iostream>
#include "Fecha.hpp"
#include "Usuario.hpp"
#include "Contenido.hpp"
#include "util\ArbolBinario.cpp"


using namespace std;

Fecha* ingresarFecha();
Contenido* ingresarPublicacion(Fecha* fecha, Usuario* usuario);
Usuario* ingresarUsuario();

int main(){
    cout << "Bienvenido a Reddin´t" << endl << "Haz la primera publicacion!! "<< endl;
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
        cout << "Que quieres hacer?" << endl << "A) Ver muro" << endl << "B)";

        reddint->Imprimir();

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
    getline(cin, nombre);
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
