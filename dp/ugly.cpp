#include<bits/stdc++.h>
#define N 100011
typedef long long ll;
using namespace std;

int main(){
  vector <int> ans ;
  ans.push_back(1);
  int i1=0,i2=0,i3=0;
  int nm1,nm2,nm3;
  nm1 = ans[i1]*2;
  nm2 = ans[i2]*3;
  nm3 = ans[i3]*5;
  int nxm;
  for(int i=0 ; i<150 ; i++){
    nxm = min(nm1,min(nm2,nm3));
    ans.push_back(nxm);

      if(nxm == nm1){
        i1++;
        nm1 = ans[i1]*2;
      }
      if(nxm == nm2){
        i2++;
        nm2 = ans[i2]*3;
      }
      if(nxm == nm3){
        i3++;
        nm3 = ans[i3]*5;
      }
  }

  for(int i=0 ; i <150 ; i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;

  return 0;
}
