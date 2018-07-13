t= int(input())
sr = "littlejhool"
dic={}
dic = set(sr)

for i in range(t):
	ans={}
	n,m = map(int,input().split())
	str = input()
	s1 = str.split(" ")
	for j in range(len(s1)):
		tmps= set(s1[j].lower())
		cnt=0
		for k in tmps:
			if(k in dic):
				cnt+=1
		if(cnt in ans):
			tmps1= ans[cnt]
			tmps1= tmps1 + " " + s1[j]
			ans[cnt]= tmps1
		else:
			ans[cnt]= s1[j]
	while(m>0):
		val = list(ans.keys())[0]
		ansstr= ans[val]
		ans.popitem()
		list_str= ansstr.split(" ")
		for j in range(len(list_str)):
			print(list_str[j] , end=" ")
			m=m-1
			# print(m, end=" ")
			if(m<=0):
				break;

	print()

