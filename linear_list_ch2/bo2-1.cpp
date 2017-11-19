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


