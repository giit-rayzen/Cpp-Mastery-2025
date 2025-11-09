#pragma once
#include <string>
#include <fstream>

namespace library{
   class Book{
protected:
    std::string title;
    std::string author;
public:
    Book(const std::string&t,const std::string&a);

    virtual void display() const=0;
    virtual void saveToFile(std::ofstream& out)const=0;
    virtual bool matches(const std::string &keyword)const=0;
    virtual void update(const std::string& newTitle,const std::string& newAuthor)=0;

    virtual ~Book();
   };
}