#pragma once
#include "Book.h"

namespace library {

class EBook : public Book {
    double fileSizeMB;
public:
    EBook(const std::string& t, const std::string& a, double size);
    void display() const override;
    void saveToFile(std::ofstream& out) const override;
    bool matches(const std::string& keyword) const override;
    void update(const std::string& newTitle, const std::string& newAuthor) override;
};

}