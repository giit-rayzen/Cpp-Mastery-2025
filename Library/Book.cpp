#include"Book.h"

namespace library{
    Book::Book(const std::string& t,const std::string& a):title(t),author(a){}
    Book::~Book(){}
}