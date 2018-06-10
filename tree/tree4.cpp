#include<bits/stdc++.h>
typedef long long ll;

struct node {
	ll data;
	struct node *left,*right;
};

struct node* nnode(ll val){
	struct node* temp = (node*)malloc(sizeof(node));
	temp->data= val;
	temp->left = temp->right= NULL;

	return temp;
}

struct node* makebst(node * root,int val){
	if(root==NULL)
		return nnode(val);
	else{
		if(val<=root->data)
			root->left = makebst(root->left,val);
		else
			root->right = makebst(root->right,val);

		return root;
	}
}

struct node* comparent(node* root,ll p,ll q){
	
	while((p < root->data && q < root->data) || (p > root->data && q > root->data)){
		if(p < root->data && q < root->data)
			root= root-> left;
		else if(p > root->data && q > root->data)
			root= root-> right;
	}

	return root;
}

ll findmx(node* root ,ll q){
	ll mx = INT_MIN;

	while( root->data != q){
		if(root->data > q){
			mx = std::max(mx, root->data);
			root=root->left;
		}
		else{
			mx = std::max(mx, root->data);
			root = root->right;
		}
	}

	return std::max(mx,q);
}






using namespace std;
int main(){
	ll n,val;
	struct node* root;
	cin>>n;
	cin>>val;
	root = nnode(val);
	for(ll i=0;i<n-1;i++){
		cin>>val;
		root= makebst(root,val);
	}

	ll p,q;
	cin>>p>>q;
	node* LCA = comparent(root,p,q);
	ll maxval= max(findmx(LCA,p),findmx(LCA,q));
	cout<<maxval<<endl;



	return 0;
}
