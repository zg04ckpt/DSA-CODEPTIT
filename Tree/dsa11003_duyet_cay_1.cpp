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

int n, pre[1001], curIdx;
map<int, int> indexOf;

node* build(int l, int r)
{
    if(l > r) return NULL;
    node *root = new node(pre[curIdx]);
    int m = indexOf[pre[curIdx]]; curIdx++;
    root->l = build(l, m-1);
    root->r = build(m+1, r);
    return root;
}

void postOrder(node *root)
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
            cin>>pre[i];
        
        curIdx = 0;//pre
        node *root = build(0, n-1);
        postOrder(root);
        cout<<"\n";

        indexOf.clear();
    }
}