#include <iostream>
#include <ctime>
#include "editorial.h"

using namespace std;
bool esEntero(string entrada);

int main()
{
    Cola QIniciado;
    Cola QAlmacen;
    Cola QImprenta;
    Cola QListo;

    Pila PCaja0;
    Pila PCaja1;
    Pila PCaja2;
    Pila PCaja3;
    Pila PCaja4;
    Pila PCaja5;

    Pila PStock;


    srand(time(NULL));
    string entrada;
    int i;
    Pedido pedido_aux;
    do{
    cout<<"=== MENU ==="<<endl
    <<"1) Generar N pedidos"<<endl
    <<"2) Paso (una FASE)"<<endl
    <<"3) Mostrar estado"<<endl
    <<"4) Paso COMPLETO (4 fases)"<<endl
    <<"5) Ver caja de una libreria"<<endl
    <<"0) Salir"<<endl<<endl
    <<"Opcion: ";


    getline(cin, entrada); cout<<endl;
    if (esEntero(entrada)){
        i = stoi(entrada);
        switch(i){
        case 0:
            cout<<"Se ha elegido: 0) Salir"<<endl<<endl;
            break;
        case 1:{
            while (comp){
            string npedidos;
            cout<<"Introduzca la cantidad de pedidos que desea generar"<<endl;
            getline(cin, npedidos);


            if (esEntero(npedidos)) {

                for (int j; j<stoi(npedidos); j++) {
                        pedido_aux = opcion1();
                        QIniciado.encolar(pedido_aux);
                        comp = false
                } else {
                    printf("Por favor, introduzca un numero entero.")
                }

            }
            cout<<"Se ha elegido: 1) Generar N pedidos"<<endl<<endl;
            break;
            }
        }
        case 2:
            cout<<"Se ha elegido: 2) Paso (una FASE)"<<endl<<endl;
            break;
        case 3:
            cout<<"Se ha elegido: 3) Mostrar estado "<<endl<<endl;
            break;
        case 4:
            cout<<"Se ha elegido: 4) Paso COMPLETO (4 fases)"<<endl<<endl;
            break;
        case 5:
            cout<<"Se ha elegido: 5) Ver caja de una libreria"<<endl<<endl;
            break;
        default:
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"======================================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"======================================================================="<<endl<<endl;};
    }while (i!=0);
    cout<<"Fin del programa."<<endl<<endl;
    return 0;
}


