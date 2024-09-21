#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string s(n,'$');
        char zeroe='a',firste='a';
        // unordered_map<char,int>mp;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            if(a[i]==0){
                // cout<<"zeroe  "<<i<< " "<<zeroe<<"\n";
                s[i]=zeroe;
               freq[zeroe-'a']++;
                // cout<<"zeroe freq "<<mp[zeroe]<<"\n";
                zeroe=zeroe+1;
            }
            else if(a[i]==1){
                // cout<<"firste "<<i<<" "<<firste<<"\n";
                s[i]=firste;
               freq[firste-'a']++;
                // cout<<"firste ffreq "<<mp[firste]<<"\n";
                firste=firste+1;
            }
            else if(a[i]>1){

                for(int j=0;j<26;j++){
                    if(freq[j]==a[i]){
                        s[i]= char('a'+j);
                        freq[j]++;
                        break;
                    }
                }






            //     for(auto it:mp){
            //         if(it.second==a[i]){
            //             s[i]=it.first;
            //             cout<<"i "<<i<<"s]i  "<<s[i]<<"\n";
            //             (it.second)= ((it.second)+1);
            //             cout<<"it "<<it.first<<"  "<<it.second<<"\n";
            //             cout<<"senhaa\n";
            //         }
            //     }
            //     for(auto it:mp){
            //     cout<<i<<"  "<<it.first<<" "<< it.second<<"\n";
            // }
            }
            
        }
        cout<<s<<"\n";

    }
}