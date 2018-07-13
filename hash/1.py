s="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dic= {}
for i in range(len(s)):
	dic[s[i]]=i

t = int(input())
for i in range(t):
	inp = input()
	st = []
	ans=0
	st = list(inp.split(" "))
	for j in range(len(st)):
		for k in range(len(st[j])):
			ans+= k + dic[st[j][k]]

	print(ans*len(st))

