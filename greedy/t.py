n=int(input())
ar=list(map(int,input().split()))
mn=0
i=0
j=0
k=0
for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            if((ar[i]*ar[j]*ar[k])>mn and ar[i]<ar[j]<ar[k]):
                mn=ar[i]*ar[j]*ar[k]
                print(ar[i],ar[j],ar[k])
 
print(mn)