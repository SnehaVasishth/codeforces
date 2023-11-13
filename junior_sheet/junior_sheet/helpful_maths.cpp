#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int>nums;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            int a= s[i]-'0';
            nums.push_back(a);
        }

    }
    sort(nums.begin(),nums.end());
    string ans="";
    char p='+';
    for(int i=0;i<(nums.size()-1);i++){
        char b= nums[i]+'0';
        ans= ans+b+p;
    }
    char d= nums[nums.size()-1]+'0';
    ans= ans+d;
    cout<<ans<<"\n";
}