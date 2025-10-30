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

    Pedido stock[MAX_TITULOS];

    Pila cajas[] = {PCaja0, PCaja1, PCaja2, PCaja3, PCaja4, PCaja5};


    srand(time(NULL));
    string entrada;
    int i = -1;
    Pedido pedido_aux;
    generarStock(stock);
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
        int npedidos;
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
                int nlibro;

                for (int j=0; j<stoi(npedidos); j++) {
                        nlibro = digitoRandom();
                        pedido_aux = generarPedido();

                        pedido_aux.cod_libro = stock[nlibro].cod_libro;
                        pedido_aux.materia = stock[nlibro].materia;
                        pedido_aux.estado = "Iniciado";

                        QIniciado.encolar(pedido_aux);
                        }
                    valido=true;
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

            //Bucle que reparte cada pedido en la Cola "Listo" a su respectiva caja
            npedidos = QListo.contarCola();
            if (npedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (npedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < npedidos; j++){
                        Pedido pedido = QListo.desencolar();
                        if (cajas[pedido.id_editorial].contarPila() < CAP_CAJA){
                                pedido.estado = "caja";
                                cajas[pedido.id_editorial].apilar(pedido);
                        }
                        else {
                             cajas[pedido.id_editorial].~Pila();
                             pedido.estado = "caja";
                             cajas[pedido.id_editorial].apilar(pedido);
                        }

                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        Pedido pedido = QListo.desencolar();
                        if (cajas[pedido.id_editorial].contarPila() < CAP_CAJA){
                                pedido.estado = "caja";
                                cajas[pedido.id_editorial].apilar(pedido);
                        }
                        else {
                             cajas[pedido.id_editorial].~Pila();
                             QListo.encolar(QListo.desencolar());
                        }
                    }
                }
            }
            //Bucle que pasa pedidos de la cola "Imprenta" a la cola listo o imprime mas libros para el stock

            npedidos = QImprenta.contarCola();
            int max_paso = N_PEDIDOS_PASO;
            int cont = QImprenta.contarCola();

            if (npedidos != 0){

                    while (max_paso > 0 && cont > 0) {
                        Pedido pedido = QImprenta.desencolar();
                        int pos = buscarPosicion(pedido.cod_libro, stock);

                        if (pedido.unidades >= stock[pos].unidades){
                            stock[pos].unidades += TAM_LOTE;
                            QImprenta.encolar(pedido);
                            cont--;
                        } else {
                            stock[pos].unidades -= pedido.unidades;
                            QListo.encolar(pedido);
                            cont--; max_paso--;
                        }

                    }
            }

            //Bulce que pasa pedidos de la cola "Almacen" a la cola "Imprenta" o a la cola "Listo"
            //en funcion de la necesidad de impresion de mas copias

            npedidos = QAlmacen.contarCola();
            if (npedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (npedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < npedidos; j++){
                        Pedido pedido = QAlmacen.desencolar();
                        int pos = buscarPosicion(pedido.cod_libro, stock);
                        string id = pedido.id_pedido;

                        if (stock[pos].unidades >= pedido.unidades){
                            pedido.estado = "Listo";
                            QListo.encolar(pedido);
                            libro.unidades -= pedido.unidades;
                        } else {
                            pedido.estado = "Imprenta";
                            QImprenta.encolar(pedido);
                        }
                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        Pedido pedido = QAlmacen.desencolar();
                        Pedido libro = buscarEnStock(pedido.cod_libro, stock);
                        string id = pedido.id_pedido;

                        if (libro.unidades >= pedido.unidades){
                            pedido.estado = "Listo";
                            QListo.encolar(pedido);
                            libro.unidades -= pedido.unidades;
                        } else {
                            pedido.estado = "Imprenta";
                            QImprenta.encolar(pedido);
                        }
                    }
                }
            }

            //Bucle que pasa pedidos de la cola "Iniciado" a la cola "Almacen"
            npedidos = QIniciado.contarCola();
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
            imprimirStock(stock);

            break;
        case 4:
            cout<<"Se ha elegido: 5) Ver caja de una libreria"<<endl<<endl;

            //Se imprimen todas las colas
            cout << "Caja 0:" << endl;
            cajas[0].imprimirPila();

            cout << "Caja 1:" << endl;
            cajas[1].imprimirPila();

            cout << "Caja 2:" << endl;
            cajas[2].imprimirPila();

            cout << "Caja 3:" << endl;
            cajas[3].imprimirPila();

            cout << "Caja 4:" << endl;
            cajas[4].imprimirPila();

            cout << "Caja 5:" << endl;
            cajas[5].imprimirPila();

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


