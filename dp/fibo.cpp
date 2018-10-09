#include<bits/stdc++.h>
#define N 100011
typedef long long ll;
using namespace std;
int main(){
  vector <ll> fib;
  fib.push_back(1);
  fib.push_back(1);
  for(int i = 2 ; i < 150 ; i++){
    fib.push_back(fib[i-1]+fib[i-2]);
  }

  for(int i=0 ; i<150 ; i++){
    cout<<fib[i]<<" ";
  }
  cout<<endl;
  return 0;
}
