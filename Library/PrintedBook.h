#pragma once
#include "Book.h"

namespace library {

class PrintedBook : public Book {
    int pages;
public:
    PrintedBook(const std::string& t, const std::string& a, int p);
    void display() const override;
    void saveToFile(std::ofstream& out) const override;
    bool matches(const std::string& keyword) const override;
    void update(const std::string& newTitle, const std::string& newAuthor) override;
};
}