#pragma once
//hey making functions is easiest way of solving difficult problems 

auto wrong_slection_sorting(int* ar, int size)  //wrong slection sorting
{
    int temp, i, j;

    auto start = std::chrono::high_resolution_clock::now();   //for calcualting time from start of sorting
    for (i = 0; i < size - 1; i++)
    {
        temp = ar[i];
        for (j = i + 1; j < size - 2; j++)
        {
            if (temp > ar[j])
            {
                int sp = ar[j];
                ar[j] = temp;
                temp = sp;
            }
        }
    }
    auto  end = std::chrono::high_resolution_clock::now();  //calculating time where sorting has been done
    auto t3 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //calculating time in milli second

    return t3;   //return calculated time

}


auto bubble_sorting(int* ar, int size)
{

    int temp, i, j;
    auto  start = std::chrono::high_resolution_clock::now();  //starting time calculation
    for (i = 0; i < size - 1; i++)
    {
        bool found = false;
        for (j = 0; j < size - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
                found = true;
            }
        }
        if (!found)
        {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();  //time when program has done sorting
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //calculating time in milli seconds
    return time; //return time
}

auto right_slection_sorting(int* ar, int size)
{
    int i, j, temp;


    auto start = std::chrono::high_resolution_clock::now(); //noting time when program enter into sorting 
    for (i = 0; i < size - 1; i++)
    {
        temp = i;
        for (j = i + 1; j < size - 2; j++)
        {
            if (ar[temp] < ar[j])
            {
                temp = j;
            }
        }
        if (i != temp)
        {
            std::swap(ar[i], ar[temp]);
        }
    }
    auto  end = std::chrono::high_resolution_clock::now(); //time when program has done sorting
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //calculating time in milli second
    return t;  //return time
}


auto insertion_sorting(int* ar, int size)
{

    int i, j, temp;
    auto start = std::chrono::high_resolution_clock::now();//noting time when program enter into sorting 

    for (i = 1; i < size; i++)
    {
        j = i;
        temp = ar[i];
        while (j > 0 && temp < ar[j - 1])
        {
            ar[j] = ar[j - 1];
            --j;
        }
        if (ar[i] != temp)
        {
            ar[j] = temp;
        }
       
    
    }

    auto end = std::chrono::high_resolution_clock::now(); //time when program has done sorting
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);//calculating time in milli second
    return t;  //return time
}
