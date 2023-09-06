#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class node{
	public :
	int val;
	node* left ;
	node* right ;
	
	node(int data)
	{
		val = data;
		left = NULL;
		right = NULL;
	}
};

void helper(node* rootnode,vector<int> &v)
{
	if(rootnode==NULL) return ;
	
	queue<node*> q;
	q.push(rootnode);
	
	while(!q.empty())
	{
		int nodesAtCurrentLevel = q.size();
		vector<int> temp;
		while(nodesAtCurrentLevel--)
		{
			
			node* currNode = q.front();
			q.pop();
			temp.push_back(currNode->val);
				
			if(currNode->left!=NULL)
			{
				q.push(currNode->left);
				
			}
			if(currNode->right != NULL)
			{
				q.push(currNode->right);
			}
		
		}
			v.push_back(temp[0]);
		
	}
}

int main()
{
	node* rootnode = new node(1);
	rootnode->left = new node(2);
	rootnode->left->right = new node(5);
	rootnode->right = new node(3);
	rootnode->right ->right = new node(4);
	vector<int> ans;
	helper(rootnode,ans);
	
	cout<<"The final output is : ";
	cout<<endl;
	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"  ";
	}
	
	cout<<endl;
	return 0;
}//Jai Jai Jai Bajarangbali...

