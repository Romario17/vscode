#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    bool boolean = false;
    int i;
    while(!boolean){
        scanf("%d", &i);
        if(i == 1)
            boolean = true;
    }

    return (EXIT_SUCCESS);
}