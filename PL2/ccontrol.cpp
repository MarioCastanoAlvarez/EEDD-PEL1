#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> // para esIdPedido()
#include "ccontrol.h"
#include <cmath>

using namespace std;
int digitoRandom(){
    int resultado = rand()%10;
    return resultado;
};

//Devuleve un string (PXXXXX; P="literalmente la letra 'P'"; X="un número entero 0-9") aleatorio que representa la id del pedido. Está comprobado que funciona correctamente.
string id_pedidoRandom(){
    string resultado = "P";
    for(int i = 0; i<5; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};


//Devuleve un string (XXXKXX; X="un número entero 0-9; K="Es una letra aleatoria de entre todo el alfabeto") aleatorio que representa el codigo del libro. Está comprobado que funciona correctamente.
string cod_libroRandom(){
    string resultado="";
    for(int i = 0; i<3; ++i)
        resultado+=to_string(digitoRandom());
    string alfabeto[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    resultado+=alfabeto[rand()%26];
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
//Array con todas las localidades
string LOCALIDADES [20]={"Alcala", "Alcobendas", "Alcorcon", "Aranjuez", "Arganda", "Boadilla", "Colmenar", "Coslada", "Fuenlabrada", "Getafe", "Leganes", "Majadahonda", "Mostoles", "Parla", "Pinto", "Pozuelo", "Rivas", "Torrejon", "Tres Cantos", "Valdemoro"};
//Fecha random de 2025 (modificable)
time_t fechaRand(){
    struct tm datetime;

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

    return mktime(&datetime);
}
time_t crearFecha(int a, int m, int d){
    struct tm datetime;

    datetime.tm_year = a - 1900;
    datetime.tm_mon = m;
    datetime.tm_mday = d;

    return mktime(&datetime);

}
//Funciones de listas simples

ListaS::~ListaS()
{
    pnodoLS aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}
void ListaS::insertarNodo(int v)
{
    pnodoLS aux;
    if (listaVacia())
    {
        cabeza = new NodoLS(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new NodoLS(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}

void ListaS::borrarNodo(int v)
{
    pnodoLS anterior; actual = cabeza;
    while (actual->valor!=v && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza) // Primer elemento
        cabeza = actual->siguiente;
    else
    {
        anterior->siguiente = actual->siguiente;
        if(actual==final) final=anterior;
    }
    actual->siguiente=NULL;
    delete actual;
}

bool ListaS::listaVacia()
{
    return cabeza == NULL;
}

int ListaS::getValor(int pos)
{
    if(!this->listaVacia()){
        actual = cabeza;
        while (actual->siguiente && pos > 0){actual = actual->siguiente; pos--;}
        if(pos>0){
            return -1;
        }
        return actual->valor;
    }
    return -1;
}
int ListaS::getFinal()
{
    return final->valor;
}

int ListaS::contar()
{
    int cont = 0;
    actual = cabeza;
    while(actual) {cont++; actual = actual->siguiente;}
    return cont;
}
bool ListaS::esta(int v)
{
    if (this->listaVacia()){return false;}
    bool comp = false;
    for (int i = 0; i < this->contar(); i++) {if (this->getValor(i) == v){comp = true;}}
    return comp;
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
 void Lista::recorrerLista (int orden){
pnodoL aux;
if (orden == ASCENDENTE) {
    esCabeza();
    aux = cabeza;
    while(aux){
        imprimirPedido(aux->pedido);
        aux = aux->siguiente;
        }
    }
else {
    esFinal();
    aux = final;
    while(aux) {
        cout << aux->pedido.id_pedido << "-> "; aux = aux->anterior;
        }
    }
cout << endl;
}

//Mira si el puntero Cabeza es Null.
bool Lista::listaVacia()
{
return cabeza == NULL;
}
//Devuelve el valor de la posición del parámetro pos
Pedido Lista::getValor(int pos, int orden)
{
    if (orden == ASCENDENTE){
        if(!this->listaVacia()){
        actual = cabeza;
        while (actual->siguiente && pos > 0) {actual = actual->siguiente; pos--;}
        if(pos>0){
            return VACIO;
        }
        return actual->pedido;
    }
    return VACIO;
    }
    if (orden == DESCENDENTE) {
        if(!this->listaVacia()){
        actual = final;
        while (actual->anterior && pos > 0) {actual = actual->anterior; pos--;}
        if(pos>0){
            return VACIO;
        }
        return actual->pedido;
    }
    return VACIO;
    }
    return VACIO;
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

void Lista::concatenar(Lista &lista)
{

    if(final && lista.cabeza){
    final->siguiente = lista.cabeza;
    lista.cabeza->anterior = final;
    final = lista.final;
    }
    else if (lista.cabeza){
        cabeza = lista.cabeza; final = lista.final; actual = lista.actual;
    }
}

Pedido Lista::buscarPedidoL(string entrada){
    pnodoL aux = cabeza;
    while(aux){
        if(aux->pedido.id_pedido==entrada)return aux->pedido;
        else aux = aux->siguiente;
    } return VACIO;
};

void Lista::extraerPedidoL(string entrada){
    pnodoL aux=cabeza;
    bool ready=false;
    while(aux){
        if(aux->pedido.id_pedido==entrada){
            aux->anterior->siguiente=aux->siguiente;
            aux->siguiente->anterior=aux->anterior;
            aux->anterior=NULL;
            aux->siguiente=NULL;
            delete aux;
            ready=true;
            cout<<"El pedido ha sido correctamente extraido."<<endl;
        }else aux=aux->siguiente;
    }
    if(!ready)cout<<"Ha surgido un error. El pedido no se ha encontrado."<<endl;
};

//Funcion para verificar si una entrada es un entero o no.
bool esEntero(string entrada){
    if(entrada.empty())return false;
    for (char c : entrada){
        if(!isdigit(c))return false;
    } return true;
};

bool esLocalidad(string entrada){
    for(int i=0;i<20;i++){
        if(entrada == LOCALIDADES[i])return true;

    }return false;
};
bool esIdPedido(string entrada){
    if(entrada.length()!=6)return false;
    if(entrada[0]!='P')return false;
    else for(int i=1;i<6;i++)if(!isdigit(entrada[i]))return false;
    return true;
};
void mostrarLocalidades(){
    cout<<"Localidades controladas por el centro: "<<endl<<"| ";
    for(int i=0;i<10;i++){
       cout<<LOCALIDADES[i]<<" | ";
    }
    cout<<endl<<"| ";
    for(int i=10;i<20;i++){
       cout<<LOCALIDADES[i]<<" | ";
    }
};
//Funciones de lista
//Muestra los atributos de una libreria por pantalla
void mostrarLibreria(Libreria lib){
    cout<<"ID: " <<setw(3)<<lib.id_lib<<" Localidad: "<<setw(11)<<lib.localidad<<" Num Pedidos: "<<setw(5)<<lib.lista->contarLista()<<endl;
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

Libreria* ArbolABB::getLibreria(int id_lib)
{
    actual = raiz;
    if(this->Buscar(id_lib)) {
        while (id_lib != actual->libreria.id_lib) {
            if (id_lib < actual->libreria.id_lib) {actual = actual->izquierdo;}
            else if (id_lib > actual->libreria.id_lib) {actual = actual->derecho;}
        }
    } else {
        return NULL;
    }
    return &(actual->libreria);

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
void ArbolABB::Borrar(const int id_lib)
{
   NodoA *padre = NULL;
   NodoA *nodo;
   Libreria aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(id_lib == actual->libreria.id_lib) { // Si el valor está en el nodo actual
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
         if(id_lib > actual->libreria.id_lib) actual = actual->derecho;
         else if(id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
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
bool ArbolABB::Buscar(const int id_lib)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(id_lib == actual->libreria.id_lib) return true; // int encontrado
      else if(id_lib > actual->libreria.id_lib) actual = actual->derecho; // Seguir
      else if(id_lib < actual->libreria.id_lib) actual = actual->izquierdo;
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
Pedido ArbolABB::buscarPedidoA(string entrada){
    NodoA* nodo = raiz;
    return auxBuscarPedidoA(nodo,entrada);
};
Pedido ArbolABB::auxBuscarPedidoA(NodoA* nodo,string entrada){
    if(nodo==NULL)return VACIO;

    Pedido pedido=nodo->libreria.lista->buscarPedidoL(entrada);
    if(pedido.cod_libro!=""){
        return pedido;
    }
    pedido=auxBuscarPedidoA(nodo->izquierdo, entrada);
    if (pedido.cod_libro!=""){
        return pedido;
    }
    pedido=auxBuscarPedidoA(nodo->derecho, entrada);
    if (pedido.cod_libro!=""){
        return pedido;
    }
    return VACIO;
};


pnodoA ArbolABB::getRaiz()
{
    return raiz;
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

Pedido generarPedido(ListaS &lista_id){
    Pedido pd;
    pd.cod_libro = cod_libroRandom();
    pd.id_libreria = lista_id.getValor(rand()%lista_id.contar());
    pd.fecha = fechaRand();
    pd.materia = materiaRandom();
    pd.unidades = unidadesRandom();
    pd.id_pedido = id_pedidoRandom();
    return pd;
};
void imprimirLibreria(Libreria libreria)
{
    cout << "-------------------------------------------------------------------" << endl;
    cout << "|ID Libreria|" << "ID Pedido|"
    << setw(8) << "Cod Libro|" << setw(13) << "Materia|" << setw(8)
    << "U|" << setw(13) << "Fecha|" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    Lista pedidos = *libreria.lista;

    for (int j = 0; j<pedidos.contarLista();j++){
        imprimirPedido(pedidos.getValor(j, ASCENDENTE));cout<<endl;
    }
}
void imprimirPedido(Pedido pedido)
{
    char fecha[50];
    strftime(fecha, sizeof(fecha), "%d/%m/%Y", localtime(&pedido.fecha));
    cout << "|" <<setw(11) << pedido.id_libreria << "|" << setw(9) << pedido.id_pedido << "|"
        << setw(9) << pedido.cod_libro << "|" << setw(12) << pedido.materia << "|" << setw(7)
        << pedido.unidades << "|" << setw(12) << fecha << "|";
}

void imprimirEstadistica(int contador[])
{
    string materias[]={"Matematicas", "Fisica", "Tecnologia", "Musica", "Historia", "Lengua"};
    cout << setw(41) <<"======Cantidad de pedidos por materia============"<<endl<<endl;
    int total = 0;
    float resultados;
    for (int i = 0; i < 6; i++){total+=contador[i];}
    for (int i = 0; i < 6; i++){
        resultados = round(100.0*contador[i]/total);
        cout << "Materia: " << setw(12) << materias[i] << " || " << "Pedidos: " << contador[i] << " (" << resultados << "%)" << endl;

    }
}
