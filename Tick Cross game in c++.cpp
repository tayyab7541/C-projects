#include<iostream>
using namespace std;
int main()
{


    const int row=3;
    int i,j;
    char num;
    const int col=3;
    char ar[row][col]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    cout<<"Welcome to Tick Cross game \n";
    cout<<"Player [T] \n";
    cout<<"Player [F] \n";
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
        cout<<ar[i][j]<<"\t";
    }
    cout<<endl;
    }
    for(i=1;i<=9;i++)
    {
        if(i%2!=0)
        {
            bool found=1;
            do
            {
            cout<<"Player [T] Turn = ";
            cin>>num;
            for(int k=0;k<row;k++)
            {
                for(j=0;j<col;j++)
                {
                    if(num==ar[k][j]&&(ar[k][j]!='T'||ar[k][j]!='F'))
                    {
                        ar[k][j]='T';
                        found=0;
                    }
                }
            }
            if(found)
            {
                cout<<"This cell was already taken by other player \n ";
            }
            }while(found);
        }
        else if(i%2==0)
        {
            bool found=1;
            do
            {      
            cout<<"Player [F] Turn = ";
            cin>>num;
            
            for(int k=0;k<row;k++)
            {
                for(j=0;j<col;j++)
                {
                    if(num==ar[k][j]&&(ar[k][j]!='T'||ar[k][j]!='F'))
                    {
                        ar[k][j]='F';
                        found=0;
                    }
                }
            }
             if(found)
            {
                cout<<"This cell was already taken by other player \n ";
            }

            }while(found);

         }
        }
    cout<<"\n \n After game is played \n \n ";
     for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
        cout<<ar[i][j]<<"\t";
    }
    cout<<endl;
    }
   }
