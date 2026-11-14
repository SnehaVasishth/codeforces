def solve(l,m,s):
    n=len(s)
    p=[0 for _ in range (n)]
    for i in range(1,n):
        if (s[i]==s[i-1]):
            p[i]=p[i-1]+1
        else:
            p[i]=p[i-1]
            
    for i in range (0,m):
        left= l[i][0]
        right= l[i][1]
        print(p[right-1]-p[left-1])

def main():
    s=input()
    m=int(input())
    l=[ list(map(int,input().split())) for _ in range (m)]
    
  
    
    solve(l,m,s)
    
    
if __name__=="__main__":
    main()
    