#include<bits/stdc++.h>
using namespace std;





int main(){
  string text,pattern;
  cin>>text>>pattern;

  int ar[pattern.size()] = {0};
  int i,j=0;
  for(i=1 ; i <pattern.size();){
    if(pattern[i]==pattern[j]){
      ar[i]= j+1;
      j++;
      i++;
    }
    else{
      if(j!=0){
        j = ar[j-1];
      }
      else{

        ar[i]=0;
        i++;
      }
    }
  }
  for( i =0 ;i <pattern.size();i++){
    cout<<ar[i]<<" ";
  }

  int index = 0;

  for(i = 0 ; i < text.size() || index < pattern.size(); i++ ){
    cout<< i <<" "<< index <<"=="<<text[i]<<" "<<pattern[index]<<endl;
    if(text[i]==pattern[index]){
      index++;
      if(index == pattern.size()){
        cout<<"yeeeeeee"<<endl;
        break;
      }
    }
    else{
      if(index!=0)
      index = ar[index-1];
    }
  }
  
    cout<<"noooooooo"<<endl;




  return 0;
}
