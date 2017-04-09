/*
  this file define some basic operations that all c files will need
 */

void vi(ElemType *e) 
{// now that we say Elem Type is also a char type, so this function is for output char.
  printf("%c ", *e);
}


Status compare(ElemType e1, ElemType e2)
{
  if (e1 == e2)
    return 1;
  else
    return 0;
}


void vi_int(ElemType *e)
{
  printf("%d ", *e);
}
