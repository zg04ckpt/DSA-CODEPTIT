#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> prime;

bool isPrime(int n)
{
    for(int i=2; i<=sqrt(n); ++i)
        if(n%i == 0) return 0;
    return n>1;
}

void init()
{
    for(int i=2; i<=200; ++i)
    {
        if(isPrime(i)) prime.push_back(i);
    }
}

int n, p, s, x[11];
vector<string> ans;

void add()
{
    string s = "";
    for(int i=1; i<=n; ++i) 
        s += to_string(x[i])+" ";
    ans.push_back(s);
}

void tryAt(int i, int pre, int sum)
{
    for(int j=pre+1; j<prime.size(); ++j)
    {
        if(prime[j] <= p) continue;
        if(sum+prime[j] > s) continue;

        x[i] = prime[j];
        if(i==n && sum+prime[j]==s) add(); 
        if(i < n) tryAt(i+1, j, sum+prime[j]);
    }
}

int main()
{
    init();
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>p>>s;
        tryAt(1, 0, 0);

        sort(ans.begin(), ans.end());

        cout<<ans.size()<<"\n";
        for(string &s : ans) cout<<s<<"\n";

        ans.clear();
    }
}