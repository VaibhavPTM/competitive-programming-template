int findLIS(vector<int> &ar) {
    int n = ar.size();
    reverse(ar.begin(), ar.end());
    vector<int> lis;
    lis.push_back(ar[0]);
    vector<int> insertedAt(n);
    insertedAt[0] = 1;
    for(int i = 1; i < n; i++) {
        if(ar[i] < lis.back()) {
            lis.push_back(ar[i]);
            insertedAt[i] = lis.size();
        }
        else {
            int idx = 0;
            int l = 0, r = lis.size();
            while(l <= r) {
                int mid = (l + r) / 2;
                if(lis[mid] > ar[i]) {
                    l = mid + 1;
                }
                else {
                    idx = mid;
                    r = mid - 1;
                }
            }
            insertedAt[i] = idx + 1;
            lis[idx] = ar[i];
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
