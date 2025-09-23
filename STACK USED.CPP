#include<iostream>
#include<stack>

class stack 
{
    private:
        int *ar;
        int _top;
        int _size;
    public:
    stack(int s=10)
    {
        _size=s;
        ar=new int[_size];
        _top=-1;
    }
    void push(const int &n)
    {
        ++_top;
        ar[_top]=n;

    }
    void pop()
    {
      -- _top;
    }
    bool isempty()
    {
       if(_top==-1)
       {
        return true;
       }
       else
       {
        return false;
       }
    }
    int top()
    { 
        return ar[_top];

    }
}


int main()
{	var = stack(100);
	int n;
	std::cout << "Enter how many numbers you want to input = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		std::cout << "Enter number = ";
		std::cin >> temp;
		var.push(temp);
	}
	for (int j = 0; j <= n; j++)
	{
		std::cout << var.top() << std::endl;
		var.pop();
	}

}
