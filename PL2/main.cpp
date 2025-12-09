#include <iostream>
#include <ctime>
#include "ccontrol.h"

using namespace std;



int main()
{
ArbolABB libs;
ListaS lista_id;

for (int i = 0; i < N_LIBRERIAS; i++){
    Libreria lib = generarLibreria();
    libs.Insertar(lib);
    lista_id.insertarNodo(lib.id_lib);
}

    string entrada;
    int i;
    do{
    cout<<"=== MENU ==="<<endl
    <<"1) Insertar una libreria de forma manual."<<endl
    <<"2) Borrar una libreria del arbol."<<endl
    <<"3) Mostrar los datos de los pedidos de una libreria dada."<<endl
    <<"4) Buscar un pedido concreto por su ID."<<endl
    <<"5) Extraer un pedido concreto."<<endl
    <<"6) Llevar un pedido concreto de una libreria a otra."<<endl
    <<"7) Mostrar una estadistica de las librerias."<<endl
    <<"8) Continuar con la distribucion de pedidos."<<endl
    <<"0) Salir del programa."<<endl
    <<endl
    <<"Opcion: ";

//Seleccion de opcion

    getline(cin, entrada); cout<<endl;
    if (esEntero(entrada)){
        i = stoi(entrada);

//Funciones del sistema
        switch(i){

//Opci�n 0: finaliza el programa.
        case 0:{
            cout<<"Se ha elegido: 0) Salir del programa."<<endl<<endl;
            break;}

//Opcion 1:
        case 1:{
            cout<<"Se ha elegido: 1) Insertar una libreria de forma manual."<<endl<<endl;
            bool ready=false;
            int id;
            cout<<"Introduzca el id de la libreria: ";
            do{
                getline(cin, entrada); cout<<endl;
                if (esEntero(entrada)){
                    id = stoi(entrada);
                    if(libs.Buscar(id)){
                        cout<<"El id introducido corresponde a una libreria ya existente."<<endl<<
                        "Por favor, introduzca otro valor: "<<endl<<endl;
                    } else{
                        ready=true;
                    }
                } else { cout<<"�Error. El valor introducido no es un entero."<<endl<<endl<<"Por favor, introduzca un entero: ";
                }
            }while(!ready);
            cout<<"Introduzca el nombre de la locaclidad donde se ubica la libreria: ";
            getline(cin, entrada); cout<<endl;
            Libreria lib = generarLibreria();
            lib.id_lib=id;
            lib.localidad=entrada;
            libs.Insertar(lib);
            cout<<"La libreria fue insertada con exito."<<endl;
            break;}

//Opcion 2:
        case 2:{
            cout<<"Se ha elegido: 2) Borrar una libreria del arbol."<<endl<<endl
            <<"Introduzca el id de la libreria que desea borrar: ";
            bool ready=false;
            int id;
            do{
            getline(cin, entrada); cout<<endl;
            if (esEntero(entrada)){
                    id = stoi(entrada);
                    if(libs.Buscar(id)){
                        libs.Borrar(id);
                        ready=true;
                    }else{cout<<"La libreria seleccionada no existe."<<endl;
                    }
            } else{ cout<<"�Error. El valor introducido no es un entero."<<endl<<endl<<"Por favor, introduzca un entero: ";
            }
            }while(!ready);
            cout<<"La libreria ha sido borrada con exito."<<endl;
            break;}

//Opcion 3:
        case 3:{
            cout<<"Se ha elegido: 3) Mostrar los datos de los pedidos de una libreria dada."<<endl<<endl;

            break;}

//Opcion 4:
        case 4:{
            cout<<"Se ha elegido: 4) Buscar un pedido concreto por su ID."<<endl<<endl;

            break;}

//Opcion 5:
        case 5:{
            cout<<"Se ha elegido: 5) Extraer un pedido concreto."<<endl<<endl;

            break;}
//Opcion 6:
        case 6:{
            cout<<"Se ha elegido: 6) Llevar un pedido concreto de una libreria a otra."<<endl<<endl;

            break;}
//Opcion 7:
        case 7:{
            cout<<"Se ha elegido: 7) Mostrar una estadistica de las librerias."<<endl<<endl;

            break;}
//Opcion 8:
        case 8:{
            cout<<"Se ha elegido: 8) Continuar con la distribucion de pedidos."<<endl<<endl;
                for (int j = 0; j < N_PEDIDOS; j++){
                    Pedido pd = generarPedido(lista_id);
                }
            break;}
        default:
//Control de errores
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"======================================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"======================================================================="<<endl<<endl;};
    }while (i!=0);
}
