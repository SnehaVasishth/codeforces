#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
    vector<string>v(n);
    for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v[i]=s;
        }
    if(m<4){
        cout<<"NO"<<"\n";
    }
    else{
        
unordered_set<char>st;
        int f=1;
        string t;
        for(int i=0;i<m;i++){
          
            for(int j=0;j<n;j++){
                
                char a= v[j][i];
                st.insert(a);
                            }

                            if(f==1 && st.find('v')!=st.end()){
                                t=t+'v';
                                f++;

                            }
                            else if(f==2 && st.find('i')!=st.end()){
                                t=t+'i';
                                f++;
                            }
                            else if(f==3 && st.find('k')!=st.end()){
                                t=t+'k';
                                f++;
                            }
                            else if(f==4 && st.find('a')!=st.end()){
                                t=t+'a';

                            }
                              st.clear();
        }

        if(t=="vika"){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }

    }


    }

}