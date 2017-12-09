// bo2-31.cpp the 11 basic operations of one array only generated only one static link list, its datastructure is defined by c2-3.h
int InitList(SLinkList L)
{
	// Construct a empty link list, the header is the first element, if cur is "0" means null pointer.
	int i;
	L[MAXSIZE - 1].cur = 0; // The pointer cur of the last element is null.
	for (i = 0; i < MAXSIZE - 2; i++)
		L[i].cur = i + 1;
	L[MAXSIZE - 2].cur = 0;
}



