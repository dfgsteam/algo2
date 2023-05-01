#include <stdio.h>

long long poww(long long a, long long n);


int main(){
    int T;
    scanf("%d", &T);
    long long a, n;
    long long Zahl;
    long long bla[T];
    for(int i = 0; i < T; i++){
        scanf("%lld", &a);
        scanf("%lld", &n);
        Zahl = poww(a, n);
        bla[i] = Zahl;
    }
    for(int i = 0; i < T; i++){
        printf("%lld\n", bla[i]);
    }


    return 0;
}

long long poww(long long a, long long n){

    if(n == 1)
        return a;
    else if(n == 0)
        return 1;
    else{
        long long result;
        result = poww(a, n/2);
        if(n%2 == 0){
            return result * result;
        }
        else{
            return result * result * a;
        }
    }
}