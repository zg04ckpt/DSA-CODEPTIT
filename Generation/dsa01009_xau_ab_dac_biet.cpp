#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
vector<int> a(16);
vector<vector<int>> ans;

bool check()
{
    int cntA = 0, cnt = 0;
    for(int i=1; i<=n; ++i)
    {
        if(!a[i]) cntA++;
        else cntA = 0;

        if(cntA > k) return 0;
        cnt += (cntA == k);
    }
    return cnt == 1;
}

void tryAt(int i)
{
    for(int j=0; j<=1; ++j)
    {
        a[i] = j;
        if(i == n) 
        {
            if(check()) ans.push_back(a);
        }
        else tryAt(i+1);
    }
}

int main()
{
    cin>>n>>k;

    tryAt(1);

    cout<<ans.size()<<"\n";
    for(vector<int> v : ans)
    {
        for(int i=1; i<=n; ++i) 
            cout<<char('A'+v[i]);
        cout<<'\n';
    }
}