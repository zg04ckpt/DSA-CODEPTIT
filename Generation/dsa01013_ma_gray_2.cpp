#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
dùng xor
-> bit đầu tiên giữ nguyên
-> từ bit thứ 2 đen xor với bit cuối của xâu nhị phân bước trước đó
-> kết quả xor chính là bit np của bước tương ứng

VD: 10110
b1: 1
b2: 1+(1 xor 0) = 11
b3: 11+(1 xor 1) = 110
b4: 110+(0 xor 1) = 1101
b5: 1101+(1 xor 0) = 11010
*/

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        for(int i=1; i<s.size(); ++i)
        {
            s[i] = ((s[i]-'0')^(s[i-1]-'0')) + '0';
        }
        cout<<s<<"\n";
    }
}