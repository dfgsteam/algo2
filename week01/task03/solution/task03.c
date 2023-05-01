#include <stdio.h>

int main(){
    int length;
    scanf("%d", &length);
    long start[length];
    long zahl;
    for(int i = 0; i < length; i++){
        scanf("%ld", &zahl);
        start[i] = zahl;
    }

    for(int i = 0; i < length; i++){
        if((start[i] % 2 != 0)^(start[i] % 3 != 0))
        // if(((start[i] % 2) && !(start[i] % 3)) || (!(start[i] % 2) && (start[i] % 3)))
            printf("%ld ", start[i]);
    }


    return 0;
}