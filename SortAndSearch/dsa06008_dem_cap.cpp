#include<bits/stdc++.h>
#define ll long long

using namespace std;

int x[100001], y[100001],n , m;
/*
x = 0 -> ko có y
x = 1 -> y = 0
x = 2 -> y = 0,1 + 5,6,7,...
x = 3 -> y = 0,1,2 + 4,5,6,...
x >= 4 -> y = 0,1 + x+1,x+2,...

lower_bound 
-> trả về con trỏ trỏ tới giá đầu tiên >= x

upper_bound
-> trả về con trỏ trỏ tới giá đầu tiên > x
*/

//1 2 2 3 3 4 -> [2,3]
//  1       5
int count(int start, int end) 
// đếm các giá trị từ [start, end]
{
    int *it1 = lower_bound(y, y+m, start);
    int *it2 = upper_bound(y, y+m, end);
    return it2-it1;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; ++i) cin>>x[i];
        for(int i=0; i<m; ++i) cin>>y[i];

        sort(y, y+m);

        int ans = 0;
        for(int i=0; i<n; ++i)
        {
            if(x[i] == 0) continue;
            else if(x[i] == 1)
                ans += count(0, 0);
            else if(x[i] == 2)
                ans += m-count(2, 4);
            else if(x[i] == 3)
                ans += m-count(3, 3);
            else
                ans += m-count(2, x[i]);
        }

        cout<<ans<<"\n";
    }
}