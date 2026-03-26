#include <iostream>
#include <chrono>
#include "functii.h"
using namespace std;

// void interclasare(int a[], int p, int q, int m, int temp[])
// {
//     int i=p, j=m+1, k=0;
//     while(i<=m&& j<=q)
//     {
//         if(a[i]<a[j])
//         {
//             temp[k++]=a[i++];
//         }
//         else
//         {
//             temp[k++]=a[j++];
//         }
//     }
//     while(i<=m)
//         temp[k++]=a[i++];
//     while(j<=q)
//         temp[k++]=a[j++];
// }

// void merge_sort(int a[],int p, int q, int temp[])
// {
//     if(p<q)
//     {
//         int m=(p+q)/2;
//         merge_sort(a,p,m,temp);
//         merge_sort(a,m+1,q,temp);
//         interclasare(a,p,q,m,temp);
//         for(int i=p;i<=q;i++)
//             a[i]=temp[i-p];
//     }
// }

int main()
{
    int a[]={3,6,5,2,8,7,1,0}, p=0,q=7,tmp[8];
    // merge_sort(a,p,q,tmp);
    // for(int i=0;i<q;i++)
    //     cout<<a[i]<<" ";

    // int a[]={3,6,5,2,8,7,1,0}, p=0, q=7;
    // quick_sort(a,p,q);
    // for(int i=0;i<=q;i++)
    //     cout<<a[i]<<" ";
    // return 0;

       // Start timer
       auto start = std::chrono::high_resolution_clock::now();
       //--------------------------------------------------------------------------------------------------------------------------
       merge_sort(a,p,q,tmp);
       //--------------------------------------------------------------------------------------------------------------------------
       // Stop timer
       auto end = std::chrono::high_resolution_clock::now();
       auto duration = (end - start);
       auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration);
       // Microsecond (as int)
       auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
       // Milliseconds (as int)
       const float ms_fractional = static_cast<float>(us.count()) / 1000;         // Milliseconds (as float)
       std::cout << "Duration Merge sort= " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;

        int b[]={3,6,5,2,8,7,1,0};
    // Start timer
       auto start1 = std::chrono::high_resolution_clock::now();
       //--------------------------------------------------------------------------------------------------------------------------
       quick_sort(b,p,q);
       //--------------------------------------------------------------------------------------------------------------------------
       // Stop timer
       auto end1 = std::chrono::high_resolution_clock::now();
       auto duration1 = (end1 - start1);
       auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(duration1);
       // Microsecond (as int)
       auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(duration1);
       // Milliseconds (as int)
       const float ms_fractional1 = static_cast<float>(us1.count()) / 1000;         // Milliseconds (as float)
       std::cout << "Duration Quick sort= " << us1.count() << "µs (" << ms_fractional1 << "ms)" << std::endl;

}
