#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isP(int n)
{
    for(int i=2; i<=sqrt(n); ++i)
        if(n%i == 0) return 0;
    return n > 1;
}

map<string,bool> p;
void init()
{
    for(int i=1000; i<=9999; ++i)
    {
        if(isP(i))
            p[to_string(i)] = 1;
    }
}

int main()
{
    init();
    int t; cin>>t;
    while(t--)
    {
        string s,t; cin>>s>>t;
        queue<string> q;
        unordered_map<string,int> step;
        q.push(s);
        while(q.front() != t)
        {
            string num = q.front();
            q.pop();

            for(int i=0; i<=3; ++i)
            {
                string newN = num;
                for(int j=0; j<=9; ++j)
                {
                    if(i==0 && j==0) continue;
                    newN[i] = j+'0';
                    if(newN==s || step[newN] || !p[newN])
                        continue;
                    q.push(newN);
                    step[newN] = step[num]+1;
                }
            }
        }

        cout<<step[t]<<"\n";
    }
}