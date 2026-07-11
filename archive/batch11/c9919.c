#include <stdio.h>
#include <stdbool.h>
static bool topo_possible(int n, const bool adj[6][6]) {
    int indegree[6] = {0};
    int queue[6]; int head = 0, tail = 0, visited = 0;
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (adj[u][v]) indegree[v]++;
    for (int i = 0; i < n; i++) if (!indegree[i]) queue[tail++] = i;
    while (head < tail) {
        int u = queue[head++]; visited++;
        for (int v = 0; v < n; v++)
            if (adj[u][v] && --indegree[v] == 0) queue[tail++] = v;
    }
    return visited == n;
}
int main(void) {
    static const bool dag[6][6] = {
        [0]={[1]=1,[2]=1},[1]={[3]=1},[2]={[3]=1,[4]=1},[3]={[5]=1},[4]={[5]=1}
    };
    static const bool cyc[6][6] = {
        [0]={[1]=1},[1]={[2]=1},[2]={[0]=1}
    };
    bool a = topo_possible(6, dag), b = topo_possible(6, cyc);
    printf("c9919 topo=%d,%d\n", (int)a, (int)b);
    return !(a && !b);
}
