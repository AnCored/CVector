#include "autotests.h"

int SummTest(){

    double arr1[] = {1., 1., 1.};
    double arr2[] = {2.,2.,0.};

    CVector test1(3, arr1);
    CVector test2(3, arr2);

    CVector resVec;

    resVec = test1 + test2;


    if( (abs(resVec[0] - 3.) > std::numeric_limits<double>::epsilon()*std::max(resVec[0], 3.)) &&
        (abs(resVec[2] - 1.) > std::numeric_limits<double>::epsilon()*std::max(resVec[2], 1.))){
        
        return 1;
    }

    return 0;
}

int SubtractionTest(){

    double arr1[] = {0.,0.};
    double arr2[] = {1.,1.};

    CVector test1(2, arr1);
    CVector test2(2, arr2);

    CVector resVec;

    resVec = test2 - test1;
    

    if(abs(resVec[1] - 1.) > std::numeric_limits<double>::epsilon()*std::max(resVec[1], 1.)){
        std::cout<<"--2--"<<std::endl;
        return 1;
    }
    
    return 0;
}

int DotProductTest(){

    double arr1[] = {2., 4., 6., 8., 10.};
    double arr2[] = {1., 1., 1., 1., 0.1};

    CVector test1(5, arr1);
    CVector test2(5, arr2);

    double resDot = test1*test2;

    if(abs(resDot - 21.) > std::numeric_limits<double>::epsilon()*std::max(resDot, 21.)){
        return 1;
    }
    
    return 0;
}

int AssigmentTest(){

    double arr1[] = {2., 4., 6., 8., 10.};
    double arr2[] = {1., 1., 1., 1., 0.1};

    CVector test1(5, arr1);
    CVector test2(5, arr2);

    test1 = test2;

    if(abs(test1[4] - 0.1) > std::numeric_limits<double>::epsilon()*std::max(test1[4], 0.1)){
        return 1;
    }
    
    return 0;
}

int MultiSummTest(){

    double arr1[] = { 0.1, 0.2, 0.3, 0.4};
    double arr2[] = { 0.1, 0.2, 0.3, 0.4};
    double arr3[] = { 0.1, 0.2, 0.3, 0.4};
    double arr4[] = { 0.1, 0.2, 0.3, 0.4};

    CVector test1(4, arr1);
    CVector test2(4, arr2);
    CVector test3(4, arr3);
    CVector test4(4, arr4);

    CVector resVec;

    resVec = test1+test2+test3+test4;

    if(abs(resVec[2] - 1.2) > std::numeric_limits<double>::epsilon()*std::max(resVec[2], 1.2)){ return 1;}


    return 0;
}

int MainTest(){

    int index=0;

    index += SummTest();
    index += SubtractionTest();
    index += DotProductTest();
    index += AssigmentTest();
    index +=  MultiSummTest();

    return index;
}
