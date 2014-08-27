int UFcount(int x)
{
    int i = x;
    while (i != id[i])
    {
        i = id[i];
    }

    return sz[i];
}