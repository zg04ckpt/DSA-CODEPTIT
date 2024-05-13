#include<bits/stdc++.h>
#define ll long long

using namespace std;

int di[] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dj[] = {-2, -1, +1, +2, +2, +1, -1, -2};

struct A {
    string pos;
    int step;
};

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string st,en; cin>>st>>en;
        queue<A> q;
        q.push({st, 0});
        map<string,bool> check;
        while(q.front().pos != en)
        {
            string pos = q.front().pos;
            int step = q.front().step;
            check[pos] = 1;
            q.pop();

            for(int k=0; k<8; ++k)
            {
                string newP = pos;
                newP[0] += di[k];
                newP[1] += dj[k];
                if(newP[0]<'a' || newP[0]>'h') continue;
                if(newP[1]<'1' || newP[1]>'8') continue;
                if(check[newP]) continue;
                q.push({newP, step+1});
            }
        }

        cout<<q.front().step<<"\n";
    }
}