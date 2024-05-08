#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[c]: khối lượng lớn nhất có thể chở với tối đa c kg
d[c] = d[c-a[i]] + a[i];
*/

int main()
{
    int c,n; cin>>c>>n;
    int w[n+1];
    for(int i=1; i<=n; ++i) 
        cin>>w[i];
    
    int d[c+1] = {};
    for(int i=1; i<=n; ++i)
    for(int j=c; j>=w[i]; j--)
        d[j] = max(d[j], d[j-w[i]]+w[i]);

    cout<<d[c];
}