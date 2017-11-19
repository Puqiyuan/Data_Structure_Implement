// The 12 basic operations of order linear list, the store structre is defined by c2-1.h
using namespace std;

Status InitList(SqList &L)
{
	// Operation result: consturct a empty serial linear list.
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if (!L.elem)
		exit(OVERFLOW); // fail to mallocstore space.

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

	return OK;
}


Status DestroyList(SqList &L)
{
	// Initially condition: the serial linear list is existed already.
	// Operaion result: Destroy serial linear list.
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;

	return OK;
}


Status ClearList(SqList &L)
{
	// Initally condition: The serial linear list existed already.
	// Operation result: Set L to empty list.
	L.length = 0;

	return OK;
}


Status ListEmpty(SqList L)
{
	// Initally condition: The serial linear list existed already.
	// Operation result: if L is empty, return TRUE, else FLASE.
	if (L.length == 0)
		return TRUE;

	return FALSE;
}


int ListLength(SqList L)
{
	// Initally condition: The serial linear list L is existed already.
	// Operation result: Return the number of element in L.
	return L.length;
}


Status GetElem(SqList L, int i, ElemType &e)
{
	// Initally condition: The serial linear list L is existed already.
	// Operation result: Return the i'th element in L by e.

	if (i < 1 || i > L.length)
		exit(ERROR);

	e = *(L.elem + i -1);
	return OK;
}


Status ListInsert(SqList &L, int i, ElemType e)
{
	// Initally condition: The serial linear list L is existed already, 1 <= i <= ListLength(L) + 1 .
	// Opeation result: Inserting a new element before location i, and increase L by 1.

	ElemType *newbase, *q, *p;

	if (i < 1 || i > L.length + 1) // the value of i is invalid.
		return ERROR;

	if (L.length >= L.listsize) // the current space was run out of, increasing space.
		{
			if ( !(newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType))))
				exit(OVERFLOW); // failed to remalloc space.

			L.elem = newbase; // newbase.

			L.listsize += LISTINCREMENT; // increase store space.
		}

	q = L.elem + i - 1;
	
	for (p = L.elem + L.length - 1; p >= q; --p)
		*(p + 1) = *p;

	*q = e;

	++L.length;

	return OK;
}


Status ListDelete(SqList &L, int i, ElemType &e)
{
	// Initall condition: The serial linear list existed alreay, i <= i <= ListLength(L)
	// Operation result: Delete the i'th element of L, and return its value by e, the length of L decrease by 1.

	ElemType *p, *q;

	if (i < 1 || i > L.length) // the value of i is invalid.
		return ERROR;

	p = L.elem + i - 1; // p is the location of deleted element.
	e = *p; // assign the deleted element to e.
	q = L.elem + L.length - 1; // the tail of L.
	for (++p; p <= q; ++p) // shift all elements that after deleted to forward.
		*(p - 1) = *p;

	L.length--; // the length of L should decrease by 1.

	return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	// Initally condition: The serial linear list L is existed already. compare() is the function used for data judge, content 1, otherwise 0.
	// Operation result: return the location of element that the first one satisfy the relationship of compare function. If there is no such element, return 0.

	ElemType *p;

	int i = 1; // the initial value of i is the first element.
	p = L.elem; // the initial value of p is the location of the first element.

	while (i <= L.length && !compare(*p++, e))
		++i;

	if (i <= L.length)
		return i;
	
	return 0;
}
