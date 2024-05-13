#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int k; cin>>k;
        string s; cin>>s;
        map<char,int> cnt;
        for(char c : s) 
            cnt[c]++;

        priority_queue<int, vector<int>> pq;
        for(auto p : cnt)
            pq.push(p.second);

        while(k--)
        {
            int f = pq.top(); pq.pop();
            if(f)
                pq.push(f-1);
        }

        ll ans = 0;
        while(pq.size())
        {
            ans += pow(pq.top(), 2);
            pq.pop();
        }

        cout<<ans<<'\n';
    }
}