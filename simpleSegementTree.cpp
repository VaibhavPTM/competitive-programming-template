struct segmentTree {
    // segment tree of sumation
    vector<int> seg;
    int n;
    segmentTree(int N) {
        n = N;
        seg.resize(n*4);
    }
    void build(int start, int end, int node, vector<int> &ar) {
        if(start == end) {
            seg[node] = ar[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, node * 2 + 1, ar);
        build(mid + 1, end, node * 2 + 2, ar);
        seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
        return;
    }

    void build(vector<int> &ar) {
        build(0, n-1, 0, ar);
    }

    int query(int start, int end, int node, int l, int r) {
        if(l > end || r < start) return 0;

        if(l <= start && end <= r) {
            return seg[node];
        }

        int mid = (start + end) / 2;
        int L = query(start, mid, node * 2 + 1, l, r);
        int R = query(mid + 1, end, node * 2 + 2, l, r);
        return L + R;
    }

    int query(int l, int r) {
        return query(0, n-1, 0, l, r);
    }



    void update(int start, int end, int node, int idx, int val) {
        if(start == end) {
            seg[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid){
            update(start, mid, node * 2 + 1, idx, val);
        }
        else{ 
            update(mid + 1, end, node * 2 + 2, idx, val);
        }

        seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
    }

    void update(int idx, int val) {
        update(0, n-1, 0, idx, val);
    }
 
};
