#include<iostream>
#include<fstream>
int main()
{
    std::fstream file;
    file.open("F:\\DSA\\past-papers\\sum.csv",std::ios::app);
    if(file.is_open())
    {
        int num1,num2,num3;
        std::cout<<"Enter v1 = ";
        std::cin>>num1;
        std::cout<<"Enter v2 = ";
        std::cin>>num2;
         std::cout<<"Enter v3 = ";
        std::cin>>num3;
        file<<num1<<","<<num2<<","<<num3<<"\n";
        file.seekp(0);
        std::cout<<"position of point put = "<<file.tellp()<<std::endl;
    }
    else 
    {
        std::cout<<"file is not opend ";
    }
   
}