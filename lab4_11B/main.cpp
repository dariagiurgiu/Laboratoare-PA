#include <iostream>
#include <vector>
#include <chrono>
#include "functii.h"
#include <algorithm>
using namespace std;

int main()
{
    // int a[]={4,2,7,9,13,16,18,20,19,17,15,12,10,8,5,1},i=0,d=16,s=0;
    // batcher_sort(a,i,d,s);
    // for(i=0;i<d;i++)
    //     cout<<a[i]<<" ";

    int n=10000,i,v[10000];
    // for(i=0;i<n;i++)
    //     v[i]=rand()%100;
    for(i=0;i<n;i++)
        v[i]=i;
    
        auto start = std::chrono::high_resolution_clock::now();
        //--------------------------------------------------------------------------------------------------------------------------
        batcher_sort(v,0,n,0);
        //--------------------------------------------------------------------------------------------------------------------------
        // Stop timer
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = (end - start);    auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration);
        // Microsecond (as int)
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        // Milliseconds (as int)
        const float ms_fractional = static_cast<float>(us.count()) / 1000;
        // Milliseconds (as float)   
        std::cout << "Duration = " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;

        for(i=9999;i>=0;i--)
        {
            v[i-9999]=i;
        }

        auto start1 = std::chrono::high_resolution_clock::now();
        //--------------------------------------------------------------------------------------------------------------------------
        batcher_sort(v,0,n,0);
        //--------------------------------------------------------------------------------------------------------------------------
        // Stop timer
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = (end1 - start1);
        auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(duration1);
        // Microsecond (as int)
        auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(duration1);
        // Milliseconds (as int)
        const float ms_fractional1 = static_cast<float>(us1.count()) / 1000;
        // Milliseconds (as float)   
        std::cout << "Duration = " << us1.count() << "µs (" << ms_fractional1 << "ms)" << std::endl;


        for(i=0;i<n;i++)
            v[i]=rand()%100;
        auto start2 = std::chrono::high_resolution_clock::now();
        //--------------------------------------------------------------------------------------------------------------------------
        batcher_sort(v,0,n,0);
        //--------------------------------------------------------------------------------------------------------------------------
        // Stop timer
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = (end2 - start2);    auto us2= std::chrono::duration_cast<std::chrono::microseconds>(duration2);
        // Microsecond (as int)
        auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(duration2);
        // Milliseconds (as int)
        const float ms_fractional2 = static_cast<float>(us2.count()) / 1000;
        // Milliseconds (as float)   
        std::cout << "Duration = " << us2.count() << "µs (" << ms_fractional2 << "ms)" << std::endl;
    return 0;
}