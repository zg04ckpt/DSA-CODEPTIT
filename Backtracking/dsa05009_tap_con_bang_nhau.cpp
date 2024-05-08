#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[101], n, sum;
bool ok;

void tryAt(int pre, int preSum)
{
    if(ok) return;
    
    for(int j=pre+1; j<=n; ++j)
    {
        if(preSum+a[j] > sum) continue;
        else if(preSum+a[j] == sum) 
        {
            ok = 1;
            return;
        }
        else tryAt(j, preSum+a[j]);
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        sum = 0;
        for(int i=1; i<=n; ++i) 
        {
            cin>>a[i];
            sum += a[i];
        }

        if(sum%2) cout<<"NO\n";
        else
        {
            sum /= 2;
            ok = 0;
            tryAt(1, 0);
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}