#include <iostream>
#include <memory>
using namespace std;
class ExceptionVec{

};

template <class T_Type>
class Vec{
    private:
        T_Type* data_;
        int len_;
    public:
        Vec(int len, T_Type* data);
        Vec(int len);
        Vec(const Vec& other);
        ~Vec();
        void set(T_Type arg, int coord);
        T_Type get(int coord)const;
        T_Type max_norm()const;
        Vec<T_Type> operator-(const Vec<T_Type>& other);
        Vec<T_Type> operator*(T_Type num);
        T_Type operator^(const Vec<T_Type>& other);
        const Vec<T_Type>& operator=();
        Vec<T_Type> operator+=();
        bool  operator==() const;
        Vec<T_Type> operator[]();
        Vec<T_Type> operator<<();
        template <typename V>
        friend Vec<V>& operator+(const Vec<V> *arr1, const Vec<V> *arr2);
};  

template <typename T>
Vec<T>::Vec(int len, T* data) : len_(len){
    if(len < 0){throw ExceptionVec();}

    data_ = new T_Type[len];
    for(int i = 0; i < len; i++){
        data_[i] = data[i]; 
    }
}

template <typename T>
Vec<T>::Vec(int len) : len_(len){
    if(len < 0){throw ExceptionVec();}

    data_ = new T[len];
    for(int i = 0; i < len; i++){
        data_[i] = 0;
    }
}

template <typename T>
Vec<T>::Vec(const Vec& other) : len_(other.len_){
    data_ = new T_Type[len_];
    for (int i = 0; i < len_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Vec<T>::~Vec(){
    delete[] data_;
}

template <typename T>
void Vec<T>::set(T arg, int coord){
    if(len_ < coord){
        throw {};
    }

    data[coord] = arg;
}

template <typename T>
T Vec<T>::get(int coord)const{
    if(len_ < coord){
        throw {};
    }
    return data_[coord];
}

template<typename T>
T Vec<T>::max_norm()const{
    T max = data_[0];
    for (int i = 1; i < len_; i++) {
        if (data_[i] > max) {
            max = data[i];
        }
    }
    return max;
}

template<typename T>
Vec<T> operator+(const Vec<T>& arr1, const Vec<T>& arr2){
    if(arr1.len_ != arr2.len_){
        throw {};
    }

    Vec<T> res(arr1.len_);

    for (int i = 0; i < arr1.len_; i++) {
        result.data_[i] = arr1.data_[i] + arr2.data_[i];
    }

    return result;
}

template<typename T>
Vec<T> Vec<T>::operator-(const Vec<T>& other){
    if(len_ != arr2.len_){
        throw {};
    }

    for (int i = 0; i < arr1.len_; i++) {
        data_[i] -= other.data_[i];
    }
}

template<typename T>
Vec<T> Vec<T>::operator*(T num){
    for (int i = 0; i < arr1.len_; i++) {
        data_[i] = data_[i] * num;
    }
}

template<typename T>
T Vec<T>::operator^(const Vec<T>& other){
    if(len_ != other.len_){
        throw {};
    }


}