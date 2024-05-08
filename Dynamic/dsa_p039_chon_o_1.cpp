#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
-> 0: ko chọn , 1:chọn
1. 1 4 3 5 6: chọn 4 -> cột 2
-> 01000

2. trạng thái đã chọn
3 1 2 -> 100
1 1 2 -> 101
1 4 2 -> 111
OR: lưu -> 100 OR 001 = 101
AND: kiểm tra -> 100 AND 010 == 000 -> chọn

3. định mảng QHĐ dp[i][j]
-> giá trị lớn nhất chọn được cho đến hàng i
với trạng thái j: là trạng thái có ở hàng i-1;

4. a<<b phép dịch bit a(trong hệ bin) sang trái b lần
1<<0 : 001 ~ 2^0
1<<1 : 010 ~ 2^1
1<<2 : 100 ~ 2^2
-> 1<<b ~ 2^b
*/


int a[21][21], dp[21][1<<21], n;

int tryAt(int i, int pre)
{
    if(i > n) return 0;

    if(dp[i][pre] != -1) 
        return dp[i][pre];
    
    int rowStatus = 1<<(n-1);
    int ma = 0;
    for(int j=1; j<=n; ++j)
    {
        if((pre&rowStatus) == 0)
        {
            int current = pre|rowStatus;
            ma = max(
                ma,
                a[i][j] + tryAt(i+1, current)
            );
        }
        rowStatus = rowStatus>>1;
    }

    dp[i][pre] = ma;
    return ma;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>a[i][j];
        
        memset(dp, -1, sizeof dp);
        cout<<tryAt(1, 0)<<"\n";
    }
}