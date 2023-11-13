#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int count=0;

    string sneha;


    cin>>sneha;

    string test={"codeforces"};

    for(int i=0;i<sneha.size();i++)
    {
        if(sneha[i]!=test[i])

        count++;
    }
    cout<<count<<endl;
    }
    return 0;
}