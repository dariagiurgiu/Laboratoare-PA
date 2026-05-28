#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 10;

struct Nod{
    int elem;
    Nod* succ;
};

struct Digraf{
    int n;
    Nod* lad[NMAX];
    int indegree[NMAX];
};

void sort_topologica(Digraf d, int rez[])
{
    int idx = 0, i, u;
    queue<int> c;
    for(i = 0; i < d.n; i++)
        if(d.indegree[i] == 0)
            c.push(i);

    for(i = 0;i<d.n;i++)
    {
        u = c.front();
        c.pop();
        rez[idx++] = u;
        Nod* l = d.lad[u];

        while(l!=nullptr)
        {
            d.indegree[l->elem]--;
            if(d.indegree[l->elem]==0)
                c.push(l->elem);
            l = l->succ;
        }
    }
}

bool sort_topologica_cicluri(Digraf d, int rez[])
{
    bool cicluri = false;
    int idx = 0, i, u;
    queue<int> c;
    for(i = 0; i < d.n; i++)
        if(d.indegree[i] == 0)
            c.push(i);

    while(c.size()!=0)
    {
        u = c.front();
        c.pop();
        rez[idx++] = u;
        Nod* l = d.lad[u];

        while(l!=nullptr)
        {
            d.indegree[l->elem]--;
            if(d.indegree[l->elem]==0)
                c.push(l->elem);
            l = l->succ;
        }
    }
    if(idx!=d.n)
        cicluri = true;
    return cicluri;
}

int main()
{
    Digraf d;
    d.n = 5;

    for(int i = 0;i<d.n;i++)
        d.indegree[i] = 0;
    
    d.lad[0] = new Nod;
    d.lad[0]->elem = 1;
    d.lad[0]->succ = new Nod;
    d.lad[0]->succ->elem = 3;
    d.lad[0]->succ->succ = nullptr;

    d.lad[1] = new Nod;
    d.lad[1]->elem = 2;
    d.lad[1]->succ = nullptr;

    d.lad[2] = new Nod;
    d.lad[2]->elem = 3;
    d.lad[2]->succ = new Nod;
    d.lad[2]->succ->elem = 4;
    d.lad[2]->succ->succ = new Nod;
    d.lad[2]->succ->succ->elem = 0;
    d.lad[2]->succ->succ->succ = nullptr;

    d.lad[3] = new Nod;
    d.lad[3]->elem = 4;
    d.lad[3]->succ = nullptr;

    d.lad[4] = nullptr;

    int i;
    for(i = 0;i<d.n;i++)
    {
        Nod *l = d.lad[i];
        while(l!=nullptr)
        {
            d.indegree[l->elem]++;
            l = l->succ;
        }
    }

    int rez[5];
    bool cicluri = sort_topologica_cicluri(d,rez);
    cout<<cicluri<<endl;
    for(i=0;i<d.n;i++)
        cout<<rez[i]<<" ";
    cout<<endl;
    return 0;
}