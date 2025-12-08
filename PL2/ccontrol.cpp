#include <iostream>
#include <ctime>
#include <iomanip>
#include "ccontrol.h"

using namespace std;

//Array con todas las localidades
string LOCALIDADES [20]={"Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon","Torrejon", "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro","Majadahonda","Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"};

//Fecha random de 2025 (modificable)
string fechaRand(){
    srand(time(NULL));
    struct tm datetime;
    time_t time;

    datetime.tm_year = 2025 - 1900; // Number of years since 1900
    datetime.tm_mon = rand()%12 + 1; // Number of months since January
    if (datetime.tm_mon == 1 || datetime.tm_mon == 3 || datetime.tm_mon == 5 || datetime.tm_mon == 7 || datetime.tm_mon == 8 || datetime.tm_mon == 10 || datetime.tm_mon == 12 )
        { datetime.tm_mday = rand()%31 + 1; }
    else if (datetime.tm_mon == 4 || datetime.tm_mon == 6 || datetime.tm_mon == 8 || datetime.tm_mon == 9 || datetime.tm_mon == 11)
        { datetime.tm_mday = rand()%30 + 1;}
    else { if(datetime.tm_year % 4 == 0){datetime.tm_mday = rand()%28 + 1;}
            else {datetime.tm_mday = rand()%28 + 1;} }
    datetime.tm_hour = rand()%24;
    datetime.tm_min = rand()%60;
    datetime.tm_sec = rand()%60;


    datetime.tm_isdst = -1;

    time = mktime(&datetime);
    return ctime(&time);
}
string crearFecha(int a, int m, int d){
    srand(time(NULL));
    struct tm datetime;
    time_t time;

    datetime.tm_year = a - 1900;
    datetime.tm_mon = m;
    datetime.tm_mday = d;

    datetime.tm_isdst = -1;

    time = mktime(&datetime);
    return ctime(&time);

}

//Destructor de Lista.
Lista::~Lista(){
pnodoL aux;
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
//Inserta un NodoL en la lista.
void Lista::insertarNodo(Pedido v, char c)
{
pnodoL aux;
char tipoInsercion;
tipoInsercion=c;
if(listaVacia()) { // Si la lista está vacía
    aux = new NodoL(v,NULL,NULL);
    final=cabeza=aux;
    }
else if (tipoInsercion=='f') {//Inserción por el final
    aux= new NodoL(v,NULL,NULL);
    aux->anterior=final;
    final->siguiente=aux;
    final=aux;
    }
else if (tipoInsercion=='p') {//Inserción por el principio
    aux= new NodoL(v,NULL,NULL);
    aux->siguiente=cabeza;
    cabeza->anterior=aux;
    cabeza=aux;
    }
}

//Elimina un NodoL de la lista
void Lista::borrarNodo(char c)
{
char tipoBorrado; tipoBorrado=c;
if(tipoBorrado=='f') {      //Eliminación por el final
    pnodoL aux=NULL;
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
    pnodoL aux=NULL;
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
/* void Lista::recorrerLista (int orden){
pnodoL aux;
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
*/

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
Pedido Lista::valorActual()
{
if (!listaVacia()) return actual->pedido;
else return VACIO;
}

//Cuenta los pedidos de una libreria
int Lista::contarLista(){
    actual=cabeza;
    int contador=0;
    while(actual){
        contador++;
        actual=actual->siguiente;
    }
    return contador;
};

//Funcion para verificar si una entrada es un entero o no.
bool esEntero(string entrada){
    if(entrada.empty())return false;
    for (char c : entrada){
        if(!isdigit(c))return false;
    } return true;
};
//Funciones de lista
//Muestra los atributos de una libreria por pantalla
void mostrarLibreria(Libreria lib){
    cout<<"ID: "<<lib.id_lib<<" Localidad: "<<setw(11)<<lib.localidad<<" Num Pedidos: "<<setw(5)<<lib.lista->contarLista()<<endl;
};

//Funciones de arbol binario
//Destructor
ArbolABB::~ArbolABB()
        {
            Podar(raiz);
        }

//Árbol vacío
bool ArbolABB::Vacio(NodoA *r)
        {
            return r==NULL;
        }

//NodoA es de tipo hoja
bool ArbolABB::EsHoja(NodoA *r)
        {
            return !r->derecho && !r->izquierdo;
        }

//Coloca el nodo actual en raíz
void ArbolABB::Raiz()
        {
            actual = raiz;
        }

// Poda: borrar todos los nodos a partir de uno incluido
void ArbolABB::Podar(NodoA* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void ArbolABB::Insertar(const Libreria lib)
{
   NodoA *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && lib.id_lib != actual->libreria.id_lib) {
      padre = actual;
      if(lib.id_lib > actual->libreria.id_lib) actual = actual->derecho;
      else if(lib.id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoA(lib);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(lib.id_lib < padre->libreria.id_lib) padre->izquierdo = new NodoA(lib);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(lib.id_lib > padre->libreria.id_lib) padre->derecho = new NodoA(lib);
}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const Libreria lib)
{
   NodoA *padre = NULL;
   NodoA *nodo;
   Libreria aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(lib.id_lib == actual->libreria.id_lib) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho->libreria.id_lib == actual->libreria.id_lib) padre->derecho = NULL;
               else if(padre->izquierdo->libreria.id_lib == actual->libreria.id_lib) padre->izquierdo = NULL;
            }
            else raiz=NULL;

            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->libreria;
            actual->libreria = nodo->libreria;
            nodo->libreria = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(lib.id_lib > actual->libreria.id_lib) actual = actual->derecho;
         else if(lib.id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(Libreria) , NodoA *nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->libreria);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(Libreria), NodoA *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   func(nodo->libreria);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(Libreria), NodoA *nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->libreria);
}

// Buscar un valor en el árbol
bool ArbolABB::Buscar(const Libreria lib)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(lib.id_lib == actual->libreria.id_lib) return true; // int encontrado
      else if(lib.id_lib > actual->libreria.id_lib) actual = actual->derecho; // Seguir
      else if(lib.id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene la libreria lib
int ArbolABB::Altura(const Libreria lib)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(lib.id_lib == actual->libreria.id_lib) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(lib.id_lib > actual->libreria.id_lib) actual = actual->derecho;
         else if(lib.id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // Función auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(NodoA *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::auxAltura(NodoA *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int d)
{
   cout << d << ",";
}

//Funcion para la generación de una librería pseudoaleatoria
Libreria generarLibreria(){
    Libreria lib;
    lib.id_lib=rand()%999;
    lib.lista= new(Lista);
    lib.localidad=LOCALIDADES[rand()%20];
    return lib;
}
