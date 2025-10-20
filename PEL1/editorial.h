#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

//Definicion de constantes
#define MAX_TITULOS 10
#define N_PEDIDOS_PASO 12
#define TAM_LOTE 10
#define LIBRERIAS 6
#define CAP_CAJA 5

//Prototipos de funciones
bool esEntero(string entrada);
int digitoRandom();
int id_editorialRandom();
string id_pedidoRandom();
string cod_libroRandom();
string materiaRandom();
int unidadesRandom();
void opcion1();
void opcion2();
void opcion3();
void opcion4();
void opcion5();


//Creación de estructura Pedido
struct Pedido{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};

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

    private:
        pNodo frente, final;
};

Cola::~Cola()
{
    while(frente) desencolar();
}

void Cola::encolar(Pedido pd)
{
    pNodo nuevo;
    nuevo = new Nodo(pd);

    if(final) final->siguiente = nuevo;
    final= nuevo;
    if(!frente) frente = nuevo;
}
//Desencolar
Pedido Cola::desencolar()
{
    pNodo nodo;
    Pedido pd;
    Pedido vacio = {0,0,"","",0,""};
    nodo = frente;
    frente = nodo->siguiente;
    pd = nodo->pedido;

    delete nodo;

    if(!frente) final = NULL;
    return pd;
}

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
};

Pila::~Pila()
{
    while(cima) desapilar();
}

void Pila::apilar(Pedido pd)
{
    pNodo nuevo;

    nuevo = new Nodo(pd, cima);

    cima = nuevo;
}

Pedido Pila::desapilar()
{
    pNodo nodo;
    Pedido pd;
    Pedido vacio = {0,0,"","",0,""};

    if(!cima) return vacio;

    nodo = cima;
    cima = nodo->siguiente;
    pd = nodo->pedido;

    delete nodo;
    return pd;
}

#endif // CABECERA_H_INCLUDED

