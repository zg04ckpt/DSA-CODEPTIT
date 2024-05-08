#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[25], x[25], n, k;
bool ok;

void print(int m)
{
    ok = 1;
    cout<<"[";
    for(int i=1; i<m; ++i) cout<<x[i]<<" ";
    cout<<x[m]<<"]";
}

void tryAt(int i, int pre, int sum)
{
    for(int j=pre; j<=n; ++j)
    {
        if(sum+a[j] > k) continue;
        x[i] = a[j];
        if(sum+a[j] == k) print(i);
        else tryAt(i+1, j, sum+a[j]);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<=n; ++i) cin>>a[i];

        ok = 0;
        tryAt(1, 1, 0);

        if(!ok) cout<<-1;
        cout<<"\n";
    }
}