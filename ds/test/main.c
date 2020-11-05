#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>


double my_atof(char *nptr){
    int* p;
    
    while (*nptr != '\0') {
        if ((*nptr >= 0 && *nptr <= 9) || *nptr == '.') {
            if(*nptr >= 0 && *nptr <= 9){
                *p=*nptr;
            }
        }
        *nptr++;
    }
    
    
    return 0;
}

int main() {
    printf("%d",calc_zig_spaces(3));
}
