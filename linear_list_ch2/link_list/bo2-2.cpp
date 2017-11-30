// bo2-2.cpp, 12 basic operations of link form of linear list whose store structure is defined by c2-2.h

Status InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); // Create a head node, and make L point this head point.

	if ( !L ) // Failed to malloc space.
		exit(OVERFLOW);

	L -> next = NULL; // The domain of next is null for now the list is null.

	return OK;
}


Status DestroyList(LinkList &L)
{
	// Initially condition:  linear list L existed already.
	// Operation result: Destroy it.

	LinkList q;
	while (L)
		{
			q = L -> next;
			free(L);
			L = q;
		}

	return OK;	
}


Status ListInsert(LinkList L, int i, ElemType e)
{
	// Inserting a node before i'th element of a link list with head node.
	int j = 0;
	LinkList p = L, s;
	while(p && j < i - 1) // seek (i-1)'th  node.
		{
			p = p -> next;
			j++;
		}

	if (!p || j > i - 1) // i is lower than 1 or larger than length of list.
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode)); // generate new node.

	s -> data = e;
	s -> next = p -> next;
	p ->next = s;
	
	return OK;
}


Status ListTraverse(LinkList L, void(*vi) (ElemType))
{
	//  the parametric of this function is ELemType that is different from ElemType& in bo2-1.cpp.
	// Initally condition: the linear list existed alredy.
	// Operation result: Calling vi() function for each element in L, operation failed once vi() is failed.

	LinkList p = L -> next;
	while(p)
		{
			vi(p -> data);
			p = p -> next;
		}

	printf("\n");

	return OK;		
}


Status GetElem(LinkList L, int i, ElemType &e)
{
	// L is the link list with head node. Assign its value to e when i'th element existed and return OK, otherwise ERROR.
	int j = 1; // j is a counter.
	LinkList p = L -> next; // p point to the first node.
	
	while (p && j < i) // seek afterward, until p is pointing to i'th element or null.
		{
			p = p -> next;
			j++;
		}

	if (!p || j > i) // there is't i'th element.
		return ERROR;

	e = p -> data; // get the i'th element.
	return OK;
}


int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	// Initally condition: linear list L existed, compare() is the function used for judge element, 1 if satisfy, 0 otherewise.
	// Operation result: Producing the order of element in L which is the first one satisfy compare() function with e, return 0 if there is no such element.
	int i = 0;
	LinkList p = L -> next;
	while(p)
		{
			i++;
			if (compare(p -> data, e))
				return i;

			p = p -> next;
		}

	return 0;
}


Status ListEmpty(LinkList L)
{
	// Initially condition: linear list L existed already.
	// Operation result: return TRUE, if L is empty, FALSE otherwise.
	if (L -> next) // nonull
		return FALSE;
	else
		return TRUE;
}
