 void solve(int idx,vector<string>&res,string &s,int num){
        if(idx>=num){
            res.push_back(s);
            return;
        }
        if(idx==0){
            s.push_back('0');
            solve(idx+1,res,s,num);
            s.pop_back();
            s.push_back('1');
            solve(idx+1,res,s,num);
        }
        else if(idx>0) {
            s.push_back('0');
            solve(idx+1,res,s,num);
            cout<<s<<" "<<idx<<"\n";
            
            s.pop_back();
            cout<<s<<"\n";
            if((idx-1)>=0 && s[idx-1]=='0'){
                s.push_back('1');
                solve(idx+1,res,s,num);
                s.pop_back();
            }
        }
        
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>res;
        string s="";
        solve(0,res,s,num);
    }