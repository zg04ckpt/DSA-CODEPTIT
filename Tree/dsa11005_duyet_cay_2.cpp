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

int lev[1001], n;
map<int,int> indexOf;

node* build(int i, int l, int r)
{
    if(i>=n || l>r) return NULL;
    node *root = new node(lev[i]);
    int m = indexOf[lev[i]];
    root->l = build(2*i+1, l, m-1);
    root->r = build(2*i+2, m+1, r);
    return root;
}

void postOrder(node* root)
{
    if(root == NULL) return;
    postOrder(root->l);
    postOrder(root->r);
    cout<<root->d<<" ";
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            int e; cin>>e;
            indexOf[e] = i;
        }
        for(int i=0; i<n; ++i)
            cin>>lev[i];
        
        node *root = build(0, 0, n-1);
        postOrder(root);
        cout<<"\n";

        indexOf.clear();
    }
}