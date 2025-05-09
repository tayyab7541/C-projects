#include<iostream>
using namespace std;
class matrix
{
    private:
    int **m;
    int row,col;
    public:
    void input()
    {
        int i,j;
        cout<<"Enter number of rows = ";
        cin>>row;
        cout<<"Enter number of colums = ";
        cin>>col;
        m=new int*[row];
        for(i=0;i<row;i++)
        {
            m[i]=new int[col];
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cout<<"Enter value = ";
                cin>>m[i][j];

            }
        }
    }
     
    friend class b;
};
class b
{
    public:
    matrix m1,m2,m3;
    
    
        void multiply()
        {
            if(m1.col==m2.row)
        {
            for(int i=0;i<m1.row;i++)
            {
                for(int j=0;j<m1.col;j++)
                {
                    int n=0;
                  for(int k=0;k<m2.row;k++)
                  {
                     n+=m1.m[i][k]*m2.m[k][j];
                  }
                  cout<<n<<"\t";
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"Multiplication is not possible bacuse of different order of matrix \n";
        }
        }
};

int main()
{
 
    matrix mat1,mat2;
    mat1.input();
    mat2.input();
    b obj;
    obj.m1=mat1;
    obj.m2=mat2;
    obj.multiply();
    return 0;
}