#include <iostream>
#include "f.h"

using namespace std;

pachet init(pachet &p)
{
    p.prim = 0;
    p.ultim = 0; 
    return p;
}

int ise(pachet p)
{
    if(p.ultim == 0 && p.prim == 0) return 1;
    return 0;
}

void put(pachet &p, int x)
{
    nod *b = new nod;
    b->data = x;
    b->succ = nullptr;

    if(ise(p) == 1)
    {
        p.prim = b;
        p.ultim = b;
    }
    else
    {
        p.ultim->succ = b;
        p.ultim = b;
    }
}

void get(pachet &p)
{
    if(ise(p))
    {
        cout<<"Coada goala"<<endl;
        return;
    }
    nod *b = p.prim;
    if(p.prim == p.ultim)   
    {
        delete b;
        p.prim = p.ultim = 0;
    }
    else
    {
        p.prim = p.prim->succ;
        delete b;
    }
}

int front(pachet p)
{
    if(ise(p))  
    {
        cout<<"Coada goala"<<endl;
        return 0;
    }
    return p.prim->data;
}

int maxim(int v[], int n)
{
    int i, maxi = v[0];
    for(i = 1; i < n; ++i)
    {
        if(v[i] > maxi) maxi = v[i];
    }
    return maxi;
}