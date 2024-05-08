#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, k, a[101], x[101], cnt;

void tryAt(int i, int pre)
{
    for(int j=pre+1; j<=n-k+i; ++j)
    {
        if(a[j] <= x[i-1]) continue;
        x[i] = a[j];
        if(i == k) cnt++;
        else tryAt(i+1, j);
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    tryAt(1, 0);

    cout<<cnt; 
}