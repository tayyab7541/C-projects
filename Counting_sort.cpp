#include<iostream>

void Counting_sort(int *input,int end)//i am considering index of input starts from 1 
{
int max;
max=input[1];
for(int i=1;i<=end;++i)
if(max<input[i])
max=input[i];

int refrence[max+1]={0};
for(int i=1;i<=end;++i)
refrence[input[i]]++;

for(int i=2;i<=max;++i)
refrence[i]=refrence[i]+refrence[i-1];

int output[refrence[max]+1];
for(int i=end;i>=1;--i)
{
output[refrence[input[i]]]=input[i];
--refrence[input[i]];
}
}

int main()
{
    int ar[]={0,8,2,5,2,7,3,2,5,2,3,4,11,8,3,7};
    Counting_sort(ar,15);
    for(int i=1;i<=15;++i)std::cout<<ar[i]<<std::endl;
}
