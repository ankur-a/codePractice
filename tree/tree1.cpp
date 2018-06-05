#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node
{
	ll data;
	struct node* left;
	struct node* right;
	
};
struct node* addnode(int val){
	struct node* tmp= (node*)malloc(sizeof(node));
	tmp->left=tmp->right= NULL;
	tmp->data = val;
	return tmp;
}



int main(){
	ll num,vroot;
	cin>>num>>vroot;
	struct node *root=NULL,*ptr;
	root=addnode(vroot);
	string s;
		



	return 0;
}