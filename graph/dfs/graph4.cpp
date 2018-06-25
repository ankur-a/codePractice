#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100011
std::vector<ll> v[N];
bool vis[N];
ll val[N];
ll n,x;
ll check(){
	memset(vis,false,sizeof(vis));
	queue<ll> s;
	s.push(1);
	vis[1]=true; 
	while(!s.empty()){
		ll tmp = s.front();
		s.pop();
		if(v[1].size()< 2)
			return 1;
		else if( v[tmp].size()< 3 )
			return tmp;
		for(ll i=0;i<v[tmp].size();i++){
			if(vis[v[tmp][i]]==false){
				vis[v[tmp][i]]=true;
				s.push(v[tmp][i]);
			}
		}

	}
	return 0;
}

ll cummulative(ll ind){
	if(vis[ind]==false){
		vis[ind]=true;
		for(ll i=0;i<v[ind].size();i++){
			val[ind]+= cummulative(v[ind][i]);
		}
		return val[ind];
	}
	else
		return 0;

}


int main(){
	std::ios::sync_with_stdio(false);
	ll t,p;
	cin>>n>>x;

	for(ll i=1;i<=n;i++)
		cin>>val[i];


	for(ll i=0;i<n-1;i++){
		cin>>t>>p;
		v[t].push_back(p);
		v[p].push_back(t);
	}
	ll ind=check();
	n++;
	cout<<ind<<endl;
	v[ind].push_back(n);
	v[n].push_back(ind);
	
	val[n]=x;
	
	memset(vis,false,sizeof(vis));
	ll tmp=cummulative(1),ans=0;
	for(ll i=0;i<=n;i++)
		ans+=val[i];
	cout<<ans<<endl;
	cout<<v[23300].size()<<"-"<<val[n-1]<<"-"<<val[n];
	return 0;
}