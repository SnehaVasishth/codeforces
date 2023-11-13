#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int sum=0,s=0,down=9,right=9,left=0;
        vector<string>v(10);
        for(int i=0;i<10;i++)
        {
            cin>>v[i];
        }

        while(s<5 && left<5 && right>4 && down>4)
        {
            for(int i=left;i<=right;i++)
            {
                if(v[s][i]=='X' )
                sum+=s+1;
                
                if(v[down][i]=='X' )
                sum+=s+1;
            }
            int stop=s,sdown=down;

            
            for(int i=s;i<=down;i++)
            {
                if(v[i][left]=='X' && i!=stop && i!=sdown)
                sum+=left+1;

                if(v[i][right]=='X' && i!=sdown && i!=stop)
                sum+=s+1;
            }


            s++,right--,down--,left++;
        }
        cout<<sum<<endl;
    }
}