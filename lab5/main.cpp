
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Nod{
    int val;
    Nod* stg, *dr;
    Nod(int data)
    {
        val=data;
        stg=nullptr;
        dr=nullptr;
    }
};

void calculLEP(Nod* rad, int depth, int &suma)
{
    if(rad->stg!=nullptr)
    {
        calculLEP(rad->stg,depth+1,suma);
        calculLEP(rad->dr,depth+1,suma);
    }
    if(rad->stg==nullptr&&rad->dr==nullptr)
        suma+=depth*rad->val;
}

struct Comparator{
    bool operator()(Nod *a, Nod* b) const{
        return (a->val>b->val);
    }
};

void afisare(Nod* rad)
{
    if(rad->stg!=nullptr)
        afisare(rad->stg);
    if(rad->dr!=nullptr)
        afisare(rad->dr);
    cout<<rad->val<<" ";
}

int main()
{
    priority_queue<Nod*,vector<Nod*>,Comparator> B;
    int i, n=5, v;
    for(i=0;i<5;i++)
    {
        cin>>v;
        B.push(new Nod(v));
    }
    while(B.size()>1)
    {
        Nod *t1=B.top();
        B.pop();
        Nod*t2=B.top();
        B.pop();
        Nod* t=new Nod(t1->val+t2->val);
        t->stg=t1;
        t->dr=t2;
        B.push(t);
    }
    Nod *rad=B.top();
    int s=0, d=0;
    afisare(rad);
    cout << endl;
    calculLEP(rad,d,s);
    cout<<s;
}