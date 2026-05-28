#include <iostream>
#include <chrono>
using namespace std;

void afisare_vector(int x[], int n)
{
    for(int i = 0; i < n; i++)
        cout << x[i]<< " ";
    cout << endl;
}

int suma_vector(int v[], int n)
{
    int i, s = 0;
    for(i = 0; i < n; i++)
        s+= v[i];
    return s;
}

int nrPasi = 0,sol = 0;

void bkt(int s, int r, int k, int w[], int x[], int m, int n)
{
    nrPasi++;
    if(k>=n)
        return;
    x[k] = 1;
    if(s + w[k] == m)
        sol++;
        //afisare_vector(x,n);
    else{
        if(s+w[k]+w[k+1]<=m)
            bkt(s + w[k], r - w[k], k + 1, w, x, m, n);
        x[k] = 0;
        if(s + (r-w[k])>=m && s+w[k+1]<=m)
            bkt(s,r-w[k],k+1,w,x,m,n);
    }
}

void bkt2(int s, int r, int k, int w[], int x[], int m, int n)
{
    nrPasi++;
    if(k>=n)
        return;
    x[k] = 1;
    if(s + w[k] == m)
        sol++;//afisare_vector(x,n);
    else{
        bkt2(s + w[k], r - w[k], k + 1, w, x, m, n);
        x[k] = 0;
        bkt2(s,r-w[k],k+1,w,x,m,n);
    }
}

int main()
{
    int s = 0,k=0,x[25]={0}, w[4] = {4,7,11,14},m = 25,n = 4,r;
    int q[25]= {0};

    m = 50;
    for(int i = 0; i < 25;i++)
        q[i] = i +1;
    r = suma_vector(q,25);
    //r = suma_vector(w,n);
    // Start timer    
    auto start = std::chrono::high_resolution_clock::now();    
    //--------------------------------------------------------------------------------------------------------------------------    
    bkt(s,r,k,q,x,m,25);
    //--------------------------------------------------------------------------------------------------------------------------    
    // Stop timer    
    auto end = std::chrono::high_resolution_clock::now();    
    auto duration = (end - start);    
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration); 
    // Microsecond (as int)    
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration); 
    // Milliseconds (as int)    
    const float ms_fractional = static_cast<float>(us.count()) / 1000;         
    // Milliseconds (as float)    
    std::cout << "Duration = " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;

    cout<<nrPasi<<endl<<"Sol: "<<sol<<endl;;

    nrPasi = 0;
    sol=0;


    auto start1 = std::chrono::high_resolution_clock::now();    
    //--------------------------------------------------------------------------------------------------------------------------    
    bkt2(s,r,k,q,x,m,25);
    //--------------------------------------------------------------------------------------------------------------------------    
    // Stop timer    
    auto end1 = std::chrono::high_resolution_clock::now();    
    auto duration1 = (end1 - start1);    
    auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(duration1); 
    // Microsecond (as int)    
    auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(duration1); 
    // Milliseconds (as int)    
    const float ms_fractional1 = static_cast<float>(us1.count()) / 1000;         
    // Milliseconds (as float)    
    std::cout << "Duration = " << us1.count() << "µs (" << ms_fractional1 << "ms)" << std::endl;
    cout<<nrPasi<<endl<<"Sol: "<<sol<<endl;
    return 0;
}