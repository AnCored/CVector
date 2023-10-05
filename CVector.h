#pragma once

#include <iostream>
#include <limits> // Тут лежит epsilon()

// Через двоеточие вызывается статическая функция
// На экзе будут задачи с даблами на побитовые операции


class CVector{
public:
    
    // Coordinates of vectors
    double *digit_;
 
    // Length of vectors
    size_t length_;

    // Empty constructor
    CVector();

    // Constructor without coordinates(return zero-vector with <length_> coordinates)
    CVector(size_t);

    // Standart constructor
    CVector(size_t, double*);
    
    // Copy constructor
    CVector(const CVector& );

    // Destructor
    ~CVector();
    
    // Addition operator
    CVector operator+(const CVector& second_vector) const ;
    
    // It is an external function
    friend CVector&& operator+(CVector&& ,const CVector&);
    
    // Subtraction operator
    CVector operator-(const CVector& second_vector);
    
    // Scalar product operator 
    double operator*(const CVector& second_vector);
    
    // Coordinate assigment operator
    double& operator[](int);

    // Assigment vector operator
    CVector& operator=(const CVector& second_vector);

    // Output operator
    friend std::ostream& operator<<(std::ostream&, const CVector&);
};
