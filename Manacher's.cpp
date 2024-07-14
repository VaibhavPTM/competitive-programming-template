class ManacherS {
public:
    int n, N;
    string str, s;
    vector<int> p;
    ManacherS(string a) {
        str = a;
        n = str.size();
        s.push_back('#');
        for(char c : str) {
            s.push_back(c);
            s.push_back('#');
        }
        N = s.size();
        p.resize(N+2);
        
    }
    void manacher() {
        int l = 1, r = 1;
        for(int i = 1; i <= N; i++) {
            p[i] = max(0ll, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
    }
    string giveLongestPelindrom() {
        int idx = 0, len = 1;
        for(int i = 1; i <= N; i++) {
            if(p[i]-1 > len) {
                int first = i - (p[i] - 2);
                idx = (first - 1) / 2;
                len = p[i]-1;
            }
        }
        idx = max(idx, 0ll);
        return str.substr(idx, len);
    }

};
