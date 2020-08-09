using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long w_ = (long long) w;
    long long h_ = (long long) h;
    return (w_ * h_) - (w_ + h_ - gcd(w_, h_));
}
