#include<cstdio>
using namespace std;
 
int N, M, g[1001][1001];
int d[1001];
int INF = 10000000000;
int s, e;
bool check[1001];
 
void dikstra(int s) {
    for (int i = 1; i <= N; i++)
        d[i] = g[s][i];
    check[s] = true;
 
    for (int k = 1; k < N - 1; k++) {
        int mini = INF;
        for (int i = 1; i <= N; i++)
            if (check[i] == false && mini > d[i]) {
                mini = d[i];
                s = i;
            }
        check[s] = true;
        for (int i = 1; i <= N; i++) {
            if (check[i] == false && d[i] > d[s] + g[s][i]) {
                d[i] = d[s] + g[s][i];
            }
        }
    }
}
 
int main() {
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            g[i][j] = INF;
            if (i == j)
                g[i][j] = 0;
        }
    }
 
    while (M--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(g[a][b] > c)
            g[a][b] = c;
    }
    scanf("%d %d", &s, &e);
 
    dikstra(s);
 
    printf("%d\n", d[e]);
 
    return 0;
}