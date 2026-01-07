// If sz == cap → reallocate amortized O(1) insertion

#include <iostream>
#include <algorithm>
#include <stdexcept>

class MiniVector {
private:
    int* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t newCap) {
        int* newData = new int[newCap];

        for (size_t i = 0; i < sz; ++i)
            newData[i] = std::move(data[i]);

        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    MiniVector() : data(nullptr), sz(0), cap(0) {}

    ~MiniVector() {
        delete[] data;
    }

    // Copy Constructor
    MiniVector(const MiniVector& other)
        : data(new int[other.cap]), sz(other.sz), cap(other.cap) {
        std::copy(other.data, other.data + sz, data);
    }

    // Move Constructor
    MiniVector(MiniVector&& other) noexcept
        : data(other.data), sz(other.sz), cap(other.cap) {
        other.data = nullptr;
        other.sz = other.cap = 0;
    }

    // Copy Assignment
    MiniVector& operator=(const MiniVector& other) {
        if (this == &other) return *this;

        int* newData = new int[other.cap];
        std::copy(other.data, other.data + other.sz, newData);

        delete[] data;
        data = newData;
        sz = other.sz;
        cap = other.cap;

        return *this;
    }

    // Move Assignment
    MiniVector& operator=(MiniVector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;
        data = other.data;
        sz = other.sz;
        cap = other.cap;

        other.data = nullptr;
        other.sz = other.cap = 0;

        return *this;
    }

    void push_back(int value) {
        if (sz == cap) {
            size_t newCap = (cap == 0) ? 1 : cap * 2;
            reallocate(newCap);
        }
        data[sz++] = value;
    }

    int& operator[](size_t index) {
        if (index >= sz)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }
};

int main() {
    MiniVector v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    MiniVector v2 = v;           // copy
    MiniVector v3 = std::move(v); // move

    std::cout << v2[5] << std::endl;
}
