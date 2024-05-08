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

        int cnt[256] = {};
        for(char &c : s) cnt[c]++;

        priority_queue<int, vector<int>> pq;
        for(int i : cnt)
        {
            if(i) pq.push(i);
        }

        while(k--)
        {
            int t = pq.top(); pq.pop();
            t--;
            if(t) pq.push(t);
        }

        ll ans = 0;
        while(pq.size())
        {
            ans += pow(pq.top(), 2);
            pq.pop();
        }

        cout<<ans<<"\n";
    }
}