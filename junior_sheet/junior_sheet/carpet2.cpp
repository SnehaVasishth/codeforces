#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,count=0,c=0;
        cin>>n>>m;
        unordered_set<char> st;
        vector<char> give{'v','i','k','a'};

        vector<vector<char>>vec(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                cin>>vec[i][j];
            }
        }

        int j=0,k=0;
        while(count!=4 && j-1<=m)
        {   c++;
            for(int i=0;i<n;i++)
            {
                st.insert(vec[i][j]);
            }
            j++;
            if(st.find(give[k])!=st.end())
            {
                count++;
                k++;
            }
            st.clear();
        }
        if(count==4)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}