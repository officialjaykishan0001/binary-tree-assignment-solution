#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class node{
    public : 
    int val;
    node* left ;
    node* right ;

    node(int data)
    {
        val = data;
        left  = NULL;
        right = NULL;
    }
};

int longestPath(node* rootnode,int &leftPath,int &rightPath)
{
    if(rootnode==NULL) return 1;

    leftPath =     longestPath(rootnode->left,leftPath,rightPath);
    rightPath = longestPath(rootnode->right,leftPath,rightPath);

    return leftPath+rightPath;
}

int main()
{
    node* rootnode = new node(1);
    rootnode->left = new node(2);
    rootnode->left->left = new node(4);
    rootnode->left->right = new node(5);
    rootnode->right = new node(3);
    rootnode->right->left = new node(6);
    rootnode->right->right = new node(7);
    rootnode->right->right->right = new node(9);

int leftPath = 0 ,rightPath = 0;
int ans =     longestPath(rootnode,leftPath,rightPath);

    cout<<"The final answer is : "<<leftPath+rightPath+1<<endl;//adding plus 1 to it for the rootnode.


 return 0;
}//Jai Jai Jai Bajarangbali...