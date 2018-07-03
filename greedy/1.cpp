#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10011


int main(){
	ll t,n,x,ar[N];
	cin>>t;
	while(t--){
		ll min=INT_MIN;
		cin>>n>>x;
		ll sum=0;
		for(ll i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n);
		ll cnt=0,i;
		for( i=0;i<n;i++){
			if(sum<x){
				if(sum+ar[i]>x){
				    cout<<i<<endl;
				    break;
				}
				else{
					sum+=ar[i];

				}
			}
			else{
				    cout<<i<<endl;
				    break;
				}
		}

	}
	return 0;
}