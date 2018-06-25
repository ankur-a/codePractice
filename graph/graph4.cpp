#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< ll > grp[10011];
ll n,m;
ll lvl[10011];
void bfs(){
	bool vis[10011];
	memset(vis,false,sizeof(vis));
	memset(lvl,0,sizeof(lvl));
	queue <ll> q;
	lvl[1]=0;
	vis[1]=true;
	q.push(1);
	while(!q.empty()){
		ll tmp= q.front();
		q.pop();
		for(ll i=0;i<grp[tmp].size();i++){
			if(vis[grp[tmp][i]]==false){
				vis[grp[tmp][i]]=true;
				q.push(grp[tmp][i]);
				lvl[grp[tmp][i]]=lvl[tmp]+1;
			}
		}
	}
}





int main(){
	cin>>n;
	ll x,y;
	for(ll i=0;i<n-1;i++){
		cin>>x>>y;
		grp[x].push_back(y);
		grp[y].push_back(x);
	}
	cin>>m;
	ll min,idx;
	min=idx=INT_MAX;
	bfs();
	for(ll i=0;i<m;i++){
		cin>>x;
		if(lvl[x]<min && x<idx){
			min=lvl[x];
			idx=x;
		}
	}
	cout<<idx<<endl;



	return 0;
}