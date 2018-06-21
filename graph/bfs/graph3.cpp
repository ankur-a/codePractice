#include<bits/stdc++.h>
#define N 1011
using namespace std;

std::vector<int> gp[N];

void dfs(int a,int b){
	bool vis[N];
	memset(vis,false,sizeof(vis));
	int pr[N];
	memset(pr,-1,sizeof(vis));
	queue <int> q;
	q.push(a);
	vis[a]=true;

	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		for(int i=0;i<gp[tmp].size();i++){
			if(vis[gp[tmp][i]]==false){
				pr[gp[tmp][i]]=tmp;
				q.push(gp[tmp][i]);
				vis[gp[tmp][i]]=true;
			}
		}
	}

	vector <int> v;
	int cur=b;
	while(pr[b]!=-1&& cur!=a){
		v.push_back(cur);
		cur= pr[cur];
	}
	v.push_back(a);
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i]<<" ";

	cout<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,t,c,x,y;
	cin>>n>>m>>t>>c;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		gp[x].push_back(y);
		gp[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		sort(gp[i].begin(),gp[i].end());
	int a,b;
	cin>>a>>b;
	dfs(a,b);

	return 0;
}