#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void * LinkListNode;

typedef struct Node {
  Node *next;
} Node;

typedef struct LinkList {
  Node headNode;
} LinkList;

int createLinkList(LinkList **linkList);
int appendLinkList(LinkList **linkList, LinkListNode node);

#ifdef __cplusplus
}
#endif

#endif
