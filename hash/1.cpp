#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
map< char , int > a ;
vector <string> inp;


int main(){
	std::ios::sync_with_stdio(false);
	for(int i=0;i< s.size(); i++){
		a[s[i]]=i;
	}
	ll t,sum;
	string s1;
	cin>>t;
	for(int i=0;i<t;i++){
		char s[100];
		scanf(" %[^\n]s",s);
		s1 = s;
		int loc=0,nms=1;
		sum=0;
		for(int j=0;j< s1.length() ; j++){
			if((char)s1[j]!= ' ' ){
				sum+= loc + a[s1[j]];
				loc++;
			}
			else{
				loc=0;
				nms++;
			}
		}
		cout<< nms*sum<<endl;
	}
	return 0;
}
