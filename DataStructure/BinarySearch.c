Position BinarySearch(List L, ElementType X)
{
    Position left=1,right=L->Last;
    Position mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(X<L->Data[mid])
        {
            right=mid-1;
        }
        else if(X>L->Data[mid])
        {
            left=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return NotFound;
}
