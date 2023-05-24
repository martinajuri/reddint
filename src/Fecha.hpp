#include <iostream>

using namespace std;

#ifndef FECHA_HPP
#define FECHA_HPP

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int d, int m, int a) {
            //validar fecha
            dia = d;
            mes = m;
            anio = a;
        }
        Fecha(){}
        
        bool fechaValida (int d, int m, int a){

            if(d <= 31 && d >= 1 && m <= 12 && m >= 1){
                return true;
            }else if (a > 5000){
                cout << "No hay mas de 5000 anios en esta linea temporal"<< endl;
                return false;
            }
            else{
                return false;
            }

        }
        
        //Devuelve true si la fecha es mayor a la ingresada por parametro
        bool esMayor(Fecha otraFecha) {
            if (anio > otraFecha.anio)
                return true;
            else if (anio < otraFecha.anio)
                return false;

            if (mes > otraFecha.mes)
                return true;
            else if (mes < otraFecha.mes)
                return false;

            if (dia > otraFecha.dia)
                return true;
            else
                return false;
        }

        void imprimir(){cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}
};

#endif