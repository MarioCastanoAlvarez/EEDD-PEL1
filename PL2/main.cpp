#include <iostream>

using namespace std;

int main()
{
    do{
    cout<<"=== MENU ==="<<endl
    <<"1) Insertar una librería de forma manual."<<endl
    <<"2) Borrar una librería del árbol."<<endl
    <<"3) Mostrar los datos de los pedidos de una librería dada."<<endl
    <<"4) Buscar un pedido concreto por su ID."<<endl
    <<"5) Extraer un pedido concreto."<<endl
    <<"6) Llevar un pedido concreto de una librería a otra."<<endl
    <<"7) Mostrar una estadística de las librerías."<<endl
    <<"8) Continuar con la distribución de pedidos."<<endl
    <<"0) Salir del programa."<<endl
    <<endl
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

            break;}

//Opcion 2: Paso de pedidos (12)
        case 2:{
            cout<<"Se ha elegido: 2) Paso (una FASE)"<<endl<<endl;

            break;}

//Opcion 3: Mostrar estado (Colas, Stock y Cajas)
        case 3:{
            cout<<"Se ha elegido: 3) Mostrar estado "<<endl<<endl;

            break;}

//Opcion 4: Mostrar pedidos contenidos en una de las cajas deseada.
        case 4:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}

//Opcion 5: Mostrar pedidos contenidos en una de las cajas deseada.
        case 5:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 6: Mostrar pedidos contenidos en una de las cajas deseada.
        case 6:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 7: Mostrar pedidos contenidos en una de las cajas deseada.
        case 7:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 8: Mostrar pedidos contenidos en una de las cajas deseada.
        case 8:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
        default:
//Control de errores
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"======================================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"======================================================================="<<endl<<endl;};
    }while (i!=0);
}
