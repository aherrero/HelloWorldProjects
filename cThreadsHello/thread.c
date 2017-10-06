#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     //sleep(...)
#include <pthread.h>

#define NUM_THREADS 1

//Mutex para sincronizar la salida en pantalla 
pthread_mutex_t m;

void* sumar(void* t)
{
    int* id= (int*)(t); //Leo parametros de la funcion
    pthread_mutex_lock(&m);
    printf("Hilo sumador %d en ejecucion\n",*id);
    pthread_mutex_unlock(&m);
    
    sleep(.5);  //Trabajo
    //suma++;
    
    pthread_mutex_lock(&m);
    printf("Hilo sumador %d termina ejecucion: \n",*id);
    pthread_mutex_unlock(&m);

}

int main()
{
    //Array de identificadores de hilos
    pthread_t thidArray[NUM_THREADS];

    //Atributos de hilos
    pthread_attr_t attr;
    
    //Array para el paso de parámetros a los hilos
    int param[NUM_THREADS];
        
    //Inicializo el atributo 
    pthread_attr_init(&attr);

    //Defino atributo joinable(por defecto) o detached 
    //pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED /*PTHREAD_CREATE_JOINABLE*/);
        
    pthread_mutex_lock(&m);
    printf("\nCreando hilo: %d desde el hilo principal\n",0);  //paso de parametros incorrecto
    pthread_mutex_unlock(&m);

    param[0]=99;


    if(pthread_create(&thidArray[0],&attr,sumar,&param[0])){
        printf("Error a crea el hilo\n");
        exit(-1);
    }

    sleep(1);
    
    //Libero el recurso atributo
    pthread_attr_destroy(&attr);
    
    // //Sincronizacion mediante join (no válido si los hilos se han definido como DETACHED)
    // for(int i=0; i<NUM_THREADS; i++){
    //     if(pthread_join(thidArray[i],NULL)){
    //         printf("Error al sincronizar con el hilo");
    //         exit(-1);
    //     }
    // }
    
    // pthread_mutex_lock(&m);
    // printf("\nLa suma es : %d \n",suma);
    // pthread_mutex_unlock(&m);
    
    //Salida estándar de hilo. Cuando el hilo maestro ejecuta pthread_exit los hilos trabajadores terminan sus tareas. En caso contrario los hilos trabajadores finalizan su ejecución inmediatamente
    //pthread_exit(NULL);   
        

return 0;
}
