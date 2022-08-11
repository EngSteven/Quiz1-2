#include<iostream>
using namespace std;

//estructuras
struct Tren{
    int disponibilidad; //disponibilidad = 1(ocupados), disponibilidad = 0(disponibles)

}vagones[5][15];    //columnas -> vagones / filas -> asientos de cada vagon

//Prototipos de funciones 
void marcarDisponibilidad(Tren [][15]);
void mostrarDisponibilidad(Tren [][15]);

int main(){

    //se llaman las funciones a usar
    marcarDisponibilidad(vagones);
    mostrarDisponibilidad(vagones);

    return 0;
}

void marcarDisponibilidad(Tren vagones[][15]){  //disponibilidad = 1(ocupados), disponibilidad = 0(disponibles)

    //ingresar la cantidad de asientos por cada vagon
    for(int i=0; i<5; i++){                         //se recorren los n vagones
        for(int j=0; j<15; j++){                    //se recorren los n asientos de cada vagon
            if(j % 5 == 0) continue;  //se saca el residuo entre un n entero, que marca de cuanto en cuanto se colocan los ocupados 
            
            vagones[i][j].disponibilidad = 1;
        }
    }
}

void mostrarDisponibilidad(Tren vagones[][15]){
    int cont = 0;   //contador que indica si ya se llego a los 10 asientos disponibles
    
    //mostrar los 10 primeros asientos
    cout<<"\nLista de los primeros asientos disponibles"<<endl;
    for(int i=0; i<5; i++){         //se recorren los vagones de principio a fin
        for(int j=0; j<15; j++){
            if(cont != 10){
                if(vagones[i][j].disponibilidad == 0){      //si la disponibilidad es 0, entonces esta disponible
                    cout<<"\nVagon: "<<(i+1)<<endl;
                    cout<<"Asiento: "<<(j+1)<<endl;
                    cont ++;
                }
            }  
        }
        if(cont == 10){
                break;
            }     
    }
    //mostrar los 10 ultimos asientos disponibles
    cont = 0;
    cout<<"\nLista de los ultimos asientos disponibles"<<endl;
    
    for(int i=4; i>=0; i--){        //se recorren los vagones de fin a principio
        for(int j=14; j>=0; j--){
            if(cont != 10){
                if(vagones[i][j].disponibilidad == 0){      //si la disponibilidad es 0, entonces esta disponible
                    cout<<"\nVagon: "<<(i+1)<<endl;
                    cout<<"Asiento: "<<(j+1)<<endl;
                    cont ++;
                }
            }        
        }
        if(cont == 10){
                break;
            }
    }
    if(cont < 10){
        cout<<"\nLa cantidad de asientos disponibles es menor a 10"<<endl;
    }  
}