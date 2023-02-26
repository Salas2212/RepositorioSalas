/*/ 
Nombre: Juan Esteban Salas
Codigo: 8975783
/*/
#include <stdio.h>

int main(){
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        scanf("%d", &N);
        int Pis[N], Qis[N], gTotal = 0, gPosicion = 0,P = 1;
        for(int j = 0; j < N; ++j){
            scanf("%d", &Pis[j]);
        }
        for(int j = 0; j < N; ++j){
            scanf("%d", &Qis[j]);
            gTotal += Pis[j] - Qis[j];
            gPosicion += Pis[j] - Qis[j];
            if (gPosicion < 0)
            {
                P = j + 2;
                gPosicion = 0;
            }
        }
        if (gTotal < 0)
        {
            printf("Case %d: Not possible\n", i+1);
        }
        else
        {
            printf("Case %d: Possible from station %d\n", i+1, P);
        }
        
    }
    
    return 0;
}