#pragma once

template <typename T>
class Queue
{
    T* mem;
    // mem: ..., begin, ..., ..., end, ...
    size_t sz;
    size_t begin;
    size_t end;
    size_t memsize;

public:
    
    Queue() {
        memsize = 10;
        mem = new T[memsize];
        sz = 0;
        begin = 0;
        end = 0;
    }

    Queue(T value) {
        memsize = 10;
        mem = new T[memsize];
        mem[0] = value;
        sz = 1;
        begin = 0;
        end = 1;
    }

    ~Queue() {
        delete[] mem;
    }

    size_t size() {
        return sz;
    }

    size_t msize() {
        return memsize;
    }

    bool empty() {
        return sz == 0;
    }

    bool full() {
        return sz == memsize;
    }

    T top() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return mem[begin];
    }

    void push(const T& x) {
        if (full()) {
            T* copy = new T[2 * memsize];
            size_t k = 0;
            for (size_t i = begin; i < memsize; i++) {
                copy[k] = mem[i];
                k++;
            }
            for (size_t i = 0; i < end; i++) {
                copy[k] = mem[i];
                k++;
            }
            delete[] mem;
            mem = copy;
            memsize = 2 * memsize;
        } 
        mem[end] = x;
        end = (end + 1) % memsize;
        sz++;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        begin = (begin + 1) % memsize;
        sz--;
    }
};
