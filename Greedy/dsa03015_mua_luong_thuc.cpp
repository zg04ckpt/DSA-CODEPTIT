#include<bits/stdc++.h>
#define ll long long

using namespace std;

// S, N, M
// tìm M nhỏ nhất sao cho M*N >= S
// M = (S + N-1)/N

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,s,m; cin>>n>>s>>m;
        if(n*(s-s/7) < m*s) cout<<"-1\n";
        else cout<<(m*s + n-1)/n<<"\n";
    }
}