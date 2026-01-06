/*
Design and implement a SmartBuffer class in C++:
Solution steps:
constructor(allocate memory,initializes memory)
Destructor(free memory,ensure no leak)
copy constructor(allocate new memory=>copy data(deep copy))
//as deep copy is heavy use move semantics to transfer ownership instead heavy copy
copy assignment(handle self assignment,exception safety,free old memory safely)
move constructor(steal resource,nullify source)
move assignment(free existing resource,transfer ownership)
*/

#include<iostream>
#include<algorithm>
#include<stdexcept>

class SmartBuffer{

private:
 int *data;
 size_t size;

public:
  //Constructor
  SmartBuffer(size_t sz=0):data(nullptr),size(sz){
    if(size>0){
        data=new int[size]();
    }
    std::cout << "Constructor called\n";
  }

  //Destructor
~SmartBuffer(){
    delete[]data;
    std::cout << "Destructor called\n";
}

//Copy Constructor(Deep copy)
SmartBuffer(const SmartBuffer& other):data(nullptr),size(other.size){
    if(size>0){
        data=new int[size];
        std::copy(other.data,other.data+size,data);
    }
    std::cout << " Copy Constructor called\n";
}

//Copy Assignment
SmartBuffer& operator=(const SmartBuffer& other){
    std::cout << "Copy Assignment called\n";

    if(this==&other)return *this;
    //Allocate first(strong exception safety)
    int *newData=nullptr;
    if(other.size>0){
        newData=new int[other.size];
        std::copy(other.data,other.data+other.size,newData);
    }
    delete[]data; //free old
    data=newData;
    size=other.size;

    return *this;
}

//Move Constructor
SmartBuffer(SmartBuffer&& other)noexcept
    :data(other.data),size(other.size){
    other.data=nullptr;
    other.size=0;
    std::cout << "Move Constructor called\n";
}

//Move Assignment Operator
SmartBuffer& operator=(SmartBuffer&& other)noexcept{
    std::cout << "Move Assignment called\n";
      if (this == &other)
            return *this;

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
}

//utility func
size_t getSize() const{
    return size;
}

int& operator[](size_t index){
    if(index>=size){
        throw std::out_of_range("Index out of bound");
    }
    return data[index];
}


};

//main function
int main(){
    SmartBuffer arr(5);
    arr[0]=87;

    SmartBuffer brr=arr; //copy ctor
    SmartBuffer crr;
    crr=arr; // copy assignment

    SmartBuffer drr=std::move(arr); //move constructor
    SmartBuffer er;
    er=std::move(brr); //move assignment

    return 0;
}