#ifndef SAFE_BOX_EXCEPTION_HPP
#define SAFE_BOX_EXCEPTION_HPP

#include <exception>
#include <sstream>
#include <string>

using namespace std;

// Base class untuk semua exception SafeBox.
class SafeBoxException : public exception {
public:
    virtual const char* what() const noexcept override = 0;
};

class BoxFullException : public SafeBoxException {
private:
    string msg;
public:
    BoxFullException(int capacity) {
        ostringstream oss;
        oss << "Box penuh: kapasitas maks " << capacity;
        msg = oss.str();
    }
    
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class BoxEmptyException : public SafeBoxException {
public:
    const char* what() const noexcept override {
        return "Box kosong";
    }
};

template <typename T> 
class InvalidItemException : public SafeBoxException {
private:
    string msg;
public:
    InvalidItemException(const T& item) {
        ostringstream oss;
        oss << "Item tidak valid: " << item;
        msg = oss.str();
    }
    
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif
