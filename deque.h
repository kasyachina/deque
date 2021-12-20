#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
struct DLNode
{
    T value;
    DLNode *prev = nullptr;
    DLNode *next = nullptr;
};
template <typename T>
class deque
{
private:
    DLNode<T> *first;
    DLNode<T> *last;
    size_t _size;
    void clone(const deque<T> &);
public:
    class iterator
    {
    private:
        DLNode<T> *node;
    public:
        iterator(DLNode<T> *n) : node(n){};
        bool operator==(const iterator &) const;
        bool operator!=(const iterator &) const;
        T operator*() const;
        iterator operator++();
        iterator operator++(int);
        iterator operator--();
        iterator operator--(int);
    };
    deque();
    deque(const deque<T> &);
    size_t size() const;
    bool empty() const;
    void clear();
    //returns iterator to first element
    deque<T>::iterator begin() const;
    //returns iterator to the element after last element
    deque<T>::iterator end() const;
    //returns iterator to last element
    deque<T>::iterator back() const;
    void push_back(const T &);
    bool pop_back();
    void push_front(const T &);
    bool pop_front();
    void print(std::ostream & = std::cout) const;
    void print_reversed(std::ostream & = std::cout) const;
    deque<T> &operator=(const deque<T> &);
    virtual ~deque();
};
#include "deque.inl"
#include "iterator.inl"