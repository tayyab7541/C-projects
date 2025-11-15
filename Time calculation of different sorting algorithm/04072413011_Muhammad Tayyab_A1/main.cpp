#include<iostream>
#include<chrono>  //library to use the function that calculate execution time 
#include<ctime>   //library to generate random number 
#include<fstream>
#include "Fuctions.h"



///////////////////////////////////////
///////////////////////////////////////

////Main starts her //////////////
//////////////////////////////////
//////////////////////////////////

int main(int arg, char** arey) //in arey takes name of .exe of this program and name of file at which result will be written  
{


    if (arg == 3)
    {
        srand(time(0));
        int i, des, k;

        int size = atoi(arey[1]);

        //these variables are used to give average
        long t_rand_wrong_slection_average=0;
        long t_rand_right_slection_average=0;
        long t_rand_insertion_average=0;
        long t_rand_bubble_average=0;

        long t_ascending_wrong_slection_average=0;
        long t_ascending_right_slection_average=0;
        long t_ascending_insertion_average=0;
        long t_ascending_bubble_average=0;

        long t_descending_wrong_slection_average=0;
        long t_descending_right_slection_average=0;
        long t_descending_insertion_average=0;
        long t_descending_bubble_average=0;


        for (k = 1; k <= 10; ++k)   //this will make surre program runs for 10 times
        {
            int* ar;   //dynamic array that will store values 
            ar = new int[size];




            for (i = 0; i < size; ++i)    //assigning random values to array 
            {
                ar[i] = rand() % 300000 + 1;
            }

            auto t1_random_wrong_slection_sorting = wrong_slection_sorting(ar, size);  //calling function for random array 
            t_rand_wrong_slection_average += t1_random_wrong_slection_sorting.count();   //thsi will sum all the times

            delete[] ar; //deleting array so that we can store ascending order values in it


            ar = new int[size];  //allocating memory to array 
            for (i = 0; i < size; ++i)    //assigning ascending order values to array 
            {
                ar[i] = i + 1;
            }
            auto t2_ascending_sorted_wrong_slection_sorting = wrong_slection_sorting(ar, size); //callign wrong slection sorting function for ascending order array
            t_ascending_wrong_slection_average += t2_ascending_sorted_wrong_slection_sorting.count();
            delete[] ar;  //delting array so that we can take new values in it


            ar = new int[size]; //assigning new memory to array 
            int assign = size;
            for (i = 0; i < size; ++i)    //assigning descending order values to array 
            {
                ar[i] = assign;
                --assign;
            }
            auto t3_descending_sorted_wrong_slection_sorting = wrong_slection_sorting(ar, size);

            t_descending_wrong_slection_average += t3_descending_sorted_wrong_slection_sorting.count();
            delete[] ar;



            //wrong slection sorting ends here

            ////////////////////////////////////////////////////
            ///////////////////////////////////////////////////
            ///////////////////////////////////////////////////

            //Right slection sorting starts here 



            ar = new int[size];

            for (i = 0; i < size; i++)  //assigning random values to array 
            {
                ar[i] = rand() % 300000 + 1;
            }

            auto time_for_random_right_slection = right_slection_sorting(ar, size); //calling function
            t_rand_right_slection_average += time_for_random_right_slection.count(); //for storing all the time

            delete[] ar; //deleting array

            ar = new int[size]; //allocating new memory

            //assigning values to ascending order array
            for (i = 0; i < size; i++)
            {
                ar[i] = i + 1;
            }
            auto time_for_ascending_order_right_slection = right_slection_sorting(ar, size);
            t_ascending_right_slection_average = time_for_ascending_order_right_slection.count();
            
            delete[] ar;


            ar = new int[size];

            //assigning values to descending order array 
            des = size;
            for (i = 0; i < size; i++)
            {
                ar[i] = des;
                --des;
            }
            auto time_for_descend_order_right_slection = right_slection_sorting(ar, size);
            t_descending_right_slection_average += time_for_descend_order_right_slection.count();
            delete[] ar;

            //Right slection sorting ends here 
     //////////////////////////////////////////////
     //////////////////////////////////////////////
     //////////////////////////////////////////////
            //Bubble sorting starts here 




            ar = new int[size];

            for (int i = 0; i < size; i++)  //assigning random values to array 
            {
                ar[i] = rand() % 300000 + 1;
            }
            auto time_for_random_array_bubble = bubble_sorting(ar, size); //calling function

            t_rand_bubble_average += time_for_random_array_bubble.count();
            delete[] ar;  //deleting memory 


            ar = new int[size];

            //assigning values to ascending array
            for (i = 0; i < size; i++)
            {
                ar[i] = i + 1;
            }

            auto time_for_ascending_array_bubble = bubble_sorting(ar, size);

            t_ascending_bubble_average += time_for_ascending_array_bubble.count();
            delete[] ar;


            ar = new int[size];

            //assigning values to descending array
            des = size;
            for (i = 0; i < size; i++)
            {
                ar[i] = des;
                --des;
            }
            auto time_for_descending_array_bubble = bubble_sorting(ar, size); //calling function

            t_descending_bubble_average += time_for_descending_array_bubble.count();
            delete[] ar;


            //end of bubble sorting 

            //////////////////////////////////////////
            /////////////////////////////////////////
            ////////////////////////////////////////

            //starting insertion sorting 




            ar = new int[size];

            //assigning random values to array 

            for (i = 0; i < size; i++)
            {
                ar[i] = rand() % 300000 + 1;
            }

            auto time_for_random_array_insertion = insertion_sorting(ar, size);
            t_rand_insertion_average += time_for_random_array_insertion.count();
            delete[] ar;

            ar = new int[size];
            //assigning values to ascending array
            for (i = 0; i < size; i++)
            {
                ar[i] = i + 1;
            }

            auto time_for_ascending_array_insertion = insertion_sorting(ar, size);
            t_ascending_insertion_average += time_for_ascending_array_insertion.count();
            delete[] ar;

            ar = new int[size];

            //assigning values to descending array
            des = size;
            for (i = 0; i < size; i++)
            {
                ar[i] = des;
                --des;
            }
            auto time_for_descending_array_insertion = insertion_sorting(ar, size);
            t_descending_insertion_average += time_for_descending_array_insertion.count();
            delete[] ar;


            ///////////////////////////////////
            // ///////////////////////////////
            // File handling part starts here 
            //writting time taken to sort the arrays in file whose name will be give in comman line argument 
            std::fstream file;

            file.open(arey[2], std::ios::app);
            if (file.is_open())
            {
                file << "Algorithm_Type,Size,Array_Type,Time_Taken,Time_scale \n";
                //writing results of wrong slection sorting 
                file << "Wrong slection sorting," << size << ",Random Array," << t1_random_wrong_slection_sorting.count() << "milli second \n";
                file << "Wrong slection sorting," << size << ",Ascending order," << t2_ascending_sorted_wrong_slection_sorting.count() << "milli second \n";
                file << "Wrong slection sorting," << size << ",Descending order," << t3_descending_sorted_wrong_slection_sorting.count() << "milli second\n";

                //writing result of right slection sorting

                file << "Right slection soring," << size << ",Random Array," << time_for_random_right_slection.count() << "milli second\n";
                file << "Right slection soring," << size << ",Ascending Array," << time_for_ascending_order_right_slection.count() << "milli second\n";
                file << "Right slection soring," << size << ",Descending Array," << time_for_descend_order_right_slection.count() << "milli second\n";

                //writing result of bubble sorting
                file << "Bubble Sorting," << size << ",Random Array," << time_for_random_array_bubble.count() << "milli second\n";
                file << "Bubble Sorting," << size << ",Ascending Array," << time_for_ascending_array_bubble.count() << "milli second\n";
                file << "Bubble Sorting," << size << ",Descending Array," << time_for_descending_array_bubble.count() << "milli second\n";

                //writting result of insetion sorting

                file << "Insertion Sorting," << size << ",Random Array," << time_for_random_array_insertion.count() << "milli seconds \n";
                file << "Insertion Sorting," << size << ",Ascending Array," << time_for_ascending_array_insertion.count() << "milli seconds \n";
                file << "Insertion Sorting," << size << ",Descending Array," << time_for_descending_array_insertion.count() << "milli seconds \n";


                std::cout << k + 1 << "  Result enterd \n ";

                if (k == 10)
                {
                    file << "\n \n \nAlgorithm Type,Array Type,Average Time \n";
                    file << "Wrong slection sorting," << ",Random Array," <<t_rand_wrong_slection_average/10 << "milli second \n";
                    file << "Right slection soring," << ",Random Array," <<t_rand_right_slection_average/10 << "milli second\n";
                    file << "Bubble Sorting," << ",Random Array," <<t_rand_bubble_average/10 << "milli second\n";
                    file << "Insertion Sorting," << ",Random Array," << t_rand_insertion_average/10 << "milli seconds \n";
                    file << "Wrong slection sorting," << ",Ascending order," <<t_ascending_wrong_slection_average/10<< "milli second \n";
                    file << "Right slection soring,"<< ",Ascending Array," <<t_ascending_right_slection_average/10 << "milli second\n";
                    file << "Bubble Sorting," << ",Ascending Array," << t_ascending_bubble_average/10 << "milli second\n";
                    file << "Insertion Sorting," << ",Ascending Array," <<t_ascending_insertion_average/10 << "milli seconds \n";
                    file << "Wrong slection sorting," << ",Descending order," <<t_descending_wrong_slection_average/10<< "milli second\n";
                    file << "Right slection soring," << ",Descending Array," <<t_descending_right_slection_average/10 << "milli second\n";
                    file << "Bubble Sorting," << ",Descending Array," <<t_descending_bubble_average/10 << "milli second\n";
                    file << "Insertion Sorting," << ",Descending Array," <<t_descending_insertion_average/10 << "milli seconds \n";

                }
            }
            else
            {
                std::cout << "file not opened";
            }


        }
    
    }
    else
    {
        std::cout << "Usage =  size_of_array  Name_of_csv_file  ";
    }
    return 0;
}



