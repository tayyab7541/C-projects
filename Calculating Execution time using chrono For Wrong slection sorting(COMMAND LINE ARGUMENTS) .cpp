#include<iostream>
#include<chrono>  //library to use the function that calculate execution time 
#include<ctime>   //library to generate random number 
#include<fstream>
using namespace std;
using namespace chrono;
int main(int arg, char** arey) //in arey takes name of .exe of this program and name of file at which result will be written  
{


    if (arg == 2) 
    {
        srand(time(0));



        const int size = 100000;
        int ar[size];

        for (int i = size; i >= 0; i--)    //assigning random values to array 
        {
            ar[i] = rand()%3000+1;
        }
        int temp = 0;

        //performing slection sorting in wrong way 
        auto start = high_resolution_clock::now();   //for calcualting time from start of sorting
        for (int i = 0; i < size - 1; i++)
        {
            temp = ar[i];
            for (int j = i + 1; j < size-2; j++)
            {
                if (temp > ar[j])
                {
                    int sp = ar[j];
                    ar[j] = temp;
                    temp = sp;
                }
            }
        }
        auto end = high_resolution_clock::now();   //calculating time where sorting has been done
        auto duration = duration_cast<milliseconds>(end - start);   //calculating time taken in milli seconds 

        //writting time taken to sort the array in file whose name will be give in comman line argument 
        fstream file;
        file.open(arey[1], ios::app);
        if (file)
        {
            file << "Slection sorting wrong algorithm = " << duration.count()<<"mili second" << endl; 
            cout << "Result enterd";
        }
        else
        {
            cout << "file not opened";
        }
    }
    else
    {
        cout << "Invalid arguments given give two arguments only";
    }

}
