#pragma once

struct nod
{
    int data;
    nod *succ;
};

struct pachet
{
    nod *prim;
    nod *ultim;
};

pachet init(pachet &p);
int ise(pachet p);
void put(pachet &p, int x);
void get(pachet &p);
int front(pachet p);

int maxim(int v[], int n);
