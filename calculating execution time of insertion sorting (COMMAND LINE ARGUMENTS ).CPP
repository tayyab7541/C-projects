#include<iostream>
#include<chrono>//library to use the function that calculate execution time
#include<fstream>//library to generate random number 
#include<ctime>

using namespace std;
using namespace chrono;
int main(int argv,char **arey) //in arey takes name of .exe of this program and name of file at which result will be written  
{

    if(argv==2)
    {
    const int size=10000;
    int ar[size];
    srand(time(0));

    for(int i=0;i<size;i++)  //assigning random values to array 
    {
        ar[i]=rand()%5000+1;
    }


     auto start=high_resolution_clock::now();  //for calcualting time from start of sorting
    //performing insertion sorting in wrong way 
    for(int i=1;i<size;i++)
    {
        int temp=ar[i];
        int j=i;
        while(j>0&&temp<ar[j-1])
        {
            ar[j]=ar[j-1 ];
            j--;
        }
        ar[j]=temp;

    }
   auto end =high_resolution_clock::now();    //calculating time where sorting has been done
   auto duration=duration_cast<milliseconds>(end-start);  //calculating time taken in milli seconds 


   //writting time taken to sort the array in file whose name will be give in comman line argument 
   fstream file ;
   file.open(arey[1],ios::app);
   if(file)
   {
    file<<"Result of insert sorting = "<<duration.count()<<"\n";
     cout<<"Result enterd \n";   
   }
   else 
   {
    cout<<"Sorry file cannot be opened \n";
   }
 } 
 else 
 {
    cout<<"Invalid number of command line arguments \n";
 }
}
