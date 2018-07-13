#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bin(ll num, ll low , ll high){
	
	 if (num == 0 || num == 1)
    return num;
	int ans; 	
	while(low<=high){
		ll val = (high+low)/2;

		if(val*val == num)
			return val;
		if(val*val<num){
			ans = val;
			low = val+1;
		}
		else
			high=val-1;
	}
	return ans;

}
int main(){
	ll n;
	cin>>n;
	ll ans = bin(n,1,n);
	cout<<ans<<endl;
	return 0;
}