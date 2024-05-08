#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[31], n, ans;
bool ok;

void tryAt(int pre, int cnt, int s)
{
    for(int j=pre+1; j<=n; ++j)
    {
        if(a[j] > s) continue;
        if(a[j] == s)
        {
            ans = min(ans, cnt+1);
            ok = 1;
        }
        else if(cnt+1 < ans) 
            tryAt(j, cnt+1, s-a[j]);
    }
}

int main()
{
    int s; cin>>n>>s;
    for(int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1, a+n+1, greater<int>());

    ans = 1e9;
    tryAt(0, 0, s);

    if(!ok) cout<<"-1";
    else cout<<ans;
}