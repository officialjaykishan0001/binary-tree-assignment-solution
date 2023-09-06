#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class node{
    public : 
    int val;
    node* left;
    node* right ;

    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void helper(node* rootnode,bool &ans,int &targetSum,int sum)
{
    if(rootnode==NULL) return ;
     sum += rootnode->val;

     if(sum == targetSum)
     {
        ans = true;
        return ;
     }

     helper(rootnode->left,ans,targetSum,sum);

    if(sum==targetSum)
    {
        ans = true;
        return ;
    }

    helper(rootnode->right, ans,targetSum,sum);

    if(sum==targetSum)
    {
        ans  = true;
        return ;
    }

    helper(rootnode->left,ans,targetSum,0);
    if(sum==targetSum)
    {
        ans = true;
        return ;
    }

    helper(rootnode->right, ans,targetSum,0);
    
    if(sum==targetSum)
    {
        ans = true;
        return ;
    }

}

int main()
{
    node* rootnode = new node(1);
    rootnode->left = new node(2);
    rootnode->left->left = new node(4);
    rootnode->left->right = new node(5);
    rootnode->right = new node(3);
    rootnode->right ->left = new node(9);
    rootnode->right->right = new node(7);

    int targetSum ;
    cout<<"Enter the value of the target sum : ";
    cin>>targetSum;


    bool ans = false;

    helper(rootnode,ans,targetSum,0);

    cout<<"The output is : "<<ans<<"\n";
    
    return 0;
}