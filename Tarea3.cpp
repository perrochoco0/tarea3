#include <iostream>
#include <fstream>
#include <string>

#define VACIA -1

using namespace std;

struct Plato {
    string nombre ;
    int precio ;
};

struct ranura{
    int clave;
    Registro info;
    int colisiones;
};

ranura HT[1000];

int h1(int clave){
    return clave * 3;
};

int h2(int clave){
    return clave * 5;
};

int colision(int clave, int i){
    return i * h2(clave);
};

int insertHash(ranura HT[], int clave, Registro info){
    int inicio, i , colisiones = 0;
    int pos = inicio = h1(clave);

    for(i = 1; HT[pos].clave != -1 && HT[pos].clave != clave; ++){
        pos = (inicio + colision(clave,i)) % 10000;
        colisiones++;
    }

    if(HT[pos].clave == clave){
        return 0;
    }
    else{
        HT[pos].clave = clave;
        HT[pos].info = info;
        HT[pos].colisiones = colisiones;
        return 1; // insercion exitoso
    }

};

class Pedido {
    private :
    Plato * platos ; // arreglo de platos en el pedido , tamaño inicial 25
    bool servir ; // true para servir , false para llevar
    int id ; // Numero identificador del pedido
    size_t cant_platos ;
    size_t max = 25 ;

    public :
    Pedido (bool servicio, int cant_platos) ;
    ~ Pedido () ;
    void agregar_plato ( Plato * plato ); // agrega un plato al pedido
    int precio_total () ; // retorna la suma del precio de todos los platos del pedido
    int precio_proppina () ; // retorna la suma del precio de todos los platos mas la propina
    int num_id() ;
    bool tipo_servicio() ; 
};

Pedido::Pedido(bool servicio, int n_platos){

    cant_platos = n_platos;
    platos = new Plato[cant_platos];
    bool servir = servicio;
    
};

void Pedido::agregar_plato(Plato * plato){
    

}

class Registro {
    private :
    Pedido * pedidos ; // arreglo de pedidos , tamaño inicial n ( cantidad de mesas )
    size_t size ; // define en un inicio el tamano de la tabala hash
    size_t size_e; // define la cantida de ranuras no vacias de la tabla hash
    void ajustar_arreglo () ; // ajusta el tamaño de la tabla de hashing
    int ganancias ;


    public :
    Registro ( int n ) ;
    ~ Registro () ;
    void agregar_pedido ( Pedido * pedido );
    Pedido * get_pedido ( int id , bool tipo ); // Retorna el pedido seg ún id y tipo ( servir true llevar false )
    Pedido * eliminar_pedido ( int id , bool tipo ); // Elimina el pedido según id y tipo

    float calcular_factor(); // Devuelve el factor de carga
    int entregar_ganancias(); // Devuelve las ganancias del dia
  
    int funcion_hash(Pedido * pedido); //
    int f_colision(int i, int k) //
};


Registro::Registro(int n){

    size = n;
    pedidos = new Pedido;
    ganancias = 0;
    
}


void Registro::agregar_pedido(Pedido * pedido){
    int inicio, i, colisiones = 0;
    int pos = inicio = funcion_hash(pedido);

    for (i = 1; pedidos[pos].num_id() != VACIA && pedidos[pos].num_id() != pedido->num_id(); i++){
        pos = inicio + f_colision(pedido->num_id(), i) % size;
        colisiones++;
    }
    if(pedidos[pos].num_id() == pedido->num_id()){
        return; // insercion no exitosa
    }
    else{
        pedido[pos].
        pedido[pos].
        pedido[pos].
    }

};

float Registro::calcular_factor(){
    return size_e%size;
};

int Registro::funcion_hash(Pedido * pedido){
    if(pedido->tipo_servicio() == true ){
        return pedido->num_id()*3;
    }
    else{
        return pedido->num_id()*5;
    }
};

int main(){
    fstream archivo("Menus.txt");
    string linea;
    int n_platos;
    string nombre_p;
    int precio_p;
    

    if (!archivo.is_open()) {    // esto
        cerr << "Error al abrir el archivo." << endl;
    exit(1);
    }
    getline(archivo, linea);
    n_platos = stoi(linea);
    Plato* platos = new Plato[n_platos];

    for (int i = 0; i < n_platos; i++){
        int pos = 0;
        getline(archivo, linea);
        for (int i = 0; i < linea .length(); i++){
            if (linea[i] == '-'){
                pos = i;
            }
        }

    cout<<"hola"<<endl;
    nombre_p = linea.substr(0,pos);
    precio_p = stoi(linea.substr(pos+1,linea.length()-nombre_p.length()));

    platos[i].nombre = nombre_p;
    platos[i].precio = precio_p;
    }

    
    string num;
    int cant;
    getline(cin, num);
    cant=stoi(num);
    
    Registro plop;
    plop.llamando(cant);
   
    while (true) {
        string pollito;
        int m;
        string nombre,nmesa,plato,tipo;
        getline(cin, pollito);
        if (pollito=="registrar"){
            getline(cin,nombre);
            for(int i=0; i<nombre.length();i++){
                if(nombre[i]==' '){
                    break;
                }
                tipo=tipo+nombre[i];
                
            }
            cout<<tipo;
            nmesa=nombre.substr(nombre.length()-2, 2);
            m=stoi(nmesa);
            cout<<m;

        }
        if (pollito=="agregar"){
            getline(cin,plato);
            cout<<plato;

        }
        if(pollito=="info"){
            getline(cin,nombre);
            nmesa=nombre.substr(nombre.length()-2, 2);
            m=stoi(nmesa);

        }
        if(pollito=="pedir"){

        }
        if(pollito=="pagar"){
            getline(cin,nombre);
            nmesa=nombre.substr(nombre.length()-2, 2);
            m=stoi(nmesa);
    
        }
        if(pollito=="cerrar"){

            break;
        }
        nmesa=" ";
        plato=" ";
        m=0;

    }

    archivo.close();

    cout<<platos[1].precio<<endl;
    return 0;
};