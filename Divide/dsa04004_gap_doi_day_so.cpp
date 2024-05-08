#include<bits/stdc++.h>
#define ll long long

using namespace std;

//k trong dãy n
//k trả về n
// k>mid -> n--; lấy dx
// k<mid -> n--; ko lấy đx
// mid = 2^(n-1)

ll find(ll n, ll k)
{
    ll m = pow(2, n-1);
    if(k == m) return n;
    if(k > m) return find(n-1, m*2-k);
    return find(n-1, k);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n, k; cin>>n>>k;
        cout<<find(n, k)<<"\n";
    }
}