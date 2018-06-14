#include <bits/stdc++.h>
typedef long long ll;
std::vector < pair(ll,ll) > v;
ll v;
void bfs_zero(ll s){
	int dist[v];
	memset(dist,INT_MAX,sizeof(dist));
	deque <ll> q;
	dist[s] = 0;
	q.push_back(src);
	while(!q.empty()){
		ll tmp = q.front();
		q.pop_front();

		for(ll i=0;i< v[tmp].size();i++){
			if(dist[v[tmp][i].first] > dist[v] + v[tmp][i].second)
				{
					dist[v[tmp][i].first] > dist[v] + v[tmp][i].second;

					if(v[tmp][i].second==0)
						q.push_front(v[tmp][i].first);
					else
						q.push_back(v[tmp][i].first);
				}
		}
	}

	for(ll i=0;i<v; i++)
		cout<<dist[v]<<" "<<endl;
}
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	ll edges,weight;
	cin>>v>>edges;
	for()
	return 0;

}