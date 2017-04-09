/*
  this file define some base operations of linear table, such as insert, delete.
 */


Status InitList(SqList *L)
{// construct a empty linear table L.
  
  (*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));

  if(!(*L).elem)
    exit(OVERFLOW);

  (*L).length = 0;
  (*L).listsize = LIST_INIT_SIZE;

  return OK;
}


Status DestroyList(SqList *L)
{
  // initial condition: the linear table existed.
  // operation result: destroy linear table.
  
  free((*L).elem);
  (*L).elem = NULL;
  (*L).length = 0;
  (*L).listsize = 0;
  
  return OK;
}


Status ClearList(SqList *L)
{
  // initial condition: the linear table existed.
  // operation result: set the the liner table to empty.
  
  (*L).length = 0;

  return OK;
}


Status ListEmpty(SqList L)
{
  // initial condition: the linear table existed.
  // operation result: if the linear table is empty, return TRUE, else FALSE.
  
  if (L.length == 0)
    return TRUE;

  else
    return FALSE;
}


Status ListLength(SqList L)
{
  // initial condition: the linear table is existed.
  // operation result: return the number of elements of linear table.
  
  return L.length;
}


Status GetElem(SqList L, int i, ElemType *e)
{
  // initial condition: the linear table is existed, 1 <= i <= ListLength(L).
  // operation result: return i'th element of L in e.
  
  if (i < 1 || i > L.length)
    exit(ERROR);

  *e = *(L.elem + i - 1);

  return OK;
}


int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
  // initial condition: the linear table is existed, the compare function is judge function.
  // operation result: return the order of the element that the first satisfy the compare function
  // if that does not exist, return 0.
  
  ElemType *p;

  int i = 1;
  p = L.elem;

  while(i <= L.length && !compare(*p++, e))
    ++i;

  if (i <= L.length)
    return i;

  else
    return 0;
}


Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
  // initial condition: the linear table is existed.
  // operation result: if cur_e is belong of L and is not the first one, return it's
  // precursor in pre_e, otherwise pre_e is undefined.
  
  int i = 2;

  ElemType *p = L.elem + 1;
  
  while (i <= L.length && *p != cur_e)
    {
      p++;
      i++;
    }

  if (i > L.length)
    return INFEASIBLE;

  else
    {
      *pre_e = *--p;
      return OK;
    }
}


Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
  // initial condition: the linear table is existed.
  // operation result: if cur_e is the element belong as L and is not the last one, return it's
  // successor in next_e, otherwise next_e is undefined.
  
  int i = 0;

  ElemType *p = L.elem;

  while(i <= L.length - 2 && *p != cur_e)
    {
      i++;
      p++;
    }


  if (i == L.length - 1)
    return INFEASIBLE;

  else
    {
      *next_e = *++p;
      return OK;
      }
}


Status ListInsert(SqList *L, int i, ElemType e)
{
  // initial condition: the linear table is existed.
  // operation result: insert the e before i'th element, the length of L increment by 1.
  
  ElemType *newbase, *q, *p;

  if (i < 1 || i > (*L).length + 1)
    return ERROR;

  if ((*L).length >= (*L).listsize)
    {
      newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));

      if (!newbase)
	exit(OVERFLOW);

      (*L).elem = newbase;

      (*L).listsize += LISTINCREMENT;
    }

  q = (*L).elem + i - 1;

  for (p = (*L).elem + (*L).length - 1; p >= q; --p)
    *(p + 1) = *p;

  *q = e;
  ++(*L).length;

  return OK;
}


Status ListDelete(SqList *L, int i, ElemType *e)
{
  // initial condition: the linear table is existed and is not empty, 1 <= i <= ListLength(L).
  // operation result: delete the i'th element of L, and return it's value in e, decrease the
  // length by 1.
  
  ElemType *p, *q;

  if (i < 1 || i > (*L). length)
    return ERROR;

  p = (*L).elem + i - 1;
  *e = *p;
  q = (*L).elem + (*L).length - 1;
  
  for (++p; p <= q; ++p)
    *(p - 1) = *p;

  (*L).length--;

  return OK;
}


Status ListTraverse(SqList L, void (*vi)(ElemType*))
{
  // initial condition: the linear table is existed.
  // operation result: call vi function for each element in linear table, once vi is failure,
  // the operation is failure.
  
  ElemType *p;
  int i;

  p = L.elem;

  for (i = 1; i <= L.length; i++)
    vi(p++);
  
  printf("\n");

  return OK;
}
