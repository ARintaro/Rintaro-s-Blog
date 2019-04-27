// test site: https://www.luogu.org/problemnew/show/P3385 
// task: 600ms以内判定负环，请注意，有多组数据，要求实现clear函数（包括邻接表 
// tips: 循环队列已实现好。 
// extra: ”同时记录节点个数“ “卡时” 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define rint register int
#define lint long long
#define isnum(x) ('0' <= (x) && (x) <= '9')
template<typename tint>
inline void readint(tint& x) {
    int f = 1; char ch = getchar(); x = 0;
    for(; !isnum(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isnum(ch); ch = getchar()) x = x * 10 + ch - '0';
    x *= f;
}
using namespace std;
const int maxn = 2000 + 10;
const int maxm = 6000 + 10;
int n, m, start = 1;

int head[maxn], ev[maxm], ew[maxm], nxt[maxm];
int totedge = 0;
inline void addedge(int nu, int nv, int nw) {
    ev[++totedge] = nv, ew[totedge] = nw, nxt[totedge] = head[nu];
    head[nu] = totedge;
}

struct Queue{
    int arr[maxn];
    int l, r, size;
    inline void init() { l = 1, r = 0, size = maxn - 10; }
    inline void push(int x) {
        if(r == size) r = 0;
        arr[++r] = x;
    }
    inline int pop() {
        if(l == size) {l = 1; return arr[size]; }
        return arr[l++];
    }
    inline bool empty() { return l == r + 1; }
}q;

void clear() {
    
}

bool check() {
	
}

int main() {
    int T;
    readint(T);
    while(T--) {
        int nu, nv, nw;
        readint(n), readint(m);
        clear();
        for(rint i=1; i<=m; i++) {
            readint(nu), readint(nv), readint(nw);
            addedge(nu, nv, nw);
            if(nw >= 0) addedge(nv, nu, nw);
        }
        puts(check() ? "YE5" : "N0");
    }
    return 0;
}

