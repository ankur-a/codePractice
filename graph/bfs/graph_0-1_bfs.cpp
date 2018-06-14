#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
std::vector < pair<ll,ll> > v[20];
ll nodes;
void bfs_zero(ll s){
	int dist[nodes];
	for(ll i=0 ; i<nodes; i++)
		dist[i]=INT_MAX;
	deque <ll> q;
	dist[s] = 0;
	q.push_back(s);
	while(!q.empty()){
		ll tmp = q.front();
		q.pop_front();

		for(ll i=0;i< v[tmp].size();i++){
			if(dist[v[tmp][i].first] > dist[tmp] + v[tmp][i].second)
				{
					dist[v[tmp][i].first] = (dist[tmp] + v[tmp][i].second) ;

					if(v[tmp][i].second==0)
						q.push_front(v[tmp][i].first);
					else
						q.push_back(v[tmp][i].first);
				}
		}
	}

	for(ll i=0;i<nodes; i++)
		cout<<dist[i]<<" "<<endl;
}

int main(){

	ll edges,weight,j,k,wt;
	cin>>edges>>nodes;
	for(ll i=0;i<edges;i++){
		cin>>j>>k>>wt;
		v[j].push_back(make_pair(k,wt));
		v[k].push_back(make_pair(j,wt));
	}

	bfs_zero(0);

	
	return 0;

}