#include <stdio.h>
#include <stdbool.h>
static int count_components(int n, const bool adj[8][8]) {
    bool visited[8] = {false};
    int stack[8]; int components = 0;
    for (int start = 0; start < n; start++) {
        if (visited[start]) continue;
        components++;
        int top = 0; stack[top++] = start;
        while (top) {
            int node = stack[--top];
            if (visited[node]) continue;
            visited[node] = true;
            for (int i = 0; i < n; i++)
                if (adj[node][i] && !visited[i]) stack[top++] = i;
        }
    }
    return components;
}
int main(void) {
    static const bool g[8][8] = {
        [0]={[1]=1,[2]=1},[1]={[0]=1},[2]={[0]=1},
        [3]={[4]=1},[4]={[3]=1},
        [5]={0},[6]={[7]=1},[7]={[6]=1}
    };
    int c = count_components(8, g);
    printf("c9925 components=%d\n", c);
    return c != 4;
}
