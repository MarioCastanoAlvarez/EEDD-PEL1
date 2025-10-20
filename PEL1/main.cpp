#include <iostream>
#include <ctime>

using namespace std;
bool esEntero(string entrada);

int main()
{
    srand(time(NULL));
    string entrada;
    int i;
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
        case 1:
            cout<<"Se ha elegido: 1) Generar N pedidos"<<endl<<endl;
            break;
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


