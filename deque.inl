#include "deque.h"

template <typename T>
deque<T>::deque()
{
    this->first = nullptr;
    this->last = nullptr;
    this->_size = 0;
}
template <typename T>
void deque<T>::clone(const deque<T> &d)
{
    clear();
    for (const auto &x : d)
        push_back(x);
}
template <typename T>
deque<T>::deque(const deque<T> &d)
{
    clone(d);
}
template <typename T>
size_t deque<T>::size() const
{
    return _size;
}
template <typename T>
bool deque<T>::empty() const
{
    return (first == nullptr);
}
template <typename T>
void deque<T>::clear()
{
    while (pop_back());
}
template <typename T>
deque<T>::iterator deque<T>::begin() const
{
    return iterator(first);
}
template <typename T>
deque<T>::iterator deque<T>::end() const
{
    return iterator(nullptr);
}
template <typename T>
deque<T>::iterator deque<T>::back() const
{
    return iterator(last);
}
template <typename T>
void deque<T>::push_back(const T &val)
{
    if (empty())
    {
        first = new DLNode<T>;
        last = first;
        first->value = val;
    }
    else
    {
        DLNode<T> *NewNode = new DLNode<T>;
        last->next = NewNode;
        NewNode->prev = last;
        last = NewNode;
        NewNode->value = val;
    }
    _size++;
}
template <typename T>
bool deque<T>::pop_back()
{
    if (empty())
    {
        return 0;
    }
    DLNode<T> *NewLastNode = last->prev;
    //std::cout << last->value << " is deleted\n";
    delete last;
    if (NewLastNode != nullptr)
        NewLastNode->next = nullptr;
    else
    {
        first = nullptr;
    }
    last = NewLastNode;
    _size--;
    return 1;
}
template <typename T>
void deque<T>::push_front(const T &val)
{
    if (empty())
    {
        first = new DLNode<T>;
        first->value = val;
        last = first;
    }
    else
    {
        DLNode<T> *NewNode = new DLNode<T>;
        NewNode->value = val;
        first->prev = NewNode;
        NewNode->next = first;
        first = NewNode;
    }
    _size++;
}
template <typename T>
bool deque<T>::pop_front()
{
    if (empty())
    {
        return 0;
    }
    DLNode<T> *NewFirstNode = first->next;
    //std::cout << first->value << " is deleted\n";
    delete first;
    if (NewFirstNode != nullptr)
        NewFirstNode->prev = nullptr;
    else
    {
        last = nullptr;
    }
    first = NewFirstNode;
    _size--;
    return 1;
}
template <typename T>
deque<T>::~deque()
{
    clear();
    //std::cout << "Deque is deleted" << std::endl;
}
template <typename T>
void deque<T>::print(std::ostream &out) const
{
    out << "Deque : (";
    if (!empty())
    {
        DLNode<T> *CurrentNode = first;
        while (CurrentNode != last)
        {
            out << CurrentNode->value << ',';
            CurrentNode = CurrentNode->next;
        }
        out << last->value;
    }
    out << ")\n";
}
template <typename T>
void deque<T>::print_reversed(std::ostream &out) const
{
    out << "Reversed deque : (";
    if (!empty())
    {
        DLNode<T> *CurrentNode = last;
        while (CurrentNode != first)
        {
            out << CurrentNode->value << ',';
            CurrentNode = CurrentNode->prev;
        }
        out << first->value;
    }
    out << ")\n";
}
template <typename T>
deque<T> &deque<T>::operator=(const deque<T> &d)
{
    if (this != &d)
    {
        clone(d);
    }
    return *this;
}