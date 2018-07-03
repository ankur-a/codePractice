#include<bits/stdc++.h>
using namespace std;
#define N 200011
typedef long long ll;
ll ar[N],n;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>ar[i];

	ll hr[N],hl[N];
	hr[n-1]=-1;
	hl[0]=-1;
	set<ll> tmpset;
	tmpset.insert(ar[0]);
	for(ll i=1;i<n;i++){
		
		auto t=tmpset.upper_bound(ar[i]);
		t--;
		if(ar[i]==*t)
			t--;
		hl[i]=*t;
		// cout<<ar[i]<<" "<<*t<<endl;
		tmpset.insert(ar[i]);
	}

	memset(hr,-1,sizeof(hr));
	ll max_from_right=ar[n-1];
	for(ll i=n-2;i>=0;i--){
		ll temp = ar[i];
		if(max_from_right>ar[i])
		hr[i]= max_from_right;
		if(temp>max_from_right)
			max_from_right= temp;
	}
	ll max=INT_MIN;
	for(ll i=0;i<n;i++){
		// cout<<ar[i]*hl[i]*hr[i]<<" "<<max<<endl;
		if(ar[i]*hl[i]*hr[i]>max && (hl[i]!=-1 || hr[i]!=-1)){
			max=ar[i]*hl[i]*hr[i];
			cout<<ar[i]<<" "<<hl[i]<<" "<<hr[i]<<endl;
		}
	}

	// for(ll i=0;i<n;i++){
	// 	cout<<ar[i]<<"->"<<hl[i]<<"---"<<hr[i]<<endl;
	// }
	cout<<"--"<<max<<"--"<<endl;
	if(max>0)
	cout<<max<<endl;
	else cout<<0<<endl;


}