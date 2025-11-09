#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Book.h"

namespace library {

class Library {
    std::vector<std::unique_ptr<Book>> books;
public:
    void addBook(std::unique_ptr<Book> book);
    void displayAll() const;
    void saveAll(const std::string& filename) const;
    void searchBook(const std::string& keyword) const;
    void updateBook(int index, const std::string& newTitle, const std::string& newAuthor);
    void deleteBook(int index);
};
}