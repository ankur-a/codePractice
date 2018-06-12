#include<bits/stdc++.h>
typedef long long ll;

bool adj[1001][1001];

using namespace std;
int main(){
	ll n,m,p,q,que;
	cin>>n>>m;
	memset(adj,false,sizeof(adj));
	for(int i=0;i<m;i++){
		cin>>p>>q;
		adj[p][q]=adj[q][p]=true;
	}
	cin>>que;
	while(que--){
		cin>>p>>q;
		if(adj[p][q]| adj[q][p])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}