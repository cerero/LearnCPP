#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int createLinkList(LinkList **linkList/**out**/);
// int appendLinkList(LinkList *linkList, LinkListNode *listNode);
// int getLinkListLength(LinkList *linkList, int *length/**out**/);
// int getNodeByIndex(LinkList *linkList, int index, LinkListNode **listNode/**out**/);
// int insertLinkListNode(LinkList *linkList, LinkListNode *listNode, int appendIndex);
// int removeLinkListNode(LinkList *linkList, LinkListNode **listNode/**out**/, int delIndex);
// int removeAllLinkListNode(LinkList *linkList);
// int destroyLinkList(LinkList **linkList);
typedef struct Box {
  Node node;
  int size;
} Box;

int appendBoxList(LinkList *list, Box *box, int length) {
  int ret = 0;
  if (list == NULL || box == NULL) {
    ret = -1;
    return ret;
  }
  for (int i = 0; i < length; i++) {
    ret = appendLinkList(list, (LinkListNode *)(box + i));
    if (ret != 0) {
      printf("call appendLinkList error:%d\n", ret);
      return ret;
    }
  }

  return ret;
}

int printBoxList(LinkList *list) {
  int length = 0;
  int ret = 0;
  ret = getLinkListLength(list, &length);
  if (ret != 0) {
    printf("call getLinkListLength error:%d\n", ret);
    return ret;
  }

  Box *tmpBox = NULL;
  for (int i = 0; i < length; i++) {
    ret = getNodeByIndex(list, i, (LinkListNode **)&tmpBox);
    if (ret != 0) {
      printf("call getNodeByIndex error:%d, index:%d\n", ret, i);
      return ret;
    }
    printf("ind:%d  size:%d\n", i, tmpBox->size);
  }

  return ret;
}

int main() {
  int ret = 0;
  Box boxes[5];
  boxes[0].size = 1;
  boxes[1].size = 2;
  boxes[2].size = 3;
  boxes[3].size = 4;
  boxes[4].size = 5;

  LinkList *list = NULL;
  ret = createLinkList(&list);
  if (ret != 0) {
    printf("call createLinkList error:%d\n", ret);
    return ret;
  }

  ret = appendBoxList(list, boxes, 5);
  if (ret != 0) {
    printf("call appendBoxList error:%d\n", ret);
    return ret;
  }

  printBoxList(list);

  Box box10;
  box10.size = 10;
  int insertInd = 5;
  ret = insertLinkListNode(list, (LinkListNode *)&box10, insertInd);
  if (ret != 0) {
    printf("call insertLinkListNode error:%d\n insertInd:%d", ret, insertInd);
    return ret;
  }

  printf("after insert at %d\n", insertInd);
  printBoxList(list);

  Box *delBox = NULL;
  int delInd = 2;
  ret = removeLinkListNode(list, (LinkListNode *)&delBox, delInd);
  if (ret != 0) {
    printf("call removeLinkListNode error:%d\n delInd:%d", ret, delInd);
    return ret;
  }

  printf("after remove at %d, box.size=%d\n", delInd, delBox->size);
  printBoxList(list);

  return ret;
}
