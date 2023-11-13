#include<bits/stdc++.h>

using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt=0;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int k= 2*diff;
        for(auto x:s){
            if(s.find(x+diff)!=s.end()  && (s.find(x+k)) !=s.end()){
                cnt++;
            }
        }
return cnt;
    }

    int main(){
        int n,k;
        cin>>n>>k;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        cout<<arithmeticTriplets(nums,k)<<"\n";

    
    }