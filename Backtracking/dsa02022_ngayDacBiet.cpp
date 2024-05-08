#include<bits/stdc++.h>
#define ll long long

using namespace std;

string day[] = {"02", "20", "22"};
string yea[] = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};

string x[4];

void tryAt(int i)
{
    if(i == 1)
    {
        for(int j=0; j<3; ++j)
        {
            x[i] = day[j];
            tryAt(i+1);
        }
    }
    else if(i == 2)
    {
        x[i] = "02";
        tryAt(i+1);
    }
    else
    {
        for(int j=0; j<8; ++j)
        {
            x[i] = yea[j];
            cout<<x[1]<<"/"<<x[2]<<"/"<<x[3]<<"\n";
        }
    }
}

int main()
{
    tryAt(1);
}