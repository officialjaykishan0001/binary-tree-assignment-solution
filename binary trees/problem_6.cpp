#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class node{
    public : 
    int val;
    node* left ;
    node* right;

    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;

    }
};

vector<int> helper(node* rootnode)
{
    vector<int> ans;
    queue<pair<node*, int>> q;
    q.push({rootnode,0});
    map<int,int> mp;

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        node* currNode = it.first;
        int data = it.second;

        mp[data] = currNode->val;

        if(currNode->left)
        {
            q.push({currNode->left,data-1});
        }
        if(currNode->right != NULL)
        {
            q.push({currNode->right,data+1});
        }
    }

    for(auto node : mp)
    {
        ans.push_back(node.second);
    }
    return ans;
}

int main()
{
    node* rootnode= new node(20);
    rootnode->left = new node(8);
    rootnode->left->left = new node(5);
    rootnode->left->right = new node(3);
    rootnode->left->right->left = new node(10);
    rootnode->left->right->right   = new node(14);
    rootnode->right = new node(22);
    rootnode->right->right = new node(25);

    vector<int> res = helper(rootnode);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}//Jai Jai Jai Bajarangbali....