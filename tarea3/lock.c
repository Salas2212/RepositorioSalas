/*/ 
Nombre: Juan Esteban Salas
Codigo: 8975783
/*/
#include <stdio.h>

int main(){
    int arreglo[4], end = 0;
    while(end != 4){
        int degrees = 1080;
        end = 0;
        for (int i = 0; i < 4; i++){
            scanf("%d", &arreglo[i]);
            if(i == 1 || i == 3){
                if ( arreglo[i] > arreglo[i-1]){
                    degrees += ((arreglo[i-1] - arreglo[i]) + 40)*9;
                }
                else if(arreglo[i] < arreglo[i-1] || arreglo[i] == arreglo[i-1]){
                    degrees += (arreglo[i-1] - arreglo[i])*9;
                }
            }
            if(i == 2){
                if( arreglo[i] > arreglo[i-1] || arreglo[i] == arreglo[i-1]){
                    degrees += (arreglo[i] - arreglo[i-1])*9;
                }
                else{
                    degrees += ((40 - arreglo[i-1]) + arreglo[i])*9;
                }
            }
            if(arreglo[i] == 0){
                end++;
            }
        }
        if(end != 4){
            printf("%d\n", degrees);
        }
        
    }

    return 0;
}