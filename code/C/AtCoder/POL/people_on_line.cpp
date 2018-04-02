#include<cstdio>
const int MAXN = 100000;
int pre[MAXN + 5], f[MAXN + 5];
int Find(int x) {
	if( pre[x] == x ) return x;
	int ret = Find(pre[x]);
	f[x] = f[x] + f[pre[x]];
	return pre[x] = ret;
}
int main() {
	int N, M;
	bool flag = true;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		pre[i] = i;
	for(int i=1;i<=M;i++) {
		int L, R, D;
		scanf("%d%d%d",&L,&R,&D);
		if( flag ) {
			if( Find(L) == Find(R) ) {
				if( f[R] <= f[L] ) {
					int p = f[L] - f[R];
					if( p != D ) flag = false;
				}
				else {
					flag = false;
				}
			}
			else {
				int k = Find(L);
				pre[k] = L;f[k] = -f[L];
				pre[L] = R;f[L] = D;
			}
		}
	}
	if( flag ) printf("Yes\n");
	else printf("No\n");
}
