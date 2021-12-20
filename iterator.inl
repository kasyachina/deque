#include "deque.h"

template<typename T>
bool deque<T>::iterator::operator==(const deque<T>::iterator& it) const
{
    return (this -> node == it.node);
}
template<typename T>
bool deque<T>::iterator::operator!=(const deque<T>::iterator& it) const
{
    return !this->operator==(it);
}
template<typename T>
T deque<T>::iterator::operator*() const
{
    return this -> node -> value;
}
template<typename T>
deque<T>::iterator deque<T>::iterator::operator++()
{
    this -> node = node -> next;
    return *this;
}
template<typename T>
deque<T>::iterator deque<T>::iterator::operator++(int)
{
    deque<T>::iterator it = *this;
    this -> node = node -> next;
    return it;
}
template<typename T>
deque<T>::iterator deque<T>::iterator::operator--()
{
    this -> node = node -> prev;
    return *this;
}
template<typename T>
deque<T>::iterator deque<T>::iterator::operator--(int)
{
    deque<T>::iterator it = *this;
    this -> node = node -> prev;
    return it;
}