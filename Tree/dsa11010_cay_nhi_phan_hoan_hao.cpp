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

map<int,int> cnt;
int depth;

void traversal(node* root, int lev)
{
    if(root == NULL) return;
    cnt[lev]++;
    depth = max(depth, lev);
    traversal(root->l, lev+1);
    traversal(root->r, lev+1);
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

        depth = 0;
        traversal(root, 0);
        bool ok = 1;
        for(int i=0; i<=depth; ++i)
        {
            if(cnt[i] != pow(2, i))
            {
                ok = 0;
                break;
            }
        }

        cout<<(ok? "Yes\n":"No\n");
        cnt.clear();
    }
}