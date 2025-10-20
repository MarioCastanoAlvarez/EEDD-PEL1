#include <iostream>
#include <ctime>
#include "editorial.h"

using namespace std;

//Funcion para verificar si una entrada es un entero o no.
bool esEntero(string entrada){
    if(entrada.empty())return false;
    for (char c : entrada){
        if(!isdigit(c))return false;
    } return true;
};

//Todas las funcionas que generan de forma aleatoria los atributos previos. Para todas estas funciones, debe estar la linea de codigo "srand(time(NULL));" en el main().
//Funcion auxiliar que genera un digito (0-9) aleatorio. Est� comprobado que funciona correctamente.
int digitoRandom(){
    int resultado = rand()%10;
    return resultado;
};

//Devuleve un int (0-9) aleatorio que representa la id de la editorial. Est� comprobado que funciona correctamente.
int id_editorialRandom(){
    int resultado = rand()%LIBRERIAS;
    return resultado;
};

//Devuleve un string (PXXXXX; P="literalmente la letra 'P'"; X="un n�mero entero 0-9") aleatorio que representa la id del pedido. Est� comprobado que funciona correctamente.
string id_pedidoRandom(){
    string resultado = "P";
    for(int i = 0; i<5; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};


//Devuleve un string (XXXKXX; X="un n�mero entero 0-9; K="literalmente la letra 'K') aleatorio que representa el codigo del libro. Est� comprobado que funciona correctamente.
string cod_libroRandom(){
    string resultado="";
    for(int i = 0; i<3; ++i)
        resultado+=to_string(digitoRandom());
    resultado+="K";
    for(int i = 0; i<2; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};

//Devuleve un string aleatorio que representa una materia de entre las siguietes: Matem�ticas, F�sica, Tecnolog�a, M�sica, Historia y Lengua. Est� comprobado que funciona correctamente.
string materiaRandom(){
    string materias[]={"Matematicas", "Fisica", "Tecnologia", "Musica", "Historia", "Lengua"};
    string resultado = materias[rand()%6];
    return resultado;
};

//Devuleve un int (0-20) aleatorio que representa las unidades. Est� comprobado que funciona correctamente.
int unidadesRandom(){
    int resultado = rand()%21;
    return resultado;
};

//Obviamente no hay funcion de generaci�n aleatoria de "estado".
//Fin de las funcionas que generan de forma aleatoria los atributos previos.


//Funciones de ejecuci�n segun la opcion seleccionada en el menu.
//Fucion si se elige la opcion 1.
Pedido opcion1(){
//    string entrada;
//    int i;
//    cout<<"N: "<<endl;
//    getline(cin, entrada); cout<<endl;
//    if (esEntero(entrada)){
//        i = stoi(entrada);};
//    for (i;0<i;--i){
        Pedido p;
        p.id_editorial=id_editorialRandom();
        p.id_pedido=id_pedidoRandom();
        p.cod_libro=cod_libroRandom();
        p.materia=materiaRandom();
        p.unidades=unidadesRandom();

        return p;
//    };
//    cout<<"Generados "<<i<<" pedidos en QIniciado."<<endl;
    cout<<"QIniciado: "<<endl;
};
