#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node{
	ll val;
	struct node *left,*right;
};
bool h=false;
struct node* addnode(ll data){
	struct node* temp= (node*)malloc(sizeof(node));

	temp->left= temp->right=NULL;
	temp->val=data;

	return temp;

}

struct node* makebst(struct node* root, ll data){
	if(root==NULL)
		return addnode(data);
	else{
		if(data <= root->val)
			root->left=makebst(root->left,data);
		else
			root->right = makebst(root->right,data);

		return root;
	}
}

void printpreoder(struct node* root){
	if(root){
		cout<<root->val<<endl;
		printpreoder(root->left);
		printpreoder(root->right);
	}

}

void preorder(struct node* root,ll data){
	if(root){
	if(root->val==data)
		printpreoder(root);
	preorder(root->left,data);
	preorder(root->right,data);
	}
}





int main(){
	ll n,ar[10011];
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>ar[i];
	struct node* root=addnode(ar[0]);
	for(ll i=1;i<n;i++)
		root= makebst(root,ar[i]);
	ll q;
	cin>>q;
	preorder(root,q);

	return 0;
}