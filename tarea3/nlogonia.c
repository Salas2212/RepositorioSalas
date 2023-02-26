/*/ 
Nombre: Juan Esteban Salas
Codigo: 8975783
/*/
#include <stdio.h>

int main(){
    int K, N, M, X, Y, i;
    scanf("%d", &K);
    while (K != 0)
    {
        scanf("%d %d", &N, &M);
        for(i = 0; i < K; ++i){
            scanf("%d %d", &X, &Y);
            if(X < N && Y < M){
                printf("SO\n");
            }
            else if(X > N && Y > M){
                printf("NE\n");
            }
            else if(X > N && Y < M){
                printf("SE\n");
            }
            else if(X < N && Y > M){
                printf("NO\n");
            }
            else{
                printf("divisa\n");
            }
        }
        scanf("%d", &K);
    }
    return 0;
}