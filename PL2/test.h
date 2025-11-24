#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#define ASCENDENTE 0
#define DESCENDENTE 1

//Clase Nodo
class Nodo
{
private:
int valor;
Nodo *siguiente;
Nodo *anterior;
friend class Lista;
public:
Nodo(int v, Nodo *sig = NULL, Nodo *ant = NULL)
{
valor = v;
siguiente = sig;
anterior = ant;
}
};
typedef Nodo *pnodo;

//Clase Lista
class Lista
{
private:
pnodo cabeza, actual, final;
public:
Lista() {cabeza=actual=final=NULL; }
~Lista();
void insertarNodo(int v, char c);
void borrarNodo(char c);
bool listaVacia();
void esCabeza();
void esFinal();
void esSiguiente();
void esAnterior();
bool esActual();
int valorActual();
void recorrerLista(int);
};

#endif // TEST_H_INCLUDED
