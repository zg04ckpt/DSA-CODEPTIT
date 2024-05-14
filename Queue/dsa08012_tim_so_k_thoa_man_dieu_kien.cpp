#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(string &a, string &b)
{
    if(a.size() == b.size())
        return a >= b;
    return a.size() > b.size();
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string l,r; cin>>l>>r;
        queue<string> q;
        q.push("0");
        q.push("1");
        q.push("2");
        q.push("3");
        q.push("4");
        q.push("5");
        int ans = 0;
        while(q.size())
        {
            string num = q.front(); q.pop();

            if(cmp(num, l) && cmp(r, num))
                ans++;
            
            if(num=="0" || !cmp(r, num))
                continue;
            
            bool check[6] = {};
            for(char &c : num) check[c-'0'] = 1;
            for(int i=0; i<=5; ++i)
            {
                if(!check[i])
                    q.push(num + to_string(i));
            }
        }

        cout<<ans<<'\n';
    }
}