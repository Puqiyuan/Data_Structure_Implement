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

	else
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
