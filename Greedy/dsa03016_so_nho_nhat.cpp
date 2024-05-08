#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int s,d; cin>>s>>d;

        if(9*d < s)
        {
            cout<<"-1\n";
            continue;
        }

        int mi[d] = {};
        mi[0] = 1;
        int dis = s-1;

        int i=d-1;
        while(dis >= 9)
        {
            mi[i] = 9;
            dis -= 9;
            i--;
        }
        mi[i] += dis;

        for(int i : mi) cout<<i;
        cout<<"\n";
    }
}