n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
ans=l[k-1]
if(k==0 and l[0]>1):
    ans=1
if((k==0 and l[0]==1) or (k<=(n-1) and l[k]==l[k-1])):
    ans=-1
    
print(ans)