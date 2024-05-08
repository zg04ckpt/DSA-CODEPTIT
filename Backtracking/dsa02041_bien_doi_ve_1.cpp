#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, ans;

void tryAt(int n, int cnt)
{
    if(n == 1)
    {
        ans = min(ans, cnt);
        return;
    }

    if(n%3==0 && cnt+1<ans) tryAt(n/3, cnt+1);
    if(n%2==0 && cnt+1<ans) tryAt(n/2, cnt+1);
    if(cnt+1 < ans) tryAt(n-1, cnt+1);
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
       cin>>n;
       ans = n;
       tryAt(n, 0);
       cout<<ans<<"\n";
    }
}