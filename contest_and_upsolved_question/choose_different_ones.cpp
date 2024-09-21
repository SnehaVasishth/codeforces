#include<bits/stdc++.h>

using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp1[a[i]]++;
        }
         for(int i=0;i<m;i++){
            cin>>b[i];
            mp2[b[i]]++;
        }
        unordered_map<int,vector<pair<int,char>>>mp;
        vector<bool>entery(k+1,0);
        bool flag=0;
        int cnta=0,cntb=0;
        
        // for(auto it:mp1){
        //     cout<<"no>  "<<it.first<<"feq "<<it.second<<"\n";
        // }
        // for(auto it:mp2){
        //     cout<<"no>  "<<it.first<<"feq "<<it.second<<"\n";
        // }
        for(int i=1;i<=k;i++){
            if(mp1[i]>0){
                // cout<<"which "<<i<<"  kya "<<mp1[i]<<"\n";
                mp[i].push_back({mp1[i],'a'});
                // cout<<"sneha\n";
            }
            if(mp2[i]>0){
                // cout<<"what np. "<<i<<" freqwhat "<<mp2[i]<<"\n";
                mp[i].push_back({mp2[i],'b'});
                // cout<<"aashi\n";
            }

            if(mp[i].size()==1){
                if(mp[i][0].second=='a' && cnta<(k/2)){
                    cnta++;
                    entery[i]=1;
                    // cout<<"spaesh\n";
                }
                else if(mp[i][0].second=='b' && cntb<(k/2)){
                    cntb++;
                    entery[i]=1;
                    // cout<<"khushi\n";
                }
                else if((cnta>=(k/2) && mp[i][0].second=='a') || (cntb>=(k/2) && mp[i][0].second=='b')){
                    flag=1;
                    // cout<<"akanshsg\n";
                    break;
                }
            }

        }

        for(int i=1;i<=k;i++){
            // cout<<"abhi kaun "<<i<<" value "<<entery[i]<<"\n";
            // cout<<"size batap "<<i<< mp[i].size()<<"\n";
           
            if(entery[i]==0){
                // cout<<"tu hai "<<i<<"\n";
                if(mp[i].size()==2){
                    // cout<<"kya ne "<<i<<"\n";
                    if(cnta<(k/2)){
                        cnta++;
                        entery[i]=1;
                        // cout<<"kuansi "<<i<<" which one"<<entery[i]<<"\n";
                        // cout<<"shiva\n";

                    }
                    else if(cntb<(k/2)){
                        entery[i]=1;
                        // cout<<"kuansi "<<i<<" which one"<<entery[i]<<"\n";
                        cntb++;
                        // cout<<"diya\n";

                    }
                    else if((cnta>=(k/2) && cntb>=(k/2))){
                        flag=1;
                        // cout<<"sdfg\n";
                        // cout<<"kuansi "<<i<<" which one"<<entery[i]<<"\n";
                        break;
                    }
                    // cout<<"meri "<<i<<"\n";
                }
            

                else if(mp[i].size()==0){
                    flag=1;
                    // cout<<"archan\n";
                    // cout<<"kuansi "<<i<<" which one"<<entery[i]<<"\n";
                    break;
                }
                // cout<<"kaun hu mao "<<i<<"\n";
            }

            
        }
        if(flag==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
