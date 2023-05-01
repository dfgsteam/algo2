#include <stdio.h>

int main(){
    unsigned long long n;
    int counter = 0, rest;

    scanf("%llu", &n);
    while(n > 0){
        rest = n % 2;
        n /= 2;
        if(rest)
            counter++;

    }
    printf("%i", counter);
return 0;
}