#include <stdio.h>

struct Node { int key; int left; int right; };

static int find(const struct Node nodes[], int root, int key)
{
    int current = root;
    while (current >= 0) {
        if (key == nodes[current].key) return current;
        current = key < nodes[current].key ? nodes[current].left : nodes[current].right;
    }
    return -1;
}

int main(void)
{
    static const struct Node nodes[] = {{8,1,2},{3,3,4},{12,-1,-1},{1,-1,-1},{6,-1,-1}};
    int found = find(nodes, 0, 6); int missing = find(nodes, 0, 10);
    printf("c8919 bst=%d,%d\n", found, missing);
    return !(found == 4 && missing == -1);
}
