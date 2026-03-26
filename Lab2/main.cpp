#include <iostream>
#include "f.h"

using namespace std;

int main()
{
    int v[100], n, i, maxi, j, k = 10, c, nr, l = 1;
    pachet p[10];
    for(i = 0; i < 10; ++i)
    {
        p[i] = init(p[i]);
    }

    cout<<"Introduceti dimensiunea sirului: ";
    cin>>n;

    cout<<"Introduceti elementele sirului: ";
    for(i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    maxi = maxim(v, n);

    while(maxi % 10)
    {
        for(i = 0; i < n; ++i)
        {
            c = (v[i]/k)%10;
            put(p[c], v[i]);
        }
        nr = 0;
        for(j = 0; j < 10; ++j)
        {
            while(ise(p[j]) == 0)
            {
                v[nr++] = front(p[j]);
                get(p[j]);
            }
        }
        
        k = k * 10;
        maxi = maxi / 10;
    }

    for(j = 0; j < nr; ++j)
    {
        cout<<v[j]<<" ";
    }
        
    cout<<endl;

    return 0;
}

// 8
// 9 512 117 23 24 48 64 80