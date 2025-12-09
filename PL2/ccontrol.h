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
    private:
        pnodoL cabeza, actual, final;
    public:
        Lista() {cabeza=actual=final=NULL; }
        ~Lista();
        void insertarNodo(Pedido v, char c);
        void borrarNodo(char c);
        bool listaVacia();
        Pedido getValor(int pos, int orden);
        void esCabeza();
        void esFinal();
        void esSiguiente();
        void esAnterior();
        bool esActual();
        Pedido valorActual();
        void recorrerLista(int);
        int contarLista();
        void concatenar(Lista &lista);
        Pedido buscarPedidoL(string entrada);
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
    pnodoLS cabeza, actual, final;
public:
    ListaS()
    {
        cabeza = actual = final = NULL;
    }
    ~ListaS();
    void insertarNodo(int v);
    void borrarNodo(int v);
    bool listaVacia();
    int getValor(int pos);
    int getFinal();
    int contar();
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
bool esEntero(string entrada);
//Prototipos de funciones
bool esEntero(string entrada);
bool esLocalidad(string entrada);
bool esIdPedido(string entrada);
void mostrarLocalidades();
int digitoRandom();
int id_libreriaRandom();
string id_pedidoRandom();
string cod_libroRandom();
string materiaRandom();
int unidadesRandom();
Libreria generarLibreria();
void mostrarLibreria(Libreria lib);
Pedido generarPedido(ListaS &lista_id);
void imprimirLibreria(Libreria libreria);
void imprimirPedido(Pedido pedido);
void imprimirEstadistica(Libreria lib, int contador[]);
time_t crearFecha();
time_t fechaRand();

#endif // CCONTROL_H_INCLUDED
