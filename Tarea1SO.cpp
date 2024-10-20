#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>

using namespace std;   
using namespace chrono;      
using namespace this_thread; //para no tener que escribir this_thread::, chrono::, std::   (flojera)
mutex mtx;

int llegada=0;
string* podio;


void carrera(string* id, long metros){
    //se definen variables 
    long metrosRecorridos = 0;
    long distancia = 0;
    long Tiempo_espera = 0;

    srand(time(0) +hash<string>{}(*id)); //se le da una semilla unica a cada auto)

    while (metrosRecorridos < metros)
    {   //se le asignan valores random a distancia, tiempo_espera y metrosRecorridos
        distancia= rand() % 10 + 1;
        Tiempo_espera = rand() % 500 + 100;
        metrosRecorridos= metrosRecorridos + distancia;

        //se espera durante el tiempo random antes determinado
        sleep_for(milliseconds(Tiempo_espera));

        //se bloquea para que imprima sin interrupciones de otra hebra
        lock_guard<mutex> lock(mtx);
        if (metrosRecorridos <= metros){
            cout << *id << " avanzo: " << distancia << " metros. (Total avanzado: " << metrosRecorridos << " metros.)" << endl;
        }
        
    
    }

    //seccion critica para imprimir el podio
    {
        lock_guard<mutex> lock(mtx);
        podio[llegada] = *id;
        cout << "\033[32m" <<*id << " ha terminado la carrera! en "<< llegada+1 << " lugar!"<< "\033[0m" << endl;
        llegada++;
    }
}

int main(int argc, char const *argv[])
{
    //validar argumentos de entrada para que sean 2, la cantidad de metros y la cantidad de hilos
     if (argc < 3) {
        

        cout << "Cantidad de argumentos invalida...  <Cantidad_de_metros> <cantidad_de_autos>\n " << endl;
        return 1;
    }

    long metros = atoll(argv[1]);
    if (metros < 10 )
    {cout << "Cantidad de metros invalida" << endl;
        return 0;
    }

    int cant_autos = atoll(argv[2]);
    if (cant_autos <=0){
        fprintf(stderr, "Cantidad de autos invalida\n");
        return 0;
    }
    cout << "Distancia total de carrera: " << metros << " metros" << endl;
    cout <<"Cantidad de autos: " << cant_autos << endl;
    cout << "-------------------------------------------------------" << endl;
 

    //se crea arreglo para almacenar id de los autos y los hilos
    string* idAuto = new string[cant_autos];
    thread* hilos = new thread[cant_autos];
    podio = new string[cant_autos];

 

    for(int i = 0 ; i < cant_autos ; i++){

        idAuto[i] = "Auto " + to_string(i);
        hilos[i] =thread(carrera, &idAuto[i], metros);
        
    }

    //espera que todos los autos terminen la carrera
    for(int i = 0 ; i < cant_autos ; i++){
        hilos[i].join();
    }
  
    cout << "\nLa carrera ha terminado! \n" << endl;

    //imprime el podio
    for (int i = 0; i < cant_autos; i++) {
        cout << "Puesto " << i + 1 << ": " << podio[i] << endl;
    }

    delete[] idAuto;
    delete[] hilos;
    delete[] podio;

    return 0;
}
