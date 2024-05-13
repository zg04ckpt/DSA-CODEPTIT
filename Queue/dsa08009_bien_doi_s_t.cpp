#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int s,t; cin>>s>>t;
        queue<pair<int,int>> q;
        map<int,bool> check;
        q.push({s, 0});
        while(q.front().first != t)
        {
            int cur = q.front().first;
            int step = q.front().second;
            check[cur] = 1;
            q.pop();

            if(cur<t && !check[cur*2])
                q.push({cur*2, step+1});
            
            if(!check[cur-1])
                q.push({cur-1, step+1});
        }

        cout<<q.front().second<<"\n";
    }
}