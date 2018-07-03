#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000111
ll ar1[N],ar2[N];

int main(){
	std::ios::sync_with_stdio(false);
	ll n,tmp;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>ar1[i];
	}
	set<ll> s;

	for(ll i=0;i<n;i++){
		cin>>tmp;
		s.insert(tmp);
	}
	ll ans=0;
	// auto t,t1;
	for(ll i=0;i<n;i++){
		auto t=s.upper_bound(ar1[i]);
		auto t1 = s.lower_bound(ar1[i]);
		ll tm=min(*(t),*(t1));
		ans+= abs(tm-ar1[i]);
		s.erase(tm);
	}
	cout<<ans<<endl;


	return 0;
}


