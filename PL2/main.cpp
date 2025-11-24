#include <iostream>

using namespace std;

int main()
{
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

//Opcion 4: Mostrar pedidos contenidos en una de las cajas deseada.
        case 5:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 4: Mostrar pedidos contenidos en una de las cajas deseada.
        case 5:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 4: Mostrar pedidos contenidos en una de las cajas deseada.
        case 6:{
            cout<<"Se ha elegido: 4)"<<endl<<endl;

            break;}
//Opcion 4: Mostrar pedidos contenidos en una de las cajas deseada.
        case 7:{
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
