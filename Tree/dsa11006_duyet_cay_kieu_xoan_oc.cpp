#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    int d;
    node *l = NULL, *r = NULL;
    node(int d)
    {
        this->d = d;
    }
};

int par, chi;
char c;

void build(node *root)
{
    if(root == NULL) return;
    if(root->d == par)
    {
        if(c == 'L') root->l = new node(chi);
        else root->r = new node(chi);
    }
    else
    {
        build(root->l);
        build(root->r);
    }
}

void spiralOrder(node *root)
{
    map<int, vector<int>> ans;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    while(q.size())
    {
        node *n = q.front().first; 
        int lev = q.front().second;
        q.pop();

        ans[lev].push_back(n->d);

        if(n->l != NULL)
            q.push({n->l, lev+1});
        if(n->r != NULL)
            q.push({n->r, lev+1});
    }

    for(auto e : ans)
    {
        if(e.first%2)
        {
            for(int i : e.second)
                cout<<i<<" ";
        }
        else
        {
            for(int i=e.second.size()-1; i>=0; i--)
                cout<<e.second[i]<<" ";
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        node *root = NULL;
        while(n--)
        {
            cin>>par>>chi>>c;
            if(root == NULL)
                root = new node(par);
            build(root);
        }

        spiralOrder(root);
        cout<<"\n";
    }
}