#include <iostream>
#include <cmath>

using namespace std;

int d[10][10];

int rucsac_continuu(int n, int M, int w[],int p[], int dp[10][10])
{
    if(n==0)
        return 0;
    if(M<0)
        return -1000;
    if(dp[n][M]!=-1)
        return dp[n][M];
    int rez = max(rucsac_continuu(n-1,M,w,p,dp),rucsac_continuu(n-1,M-w[n],w,p,dp)+p[n-1]);
    dp[n][M] = rez;
    return rez;
}


int main()
{
    for(int i = 0;i<10;i++)
        for(int j = 0;j<10;j++)
            d[i][j] = -1;
    int n = 3, M = 10, w[] = {3,5,6}, p[]={10,30,20}, x[5];
    cout<< rucsac_continuu(n,M,w,p,d)<<endl;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<M;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
}