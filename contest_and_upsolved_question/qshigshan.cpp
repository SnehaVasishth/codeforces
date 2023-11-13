#include<bits/stdc++.h>
using namespace std;

bool problem(string &s,string &t)
{  
    
     int m=t.size();
    int n=s.size();
   
    int end=t[m-1];


    bool flag=0;
     int first=t[0];


    for(int i=1;i<m;i++)
    {
        if(t[i]==t[i-1])
        {
            flag=1;
            break;
        }

    }
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1] && flag==0)
        {
            if(first==s[i-1] || end==s[i-1])
            {
                return 0;
            }
        }
        else if(s[i]==s[i-1] && flag==1)
        {
            return 0;
        }
    }
    return 1;

}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        string t;
        cin>>t;

        if(problem(s,t)==1)
        cout<<"YES\n";

        else
        cout<<"NO\n";
    }
    
}