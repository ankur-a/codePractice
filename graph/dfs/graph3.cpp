#include<bits/stdc++.h>
#define N 100011
using namespace std;
typedef long long ll;
ll n,q;
std::vector<ll> v[N];
std::vector < ll > ans[N];
char stvl[N];
bool vis[N];

string dfs(ll ind){
	string val;
	val+=stvl[ind];
	if(vis[ind]==false){
		vis[ind]=true;
		for(ll i=0;i<v[ind].size();i++){
			val.append(dfs(v[ind][i]));
		}
		for(ll i=0;i<val.size();i++){
			ans[ind][(int)(val[i]-97)]++;
		}
	return val;
	}
	else
		return "";

}
int main(){
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
		cin>>stvl[i];
	ll x,y;
	for(ll i=0;i<n-1;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	for(ll j=0;j<26;j++)
		ans[0].push_back(0);
	for(ll i=1;i<=n;i++)
		ans[i]=ans[0];
	string st=dfs(1);
	while(q--){
		ll fans=0,tans[26];
		memset(tans,0,sizeof(tans));
		cin>>x>>st;
		for(ll i=0;i<st.size();i++){
			tans[int(st[i]-'a')]++;
		}
		for(ll i=0;i<26;i++){
			if(ans[x][i]-tans[i]<0)
				fans+= abs(ans[x][i]-tans[i]);
		}
		cout<<fans<<endl;
	}
	return 0;
}