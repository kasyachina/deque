#include <iostream>
#include "deque.h"
#include <fstream>

int main()
{
    std::ofstream fout("deque.out");
    {
        deque<int> l;
        l.push_back(9);
        l.push_front(3);
        l.push_front(1);
        l.push_back(7);
        l.print(fout);
        l.print_reversed(fout);
        for (deque<int>::iterator it = l.back(); it != l.end(); --it)
        {
            fout << *it << ' ';
        }
        fout << std::endl;
        for (deque<int>::iterator it = l.begin(); it != l.end(); ++it)
        {
            fout << *it << ' ';
        }
        fout << std::endl;
        for(const auto& x : l)
        {
            fout << x << ' ';
        }
        fout << std::endl;
    }
    {
        deque<const char *> d;
        d.push_back("abacaba");
        d.push_back("bacabaca");
        d.push_front("cabacaba");
        d.print(fout);
    }
    {
        deque<double> d;
        d.push_back(1.5);
        d.push_back(3.7);
        d.push_front(0.3);
        d.print(fout);
    }
    return 0;
}