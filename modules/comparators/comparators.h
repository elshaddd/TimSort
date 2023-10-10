bool ascending(int a, int b)
{
    int f = abs(a), s = abs(b);
    if (f == s)
    {
        return a > b;
    }
    return f < s;
}

bool descending(int a, int b)
{
    int f = abs(a), s = abs(b);
    if (f == s)
    {
        return a > b;
    }
    return f > s;
}