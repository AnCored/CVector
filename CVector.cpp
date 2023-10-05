#include "CVector.h"
// All instructions about these operators and methods
// you just find in CVector.hpp

CVector::CVector(size_t length, double *arr){

    this->length_ = length;

    this->digit_ = new double[length];

    for(int i=0; i  < static_cast<int>(length_); i++){
        this->digit_[i] = arr[i];
    }
}

CVector::CVector(size_t length){
    this->length_ = length;

    this->digit_ = new double[length];

    for(int i=0; i<static_cast<int>(length); i++){
        this->digit_[i] = 0;
    }
}

CVector::CVector(){
    this->length_ = 0;
    this->digit_ = new double[0];
}


CVector::CVector(const CVector& vector){
    this->digit_ = vector.digit_;
    this->length_ = vector.length_;
}


CVector::~CVector(){
    delete[] this->digit_;
}


CVector CVector::operator+(const CVector &second_vector)const {
    
    if(this->length_ != second_vector.length_){
        throw std::runtime_error("Error! Two vectors have difference length!");
    }

    CVector resVec(this->length_);

    for(int i=0; i < static_cast<int>(this->length_); i++){
        resVec.digit_[i] = this->digit_[i] + second_vector.digit_[i];
    }

    return resVec;
}


CVector&& operator+(CVector&& first_vector, const CVector& second_vector){

    if(first_vector.length_ != second_vector.length_){ throw std::runtime_error("Error! Two vectors have difference length!");}

    std::cout<< " Smart plus"<< std::endl;

    for(int i=0; i < static_cast<int>(first_vector.length_); i++){
        first_vector.digit_[i] += second_vector.digit_[i];
    }

    return static_cast<CVector&&>(first_vector);
}

CVector CVector::operator-(const CVector &second_vector){
    
    if(this->length_ != second_vector.length_){
        throw std::runtime_error("Error! Two vectors have difference length!");
    }

    CVector resVec(this->length_);

    for(int i=0; i<static_cast<int>(this->length_); i++){
        resVec.digit_[i] = this->digit_[i] - second_vector.digit_[i];
    }

    return resVec;
}

double CVector::operator*(const CVector &second_vector){

    if(this->length_ != second_vector.length_){
        throw std::runtime_error("Error! Two vectors have difference length!");
    }

    double dot_product=0.;

    for(int i=0; i < static_cast<int>(this->length_); i++){
        dot_product += this->digit_[i] * second_vector.digit_[i];
    }

    return dot_product;
}


double& CVector::operator[](int n){
    // If the index "n" is over than length of array then 
    // it need to expand on n-length_ elements

    if( n > static_cast<int>(this->length_) ){
        CVector tmp(n);

        // Reconstruct the this->digit_ and this->length_
        for(int i=0; i < static_cast<int>(this->length_); i++){
            tmp.digit_[i] = this->digit_[i]; 
        }

        delete[] this->digit_;

        this->digit_ = tmp.digit_;
        tmp.digit_ = nullptr;
        this->length_ = tmp.length_;

        //-----------------------------------------------
        return this->digit_[n-1];
    }
    else{
        return this->digit_[n];
    }
}

// Assignable operator
CVector& CVector::operator=(const CVector& assignable_vector){

    // Test for comparsing <this> and <assignable_vector>
    if(this == &assignable_vector){ return *this; }

    this->length_ = assignable_vector.length_;

    delete[] this->digit_;

    this->digit_ = new double[this->length_];

    for(int i=0; i < static_cast<int>(assignable_vector.length_); i++){
        this->digit_[i] = assignable_vector.digit_[i];
    }

    return *this;
}


std::ostream& operator<<(std::ostream& out, const CVector& vect){

    out << "(";  
    for (int i = 0; i < static_cast<int>(vect.length_); i++){
        if(i < static_cast<int>(vect.length_) - 1){ out << vect.digit_[i] << ", ";}
        else{ out << vect.digit_[i]; out << ")" << std::endl; }
    } 
	
    return out;
}
