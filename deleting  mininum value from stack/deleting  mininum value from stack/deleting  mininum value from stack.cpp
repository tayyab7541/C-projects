#include<climits>
#include <iostream>
#include"stack.h"
int main()
{
    stack stk;
    stk.push(10);
    stk.push(5);
    stk.push(5);
    stk.push(3);
    stk.push(3);
    stk.push(3);
    stk.push(3);
    stk.push(3);
    stk.push(7);
    stk.push(7);
    stk.push(7);
    stk.push(3);
    std::cout << "size of stakc before del  = " << stk.size();
    stk.del_min();
    std::cout << "size of stakc after del  = " << stk.size();
    while (!stk.empty())
    {
        std::cout <<stk.top( )<< std::endl;
        stk.pop();
    }

}
