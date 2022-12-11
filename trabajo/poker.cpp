/*
 * CLAUDIA RODRIGUEZ MARTINEZ
 */

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define CAPITAL_INICIAL 100 
//creamos una baraja de cartas con sus valores de 1 a 13
int baraja[13] = {1,2,3,4,5,6,7,8,9,10,10,10,11};

int opcion_apuesta_usuario(); 
int apuesta_usuario(int capital_usuaio);

int main(){ 
    srand(time (NULL)); //inicializamos la semilla
    printf("Bienvenido al Blackyac\n"); // imrimirms el mensaje de bienvenida
    int capital_usuario = CAPITAL_INICIAL; //inicializamos el capital del usuario
    int opcion_apuesta_usuario = -1, cantidad_apostada_usuario =-1; //inicializamos la opcion de apuesta y la cantidad apostada
    int carta1 = 0, carta2= 0, suma_cartas_usuario; //inicializamos las cartas y la suma de las cartas
    int carta3= 0, carta4= 0, suma_cartas_croupier; //inicializamos las cartas y la suma de las cartas
    int ganadas = 0, perdidas = 0; //inicializamos las partidas ganadas y perdidas
    while(capital_usuario > 0 && cantidad_apostada_usuario !=0){ //mientras el capital del usuario sea mayor que 0 y la cantidad apostada sea diferente de 0
        cantidad_apostada_usuario = -1; //inicializamos la cantidad apostada
        do{ //hacemos un bucle do while
            printf("Tienes un capital de %d Euros, ¿que cantidad quieres apostar?\n", capital_usuario); //imprimimos el mensaje
            scanf("%d", &cantidad_apostada_usuario); //leemos la cantidad apostada
            //capital_usuario -= cantidad_apostada; 
            capital_usuario-=cantidad_apostada_usuario; //restamos la cantidad apostada al capital del usuario
        }while(cantidad_apostada_usuario > capital_usuario  || cantidad_apostada_usuario < 0); //mientras la cantidad apostada sea mayor que el capital del usuario o menor que 0
        if (cantidad_apostada_usuario !=0){ //si la cantidad apostada es diferente de 0
            opcion_apuesta_usuario = -1; //inicializamos la opcion de apuesta
            printf("Repartimos las cartas"); //imprimimos el mensaje
        }
        //generamos un numero aleatorio de int baraja
        carta1 = baraja[rand() % 11]; //generamos un numero aleatorio entre 1 y 11
        carta2 = baraja[rand() % 11]; //generamos un numero aleatorio entre 1 y 11
       // carta1 = rand() % 11 +1; //generamos un numero aleatorio entre 1 y 13
     //   carta2 = rand() % 11 +1; //generamos un numero aleatorio entre 1 y 13
        
        suma_cartas_usuario = carta1 + carta2; //sumamos las cartas
        printf(", tus cartas son %d i %d (suma = %d) \n", carta1, carta2, suma_cartas_usuario); //imprimimos las cartas y la suma de las cartas

        while (suma_cartas_usuario == 21){ //mientras la suma de las cartas sea igual a 21
            printf("Has ganado %d! \n", cantidad_apostada_usuario); //imprimimos el mensaje
                    capital_usuario = capital_usuario + cantidad_apostada_usuario*2; //sumamos la cantidad apostada al capital del usuario
                    ganadas++; //sumamos una partida ganada
        }


        while (suma_cartas_usuario >= 22){ //mientras la suma de las cartas sea mayor o igual que 22
            printf("Has perdido %d \n", (cantidad_apostada_usuario)); //imprimimos el mensaje
            perdidas++; //sumamos una partida perdida
        }
        
        if (suma_cartas_usuario <= 20){ //si la suma de las cartas es menor o igual que 20  
            carta3 = rand() % 13 +1;
            carta4 = rand() % 13 +1;
            suma_cartas_croupier = carta3 + carta4;
            printf("Las cartas del croupier son %d i %d (suma = %d) \n", carta3, carta4, suma_cartas_croupier); 

            if(suma_cartas_croupier>=22){ //si la suma de las cartas del croupier es mayor o igual que 22
                printf("Has ganado %d! \n", cantidad_apostada_usuario); //imprimimos el mensaje
                capital_usuario = capital_usuario + cantidad_apostada_usuario*2; //sumamos la cantidad apostada al capital del usuario
                ganadas++; //sumamos una partida ganada
            } 

            if(suma_cartas_croupier > suma_cartas_usuario && suma_cartas_croupier <=21 ) { //si la suma de las cartas del croupier es mayor que la suma de las cartas del usuario
                printf("Has perdido %d \n", (cantidad_apostada_usuario)); //imprimimos el mensaje
                perdidas++; //sumamos una partida perdida
            } //
            else{
                printf("Has ganado %d! \n", cantidad_apostada_usuario); //sino has ganado
                capital_usuario = capital_usuario + cantidad_apostada_usuario*2; //sumamos la cantidad apostada al capital del usuario
                ganadas++; //sumamos una partida
            }
            
            
        }
    }
    printf("Has ganado %d partidas y has perdido %d partidas. \n", ganadas, perdidas);
    printf("Has terminado la partida con un total de %d euros. \n ", capital_usuario);
    return 0;
}
int apuesta_usuario(int capital_usuario){ //funcion para la apuesta del usuario
    int cantidad_apuesta_usuario = -1; //inicializamos la cantidad apostada
    while(cantidad_apuesta_usuario > capital_usuario  || cantidad_apuesta_usuario < 0){ //mientras la cantidad apostada sea mayor que el capital del usuario o menor que 0
        printf("Tienes un capital de %d Euros, ¿que cantidad quieres apostar?\n", capital_usuario); //imprimimos el mensaje
        scanf("%d", &cantidad_apuesta_usuario); //leemos la cantidad apostada
        //capital_usuario -= cantidad_apostada;
    }
    return cantidad_apuesta_usuario;
}


