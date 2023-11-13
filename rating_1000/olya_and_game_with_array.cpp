#include<bits/stdc++.h>

using namespace std;
vector<int>firstmini(vector<vector<int>>&a){
    vector<int>first;
    for(int i=0;i<a.size();i++){
        int mini=*min_element(a[i].begin(),a[i].end());
        first.push_back(mini);
    }
    return first;
}
vector<int>secondmini(vector<vector<int>>&a,vector<int>&first){
    vector<int>second;
    bool flag=0;
    for(int i=0;i<a.size();i++){
        int first_mini=first[i];
        int mini=INT_MAX;
        flag=0;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]<mini && a[i][j]!=first_mini){
                mini=a[i][j];
            }
          if(a[i][j]<mini && a[i][j]==first_mini && flag==1){
                mini=a[i][j];
            }
           else if(a[i][j]<mini && a[i][j]==first_mini){
                flag=1;

            }
          

        }
          second.push_back(mini);
    }
    return second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>a;
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            vector<int>temp(m);
            for(int j=0;j<m;j++){
                cin>>temp[j];
            }
            a.push_back(temp);
        }
        
        
        vector<int>first=firstmini(a);
        vector<int>second=secondmini(a,first);
        
       
       
        long long int sum=0;
        int smallest_sec_mini=*min_element(second.begin(),second.end());
        int smallest_first_mini= *min_element(first.begin(),first.end());
        for(int i=0;i<second.size();i++){
            sum+=second[i];
        }
        sum=sum- smallest_sec_mini + smallest_first_mini;
        cout<<sum<<"\n";

    }
}