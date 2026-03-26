#include <iostream>
#include <chrono>
#include "functii.h"

using namespace std;

void interclasare(int a[], int p, int q, int m, int temp[])
{
    int i=p, j=m+1, k=0;
    while(i<=m&& j<=q)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=q)
        temp[k++]=a[j++];
}

void merge_sort(int a[],int p, int q, int temp[])
{
    if(p<q)
    {
        int m=(p+q)/2;
        merge_sort(a,p,m,temp);
        merge_sort(a,m+1,q,temp);
        interclasare(a,p,q,m,temp);
        for(int i=p;i<=q;i++)
            a[i]=temp[i-p];
    }
}

void partitionare(int a[], int p, int q, int& k)
{
    int i=p+1, j=q,aux, x=a[p];
    while(i<=j)
    {
        if(a[i]<=x)
            i++;
        if(a[j]>=x)
            j--;
        if(i<j)
        {
            if(a[i]>x&&a[j]<x)
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
                i++;
                j--;
            }
        }
    }
    a[p]=a[i-1];
    a[i-1]=x;
    k=i-1;
}

void quick_sort(int a[],int p, int q)
{
    if(p<q)
    {
        int k=p;
        partitionare(a,p,q,k);
        quick_sort(a,p,k-1);
        quick_sort(a,k+1,q);
    }
}

