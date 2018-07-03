#include<bits/stdc++.h>
using namespace std;

int binary_search(vector <int> v,int x,int low,int high)
{
long mid = (low + high)/2;
if(mid == 0 && x < v[mid])
return 0;

if(x == v[mid] || x > v[mid] && x < v[mid+1] || mid == v.size()-1)
return mid+1;

if(v[mid] > x)
return binary_search(v,x,low,mid-1);
return binary_search(v,x,mid+1,high);

}

int functor(int n,int x,vector <int> v)
{
sort(v.begin(),v.end());
for(int i=1;i<n;i++)
v[i] = v[i] + v[i-1];
return binary_search(v,x,0,n-1);
}

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int n,x;
cin>>n>>x;
vector <int> v;
for(int i=0;i<n;i++)
{
int k;
cin>>k;
v.push_back(k);

}
cout<<functor(n,x,v)<<endl;
}
return 0;
}