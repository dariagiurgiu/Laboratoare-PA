#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define NMAX 10

using namespace std;

struct Nod{
    int elem;
    Nod *succ;
};

struct Digraf{
    int nr_noduri;
    Nod *lad[NMAX];
};

void dijkstra(Digraf G, int d[][7],int D[], int P[], Nod start)
{
    for(int i = 0; i < G.nr_noduri;i++)
    {
        P[i] = start.elem;
        D[i] = d[start.elem][i];
    }

    //queue<int> S;
    vector<int> S;
    int i;
    S.push_back(start.elem);
    while(S.size()<G.nr_noduri)
    {
        i = 10;
        int dmin = 100;
        for(int j = 0;j<G.nr_noduri;j++)
        {
            // if(find(S.begin(),S.end(),j)==S.end()&&D[j]<dmin)
            // {
            //     dmin = D[j];
            //     i = j;
            // }
            int gasit = 0;
            for(int k = 0;k<S.size();k++)
            {
                if(S[k] == j)
                    gasit = 1;
            }
            if(gasit == 0&& D[j]<dmin)
            {
                dmin = D[j];
                i = j;
            }
        }
        S.push_back(i);
        Nod *l = G.lad[i];
        while(l!=nullptr)
        {
            int val = l->elem;
            if(find(S.begin(),S.end(),val)==S.end())
            {
                if(D[val]>D[i]+d[i][val])
                {
                    D[val] = D[i] + d[i][val];
                    P[val] = i;
                }
            }
            l = l->succ;
        }
    }
}

int main()
{
    Digraf G;
    G.nr_noduri = 7;
    G.lad[0] = new Nod;
    G.lad[0]->elem = 1;
    G.lad[0]->succ = new Nod;
    G.lad[0]->succ->elem = 2;
    G.lad[0]->succ->succ = nullptr;

    G.lad[1] = new Nod;
    G.lad[1]->elem = 3;
    G.lad[1]->succ = nullptr;

    G.lad[2] = new Nod;
    G.lad[2]->elem = 3;
    G.lad[2]->succ = nullptr;

    G.lad[3] = new Nod;
    G.lad[3]->elem = 4;
    G.lad[3]->succ = new Nod;
    G.lad[3]->succ->elem = 5;
    G.lad[3]->succ->succ = nullptr;

    G.lad[4] = new Nod;
    G.lad[4]->elem = 5;
    G.lad[4]->succ = new Nod;
    G.lad[4]->succ->elem = 6;
    G.lad[4]->succ->succ = nullptr;
    
    G.lad[5] = new Nod;
    G.lad[5]->elem = 6;
    G.lad[5]->succ = nullptr;

    G.lad[6] = nullptr;

    int D[7], P[7], d[7][7];

    for(int i =0;i<7;i++)
        for(int j =0;j<7;j++)
            d[i][j] = 0;
    
    d[0][1] = 2;
    d[0][2] = 6;
    d[1][3] = 5;
    d[2][3] = 8;
    d[3][4] = 10;
    d[3][5] = 5;
    d[4][5] = 6;
    d[4][6] = 2;
    d[5][6] = 1;

    for(int i =0;i<7;i++)
        for(int j = 0;j<7;j++)
            if(i!=j&&d[i][j]==0)
                d[i][j] = 1000;
    Nod start;
    start.elem = 0;
    dijkstra(G,d,D,P,start);

    for(int i = 1;i<7;i++)
    {
        cout<<"Drum minim 0 - "<<i<<": Lungime = "<< D[i]<<": ";
        int j = P[i];
        vector<int> l;
        l.push_back(i);
        l.push_back(j);
        while(j!=start.elem)
        {
            j = P[j];
            l.push_back(j);
        }
        for(int k = l.size()-1;k>0;k--)
            cout<< l[k]<<" - ";
        cout<<l[0];
        cout << endl;
    }
    return 0;
}