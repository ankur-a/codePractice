#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
std::vector<ll> grp[10011];
ll n,m;

ll dfs(ll val){
	stack<ll> g;
	bool vis[10011];
	memset(vis,false,sizeof(vis));
	vis[val]=true;
	g.push(val);
	while(!g.empty()){
		ll tmp = g.top();
		g.pop();
		for(ll i=0;i<grp[tmp].size();i++){
			if(vis[grp[tmp][i]]==false){
				g.push(grp[tmp][i]);
				vis[grp[tmp][i]]=true;
			}
		}
	}
	ll ans=0;

	for(ll i=1;i<=n;i++){
		if(vis[i]==false)
			ans++;
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	ll x,y;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		cin>>x>>y;
		grp[x].push_back(y);
		grp[y].push_back(x);
	}
	ll val;
	cin>>val;
	ll ans=dfs(val);
	cout<<ans<<endl;
	return 0;
}