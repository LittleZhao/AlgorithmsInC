link list_selection(link h)
{
    link max, temp, out=NULL;
    if (NULL == h)
    {
        return NULL;
    }

    while (NULL != head->next)
    {
        temp = find_max(head);
        max = temp->next;
        temp->next = max->next;
        max->next = out;
        out = max;
    }
    head->next = out;
    return head;
}

link find_max(link h)
{
    int v;
    link t, r;
    if (NULL == h)
    {
        return NULL;
    }
    t = r = h;
    v = t->next->data;
    while (NULL != t->next)
    {
        if (t->next->data > v)
        {
            r = t;
            v = t->next->data;
        }
    }
    return r;
}