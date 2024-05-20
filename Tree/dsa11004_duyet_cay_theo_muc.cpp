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

void levelOrder(node *root)
{
    queue<node*> q;
    q.push(root);
    while(q.size())
    {
        node *f = q.front(); q.pop();
        cout<<f->d<<" ";
        if(f->l != NULL) q.push(f->l);
        if(f->r != NULL) q.push(f->r);
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
        levelOrder(root);
        cout<<"\n";
    }
}