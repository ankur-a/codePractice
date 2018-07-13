n= int(input())
ar= list(map(int,input().split()))
dic={}
lst = []
for i in range(len(ar)):
	tp = ar[i]
	sum1=0
	while(tp):
		sum1+= tp%10
		tp = tp//10
	val = ar[i] ^ sum1
	lst.append(val)
st=set(lst)
if(len(st)==n):
	lst.sort()
	print(lst[-1] , 0)
else:
	max=0
	minv=99999999
	for i in lst:
		if(i in dic):
			dic[i]+=1
			if(dic[i]>max and i<minv):
				max=dic[i]
				minv = i

		else:
			dic[i]=1

	print(minv,max)
