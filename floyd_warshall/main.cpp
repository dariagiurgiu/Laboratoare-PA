#include <iostream>
#include <vector>
using namespace std;

struct Nod{
    int elem;
    Nod *succ;
};

struct Digraf{
    int nr_noduri;
    Nod* lad[10];
};

void floyd_warshall(Digraf G, int A[][4], int P[][4])
{
    for(int k = 0 ;k<G.nr_noduri;k++)
    {
        for(int i = 0;i<G.nr_noduri;i++)
            for(int j = 0;j<G.nr_noduri;j++)
                if(A[i][k] + A[k][j]<A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = P[k][j];
                }
    }
}

int main()
{
    Digraf G;
    G.nr_noduri = 4;
    int A[4][4], P[4][4];
    for(int i = 0;i<4;i++)
        for(int j = 0;j<4;j++)
        {
            if(i == j)
            {
                A[i][j] = 0;
            }
            else{
                A[i][j] = 1000;
                P[i][j] = -1;
            }
        }

    A[0][1] = 3;
    P[0][1] = 0;

    A[0][3] = 7;
    P[0][3] = 0;

    A[1][0] = 8;
    P[1][0] = 1;

    A[1][2] = 2;
    P[1][2] = 1;

    A[2][0] = 5;
    P[2][0] = 2;

    A[2][3] = 1;
    P[2][3] = 2;

    A[3][0] = 2;
    P[3][0] = 3;

    floyd_warshall(G,A,P);

    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            cout<<"Drumul minim de la "<<i<<" - "<<j<<" are lungimea = "<<A[i][j]<<": ";
            vector<int> v;
            int k = j;
            v.push_back(k);
            while(k!=i)
            {
                k = P[i][k];
                v.push_back(k);
            }
            for(int l = v.size()-1;l>0;l--)
                cout<<v[l]<<" - ";
            cout<<v[0]<<endl;
        }
    }
}