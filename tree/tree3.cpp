#include<bits/stdc++.h>
#define N 10011
typedef long long ll;
using namespace std;
ll maxheight=0;

struct node {
	int data;
	struct node  *left,*right;
};

struct node* nnode(int val){
	struct node* temp= (node*)malloc(sizeof(node));
	temp->data= val;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* ctbst(int val, struct node* root){
	if(root == NULL)
		return nnode(val);
	else{
		if(root->data >=val){
			root->left= ctbst(val,root->left);
		}
		else{
			root->right= ctbst(val,root->right);
		}

		return root;
	}

}

int maxhe(node* root){
	if(root==NULL)
		return 0;
	else{
		int ldepth= maxhe(root->left);
		int rdepth= maxhe(root->right);



		if(ldepth>rdepth)
			return ldepth+1;
		else
			return rdepth+1;		
	}
}

int main(){
	ll n,ar[N],cnt=0,val;
	cin>>n;
	cin>>val;
	struct node* root;
	root=nnode(val);
	for(ll i=0;i<n-1;i++){
		cin>>val;
		root= ctbst(val,root);
	}
	ll depth = maxhe(root);
	cout<<depth<<endl;
	return 0;
}
