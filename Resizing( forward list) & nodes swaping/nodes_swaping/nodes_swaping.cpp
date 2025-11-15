#include<iostream>
#include "forward.h"
int main()
{
    forward f;

    for (int i = 1; i < 5; ++i)
    {
        f.push_front(i);
    }

    f.swaping();

    for (int i = 1; i < 5; ++i)
    {
        std::cout << f.front() << "\n";
        f.pop_front();
    }
    return 0;


}