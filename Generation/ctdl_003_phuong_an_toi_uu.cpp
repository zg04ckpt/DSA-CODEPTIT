#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, b, x[101], c[101], w[101], f, fopt[101];

void save(int currentCost)
{
    f = currentCost;
    for(int i=1; i<=n; ++i)
        fopt[i] = x[i];
}

void tryAt(int i, int cost, int weight)
{
    for(int j=0; j<=1; ++j)
    {
        if(weight + j*w[i] > b) continue;
        x[i] = j;
        if(i==n && cost+j*c[i] > f) save(cost + j*c[i]);
        if(i < n) tryAt(i+1, cost + j*c[i], weight + j*w[i]);
    }
}

int main()
{
    cin>>n>>b;
    for(int i=1; i<=n; ++i) cin>>c[i];
    for(int i=1; i<=n; ++i) cin>>w[i];

    f = -1e9;
    tryAt(1, 0, 0);

    cout<<f<<"\n";
    for(int i=1; i<=n; ++i) cout<<fopt[i]<<" ";
}