
class ManacherS {
public:
    int n, N;
    vector<int> arr, s, p;

    ManacherS(const vector<int>& a) {
        arr = a;
        n = arr.size();
        s.push_back(0);  // Use 0 as a separator (assuming input values are non-negative)
        for(int num : arr) {
            s.push_back(num);
            s.push_back(0);
        }
        N = s.size();
        p.resize(N + 2);
    }

    void manacher() {
        int l = 1, r = 1;
        for(int i = 1; i <= N; i++) {
            p[i] = max(0ll, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        
    }

    vector<int> giveLongestPalindrome() {
        int idx = 0, len = 1;
        for(int i = 1; i <= N; i++) {
            if(p[i] - 1 > len) {
                int first = i - (p[i] - 2);
                idx = (first - 1) / 2;
                len = p[i] - 1;
            }
        }
        idx = max(idx, 0ll);
        vector<int> result;
        for(int i = idx; i < idx + len; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
    // brute force to check correct approach.
    int getAns() {
        int res = 0;
        print(s);
        print(p);
        for(int i = 1; i < s.size()-1; i++) {
            int sum = s[i];
            res = mod_add(res, sum);
            for(int j = i - 1, k = 1; k < p[i]; k++, j--) {
                sum = mod_add(sum, s[j] * 2);
                if(j % 2){
                    res = mod_add(res, sum);
                }
            }
        }
        return res;
    }
    int getOdd(int i) {
        return p[2 * i + 1] / 2;
    }
    int getEven(int i) {
        return (p[2 * i] - 1) / 2;
    }
};
