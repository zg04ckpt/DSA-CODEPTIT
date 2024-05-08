#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,s; cin>>n>>s;
    if(9*n<s || s<1) 
    {
        cout<<"-1 -1";
        return 0;
    }
    
    int mi[n], ma[n];
    for(int &i : ma) i = 9;
    for(int &i : mi) i = 0; mi[0] = 1;

    int dis = s-1;
    int i = n-1;
    while(dis >= 9)
    {
        mi[i] = 9;
        dis -= 9;
        i--;
    }
    mi[i] += dis;

    dis = 9*n - s;
    i = n-1;
    while(dis > 9)
    {
        ma[i] = 0;
        dis -= 9;
        i--;
    }
    ma[i] -= dis;

    for(int i : mi) cout<<i;
    cout<<" ";
    for(int i : ma) cout<<i;
}