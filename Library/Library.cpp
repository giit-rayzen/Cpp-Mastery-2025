#include "Library.h"
#include "LibraryException.h"
#include <fstream>
#include <iostream>

namespace library {

void Library::addBook(std::unique_ptr<Book> book) {
    books.push_back(std::move(book));
}

void Library::displayAll() const {
    for (const auto& book : books) book->display();
}

void Library::saveAll(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw LibraryException("Failed to open file: " + filename);
    for (const auto& book : books) book->saveToFile(out);
}

void Library::searchBook(const std::string& keyword) const {
    bool found = false;
    for (const auto& book : books) {
        if (book->matches(keyword)) {
            book->display();
            found = true;
        }
    }
    if (!found) std::cout << "No book found for keyword: " << keyword << "\n";
}

void Library::updateBook(int index, const std::string& newTitle, const std::string& newAuthor) {
    if (index < 0 || index >= books.size()) {
        std::cout << "Invalid index\n";
        return;
    }
    books[index]->update(newTitle, newAuthor);
}

void Library::deleteBook(int index) {
    if (index < 0 || index >= books.size()) {
        std::cout << "Invalid index\n";
        return;
    }
    books.erase(books.begin() + index);
    std::cout << "Book deleted successfully\n";
}
}