#include<bits/stdc++.h>
#define ll long long

using namespace std;

string a[9];
int n, k, x[9];

int calc()
{
    int ma = -1e9, mi = 1e9;
    for(int i=0; i<n; ++i)
    {
        int num = 0;
        for(int j=0; j<k; ++j)
            num += (a[i][x[j]]-'0') * pow(10, k-j-1);
        ma = max(ma, num);
        mi = min(mi, num);
    }
    return ma-mi;
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<k; ++i) x[i] = i;

    int ans = 1e9;
    do ans = min(ans, calc());
    while(next_permutation(x, x+k));

    cout<<ans;
}