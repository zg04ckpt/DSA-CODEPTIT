#include<bits/stdc++.h>
#define ll long long

using namespace std;

int a[1001], b[1001], n;

bool process()
{
    bool needLoop = 0;
    for(int i=1; i<n; ++i)
    {
        if(a[i-1]/b[i-1] != a[i]/b[i])
        {
            needLoop = 1;
            while(a[i-1]/b[i-1] != a[i]/b[i])
            {
                if(a[i-1]/b[i-1] > a[i]/b[i])
                {
                    b[i-1]++;
                }
                else b[i]++;
            }
        }
    }
    return needLoop;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) b[i] = 1;

    while(process());

    int ans = 0;
    for(int i=0; i<n; ++i) 
        ans += b[i];

    cout<<ans;
}