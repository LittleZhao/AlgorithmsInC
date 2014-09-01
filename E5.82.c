void traverse_n(link h)
{
    link p = NULL;
    if (NULL == h)
    {
        return;
    }
    STACKpush(h);
    p = h->l;
    while (NULL!= p && !STACKempty())
    {
        while (NULL != p)
        {
            STACKpush(p);
            p = p->l;
        }

        if (!STACKempty())
        {
            p = STACKpop();
            visit(p);
            p = p->r;
        }
    }
    return;

}