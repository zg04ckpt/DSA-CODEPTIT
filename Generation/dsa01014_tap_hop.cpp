#include<bits/stdc++.h>
#define ll long long

using namespace std;

int x[11], n, k, s, ans;

void tryAt(int i, int sum, int pre)
{
    for(int j=pre+1; j<=n; ++j)
    {
        x[i] = j;
        if(i == k & sum+j == s) ans++;
        if(i < k) tryAt(i+1, sum+j, j);
    }
}

int main()
{
    while(1)
    {
        cin>>n>>k>>s;
        if(!n && !k && !s) break;

        ans = 0;
        tryAt(1, 0, 0);

        cout<<ans<<"\n";
    }
}