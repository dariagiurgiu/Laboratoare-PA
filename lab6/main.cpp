#include <iostream>
using namespace std;

struct Obiect{
    int index;
    double w,p,r;
};

void sort(Obiect *v,int n)
{
    int i, j;
    Obiect aux;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(v[i].r<v[j].r)
            {
               aux=v[i];
               v[i]=v[j];
               v[j]=aux; 
            }
        }
    }
}

void rucsac(double w[],double p[], int n, int M, double x[])
{
    Obiect *ob=new Obiect[n];
    double c=0;
    int i;

    for(i=0;i<n;i++)
    {
        ob[i].index=i;
        ob[i].w=w[i];
        ob[i].p=p[i];
        ob[i].r=p[i]/w[i];
        x[i]=0;
    }

    sort(ob,n);

    for(i=0;i<n&&c<M;i++)
    {
        if(c+ob[i].w<=M)
        {
            c+=ob[i].w;
            x[ob[i].index]=1;
        }
        else
        {
            x[ob[i].index]=(M-c)/ob[i].w;
            c=M;
        }
    }
}


int main()
{

    double w[]={2,1,2.5}, p[]={2,4,5}, x[3];

    double M=3;
    int n=3;

    rucsac(w,p,n,M,x);
    double s=0;
    for(int i=0;i<n;i++)
        s+=x[i]*p[i];
    cout<<s<<endl;
    return 0;
}