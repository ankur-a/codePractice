#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
	vector <ll> v[10];

	int level[10];
	bool vis[10];
	void bfs(ll s){
		queue <ll> q;
		q.push(s);
		level[s] = 0;

		vis[0]= true;

		while(!q.empty()){
			ll p=q.front();
			q.pop();
			for(ll i=0;i<v[p].size();i++){
				if(vis[v[p][i]]==false){
					level[v[p][i]]= level[p] + 1;
					q.push(v[p][i]);
					vis[v[p][i]] = true;
				}
			}
		}

 	}


int main(){
	


	return 0;
}
