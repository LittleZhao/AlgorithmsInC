#include <stdio.h>
#include <stdlib.h>
typedef struct node * link;
struct node
{
    /* data */
    int item;
    link l, r;
};

link NEW(int item, link l, link r)
{
    link x = malloc(sizeof( *x));
    x->item = item;
    x->l = l;
    x->r = r;
    return x;
}


link max(int *a, int l, int r)
{
    int m = (l + r)/2;
    int u, v;
    link x = NEW(a[m], NULL, NULL);
    if (l == r) {return x;}
    x->l = max(a, 0, m);
    x->r = max(a, m+1, r);
    u = x->l->item;
    v = x->r->item;

    if (u > v)
    {
        x->item = u;
    }
    else
    {
        x->item = v;
    }
    return x;
}

void destroy(link p)
{
    if (p == NULL) {return;}
    destroy(p->l);
    destroy(p->r);
    printf("%d ", p->item);
    free(p);
}

int main(void)
{
    int n, *a;
    link p;
    int i;
    printf("The length of the array-> ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    p = max(a, 0, n - 1);
    printf("The max number is %d\n", p->item);
    free(a);
    destroy(p);
    return;
}