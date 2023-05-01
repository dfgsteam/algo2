#include <stdio.h>

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    long long List[N];
    for(int i = 0; i < N; i++){
        long long Zahl;
        scanf("%lld", &Zahl);
        List[i] = Zahl;
    }

    long long ges[M];
    for(int i = 0; i < M; i++){
        long long raten;
        scanf("%lld", &raten);
        ges[i] = raten;
    }

    for(int i = 0; i < M; i++){
        long long jetzt;
        jetzt = ges[i];
        int counter = 0;
        for(int i = 0; i < N; i++){
            if(List[i] == jetzt){
                counter++;
                printf("%d ", i+1);
            }
        }
        if(counter == 0)
            printf("None!");
        printf("\n");
    }
    return 0;
}