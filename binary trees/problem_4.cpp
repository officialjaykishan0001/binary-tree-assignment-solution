//Q. return the no of the leaf node presented in binary tree.

#include<iostream>
#include<algorithm>

using namespace std;
class node{
    public : 
    int val;
    node* left ;
    node* right ;

    node(int data)
    {
        data  = val;
        left = NULL;
        right = NULL;
    }
};

 void problemHelper(node* rootnode,int &leaf_count)
 {
    if(rootnode==NULL)
    {
        return ;
    }

    if(rootnode->left == NULL && rootnode->right == NULL) leaf_count++;

    problemHelper(rootnode->left,leaf_count);
    problemHelper(rootnode->right,leaf_count);

    return ;
 }

int main()
{
    node* rootnode = new node(2);
    rootnode->left = new node(4);
    rootnode->left->left = new node(6);
    rootnode->left->right = new node(5);
    rootnode->right  = new node(10);
    rootnode->right->right = new node(11);
int ans = 0;
    problemHelper(rootnode,ans);
    cout<<"The toral no leaf node in this tree is : "<<ans<<endl;

    return 0;
}//Jai Jai Jai Bajarangbali...
