bool ascending(int a, int b)
{
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b ? false : true;
    }
    return squareA > squareB;
}

bool descending(int a, int b)
{
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b ? true : false;
    }
    return squareA < squareB;
}

bool cmp(int a, int b) // for tests
{
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b;
    }
    return squareA < squareB;
}