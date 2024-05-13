#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        queue<string> q;
        q.push("1");
        while(n--)
        {
            string f = q.front(); q.pop();
            cout<<f<<" ";
            q.push(f + "0");
            q.push(f + "1");
        }

        cout<<"\n";
    }
}