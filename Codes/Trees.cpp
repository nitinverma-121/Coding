#include<bits/stdc++.h>
using namespace std;

class treedetail{
public: 
	int size;
	int maxrange;
	int minrange;

 treedetail(int sz, int minrange, int maxrange) {
 	this->size= sz;
 	this->minrange= minrange;
 	this->maxrange= maxrange;
 }	
};



class tree{

public: 
	tree* left;
	tree* right;
	int val;

	tree(int d) {
		this->val= d;
		this->left= NULL;
		this->right= NULL;
	}

	tree* builtTree(tree* root) {

	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new tree(data);
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

	tree* insertBST(tree* root, int d) {

		if(!root) return new tree(d);

		if(root->val> d) {
			root->left= insertBST(root->left, d);
		}
		else {
			root->right= insertBST(root->right, d);
		}
		return root;
	}
	//DFS (INORDER)

	void inorder(tree* root) {
		if(!root) return;

		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}

	void bfs(tree* root) {
		if(!root) return;

		queue<tree*> q;
		q.push(root);

		while(!q.empty()) {
			int sz= q.size();
			for(int i=0; i< sz; i++) {
				  tree* t= q.front();
				  q.pop();
				  cout<<t->val<<" ";
				  if(t->left) q.push(t->left);
				  if(t->right) q.push(t->right);
			}
			cout<<endl;
		}
	}

	treedetail largestBST(tree* root) {
		if(!root) {
			return treedetail({0, INT_MAX, INT_MIN});
		}

		treedetail leftans= largestBST(root->left);
		treedetail rightans= largestBST(root->right);

		//IST BST
		if(root->val> leftans.maxrange and root->val< rightans.minrange) { 
			return treedetail({root->val + leftans.size + rightans.size, min(root->val, leftans.minrange), max(root->val, rightans.maxrange)});
		}
		//IF NOT BST
		//STOP SEARCH
		return treedetail({max(leftans.size,rightans.size), INT_MIN, INT_MAX});
	}


	int largestBSTinBT(tree* root) {
		if(!root) return 0;
		return largestBST(root).size;
	}

	//root== ans=> leftans + rightans + root->val
	//(from any node to any node)
	int maxpathsum(tree* root, int &ans) {
		if(!root) return 0;

		int lans= maxpathsum(root->left, ans);
		int rans= maxpathsum(root->right, ans);
		if(lans< 0) lans= 0;
		if(rans< 0) rans= 0;

		ans= max(ans, lans + rans+ root->val);

		return root->val +  max(lans, rans);
	}

	//from one leaf to another
	pair<int, int> max_path_leaf_leaf(tree* root, int &ans) {
		if(!root) return {0, 0};

		if(!root->left and !root->right) return {root->val, root->val};

		pair<int, int> lans= max_path_leaf_leaf(root->left, ans);
		pair<int, int> rans= max_path_leaf_leaf(root->right, ans);

		ans= max(ans, (root->val + max(lans.first, lans.second) + max(rans.first, rans.second)) );

		return {root->val + max(lans.first, lans.second), root->val + max(rans.first, rans.second)};
	}

};




int main() {

	tree* root= NULL;

	root= root->builtTree(root);
	//root->inorder(root);
	cout<<endl;
	//cout<<root->largestBSTinBT(root);
	int ans= 0;
	root->max_path_leaf_leaf(root, ans);
	cout<<ans;
	return 0;
}