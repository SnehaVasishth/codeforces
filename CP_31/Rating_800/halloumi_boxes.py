def solve(n,k,arr):
    flag=0
    if k>=2:
        return flag
    else:
        for i in range(1,n):
            if arr[i]>=arr[i-1]:
                continue
            else:
                flag=1
                break
    return flag

def main():
    t=int(input())
    while(t>0):
        n,k=map(int,input.split())
        arr=list()
        for i in range (n):
            arr[i]=int(input())
        ans=solve(n,k,arr)
        if ans==0:
            print("YES")
        else:
            print("NO")
        
        t=t-1
    
if __name__ == "__main__":
    main()