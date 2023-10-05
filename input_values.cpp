#include "header.h"


void write_array(int length, double *array){
    
    for(int i=0; i<length; i++){
        std::cout<< " Input ["<< i+1<<"] coordinate of vector: ";
        std::cin >> array[i];
        std::cout<< std::endl;
    }
}