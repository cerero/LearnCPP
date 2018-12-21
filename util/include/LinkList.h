#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void LinkListNode;

typedef struct Node {
  struct Node *next;
} Node;

typedef struct LinkList {
  Node *next;
} LinkList;

int createLinkList(LinkList **linkList/**out**/);
int appendLinkList(LinkList *linkList, LinkListNode *listNode);
int getLinkListLength(LinkList *linkList, int *length/**out**/);
int getNodeByIndex(LinkList *linkList, int index, LinkListNode **listNode/**out**/);
int insertLinkListNode(LinkList *linkList, LinkListNode *listNode, int appendIndex);
int removeLinkListNode(LinkList *linkList, LinkListNode **listNode/**out**/, int delIndex);
int removeAllLinkListNode(LinkList *linkList);
int destroyLinkList(LinkList **linkList);

#ifdef __cplusplus
}
#endif

#endif
