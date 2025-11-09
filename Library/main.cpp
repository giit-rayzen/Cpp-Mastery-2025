#include "Library.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "LibraryException.h"
#include <iostream>

using namespace library;

int main() {
    try {
        Library lib;
        lib.addBook(std::make_unique<PrintedBook>("1984", "George Orwell", 328));
        lib.addBook(std::make_unique<EBook>("Clean Code", "Robert C. Martin", 3.2));
        lib.addBook(std::make_unique<PrintedBook>("The Great Gatsby", "F. Scott Fitzgerald", 180));

        std::cout << "\nAll Books:\n";
        lib.displayAll();

        std::cout << "\nSearch for 'Code':\n";
        lib.searchBook("Code");

        std::cout << "\nUpdating book at index 0:\n";
        lib.updateBook(0, "Nineteen Eighty-Four", "George Orwell");

        std::cout << "\nAfter Update:\n";
        lib.displayAll();

        std::cout << "\nDeleting book at index 1:\n";
        lib.deleteBook(1);

        std::cout << "\nAfter Deletion:\n";
        lib.displayAll();

        lib.saveAll("library.txt");
    } catch (const LibraryException& e) {
        std::cerr << "Library error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << "\n";
    }

    return 0;
}