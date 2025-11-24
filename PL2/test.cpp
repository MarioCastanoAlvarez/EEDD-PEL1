#include <iostream>
#include <ctime>
#include "test.h"
#include <iomanip>

using namespace std;

//Destructor de Lista.
Lista::~Lista(){
pnodo aux;
esCabeza();
while(cabeza){
    aux = cabeza;
    cabeza = cabeza->siguiente;
    delete aux;
    }
cabeza=NULL;
actual=NULL;
final=NULL;
}
//Inserta un Nodo en la lista.
void Lista::insertarNodo(int v, char c)
{
pnodo aux;
char tipoInsercion;
tipoInsercion=c;
if(listaVacia()) { // Si la lista está vacía
    aux = new Nodo(v,NULL,NULL);
    final=cabeza=aux;
    }
else if (tipoInsercion=='f') {//Inserción por el final
    aux= new Nodo(v,NULL,NULL);
    aux->anterior=final;
    final->siguiente=aux;
    final=aux;
    }
else if (tipoInsercion=='p') {//Inserción por el principio
    aux= new Nodo(v,NULL,NULL);
    aux->siguiente=cabeza;
    cabeza->anterior=aux;
    cabeza=aux;
    }
}

//Elimina un Nodo de la lista
void Lista::borrarNodo(char c)
{
char tipoBorrado; tipoBorrado=c;
if(tipoBorrado=='f') {      //Eliminación por el final
    pnodo aux=NULL;
    if((cabeza==final)) {       //Sólo hay elemento
        aux=final;
        cabeza = final = NULL;
        aux=NULL;
        delete aux;
        }
    else {
        aux=final;
        final=final->anterior;
        aux->anterior=NULL;
        final->siguiente=NULL;
        delete aux;
        }
    }
else if(tipoBorrado=='p') { //Eliminación por el Principio
    pnodo aux=NULL;
    if((cabeza==final)) {       //Sólo hay elemento
    aux=cabeza;
    cabeza = final = NULL;
    aux=NULL;
    delete aux;
    }
    else {
    aux=cabeza;
    cabeza=cabeza->siguiente;
    aux->siguiente=NULL;
    cabeza->anterior=NULL;
    delete aux;
    }
}
}

//Recorre toda la lista mostrando sus valores por pantalla
void Lista::recorrerLista (int orden){
pnodo aux;
if (orden == ASCENDENTE) {
    esCabeza();
    aux = cabeza;
    while(aux){
        cout << aux->valor << "-> ";
        aux = aux->siguiente;
        }
    }
else {
    esFinal();
    aux = final;
    while(aux) {
        cout << aux->valor << "-> "; aux = aux->anterior;
        }
    }
cout << endl;
}

//Mira si el puntero Cabeza es Null.
bool Lista::listaVacia()
{
return cabeza == NULL;
}

//Apunta Actual al Siguiente de actual si este no apunta a Null actualmente.
void Lista::esSiguiente()
{
if(actual) actual = actual->siguiente;
}

//Apunta Actual al Anterior de actual si este no apunta a Null actualmente.
void Lista::esAnterior()
{
if(actual) actual = actual->anterior;
}

//Apunta Actual a Cabeza.
void Lista::esCabeza()
{
actual=cabeza;
}
//Apunta Actual a Final.
void Lista::esFinal()
{
actual=final;
}

//Mira si el puntero Actual apunta a algo o no.
bool Lista::esActual()
{
return actual != NULL;
}

//Devuelve el valor del puntero Actual.
int Lista::valorActual()
{
if (!listaVacia()) return actual->valor;
else return 0;
}
