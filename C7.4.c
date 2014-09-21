#define N 10
#define key(A) (A)
#define less(A, B) {key(A) < key(B)}
#define exch(A, B) {A ^= B; B ^= A; A ^= B}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void quicksort(int *a, int l, int r)
{
    int i, m;
    m = l + (r - l) / 2;
    if (r - l =< N)
    {
        return;
    }

    exch(a[m], a[r-1]);
    //make a[l] <= a[r-1] <= a[r]
    compexch(a[l], a[r-1]);
    compexch(a[l], a[r]);
    compexch(a[r-1], a[r]);

    i = partition(a, l+1, r-1);

    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

void sort(int *a, int l, int r)
{
    quicksort(a, l, r);
    insertion(a, l, r);
}