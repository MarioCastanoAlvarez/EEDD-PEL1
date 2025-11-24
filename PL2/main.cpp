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
    string entrada;
    int i;
    getline(cin, entrada); cout<<endl;
    if (esEntero(entrada)){
        i = stoi(entrada);

//Funciones del sistema
        switch(i){

//Opción 0: finaliza el programa.
        case 0:{
            cout<<"Se ha elegido: 0) Salir del programa."<<endl<<endl;
            break;}

//Opcion 1:
        case 1:{
            cout<<"Se ha elegido: 1) Insertar una librería de forma manual."<<endl<<endl;
            break;}

//Opcion 2:
        case 2:{
            cout<<"Se ha elegido: 2) Borrar una librería del árbol."<<endl<<endl;

            break;}

//Opcion 3:
        case 3:{
            cout<<"Se ha elegido: 3) Mostrar los datos de los pedidos de una librería dada."<<endl<<endl;

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
            cout<<"Se ha elegido: 6) Llevar un pedido concreto de una librería a otra."<<endl<<endl;

            break;}
//Opcion 7:
        case 7:{
            cout<<"Se ha elegido: 7) Mostrar una estadística de las librerías."<<endl<<endl;

            break;}
//Opcion 8:
        case 8:{
            cout<<"Se ha elegido: 8) Continuar con la distribución de pedidos."<<endl<<endl;

            break;}
        default:
//Control de errores
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"======================================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"======================================================================="<<endl<<endl;};
    }while (i!=0);
}
