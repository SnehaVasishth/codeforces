#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c,sneha,aashi;
        int count=0;
        cin>>a>>b>>c;

        sneha=max(a,b);
        aashi=min(a,b);
        while(1)
        {
            if(sneha==aashi || sneha<aashi)
            
            break;

            else if(c>=sneha-aashi)
            {
                count++;
                
                break;
            }
            
            sneha=sneha-c;
            
            aashi=aashi+c;
            count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}