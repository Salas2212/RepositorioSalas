/*/ 
Nombre: Juan Esteban Salas
Codigo: 8975783
/*/
#include <stdio.h>

int main(){
    int n, diff;
    while (scanf("%d", &n) == 1){
        int arreglo[n], res = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arreglo[i]);
            if(i > 0 && res != 1){
                diff = arreglo[i] - arreglo[i-1];
                if ((diff * -1) < 0 && (diff < n)){
                    res = 0;
                }
                else if((diff * -1) > 0 && (diff * -1) < n){
                    res = 0;
                }
                else{
                    res = 1;
                }
            }
        }
        if(res == 1){
            printf("Not Jolly\n");
        }
        else{
            printf("Jolly\n");
        }
    }
    return 0;
}