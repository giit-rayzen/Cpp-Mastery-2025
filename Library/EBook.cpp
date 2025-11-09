#include "EBook.h"
#include <iostream>

namespace library {

EBook::EBook(const std::string& t, const std::string& a, double size)
    : Book(t, a), fileSizeMB(size) {}

void EBook::display() const {
    std::cout << "EBook: " << title << " by " << author << " (" << fileSizeMB << " MB)\n";
}

void EBook::saveToFile(std::ofstream& out) const {
    out << "EBook," << title << "," << author << "," << fileSizeMB << "\n";
}

bool EBook::matches(const std::string& keyword) const {
    return title.find(keyword) != std::string::npos || author.find(keyword) != std::string::npos;
}

void EBook::update(const std::string& newTitle, const std::string& newAuthor) {
    title = newTitle;
    author = newAuthor;
}

}