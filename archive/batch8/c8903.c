#include <stdio.h>

struct Item { int key; char tag; };

static void stable_sort(struct Item items[], int count)
{
    int i;
    int j;
    struct Item current;
    for (i = 1; i < count; ++i) {
        current = items[i];
        j = i;
        while (j > 0 && items[j - 1].key > current.key) {
            items[j] = items[j - 1];
            --j;
        }
        items[j] = current;
    }
}

int main(void)
{
    struct Item items[5] = {{3,'a'}, {1,'b'}, {3,'c'}, {2,'d'}, {3,'e'}};
    stable_sort(items, 5);
    printf("c8903 stable=%d,%c%c%c\n", items[0].key,
           items[2].tag, items[3].tag, items[4].tag);
    return !(items[0].key == 1 && items[2].tag == 'a' &&
             items[3].tag == 'c' && items[4].tag == 'e');
}
