// Método de selección
#include <stdio.h>
#include <stdlib.h>
#include "Sorting.cpp"

#ifndef SELECTIONSORTING
#define SELECTIONSORITNG
class SelectionSorting : public Sorting
{
public:
    SelectionSorting();
    SelectionSorting(int arrayLength);
    void ordenar();
};

SelectionSorting::SelectionSorting() : Sorting()
{
    this->setSortType("Selection");
}
SelectionSorting::SelectionSorting(int arrayLength) : Sorting(arrayLength)
{
    this->setSortType("Selection");
}

void SelectionSorting::ordenar()
{   
    int menor, pos;
    cout<<"\n El array se está ordenando \n"<<endl;
    for(int i=0 ; i<this->getArrayLength() ; i++)
    {   
        if(exp){cout<<"Se realiza una pasada, con el menor siendo A["<<i<<"], \""<<this->getArray()[i]<<"\" : \n"<<endl;}
        pos = i;
        menor = this->getArray()[i];
        this->mov++;
        for(int j=i+1 ; j<this->getArrayLength() ; j++)
        {
            this->comp++;
            if(exp){cout<<"  Se compara el elemento "<<i<<", \""<<this->getArray()[i]<<"\" con el elemento "<<j<<", \""<<this->getArray()[j]<<"\": "<<endl;}
            if(this->getArray()[j]<menor)
            {
            if(exp){cout<<"    El elemento "<<j<<" es menor que el pivote "<<menor<<". Entonces es el nuevo pivote de la próxima pasada y swapean"<<endl;}
                menor=this->getArray()[j]; this->mov++;
                pos=j;
            }
            else{cout<<"    No es menor que el pivote."<<endl;}
    }
    this->getArray()[pos] = this->getArray()[i]; this->mov++; this->getArray()[i]=menor; this->mov++;
    if(exp){imprimirArray();}
}
cout<<"El array se ha ordenado después de "<<comp<<" comparaciones y "<< mov <<" movimientos"<<endl;
comp = 0;
mov = 0;
}

#endif