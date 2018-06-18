#include<bits/stdc++.h>
#define N 10011
typedef long long ll;
using namespace std;
std::vector <ll> v[N];
ll nod;
ll level[N]={0};

void dfs(){
	bool vis[nod];
	memset(vis,false,sizeof(vis));
	
	queue <ll> q;
	q.push(1);
	level[1]=1;
	vis[1]= true;
	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		for(ll i=0;i< v[temp].size();i++){
			if(vis[v[temp][i]]==false)
			{	
				level[v[temp][i]]=level[temp]+1;
				vis[v[temp][i]]=true;
				q.push(v[temp][i]);

			}

		}

	}
}




int main(){
cin>>nod;
ll p,q;

for(ll i=0;i<nod-1;i++){
	cin>>p>>q;
	v[p].push_back(q);
	v[q].push_back(p);
}
dfs();
ll lvl,cnt=0;
cin>>lvl;
for(ll i=0;i<nod;i++){
	if(lvl==level[i])
		cnt++;
}

cout<<cnt<<endl;



}