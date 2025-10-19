struct Pedido{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int unidades;
    string estado;
};
//Todas las funcionas que generan de forma aleatoria los atributos previos. Para todas estas funciones, debe estar la linea de codigo "srand(time(NULL));" en el main().
//Funcion auxiliar que genera un digito (0-9) aleatorio. Está comprobado que funciona correctamente.
int digitoRandom(){
    int resultado = rand()%10;
    return resultado;
};

//Devuleve un int (0-9) aleatorio que representa la id de la editorial. Está comprobado que funciona correctamente.
int id_editorialRandom(){
    int resultado = digitoRandom();
    return resultado;
};

//Devuleve un string (PXXXXX; P="literalmente la letra 'P'"; X="un número entero 0-9") aleatorio que representa la id del pedido. Está comprobado que funciona correctamente.
string id_pedidoRandom(){
    string resultado = "P";
    for(int i = 0; i<5; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};


//Devuleve un string (XXXKXX; X="un número entero 0-9; K="literalmente la letra 'K') aleatorio que representa el codigo del libro. Está comprobado que funciona correctamente.
string cod_libroRandom(){
    string resultado="";
    for(int i = 0; i<3; ++i)
        resultado+=to_string(digitoRandom());
    resultado+="K";
    for(int i = 0; i<2; ++i)
        resultado+=to_string(digitoRandom());
    return resultado;
};

//Devuleve un string aleatorio que representa una materia de entre las siguietes: Matemáticas, Física, Tecnología, Música, Historia y Lengua. Está comprobado que funciona correctamente.
string cod_libroRandom(){
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

//Obviamente no hay funcion de generación aleatoria de "estado".

