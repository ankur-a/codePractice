	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define N 100011
	ll ar[N],cum[N];


	int main(){
		std::ios::sync_with_stdio(false);
		ll t,n;
		cin>>t;
		while(t--){
			cin>>n;
			memset(cum,0,sizeof(N));
			for(ll i=0;i<n;i++)
				cin>>ar[i];
			cum[0]=ar[0];
		/*	for(ll i=1;i<n;i++)
				cum[i]=cum[i-1]+ar[i];*/
			if(n==1){
				cout<<"0 1"<<endl<<"Motu"<<endl;
			}
			else if(n==2)
				cout<<"1 1"<<endl<<"Tie"<<endl;

			else{  

			ll mm=0,pt=n-1,sum1=0,sum2=0,cnt1=0,cnt2=0;
			sum1=ar[mm];
			sum2=ar[pt];
			cnt1=cnt2=1;
			while(cnt1+cnt2<n){
					while(sum1 < sum2*2 && cnt1+cnt2<n){
						mm++;
						sum1+=ar[mm];
						cnt1++;
					}
					while(sum1 > sum2*2 && cnt1+cnt2<n){
						pt--;
						sum2+=ar[pt];
						cnt2++;
					}
			}
			if(cnt1>cnt2){
				cout<<cnt1<<" "<<cnt2<<endl<<"Motu"<<endl;
			}
			else if(cnt2>cnt1){
				cout<<cnt1<<" "<<cnt2<<endl<<"Patlu"<<endl;
			}
			else
				cout<<cnt1<<" "<<cnt2<<endl<<"Tie"<<endl;


		}




		}
		return 0;
	}


