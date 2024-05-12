#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
d[i] = tg nhỏ nhất tại i kí tự giống nhau

111 11
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,ins,del,cop;
        cin>>n>>ins>>del>>cop;

        int d[n+1];
        d[1] = ins;
        for(int i=2; i<=n; ++i)
        {
            d[i] = d[i-1] + ins;
            if(i%2)
                d[i] = min(d[i], d[i/2+1]+cop+del);
            else
                d[i] = min(d[i], d[i/2]+cop);
        }

        cout<<d[n]<<"\n";
    }
}