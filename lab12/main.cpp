#include <vector>
#include <queue>
#include <iostream>

using namespace std;


struct Nod{
    vector<int> board;
    int nivel;
};

int gstar(Nod a){
    int cnt = 0;
    for(int i = 0;i < a.board.size();i++){
        if(a.board[i]!=i+1&&a.board[i]!=0)
            cnt++;
    }
    return cnt;
}

int cstar(Nod a){
    return a.nivel + gstar(a);
}

struct Comparator{
    bool operator()(Nod a, Nod b)
    {
        return (cstar(a)>=cstar(b));
    }
};


void expand(priority_queue<Nod,vector<Nod>, Comparator> &A, Nod v){
    vector<int> c;
    int poz = 0;
    for(int i = 0;i<9;i++)
        if(v.board[i] == 0)
            poz = i;
    vector<int> stg = v.board, sus = v.board, jos = v.board, dr = v.board;
    if(poz%3!=0)
    {
        stg[poz] = stg[poz-1];
        stg[poz-1] = 0;
        Nod s;
        s.board = stg;
        s.nivel = v.nivel+1;
        for(int i = 0;i<stg.size();i++)
            cout<<stg[i]<<" ";
        cout<<endl;
        A.push(s);
    }
    if(poz %3!=2)
    {
        dr[poz] = dr[poz+1];
        dr[poz+1] = 0;
        Nod drN;
        drN.board = dr;
        drN.nivel = v.nivel+1;
        for(int i = 0;i<dr.size();i++)
            cout<<dr[i]<<" ";
        cout<<endl;
        A.push(drN);
    }
    if(poz>2)
    {
        sus[poz] = sus[poz-3];
        sus[poz-3] = 0;
        Nod ss;
        ss.board = sus;
        ss.nivel = v.nivel+1;
        for(int i=0;i<sus.size();i++)
            cout<<sus[i]<<" ";
        cout<<endl;
        A.push(ss);
    }
    if(poz<6)
    {
        jos[poz] = jos[poz+3];
        jos[poz+3] = 0;
        Nod j;
        j.board = jos;
        j.nivel = v.nivel+1;
        for(int i=0;i<jos.size();i++)
            cout<<jos[i]<<" ";
        cout<<endl;
        A.push(j);
    }
}

void perspico(Nod start)
{
    priority_queue<Nod,vector<Nod>,Comparator> A;
    A.push(start);
    while(!A.empty())
    {
        Nod v = A.top();
        A.pop();
        for(int i =0;i <v.board.size();i++)
            cout<<v.board[i]<<" ";
        cout<<endl;
        if(gstar(v) == 0)
        {
            cout<<v.nivel<<endl;
            for(int i = 0;i<v.board.size();i++)
                cout<<v.board[i]<<" ";
            cout<<endl;
            return;
        }
        expand(A,v);
    }
}

int main()
{
    vector<int> x = {1,2,3,4,0,6,7,5,8};
    Nod start;
    start.board = x;
    start.nivel = 0;
    perspico(start);
    return 0;
}
