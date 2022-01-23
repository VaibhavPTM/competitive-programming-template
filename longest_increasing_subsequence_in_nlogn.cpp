int lengthOfLIS(vector<int>& v) {
    vector<int> ans;
    for(int i=0; i<v.size(); ++i)
    {
        int r = 0,l = ans.size()-1;
        while(r<=l)
        {
            int mid = (r+l)/2;
            if(ans[mid]>v[i])
                l = mid-1;
            else
                r = mid+1;
        }
        if(l+1==ans.size())
            ans.push_back(v[i]);
        else
            ans[l+1] = v[i];
    }
    return ans.size();
}
