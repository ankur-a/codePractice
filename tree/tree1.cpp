#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll max_value = INT_MIN;
struct node
{
	ll data,lh,rh;
	struct node* left;
	struct node* right;
	
};
struct node* addnode(int val){
	struct node* tmp= (node*)malloc(sizeof(node));
	tmp->left=tmp->right= NULL;
	tmp->data = val;
	return tmp;
}

int finddia(struct node* ptr){
	
	if(ptr){
		ptr->lh = finddia(ptr->left);
		ptr->rh = finddia(ptr->right);
		if(ptr->rh+ptr->lh+1>max_value)
			max_value=ptr->rh+ptr->lh+1;

		return (ptr->rh > ptr->lh ? ptr->rh:ptr->lh)+1;
	}
	else 
		return 0;
}



int main(){
	ll num,vroot;
	cin>>num>>vroot;
	struct node *root=NULL,*ptr;
	root=addnode(vroot);
	string str;
	num--;
	while(num--){
		ll i=0,value;
		ptr=root;
		cin>>str;
		while(ptr&&str[i]){
			if(str[i]=='L'){
				if(ptr->left==NULL)
					ptr->left=addnode(0);
				ptr=ptr->left;
			}
			else{
				if(ptr->right==NULL)
					ptr->right=addnode(0);
				ptr=ptr->right;
			}
			i++;
			
		}
		cin>>value;
		ptr->data= value;
	}

	ll ans=		finddia(root);

	cout<<max_value;



	return 0;
}