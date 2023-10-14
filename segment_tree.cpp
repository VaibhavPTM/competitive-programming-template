class SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    void build(int index, int left, int right, const vector<int>& arr) {
        if (left == right) {
            tree[index] = arr[left] % 26;
            return;
        }

        int mid = (left + right) / 2;
        build(2 * index + 1, left, mid, arr);
        build(2 * index + 2, mid + 1, right, arr);
        tree[index] = (tree[2 * index + 1] + tree[2 * index + 2]) % 26;
    }

    void propagate(int index, int left, int right) {
        if (lazy[index] != 0) {
            tree[index] += (lazy[index] % 26) * (right - left + 1);
            tree[index] %= 26;
            if (left != right) {
                lazy[2 * index + 1] += lazy[index] % 26;
                lazy[2 * index + 2] += lazy[index] % 26;
            }
            lazy[index] = 0;
        }
    }

    void updateRange(int index, int left, int right, int l, int r, int x) {
        propagate(index, left, right);

        if (l > right || r < left) {
            return;
        }

        if (l <= left && r >= right) {
            tree[index] += (x % 26) * (right - left + 1);
            tree[index] %= 26;
            if (left != right) {
                lazy[2 * index + 1] += x % 26;
                lazy[2 * index + 2] += x % 26;
            }
            return;
        }

        int mid = (left + right) / 2;
        updateRange(2 * index + 1, left, mid, l, r, x);
        updateRange(2 * index + 2, mid + 1, right, l, r, x);
        tree[index] = (tree[2 * index + 1] + tree[2 * index + 2]) % 26;
    }

    int pointQuery(int index, int left, int right, int i) {
        propagate(index, left, right);

        if (left == right) {
            return tree[index];
        }

        int mid = (left + right) / 2;
        if (i <= mid) {
            return pointQuery(2 * index + 1, left, mid, i);
        } else {
            return pointQuery(2 * index + 2, mid + 1, right, i);
        }
    }

    void addRange(int l, int r, int x) {
        updateRange(0, 0, n - 1, l, r, x);
    }

    int getValue(int i) {
        return pointQuery(0, 0, n - 1, i);
    }
};
