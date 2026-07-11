#include <stdio.h>

#define TABLE_SIZE 7
static int hash_key(int key) { return (key * 3) % TABLE_SIZE; }

static int insert(int table[], int key)
{
    int index = hash_key(key); int probes;
    for (probes = 0; probes < TABLE_SIZE; ++probes) {
        if (table[index] == 0) { table[index] = key; return probes; }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int main(void)
{
    int table[TABLE_SIZE] = {0,0,0,0,0,0,0};
    int p1 = insert(table, 5); int p2 = insert(table, 12); int p3 = insert(table, 19);
    printf("c8920 hash=%d,%d,%d\n", p1, p2, p3);
    return !(p1 == 0 && p2 == 1 && p3 == 2);
}
