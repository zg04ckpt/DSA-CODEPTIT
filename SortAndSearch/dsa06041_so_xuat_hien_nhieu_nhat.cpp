#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        map<int, int> mp;
        for(int i=0; i<n; ++i)
        {
            int e; cin>>e;
            mp[e]++;
        }

        bool ok = 0;
        for(pair<int,int> p : mp)
        {
            if(p.second > n/2)
            {
                cout<<p.first;
                ok = 1;
                break;
            }
        }

        if(!ok) cout<<"NO";
        cout<<"\n";
    }
}