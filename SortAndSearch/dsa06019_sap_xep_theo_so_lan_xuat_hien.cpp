#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<int,int> mp;

int cmp(int a, int b)
{
    if(mp[a] == mp[b])
        return a < b;
    return mp[a] > mp[b];
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> a;
        while(n--)
        {
            int e; cin>>e;
            if(!mp[e]) a.push_back(e);
            mp[e]++;
        }

        sort(a.begin(), a.end(), cmp);

        for(int i : a)  
            while(mp[i]--) 
                cout<<i<<" ";
        cout<<"\n";

        mp.clear();
    }
}