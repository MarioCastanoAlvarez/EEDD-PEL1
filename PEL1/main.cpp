#include <iostream>
#include <ctime>
#include "editorial.h"

using namespace std;
bool esEntero(string entrada);

int main()
{
//Instanciación de variables
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
    int contPedidos;

//Inicio del programa

//Menu
    do{
    cout<<"=== MENU ==="<<endl
    <<"1) Generar N pedidos"<<endl
    <<"2) Paso (una FASE)"<<endl
    <<"3) Mostrar estado"<<endl
    <<"4) Ver caja de una libreria"<<endl
    <<"0) Salir"<<endl<<endl
    <<"Opcion: ";


//Seleccion de opcion
    getline(cin, entrada); cout<<endl;
    if (esEntero(entrada)){
        i = stoi(entrada);

//Funciones del sistema
        switch(i){
        case 0:
            cout<<"Se ha elegido: 0) Salir"<<endl<<endl;
            break;

//Opcion 1: generar N pedidos
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

//Opcion 2: Paso de pedidos (12)
        case 2:{
            cout<<"Se ha elegido: 2) Paso (una FASE)"<<endl<<endl;

            //Bucle que reparte cada pedido en la Cola "Listo" a su respectiva caja
            contPedidos = QListo.contarCola();
            if (contPedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (contPedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < contPedidos; j++){
                        pedido_aux = QListo.desencolar();
                        if (cajas[pedido_aux.id_libreria].contarPila() < CAP_CAJA - 1){
                                pedido_aux.estado = "caja";
                                cajas[pedido_aux.id_libreria].apilar(pedido_aux);
                        }
                        else {
                            cajas[pedido_aux.id_libreria].apilar(pedido_aux);
                            cajas[pedido_aux.id_libreria].~Pila();
                            cout << "Se ha enviado una caja a la libreria " << pedido_aux.id_libreria << endl;
                        }

                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        pedido_aux = QListo.desencolar();
                        if (cajas[pedido_aux.id_libreria].contarPila() < CAP_CAJA){
                                pedido_aux.estado = "caja";
                                cajas[pedido_aux.id_libreria].apilar(pedido_aux);
                        }
                        else {
                             cajas[pedido_aux.id_libreria].~Pila();
                             QListo.encolar(QListo.desencolar());
                        }
                    }
                }
            }
            //Bucle que pasa pedidos de la cola "Imprenta" a la cola listo o imprime mas libros para el stock

            contPedidos = QImprenta.contarCola();
            int max_paso = N_PEDIDOS_PASO;
            int cont = QImprenta.contarCola();

            if (contPedidos != 0){

                    while (max_paso > 0 && cont > 0) {
                        pedido_aux = QImprenta.desencolar();
                        int pos = buscarPosicion(pedido_aux.cod_libro, stock);

                        if (pedido_aux.unidades >= stock[pos].unidades){
                            stock[pos].unidades += TAM_LOTE;
                            QImprenta.encolar(pedido_aux);
                            cont--;
                        } else {
                            stock[pos].unidades -= pedido_aux.unidades;
                            pedido_aux.estado = "Listo";
                            QListo.encolar(pedido_aux);
                            cont--; max_paso--;
                        }

                    }
            }

            //Bulce que pasa pedidos de la cola "Almacen" a la cola "Imprenta" o a la cola "Listo"
            //en funcion de la necesidad de impresion de mas copias

            contPedidos = QAlmacen.contarCola();
            if (contPedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (contPedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < contPedidos; j++){
                        pedido_aux = QAlmacen.desencolar();
                        int pos = buscarPosicion(pedido_aux.cod_libro, stock);
                        string id = pedido_aux.id_pedido;

                        if (stock[pos].unidades >= pedido_aux.unidades){
                            pedido_aux.estado = "Listo";
                            QListo.encolar(pedido_aux);
                            stock[pos].unidades -= pedido_aux.unidades;
                        } else {
                            pedido_aux.estado = "Imprenta";
                            QImprenta.encolar(pedido_aux);
                        }
                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        pedido_aux = QAlmacen.desencolar();
                        int pos = buscarPosicion(pedido_aux.cod_libro, stock);
                        string id = pedido_aux.id_pedido;

                        if (stock[pos].unidades >= pedido_aux.unidades){
                            pedido_aux.estado = "Listo";
                            QListo.encolar(pedido_aux);
                            stock[pos].unidades -= pedido_aux.unidades;
                        } else {
                            pedido_aux.estado = "Imprenta";
                            QImprenta.encolar(pedido_aux);
                            }
                        }
                }
            }

            //Bucle que pasa pedidos de la cola "Iniciado" a la cola "Almacen"
            contPedidos = QIniciado.contarCola();
            if (contPedidos != 0){ //Se comprueba si hay pedidos en la cola
                if (contPedidos < N_PEDIDOS_PASO) {
                    for (int j = 0; j < contPedidos; j++){
                        pedido_aux = QIniciado.desencolar();
                        pedido_aux.estado = "Almacen";
                        QAlmacen.encolar(pedido_aux);
                    }
                } else {
                    for (int j = 0; j < N_PEDIDOS_PASO; j++) {
                        Pedido pedido_aux = QIniciado.desencolar();
                        pedido_aux.estado = "Almacen";
                        QAlmacen.encolar(pedido_aux);
                    }
                }
            }

            break;
            }

//Opcion 3: Mostrar estado (Colas, Stock y Cajas)
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

            //Se imprime el estado de las cajas
            cout << "== CAJAS (pilas por libreria) ==" << endl;
            imprimirEstadoCaja(cajas);

            break;

//Opcion 4: Mostrar pedidos contenidos en cada caja
        case 4:
            cout<<"Se ha elegido: 4) Ver caja de una libreria"<<endl<<endl;

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
//Control de errores
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"======================================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"======================================================================="<<endl<<endl;};
    }while (i!=0);
    cout<<"Fin del programa."<<endl<<endl;
    return 0;
}


