#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10011

int main(){
  ll s,x,n;
  cin>>s>>x>>n;
  ll cnt = 0 , cnt1 = 0 , mxcnt=0;
  map <long , long > vl;
  vector< pair<long , long > > v;
  ll tmp1, tmp2;
  while(n--){
    cin>>tmp1>>tmp2;
    vl.insert( pair<int , int>(tmp1 , tmp2) );
    v.push_back(make_pair(tmp1,tmp2));
    if(mxcnt<tmp1)
    mxcnt=tmp1;
  }
  sort(v.begin() , v.end());
  // cout<<v[1]'/'.first;
  ll sm = 0;
  while(sm<s){
    cout<<sm<<cnt<<cnt1<<endl;
    cnt++;
    if(mxcnt>=cnt && v[cnt1].first == cnt){
      sm+=v[cnt1].second;
      cnt1++;
    }
    else
    sm+=x;
  }

  cout<<cnt<<endl;

  return 0;
}
