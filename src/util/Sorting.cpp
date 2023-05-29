#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#ifndef SORTING
#define SORTING
class Sorting
{
protected:
    int mov, comp;
    bool exp; //booleano que habilita la explicación por consola en paso a paso
private:
    string sortType;
    int arrayLength;
    int* array; //Puntero a un array que se quiere ordenar
public:

    Sorting(int arrayLength);
    Sorting();
    void imprimirArray();
    void mezclar();
    void ordenar();
    void setSortType(string Stype);
    void setArray(int*);
    int* getArray();
    int getArrayLength();
    void setExp(bool);
};
Sorting::Sorting() //Constructor que no necesita tener el largo del array
{   
    arrayLength = 10;
    array = new int[arrayLength];
    sortType = "none";
    exp = false;
    mov=0;
    comp=0;
    mezclar();
}
Sorting::Sorting(int arrayLength) //Constructor que necesita tener el largo del array
{   
    this->arrayLength = arrayLength;
    array = new int[arrayLength];
    sortType = "none";
    exp = false;
    mov=0;
    comp=0;
    mezclar();
}
void Sorting::setSortType(string Stype)
{
    sortType = Stype;
}
void Sorting::imprimirArray() //Imprime el array
{   
    cout<<"\n"<<"---------- Array para el "<<sortType<<" Sorting   -------------" <<"\n";
    for(int i=0; i<arrayLength ; i++) 
        {cout<<"A["<<i<<"]:    "<< array[i] << endl;}
    cout<<"\n"<<"----------------- Fin del Array   --------------------" <<"\n";
}
void Sorting::setArray(int* array)
{
    this->array = array;

}
int* Sorting::getArray()
{
    return array;
}
int Sorting::getArrayLength()
{ 
    return arrayLength;
}
void Sorting::mezclar() //genera un numero aleatorio para cada elemento del array
{   
    for(int i=0; i < arrayLength ; i++)
        array[i] = int(rand());
}
void Sorting::ordenar()
{
    cout<<"No se ordena"<<endl;
}
void Sorting::setExp(bool setting)
{
    exp = setting;
};
#endif