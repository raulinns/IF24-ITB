#ifndef SAFE_BOX_HPP
#define SAFE_BOX_HPP

#include "SafeBoxException.hpp"
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> class SafeBox {
private:
    int max_capacity;
    function<bool(const T &)> validator;
    vector<T> items;

public:
    SafeBox(int capacity, function<bool(const T &)> validator = nullptr) 
        : max_capacity(capacity), validator(validator) {}

    void store(const T &item) {
        if (validator != nullptr && !validator(item)) {
            throw InvalidItemException<T>(item);
        }
        if (items.size() >= max_capacity) {
            throw BoxFullException(max_capacity);
        }
        items.push_back(item);
    }

    T retrieve() {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        T top_item = items.back();
        items.pop_back();
        return top_item;
    }

    T peek() const {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        return items.back();
    }

    void reverse() {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        std::reverse(items.begin(), items.end());
    }

    int size() const {
        return items.size();
    }

    int capacity() const {
        return max_capacity;
    }

    bool isEmpty() const {
        return items.empty();
    }

    friend ostream &operator<<(ostream &os, const SafeBox<T> &box) {
        os << "[";
        for (size_t i = 0; i < box.items.size(); ++i) {
            os << box.items[i];
            if (i < box.items.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

template <typename T> int safeMerge(SafeBox<T> &src, SafeBox<T> &dst) {
    int moved_items = 0;
    while (!src.isEmpty()) {
        try {
            dst.store(src.peek());
            src.retrieve();
            moved_items++;
        } catch (const BoxFullException &e) {
            break;
        }
    }
    return moved_items;
}

#endif
