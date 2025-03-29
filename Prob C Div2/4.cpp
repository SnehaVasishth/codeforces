void solve(TreeNode* par,TreeNode* node,vector<int>&ans,vector<int>&a,int &idx){
    if(node==NULL)
    return;
    if(node->val==a[idx])
    idx++;
    else if(node->val!=a[idx]){
        if(par->right && par->right->val==a[idx]){
            TreeNode* temp= par->right;
            par->right=par->left;
            par->left=temp;
            node=par->right;
            ans.push_back(a[idx]);
            idx++;
        }
        else{
            ans.push_back(-1);
            return;
        }
    }
    solve(node,node->left,ans,a,idx);
    solve(node,node->right,ans,a,idx);
}