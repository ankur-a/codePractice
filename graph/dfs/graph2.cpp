#include<bits/stdc++.h> using namespace std; typedef long long ll; vector<
pair<ll,ll> > grp[10011]; ll n,m; void dfs(){     bool vis[10011];
memset(vis,false,sizeof(vis));     queue<ll> q;     vis[1]=false;
queue.push(1);

	while(!q.empty()){
		ll tmp=q.top();
		q.pop();

		for(ll i=0;i<grp[tmp].size();i++){
			if(vis[grp[tmp][i].first]==false){
				q
			}
		}
	}

}





int main(){
	cin>>n;
	ll x,y;
	for(ll i=0;i<n-1;i++){
		cin>>x>>y;
		grp[x].push_back(make_pair(y,0));
		grp[y].push_back(make_pair(x,0));
	}
	ll q,ar[10011];
	cin>>q;
	for(ll i=0;i<q;i++)
		cin>>ar[i];
	dfs();
	return 0;
}