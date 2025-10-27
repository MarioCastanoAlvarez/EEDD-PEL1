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
    int i = -1;
    Pedido pedido_aux;
    PStock.generarStock();
    do{
    cout<<"=== MENU ==="<<endl
    <<"1) Generar N pedidos"<<endl
    <<"2) Paso (una FASE)"<<endl
    <<"3) Mostrar estado"<<endl
    <<"4) Ver caja de una libreria"<<endl
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

            bool valido=false;
            while (!valido){

            //Numero de pedidos a generar
            string npedidos;
            cout<<"Introduzca la cantidad de pedidos que desea generar: ";
            getline(cin, npedidos);

            //Bucle que genera pedidos y los mete en la cola de iniciado
            if (esEntero(npedidos)) {

                for (int j=0; j<stoi(npedidos); j++) {
                        pedido_aux = generarPedido();
                        pedido_aux.estado = "Iniciado";
                        QIniciado.encolar(pedido_aux);
                        }valido=true;
            }
            else{
                cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
            }
            cout << "QIniciado:" << endl;
            QIniciado.imprimirCola();
            }
            break;
            }

        case 2:{
            cout<<"Se ha elegido: 2) Paso (una FASE)"<<endl<<endl;


            //Bulce que pasa pedidos de la cola "Almacen" a la cola "Imprenta" o a la cola "Listo"
            //en funcion de la necesidad de impresion de mas copias


            //Bucle que pasa pedidos de la cola "Iniciado" a la cola "Almacen"
            int npedidos = QIniciado.contarCola();
            if (npedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (npedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < npedidos; j++){
                        Pedido pedido = QIniciado.desencolar();
                        pedido.estado = "Almacen";
                        QAlmacen.encolar(pedido);
                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        Pedido pedido = QIniciado.desencolar();
                        pedido.estado = "Almacen";
                        QAlmacen.encolar(pedido);
                    }
                }
            }

            break;
            }
        case 3:
            cout<<"Se ha elegido: 3) Mostrar estado "<<endl<<endl;

            //Se imprimen todas las colas
            cout << "QIniciado:" << endl;
            QIniciado.imprimirCola();

            cout << "QAlmacen:" << endl;
            QAlmacen.imprimirCola();

            cout << "QImprenta:" << endl;
            QImprenta.imprimirCola();

            cout << "QListo:" << endl;
            QListo.imprimirCola();

            //Se imprime el stock
            cout << "== Stock ==" << endl;
            PStock.imprimirStock();

            break;
        case 4:
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


