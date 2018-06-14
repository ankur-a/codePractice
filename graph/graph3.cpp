#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

std::vector<ll> adj[1001];

ll val[1001];
bool sortvec(pair<ll , ll> &a, pair<ll , ll> &b){
	if(a.first != b.first)
		return (a.first>b.first);
	else
		return (a.second>b.second);
	
}

int main(){
	ll n,m,k,a,b;
	cin>>n>>m>>k;
	memset(val,0,sizeof(val));

	for(ll i=0;i<n;i++)
		cin>>val[i];

	for(ll i=0;i<m;i++){
		 cin>>a>>b;
		 adj[a].push_back(b);
		 adj[b].push_back(a);
	}

	for(ll i=1;i<=n;i++){
		std::vector< pair<ll,ll> > v;
		if(adj[i].size()<k)
			cout<<1<<endl;
		else{

		for(ll j=0;j< adj[i].size(); j++){
			v.push_back(make_pair(val[adj[i][j]-1],adj[i][j]));
		}
		sort(v.begin(),v.end(),sortvec);
		cout<<v[k-1].second<<endl;
	}

	}

















	return 0;
}
