#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, X[15];
vector<string> ans;

void add(int cnt)
{
	string s = "(";
	for(int i=1; i<cnt; ++i) s += to_string(X[i])+" ";
	s += to_string(X[cnt])+")";
	ans.push_back(s);
}

void tryAt(int i, int pre, int sum)
{
	for(int j=pre; j>=1; --j)
	{
		if(sum+j > n) continue;
		X[i] = j;
		if(sum+j == n) add(i);
		else tryAt(i+1, j, sum+j);
	}
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        tryAt(1, n, 0);
        cout<<ans.size()<<"\n";
        for(string &s:ans) cout<<s<<" ";
        cout<<"\n";
        ans.clear();
    }
}
