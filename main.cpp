#include "header.h"
#include "autotests.h"

int main(){

    try {
        // if(MainTest()!=0){

        //     std::cout<< "Error! Some test failed!"<<std::endl;

        //     return 1;
        // }
        // else{
        //     std::cout<< "\n Tests complete!\n"<<std::endl;
        // }

        double arr[] = {1., 2.,12.};
        CVector v(3, arr);
        CVector v1(3, arr);
        
        v = v1 + v + v + v1 + v;

        std::cout << v << '\n';

        return 0;

        /*size_t len1=0;
        size_t len2=0;

        char tmp='a';

        double *array1;
        double *array2;


        std::cout<< " Input length of first vector(1):";
        std::cin>> len1;
        std::cout<<std::endl;

        std::cout<< " Input length of second vector(2):";
        std::cin>> len2;
        std::cout<<std::endl;


        array1 = new double[len1];
        array2 = new double[len2];


        write_array(len1, array1);
        write_array(len2, array2);

        CVector vec1(len1, array1);
        CVector vec2(len2, array2);


        while(std::cin.get(tmp)){

            std::cout<<" If you want to exit input E"<<std::endl;
            std::cout<< " What do you want to do with vector_1 and vector_2?(+,-,=,*, o[output]) \n ";
            std::cin>>tmp;
            std::cout<< std::endl;

            if(tmp == 'E'){ break;}

            switch(tmp){
                case '+': std::cout<< vec1 + vec2<< std::endl; break;
                case '-': std::cout<< vec1 - vec2<< std::endl; break;
                case '=': std::cout<< vec1; std::cout<< vec2<<"\n"; vec1 = vec2; std::cout<<" vec1 = vec2: "<< vec1<< std::endl; break;
                case '*': std::cout<< vec1*vec2<< std::endl; break;
                case 'o': std::cout<<" Vector_1: "<< vec1; std::cout<<" Vector_2: "<< vec2<<std::endl; break;
            }
        }


        delete[] array1;
        delete[] array2;*/

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
