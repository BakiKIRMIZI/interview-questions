#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
You have function called "random" that generates a number 
from 0 to 1 randomly and its uniformly distributed.
Calculate the number pi(π). 
*/

int main(){

    srand((unsigned)time(NULL));
    
    double a, cember_ici = 0 ,cember_disi = 0, x, y, uzaklik, pi;
    
    printf("Sayi gir:  ");
    scanf("%lf",&a);
    
    for(int i = 0; i <= a; i++){
        
        x = ((double)rand()/(double)(RAND_MAX)) * 1;
        y = ((double)rand()/(double)(RAND_MAX)) * 1;
        
        uzaklik = pow(x,2) + pow(y,2);
        uzaklik = uzaklik * uzaklik;
        
        if(uzaklik <= 1)
            cember_ici++;
        else
            cember_disi++;
    }
    
    pi = 4 * (cember_ici / (cember_ici + cember_disi));
    
    printf("Pi = %lf",pi);
    

    puts("\n");
    return 0;
}
