#ifndef CCONTROL_H_INCLUDED
#define CCONTROL_H_INCLUDED

#define ASCENDENTE 0
#define DESCENDENTE 1
#define N_LIBRERIAS 10
#define N_PEDIDOS 30
#define VACIO Pedido{0, "", "", "", 0, 0}
#define LIBVACIO Libreria{-1, "", NULL}
#include <ctime>

using namespace std;


//Estructura de un pedido
struct Pedido{
    int id_libreria;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    time_t fecha;
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
    //Punteros de la lista
    private:
        pnodoL cabeza, actual, final;
    public:
        Lista() {cabeza=actual=final=NULL; }
        //Destructor
        ~Lista();
        //Insercion de un nodo
        void insertarNodo(Pedido v, char c);
        //Borrado de un nodo
        void borrarNodo(char c);
        //Comprueba si la lista esta vacia
        bool listaVacia();
        //Devuelve un pedido en cierta posicion (desde el principio o el final)
        Pedido getValor(int pos, int orden);
        //Asigna el puntero actual a la cabeza
        void esCabeza();
        //Asigna el puntero actual al final
        void esFinal();
        //Asigna el puntero actual a la nodo siguiente
        void esSiguiente();
        //Asigna el puntero actual a su nodo anterior
        void esAnterior();
        //Comprueba si el puntero actual esta asignado a un nodo
        bool esActual();
        //Devuelve el pedido del nodo al que apunta actual
        Pedido valorActual();
        //Imprime los ids de los pedidos
        void recorrerLista(int);
        //Cuenta el numero de nodos de la lista
        int contarLista();
        //Une dos listas
        void concatenar(Lista &lista);
        //Devuelve el pedido dado su ID
        Pedido buscarPedidoL(string entrada);
        //Borra un pedido
        void extraerPedidoL(string entrada);
};

//Estructura de una librería
struct Libreria{
    int id_lib;
    string localidad;
    Lista *lista;
};

//Clase nodo para listas simples
class NodoLS
{
    //Atributos
private:
    int valor;
    NodoLS *siguiente;
    friend class ListaS;
public:
    NodoLS(int v, NodoLS *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef NodoLS *pnodoLS;

//Clase lista smple
class ListaS
{
private:
    //Punteros de la lista
    pnodoLS cabeza, actual, final;
public:
    ListaS()
    {
        cabeza = actual = final = NULL;
    }
    //Destructor
    ~ListaS();
    //Insercion de nodos
    void insertarNodo(int v);
    //Borrado de nodos
    void borrarNodo(int v);
    //Comprueba si la lista esta vacia
    bool listaVacia();
    //Devuelve el valor de cierto nodo por su posicion
    int getValor(int pos);
    //Devuelve el ultimo nodo
    int getFinal();
    //Cuenta el numero de nodos
    int contar();
    //Comprueba si esta un entero en la lista
    bool esta(int v);
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
        void Borrar(const int id_lib);
        // Función de búsqueda:
        bool Buscar(const int id_lib);
        //Busca un pedido por su id_pedido:
        Pedido buscarPedidoA(string entrada);
        // Comprobar si el árbol está vacío:
        bool Vacio(NodoA *r);
        //Devolver una lista simple con todos los ids de las librerías
        //ListaS getListaIDs();
        //Devolver una libreria dada su id
        Libreria* getLibreria(int id_lib);
        // Comprobar si es un nodo hoja:
        bool EsHoja(NodoA *r);
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const Libreria lib);
        // Moverse al nodo raiz:
        void Raiz();
        //Devuelve la raiz del arbol
        pnodoA getRaiz();
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);
        void PreOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);
        void PostOrden(void (*func)(Libreria), NodoA *nodo=NULL, bool r=true);


    private:
        // Funciones auxiliares
        void Podar(NodoA* &);
        void auxContador(NodoA*);
        void auxAltura(NodoA*, int);
        Pedido auxBuscarPedidoA(NodoA*,string);
};


//Prototipos de funciones
//Comprueba si la cadena de texto es un entero
bool esEntero(string entrada);
//Comprueba si la cadena de texto corresponde a una de las localidades definidas
bool esLocalidad(string entrada);
//Comprueba si la cadena de texto tiene el formato establecido para el ID de un pedido
bool esIdPedido(string entrada);
//Muestra la lista de localidades definidas
void mostrarLocalidades();
//Elige un número (0-9) aleatorio
int digitoRandom();
//Genera un id de libreria (elige un numero del 0-999)
int id_libreriaRandom();
//Genera un ID de pedido de manera pseudoaleatoria
string id_pedidoRandom();
//Genera un codigo de libro de manera pseudoaleatoria
string cod_libroRandom();
//Elige una materia de las que se han establecido aleatoriamente
string materiaRandom();
//Elige las unidades de un pedido aleatoriamente (1-20)
int unidadesRandom();
//Genera una libreria con datos pseudoaleatorios
Libreria generarLibreria();
//Imprime los datos de la libreria
void mostrarLibreria(Libreria lib);
//Genera un pedido con datos pseudoaleatorios
Pedido generarPedido(ListaS &lista_id);
//Imprime los datos de cada pedido de una libreria
void imprimirLibreria(Libreria libreria);
//Imprime los datos de un pedido
void imprimirPedido(Pedido pedido);
//Imprime la estadistica (Pedidos por materia)
void imprimirEstadistica(int contador[]);
//Crea una fecha aleatoria de 2025
time_t fechaRand();

#endif // CCONTROL_H_INCLUDED
