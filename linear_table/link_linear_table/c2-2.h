/*
  this file define structure of linear table of link form.
 */

typedef struct LNode // the type of node.
{
  ElemType data;
  struct LNode *next;
}*Link, *Position;


typedef struct // the type of link list
{
  Link head, tail; // point to head node and the last node, respectively.
  int len;
}LinkList;




