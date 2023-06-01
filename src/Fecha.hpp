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
        Fecha(int d, int m, int a)
        {
            dia = d;
            mes = m;
            anio = a;
        }
        Fecha(){}
        
        
        //Devuelve true si la fecha es mayor a la ingresada por parametro
        bool esMayor(Fecha *otraFecha)
        {
            if (anio > otraFecha->anio) return true;
            else if (anio < otraFecha->anio) return false;

            if (mes > otraFecha->mes) return true;
            else if (mes < otraFecha->mes) return false;

            if (dia > otraFecha->dia) return true;
            else return false;
        }

        void imprimir()
        {
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
};

#endif