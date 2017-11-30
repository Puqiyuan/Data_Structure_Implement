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
