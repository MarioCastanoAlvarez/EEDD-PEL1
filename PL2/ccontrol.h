#ifndef CCONTROL_H_INCLUDED
#define CCONTROL_H_INCLUDED

#define ASCENDENTE 0
#define DESCENDENTE 1
#define N_LIBRERIAS 10
#define N_PEDIDOS 30
#define VACIO Pedido{0, "", "", "", 0, ""}
#include <ctime>

using namespace std;


//Estructura de un pedido
struct Pedido{
    int id_libreria;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

//Clase nodo para listas
class NodoL
{
    private:
        // Miembros:
        Pedido pedido;
        NodoL *anterior;
        NodoL *siguiente;
        friend class Lista;

    public:
        // Constructor:
        NodoL(const Pedido ped, NodoL *ant=NULL, NodoL *sig=NULL) :
            pedido(ped), anterior(ant), siguiente(sig) {}

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
        void insertarNodo(Pedido v, char c);
        void borrarNodo(char c);
        bool listaVacia();
        void esCabeza();
        void esFinal();
        void esSiguiente();
        void esAnterior();
        bool esActual();
        Pedido valorActual();
        void recorrerLista(int);
        int contarLista();
};

//Estructura de una librería
struct Libreria{
    int id_lib;
    string localidad;
    Lista *lista;
};

//Clase nodo para arboles
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

//Estructura de árbol binario
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
        void Insertar(const Libreria lib);
        // Borrar un elemento del árbol:
        void Borrar(const Libreria lib);
        // Función de búsqueda:
        bool Buscar(const Libreria lib);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoA *r);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoA *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const Libreria lib);
        // Moverse al nodo raiz:
        void Raiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);

    private:
        // Funciones auxiliares
        void Podar(NodoA* &);
        void auxContador(NodoA*);
        void auxAltura(NodoA*, int);
};


//Prototipos de funciones
bool esEntero(string entrada);
//Prototipos de funciones
bool esEntero(string entrada);
int digitoRandom();
int id_libreriaRandom();
string id_pedidoRandom();
string cod_libroRandom();
string materiaRandom();
int unidadesRandom();
Libreria generarLibreria();
void mostrarLibreria(Libreria lib);


#endif // CCONTROL_H_INCLUDED
