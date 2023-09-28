template <int mod> struct mod_int{
    long long x;
    mod_int() : x(0){}
    mod_int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod){}
    static long long get_mod(){return mod;}
    mod_int &operator+=(const mod_int &p){return (x += p.x) >= mod ? x -= mod : 0, *this;}
    mod_int &operator-=(const mod_int &p){return (x += mod - p.x) >= mod ? x -= mod : 0, *this;}
    mod_int &operator*=(const mod_int &p){return x = (long long)((__uint128_t)x * p.x % mod), *this;}
    mod_int &operator/=(const mod_int &p){return *this *= p.inv();}
    mod_int &operator++(){return *this += mod_int(1);} 
    mod_int &operator--(){return *this -= mod_int(1);}
    mod_int operator++(int32_t){mod_int tmp = *this; ++*this; return tmp;}
    mod_int operator--(int32_t){mod_int tmp = *this; --*this; return tmp;}
    mod_int operator+(const mod_int &p)const{return mod_int(*this) += p;}
    mod_int operator-(const mod_int &p)const{return mod_int(*this) -= p;}
    mod_int operator*(const mod_int &p)const{return mod_int(*this) *= p;}
    mod_int operator/(const mod_int &p)const{return mod_int(*this) /= p;}
    mod_int operator-()const{return mod_int(-x);}
    bool operator!()const{return !x;}
    bool operator~()const{return ~x;}
    bool operator==(const mod_int &p)const{return x == p.x;}
    bool operator!=(const mod_int &p)const{return x != p.x;} 
    mod_int inv()const{assert(*this != mod_int(0)); return pow(mod - 2);}
    mod_int pow(long long k)const{mod_int now = *this, ret = 1; for (; k > 0; k >>= 1, now *= now) if (k & 1) ret *= now; return ret;}
    friend istream &operator>>(istream &is, mod_int &p){long long a; is >> a; p = mod_int<mod>(a); return is;}
    friend ostream &operator<<(ostream &os, const mod_int &p){return os << p.x;}
};
using mint = mod_int<mod>;
