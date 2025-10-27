#include <iostream>
#include <ctime>
#include "editorial.h"
#include "iomanip"

using namespace std;

//Funcion para verificar si una entrada es un entero o no.
bool esEntero(string entrada){
    if(entrada.empty())return false;
    for (char c : entrada){
        if(!isdigit(c))return false;
    } return true;
};

//Todas las funcionas que generan de forma aleatoria los atributos previos. Para todas estas funciones, debe estar la linea de codigo "srand(time(NULL));" en el main().
//Funcion auxiliar que genera un digito (0-9) aleatorio. Está comprobado que funciona correctamente.
int digitoRandom(){
    int resultado = rand()%10;
    return resultado;
};

//Devuleve un int (0-9) aleatorio que representa la id de la editorial. Está comprobado que funciona correctamente.
int id_editorialRandom(){
    int resultado = rand()%LIBRERIAS;
    return resultado;
};

//Devuleve un string (PXXXXX; P="literalmente la letra 'P'"; X="un número entero 0-9") aleatorio que representa la id del pedido. Está comprobado que funciona correctamente.
string id_pedidoRandom(){
    string resultado = "P";
    for(int i = 0; i<5; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};


//Devuleve un string (XXXKXX; X="un número entero 0-9; K="literalmente la letra 'K') aleatorio que representa el codigo del libro. Está comprobado que funciona correctamente.
string cod_libroRandom(){
    string resultado="";
    for(int i = 0; i<3; ++i)
        resultado+=to_string(digitoRandom());
    resultado+="K";
    for(int i = 0; i<2; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};

//Devuleve un string aleatorio que representa una materia de entre las siguietes: Matemáticas, Física, Tecnología, Música, Historia y Lengua. Está comprobado que funciona correctamente.
string materiaRandom(){
    string materias[]={"Matematicas", "Fisica", "Tecnologia", "Musica", "Historia", "Lengua"};
    string resultado = materias[rand()%6];
    return resultado;
};

//Devuleve un int (0-20) aleatorio que representa las unidades. Está comprobado que funciona correctamente.
int unidadesRandom(){
    int resultado = rand()%21;
    return resultado;
};

//Obviamente no hay funcion de generación aleatoria de "estado".
//Fin de las funcionas que generan de forma aleatoria los atributos previos.

//Funciones de nodos
//Funcion que devuelve el pedido
Pedido Nodo::getPedido()
{
    return pedido;
}

//Funcion que devuelve el siguiente nodo

//Funciones de Colas.
//Funcion encolar.
void Cola::encolar(Pedido pd)
{
    pNodo nuevo;
    nuevo = new Nodo(pd);

    if(final) final->siguiente = nuevo;
    final= nuevo;
    if(!frente) frente = nuevo;
}

//Funcion desencolar.
Pedido Cola::desencolar()
{
    pNodo nodo;
    Pedido pd;
    Pedido vacio = VACIO;
    if (!frente) return vacio; //Evita el acceso a un nodo vacío.
    nodo = frente;
    frente = nodo->siguiente;
    pd = nodo->pedido;

    delete nodo;

    if(!frente) final = NULL;
    return pd;
}

//Funcion destructor.
Cola::~Cola(){
    while(frente) desencolar();
}

//Funcion para obtener el frente de la cola
pNodo Cola::getFrente()
{
    if (!frente){ return VACIO; }
    else { return frente; }
}

//Funcion para contar elementos de una Cola
int Cola::contarCola()
{
    pNodo nodo_aux = frente;
    int contador = 0;
    while (nodo_aux){
        contador++;
        nodo_aux = nodo_aux -> siguiente;
    }
    return contador;

}
//Funcion para imprimir cada elemnto de la cola con sus atributos
void Cola::imprimirCola()
{
    cout << "------------------------------------------------" << endl;
    cout << setw(3) << "Lib|" << setw(8) << "Id|"
    << setw(8) << "Codigo|" << setw(13) << "Materia|" << setw(4)
    << "U|" << setw(11) << "Estado|" << endl;
    cout << "------------------------------------------------" << endl;
    pNodo nodo_aux = frente;
    while(nodo_aux){

    cout << " " << setw(2) << nodo_aux->pedido.id_editorial << "|" << setw(7) << nodo_aux->pedido.id_pedido << "|"
    << setw(7) << nodo_aux->pedido.cod_libro << "|" << setw(12) << nodo_aux->pedido.materia << "|" << setw(3)
    << nodo_aux->pedido.unidades << "|" << setw(10) << nodo_aux->pedido.estado << "|" << endl;

    nodo_aux = nodo_aux -> siguiente;

    }
    cout << endl;
}
//Funciones de Pilas.
//Funcion apilar.
void Pila::apilar(Pedido pd)
{
    pNodo nuevo;

    nuevo = new Nodo(pd, cima);

    cima = nuevo;
}

//Funcion desapilar.
Pedido Pila::desapilar()
{
    pNodo nodo;
    Pedido pd;
    Pedido vacio = VACIO;

    if(!cima) return vacio;

    nodo = cima;
    cima = nodo->siguiente;
    pd = nodo->pedido;

    delete nodo;
    return pd;
}


//Funcion destructor.
Pila::~Pila()
{
    while(cima) desapilar();
}

//Funcion para imprimir cada elemento de una pila
void Pila::imprimirPila()
{
    cout << "------------------------------------------------" << endl;
    cout << setw(3) << "Lib|" << setw(8) << "Id|"
    << setw(8) << "Codigo|" << setw(13) << "Materia|" << setw(4)
    << "U|" << setw(11) << "Estado|" << endl;
    cout << "------------------------------------------------" << endl;
    pNodo nodo_aux = cima;
    while(nodo_aux){

    cout << " " << setw(2) << nodo_aux->pedido.id_editorial << "|" << setw(7) << nodo_aux->pedido.id_pedido << "|"
    << setw(7) << nodo_aux->pedido.cod_libro << "|" << setw(12) << nodo_aux->pedido.materia << "|" << setw(3)
    << nodo_aux->pedido.unidades << "|" << setw(10) << nodo_aux->pedido.estado << "|" << endl;

    nodo_aux = nodo_aux -> siguiente;

    }
    cout << endl;
}

//Funcion para contar el numero de elementos de una Pila
int Pila::contarPila()
{
    pNodo nodo_aux = cima;
    int contador = 0;

    while(nodo_aux){
        contador++;
        nodo_aux = nodo_aux->siguiente;
    }
    return contador;
}
Pedido Pila::elemento_pos(int pos)
{
    pNodo nodo_aux = cima;
    if (!cima){ return VACIO; }
    else if (this.contarPila() < pos) {return VACIO;}
    else (pos<=this.contarPila()){
        for (int i = 0; i<pos; i++){
            nodo_aux = nodo_aux->siguiente;
        }
        return nodo_aux->pedido;
    }
}
//Funcion para generar un stock (Pila)
void Pila::generarStock()
{
    for (int i = 0; i < MAX_TITULOS; i++){ apilar(generarPedido()); }
}

//Funcion para imprimr cada elemento del stock
void Pila::imprimirStock()
{
    cout << "----------------------------------" << endl;
    cout << setw(9) << "Codigo|" << setw(13) << "Materia|" << setw(12)
    << "Unidades|" << endl;
    cout << "----------------------------------" << endl;

    pNodo nodo_aux = cima;
    while(nodo_aux){

    cout << " " <<  setw(7) << nodo_aux->pedido.cod_libro << "|" << setw(12) << nodo_aux->pedido.materia << "|" << setw(11)
    << nodo_aux->pedido.unidades << "|"<< endl;

    nodo_aux = nodo_aux -> siguiente;

    }
    cout << endl;
}

//Funciones de ejecución segun la opcion seleccionada en el menu.
//Fucion si se elige la opcion 1.
Pedido generarPedido(){
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
