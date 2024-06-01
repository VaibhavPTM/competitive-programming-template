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

// printing LIS
int findLIS(vector<int> &ar) {
    int n = ar.size();
    vector<int> lis;
    lis.push_back(ar[0]);
    vector<int> insertedAt(n);
    insertedAt[0] = 1;
    for(int i = 1; i < n; i++) {
        if(ar[i] > lis.back()) {
            lis.push_back(ar[i]);
            insertedAt[i] = lis.size();
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), ar[i]) - lis.begin();
            insertedAt[i] = it + 1;
            lis[it] = ar[i];
        }
    }
    vector<int> res;
    int len = lis.size();
    for(int i = n-1; i >= 0; i--) {
        if(insertedAt[i] == len) {
            len--;
            res.push_back(ar[i]);
        }
    }
    reverse(res.begin(), res.end());
    print(res);
    return res.size();
}
