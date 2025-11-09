#pragma once
#include <stdexcept>
#include <string>

namespace library {

class LibraryException : public std::runtime_error {
public:
    explicit LibraryException(const std::string& msg) : std::runtime_error(msg) {}
};
}