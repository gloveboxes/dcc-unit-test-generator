#include <stdio.h>

struct Trie { int next[3]; int route; };

static int insert(struct Trie *nodes, int *used, const char *key, int route)
{
    int node, edge;
    node = 0;
    while (*key != '\0') {
        edge = *key++ - 'A';
        if (edge < 0 || edge > 2) return 0;
        if (nodes[node].next[edge] == 0) { nodes[node].next[edge] = (*used)++; node = nodes[node].next[edge]; }
        else node = nodes[node].next[edge];
    }
    nodes[node].route = route; return 1;
}
static int lookup(const struct Trie *nodes, const char *key)
{
    int node, edge;
    node = 0;
    while (*key != '\0') { edge = *key++ - 'A'; if (edge < 0 || edge > 2 || nodes[node].next[edge] == 0) return -1; node = nodes[node].next[edge]; }
    return nodes[node].route;
}

int main(void)
{
    struct Trie nodes[12] = {{{0,0,0},-1}}; int used, a, b;
    used = 1; insert(nodes,&used,"AB",7); insert(nodes,&used,"ACB",9); insert(nodes,&used,"BA",4);
    a = lookup(nodes,"ACB"); b = lookup(nodes,"AA");
    printf("c8909 trie=%d,%d,%d\n", a, b, used);
    return !(a == 9 && b == -1 && used == 7);
}
