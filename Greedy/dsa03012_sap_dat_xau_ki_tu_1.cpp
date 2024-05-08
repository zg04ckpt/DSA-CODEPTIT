#include<bits/stdc++.h>
#define ll long long

using namespace std;

// n = 5, a là kí tự xh nhiều nhất là 3 lần
// a _ a _ a
// k = số lần xh cuae kí tự xh max
// k không thể lớn n-k 2 đơn vị
// k-n+k < 1 ~ 2k-n <= 1

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        map<char, int> mp;
        for(char &c : s) mp[c]++;

        int k = 0;
        for(auto p : mp) k = max(p.second, k);

        int n = s.size();
        if(2*k-n <= 1) cout<<"1\n";
        else cout<<"-1\n";
    }
}