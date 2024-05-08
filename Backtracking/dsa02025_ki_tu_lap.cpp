#include<bits/stdc++.h>
#define ll long long

using namespace std;

int count(string s1, string s2)
{
    int i, j, cnt;
    i = j = cnt = 0;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i] == s2[j])
        {
            cnt++;
            i++;
            j++;
        }
        else if(s1[i] < s2[j]) i++;
        else j++;
    }
    return cnt;
}

int main()
{
    int n; cin>>n;
    string a[n];
    int x[n];
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        x[i] = i;
    }

    int dup[n][n];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            dup[i][j] = dup[j][i] = count(a[i], a[j]);
    
    int ans = 1e9;
    do
    {
        int cnt = 0;
        for(int i=1; i<n; ++i)
            cnt += dup[x[i-1]][x[i]];
        ans = min(ans, cnt);
    }
    while(next_permutation(x, x+n));

    cout<<ans;
}