#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

using namespace std;

//Definicion de constantes
#define MAX_TITULOS 10
#define N_PEDIDOS_PASO 12
#define TAM_LOTE 10
#define LIBRERIAS 6
#define CAP_CAJA 5
#define VACIO Pedido{0, "", "", "", 0, ""}

//Creación de estructura Pedido
struct Pedido{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

//Prototipos de funciones
bool esEntero(string entrada);
int digitoRandom();
int id_editorialRandom();
string id_pedidoRandom();
string cod_libroRandom();
string materiaRandom();
int unidadesRandom();
Pedido generarPedido();





//Creación de clase Nodo
class Nodo
{
    private:

    Pedido pedido;
    Nodo *siguiente;
    friend class Cola;
    friend class Pila;

    public:
        Nodo(Pedido pd, Nodo *sig = NULL)
        {
            pedido = pd;
            siguiente = sig;
        }
        Nodo* getSiguiente(){
            return siguiente;
        }



};
typedef Nodo *pNodo;

//Creación de clase Cola
class Cola
{
    public:
        Cola() : frente(NULL), final(NULL) {}
        ~Cola();
        void encolar(Pedido pd);
        Pedido desencolar();
        Pedido getFrente();
        int contarCola();
        void imprimirCola();

    private:
        pNodo frente, final;
};



//Creación de clase pila
class Pila
{
    private:
        pNodo cima;
    public:
        Pila() : cima(NULL) {}
        ~Pila();
        void apilar(Pedido pd);
        Pedido desapilar();
        void generarStock();
        void imprimirStock();
        void imprimirPila();
        int contarPila();
};



#endif // CABECERA_H_INCLUDED

