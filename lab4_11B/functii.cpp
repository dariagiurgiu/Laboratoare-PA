#include "functii.h"

void compara_si_schimba(int &a, int &b, int s)
{
    int aux;
    if(s==0)
    {
        if(a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }
    }
    else{
    if(a<b)
    {
        aux=a;
        a=b;
        b=aux;
    }
}
}

void sortare_secv_bitona(int a[],int i, int d, int s)
{
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        int j;
        for(j=i;j<i+d/2;j++)
        {
            compara_si_schimba(a[j],a[j+d/2],s);
        }
        sortare_secv_bitona(a,i,d/2,s);
        sortare_secv_bitona(a,d/2+i,d/2,s);
    }
}

void batcher_sort(int a[],int i, int d, int s)
{
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        batcher_sort(a,i,d/2,0);
        batcher_sort(a,i+d/2,d/2,1);
        sortare_secv_bitona(a,i,d,s);
    }
}