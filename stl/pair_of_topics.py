import bisect
def solve(a,b,n):
    p=[0]*n
    
    for i in range (0,n):
        p[i]= a[i]-b[i]
    p.sort()
    ans=0
    for i in range (0,n-1):
        if(p[i]<=0):
            x= bisect.bisect_left(p,-p[i]+1)
            ans+=(n-x)
        else:
            ans+=(n-i-1)
    print(ans)
            
    
    

def main():
    n=int(input())
    a= list(map(int,input().split()))
    b= list(map(int,input().split()))
    
    solve(a,b,n)
    
    
if __name__=="__main__":
    main()