#include <iostream>
#include <ctime>
#include "ccontrol.h"

using namespace std;



int main()
{
srand(time(NULL));
ArbolABB libs;
ListaS lista_id;
//Generación de librerías e impresión de su información
cout << "Informacion de librerias iniciales" << endl;
cout << "=================================================" << endl;
for (int i = 0; i < N_LIBRERIAS; i++){
    Libreria lib = generarLibreria();
    libs.Insertar(lib);
    lista_id.insertarNodo(lib.id_lib);

    mostrarLibreria(lib);
}

cout << "=================================================" << endl << endl;

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
    <<"9) Mostrar librerias"<<endl
    <<"0) Salir del programa."<<endl
    <<endl
    <<"Opcion: ";

//Seleccion de opcion

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
            cout<<"Se ha elegido: 1) Insertar una libreria de forma manual."<<endl
            <<"Introduzca el id de la libreria: ";
            bool ready=false;
            int id;
            do{
                getline(cin, entrada);
                if (esEntero(entrada)){
                    id = stoi(entrada);
                    if(libs.Buscar(id)){
                        cout<<"El id introducido corresponde a una libreria ya existente."<<endl<<endl<<
                        "Por favor, introduzca otro valor: ";
                    } else{
                        ready=true;
                    }
                } else { cout<<"Error. El valor introducido no es un entero."<<endl<<endl<<"Por favor, introduzca un entero: ";
                }
            }while(!ready);
            cout<<"Introduzca el nombre de la locaclidad donde se ubica la libreria: ";

            ready=false;
            do{
                getline(cin, entrada);
                if(esLocalidad(entrada)){
                    ready=true;
                }else {cout<<"La localidad seleccionada no esta contemplada en este centro de control."<<endl<<endl;
                mostrarLocalidades();
                cout<<endl<<endl<<"Por favor, seleccione otra localidad: ";
                }
            }while(!ready);
            Libreria lib = generarLibreria();
            lib.id_lib=id;
            lib.localidad=entrada;
            libs.Insertar(lib);
            cout<<"La libreria fue insertada con exito."<<endl<<endl<<"================================================="<<endl;
            libs.InOrden(mostrarLibreria,nullptr,true);
            break;}

//Opcion 2:
        case 2:{
            cout<<"Se ha elegido: 2) Borrar una libreria del arbol."<<endl
            <<"Introduzca el id de la libreria que desea borrar: ";
            bool ready=false;
            int id;
            do{
            getline(cin, entrada);
            if (esEntero(entrada)){
                    id = stoi(entrada);
                    if(libs.Buscar(id)){
                        libs.Borrar(id);
                        ready=true;
                    }else{cout<<"La libreria seleccionada no existe."<<endl<<endl<<"Por favor, introduzca otro valor: ";
                    }
            } else{ cout<<"Error. El valor introducido no es un entero."<<endl<<endl<<"Por favor, introduzca un entero: ";
            }
            }while(!ready);
            cout<<"La libreria ha sido borrada con exito."<<endl<<endl<<"================================================="<<endl;
            libs.InOrden(mostrarLibreria,nullptr,true);
            break;}

//Opcion 3:
        case 3:{
            int id;
            bool ready = false;
            cout<<"Se ha elegido: 3) Mostrar los datos de los pedidos de una libreria dada."<<endl<<endl;
            cout<<"Introduzca el id de la libreria: ";
            do{
                getline(cin, entrada);
                if (esEntero(entrada)){
                    id = stoi(entrada);
                    if(!libs.Buscar(id)){
                        cout<<"El id no corresponde a ninguna libreria del sistema."<<endl<<endl<<"Por favor, introduzca otro valor: ";
                    } else{
                        ready=true;
                    }
                } else { cout<<"Error. El valor introducido no es un entero."<<endl<<endl<<"Por favor, introduzca un entero: ";
                }
            }while(!ready);

            Libreria *libreria = libs.getLibreria(id);
            imprimirLibreria(*libreria);
            break;}

//Opcion 4:
        case 4:{
            cout<<"Se ha elegido: 4) Buscar un pedido concreto por su ID."<<endl;
            bool ready = false;
            cout<<"Introduzca el id del pedido deseado: ";
            do{
              getline(cin, entrada);
              if(esIdPedido(entrada))ready=true;
              else { cout<<"Error. El valor introducido no es del formato PXXXXX."<<endl<<endl<<"Por favor, introduzca un id de pedido: ";
                }
            }while(!ready);

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
            string materias[]={"Matematicas", "Fisica", "Tecnologia", "Musica", "Historia", "Lengua"};
            int contador[6] = {0,0,0,0,0,0};
            Libreria lib;
            Lista pedidosL;
                    for(int j = 0; j<lista_id.contar(); j++){
                        lib = *libs.getLibreria(lista_id.getValor(j));
                        pedidosL = *lib.lista;
                        for(int k = 0; k < pedidosL.contarLista(); k++){
                            string materia = pedidosL.getValor(k, ASCENDENTE).materia;
                            for (int l = 0; l<sizeof(materias); l++) {
                                if (materia == materias[l]) {contador[l]++; break;}
                            }
                        }
                    }
            imprimirEstadistica(lib, contador);
            break;}
//Opcion 8:
        case 8:{
            cout<<"Se ha elegido: 8) Continuar con la distribucion de pedidos."<<endl<<endl;
                for (int j = 0; j < N_PEDIDOS; j++){
                    Pedido pd = generarPedido(lista_id);
                    int id = pd.id_libreria;
                    libs.getLibreria(id)->lista->insertarNodo(pd, 'f');
                }
            break;}
//Opcion 9:
        case 9:{
            cout<<"Se ha elegido: 9) Mostrar librerias."<<endl<<endl;
                libs.InOrden(mostrarLibreria);
            break;}
        default:
//Control de errores
            cout<<"La opcion seleccionada no esta contemplada, pruebe de nuevo."<<endl<<endl;
    }cout<<"================================================="<<endl<<endl;
    }else {cout<<"Se ha introducido un valor no valido. Porfavor, introduzca un valor entero."<<endl<<endl;
    cout<<"================================================="<<endl<<endl;};
    }while (i!=0);
}

/*
cambios cpp
char fecha[50];
strftime(fecha, sizeof(fecha), "%d/%m/%Y", localtime(&pedido.fecha)); - 680

Libreria* ArbolABB::getLibreria(int id_lib)
{
    Libreria libreria;
    if(this->Buscar(id_lib)) {
        actual = raiz;
        while (id_lib != actual->libreria.id_lib) {
            if (id_lib < actual->libreria.id_lib) {actual = actual->izquierdo;}
            else if (id_lib > actual->libreria.id_lib) {actual = actual->derecho;}
        }
        libreria = actual->libreria;
    } else {
        libreria.id_lib = -1;
    }
    return &(actual->libreria);

} 400

void imprimirEstadistica(Libreria lib, int contador[])
{
    cout << setw(20) <<"===Cantidad de pedidos por materia==="<<endl;
    for (int i = 0; i < sizeof(materias); i++){
        cout << "Materia: " << setw(3) << materias[i] << " || " << "Pedidos: " << contador[i] << endl;

    }
}
*/
