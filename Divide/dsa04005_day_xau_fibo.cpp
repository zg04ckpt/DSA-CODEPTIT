#include<bits/stdc++.h>
#define ll long long

using namespace std;

//A
//B
//AB
//BAB

ll len[93];

char find(ll n, ll k)
{
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k > len[n-2]) 
        return find(n-1, k-len[n-2]);
    return find(n-2, k);
}

int main()
{
    len[1] = len[2] = 1;
    for(int i=3; i<93; ++i)
        len[i] = len[i-2]+len[i-1];

    int t; cin>>t;
    while(t--)
    {
        ll n, k; cin>>n>>k;
        cout<<find(n, k)<<"\n";
    }
}