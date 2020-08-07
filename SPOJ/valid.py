t=int(input())
for p in range(t):
    n=int(input())
    list1=[]
    for i in range(n,2,-1):
        for j in range(2,i):
            if i%j==0:
                break
        else:
            list2=[]
            si=str(i)
            su=0
            for m in si:
                su+=int(m)
            for o in si:
                
                io=int(o)
                for q in range(2,io):
                    if io%q==0:
                        break
                else:
                    list2.append(io)
            k=sum(list2)
            if k==su:
                print("Case ",int(p+1),": ",int(i),sep='')
                break