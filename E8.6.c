//for original C8.2,[1,2] and [1,2,2] merge together.
int aux[N];
merge(int *a, int l, int m, int r)
{
    int i, j, k;
    for (i = m+1; i > l; i--)
    {
        aux[i-1] = a[i-1];
    }
    for (j = m; j < r; j++)
    {
        aux[r+m-j] = a[j+1];
    }

    for (k = l; k <=r; k++)
    {
        if (i > m)
        {
            a[k] = aux[j--];
        }
        else
        {
            if (less(aux[j], aux[i]))
            {
                a[k] = a[j--];
            }
            else
            {
                a[k] = a[i++];
            }
        }
    }
}