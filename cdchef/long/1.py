t = int(input())
for i in range(t):
    t1, t2 , k = map(int , input().split())
    if(((t1 + t2)//k)%2 == 1):
        print("COOK")
    else:
        print("CHEF")
