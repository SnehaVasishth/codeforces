#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n,k,a1,a2,sink=0;
        cin>>n>>k;
        bool flag=0;
        
        vector<long long>v(n);
        for(long long i=0;i<n;i++)
        cin>>v[i];

        if((k%2)==0) a1=k/2,a2=k/2;
        else a1=k/2+1 ,a2=k/2;

        long long st=0,en=n-1;
        while((a1!=0 || a2!=0) && st<=en)
        {
            if(a1<v[st] && a2<v[en] && st!=en) break;
            if(st==en)
            {
                if((a1+a2)>=v[st])a1=0,a2=0,sink++,st++,en--;
                else break;
            }

            if(flag==0 && a1>=v[st]) a1=a1-v[st],sink++,st++,flag=1;
            else if(flag==0 && a1<v[st]) a1=0;
            else if(flag==1 && a2>=v[en]) a2=a2-v[en],sink++,en--,flag=0;
            else if(flag==1 && a2>=v[en]) a2=0;
            //cout<<a1<<" "<<a2<<" "<<sink<<endl;;
        }
        cout<<sink<<endl;
    }
    
}