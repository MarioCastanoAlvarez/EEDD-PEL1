#ifndef CCONTROL_H_INCLUDED
#define CCONTROL_H_INCLUDED

#define ASCENDENTE 0
#define DESCENDENTE 1
#define N_LIBRERIAS 10
#define N_PEDIDOS 30
#define VACIO Pedido{0, "", "", "", 0, ""}

#include <ctime>

using namespace std;

class Lista;
//Estructura de una librería
struct Libreria{
    int id_lib;
    string localidad;
    Lista *lista;
};

//Estructura de un pedido
struct Pedido{
    int id_libreria;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

//Estructura de árbol binario
class NodoA
{
    private:
        // Miembros:
        Libreria libreria;
        NodoA *izquierdo;
        NodoA *derecho;
        friend class ArbolABB;

    public:
        // Constructor:
        NodoA(const Libreria lib, NodoA *izq=NULL, NodoA *der=NULL) :
            libreria(lib), izquierdo(izq), derecho(der) {}

};
typedef NodoA *pnodoA;

class NodoL
{
    private:
        // Miembros:
        Pedido pedido;
        NodoL *izquierdo;
        NodoL *derecho;
        friend class Lista;

    public:
        // Constructor:
        NodoL(const Pedido ped, NodoL *izq=NULL, NodoL *der=NULL) :
            pedido(ped), izquierdo(izq), derecho(der) {}

};
typedef NodoL *pnodoL;


//Clase Lista
class Lista
{
    private:
        pnodoL cabeza, actual, final;
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


class ArbolABB
{
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        NodoA *raiz;
        NodoA *actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor básicos:
        ArbolABB() : raiz(NULL), actual(NULL) {}
        ~ArbolABB();
         // Insertar en árbol ordenado:
        void Insertar(const int dat);
        // Borrar un elemento del árbol:
        void Borrar(const int dat);
        // Función de búsqueda:
        bool Buscar(const int dat);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoA *r);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoA *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const int dat);
        // Moverse al nodo raiz:
        void Raiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(int), NodoA *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(int), NodoA *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(int), NodoA *nodo=NULL, bool r=true);

    private:
        // Funciones auxiliares
        void Podar(NodoA* &);
        void auxContador(NodoA*);
        void auxAltura(NodoA*, int);
};


//Prototipos de funciones
bool esEntero(string entrada);

#endif // CCONTROL_H_INCLUDED
