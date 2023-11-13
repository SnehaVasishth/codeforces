#include<bits/stdc++.h>
#define ll long long int
#define cout(x) cout<<"x:  "<<x<<"\n"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    vector<vector<int>>v(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        sum=0;
        for(int j=0;j<s[i].size();j++){
            sum+= (s[i][j]-'0');
            v[i].push_back(sum);
            
        }

    }

    

    ll total_size=0, half_size=0,after=0,before=0,cnt=0;

    for(int i=0;i<n;i++){
        string m= s[i];
      
        for(int j=0;j<n;j++){
            string n= s[j];
            
            if((m.size()%2==0 && n.size()%2==0) ||(m.size()%2!=0 && n.size() %2!=0)){
                total_size= m.size()+n.size();
                half_size= total_size/2;
                
                if(half_size <n.size()){
                    after= v[j][n.size()-1]- v[j][n.size()- half_size-1];
                    before= v[i][m.size()-1]+ v[j][n.size()- half_size-1];
                   
                    if(after==before)
                    cnt++;
                }
                else if(half_size>= n.size()){
                   
                    before= v[i][half_size-1];
                     after= v[j][n.size()-1] + v[i][m.size()-1]-before;
                     
                     if(after==before)
                     cnt++;


                }
            }
        }
    }
    cout<<cnt<<"\n";

}