#include<bits/stdc++.h>
#define mod 100000
#define N 1000011
typedef long long ll;
using namespace std;
std::vector<ll> grp[N];
bool factor[N];
bool sv[1001];
 bool check(ll val,ll lock,ll n){
 	// cout<<lock<<"-";
 	memset(factor,false,sizeof(factor));
 	if(lock%2==0){
 		// cout<<2<<endl;
 		if(val%2!=0)
 			false;
 		while(lock%2==0)
 			lock=lock/2;
 	}
 	for(ll i=3;i <=lock ; i++){
 		if(lock%i==0){
 			// cout<<i<<endl;
	 		if(val%i!=0) return false;
	 		while(lock%i==0)
	 			lock=lock/i;
 		}
 	}
 	cout<<val;
 	return true;
 	
 }



ll ar[1001]={0};
int main(){
	ll key,lock,num,val=1;
	cin>>key>>lock;
	cin>>num;
	for(ll i=0;i<num;i++){
		cin>>ar[i];
		val*=ar[i];
	}
	if( check(val,(lock/key),num) == true){
				queue <ll> q;
				q.push(key);
				ll cnt=0;
				bool flg=true;
				while(flg){
					ll tmp= q.front();
					q.pop();
					for(ll i=0;i<num;i++){
						if((tmp*ar[i]) %mod == lock){
							flg=false;
							break;
						}
						else{
							q.push((tmp*ar[i])%mod);
						}

					}
					cnt++;
				}

				cout<<cnt<<endl;

		}
		else{
			cout<<-1<<endl;
		}
	return 0;
}