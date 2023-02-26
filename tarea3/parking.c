/*/ 
Nombre: Juan Esteban Salas
Codigo: 8975783
/*/
#include <stdio.h>

int main() {
    int i, j, t, n, Out, arreglo[100];
    scanf("%d", &t);
    for(i = 0; i < t; ++i){
        int nMayor = 0, nMenor = 101;
        scanf("%d", &n);
        for(j = 0; j < n; ++j){
            scanf("%d", &arreglo[j]);
            if(arreglo[j] < nMenor){
                nMenor = arreglo[j];
            }
            if(arreglo[j] > nMayor){
                nMayor = arreglo[j];
            }
        }
        Out = (nMayor - nMenor)*2;
        printf("%d\n", Out);
    }
    return 0;
}