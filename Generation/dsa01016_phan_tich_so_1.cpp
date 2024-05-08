#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, x[11];

void print(int m)
{
    cout<<"(";
    for(int i=1; i<m; ++i) cout<<x[i]<<" ";
    cout<<x[m]<<") ";
}

void tryAt(int i, int pre, int sum)
{
    for(int j=pre; j>=1; --j)
    {
        if(sum+j > n) continue;
        x[i] = j;
        if(sum+j == n) print(i);
        else tryAt(i+1, j, sum+j);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        tryAt(1, n, 0);
        cout<<"\n";
    }
}