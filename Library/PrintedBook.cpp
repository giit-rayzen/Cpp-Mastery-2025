#include "PrintedBook.h"
#include <iostream>

namespace library {

PrintedBook::PrintedBook(const std::string& t, const std::string& a, int p)
    : Book(t, a), pages(p) {}

void PrintedBook::display() const {
    std::cout << "PrintedBook: " << title << " by " << author << " (" << pages << " pages)\n";
}

void PrintedBook::saveToFile(std::ofstream& out) const {
    out << "PrintedBook," << title << "," << author << "," << pages << "\n";
}

bool PrintedBook::matches(const std::string& keyword) const {
    return title.find(keyword) != std::string::npos || author.find(keyword) != std::string::npos;
}

void PrintedBook::update(const std::string& newTitle, const std::string& newAuthor) {
    title = newTitle;
    author = newAuthor;
}
}