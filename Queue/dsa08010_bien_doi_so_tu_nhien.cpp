#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        queue<int> q;
        q.push(n);
        unordered_map<int,int> step;
        step[n] = 0;
        while(q.front() != 1)
        {
            int f = q.front(); q.pop();

            int sqr = sqrt(f);
            for(int i=2; i<=sqr; ++i)
            {
                if(f%i) continue;
                int ma = f/i;
                if(step[ma]) continue;
                q.push(ma);
                step[ma] = step[f]+1;
            }

            if(!step[f-1])
            {
                q.push(f-1);
                step[f-1] = step[f]+1;
            }
        }

        cout<<step[q.front()]<<"\n";
    }
}