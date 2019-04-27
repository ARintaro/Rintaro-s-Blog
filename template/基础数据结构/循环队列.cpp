// test site: https://www.luogu.org/problemnew/show/P3385
// task: 实现一个循环队列，要求有empty push init(O(1)) pop front 
// note: 一般用于需要多次清空队列且已知"队列里同时存在的最多元素数量"，
// 		 比起STL的queue，手写的可以O(1)清空。 
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
	
}q;

int cnt_path[maxn], dist[maxn];
bool inq[maxn];
void clear() {
	totedge = 0;
	q.init();
	memset(head, 0, sizeof(int) * (n+1));
	memset(inq, 0, sizeof(bool) * (n+1));
	memset(cnt_path, 0, sizeof(int) * (n+1));
	memset(dist, 0x3f, sizeof(int) * (n+1));
}

bool check() {
	q.push(start), dist[start] = 0;
	while(!q.empty()) {
		int x = q.pop();
		inq[x] = 0;
		for(rint i=head[x], y=ev[i]; i; i=nxt[i], y=ev[i]) {
			if(dist[x] + ew[i] < dist[y]) {
				dist[y] = dist[x] + ew[i];
				cnt_path[y] = cnt_path[x] + 1;
				if(cnt_path[y] > n) return 1;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	return 0;
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

