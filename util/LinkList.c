#include "LinkList.h"

int createLinkList(LinkList **linkList/**out**/) {
  int ret = 0;
  LinkList *head = NULL;
  if (linkList == NULL) {
    ret = -1;
    goto END;
  }

  head = (LinkList *) malloc(sizeof(LinkList));
  if (head == NULL) {
    ret = -2;
    goto END;
  }

  head->next = NULL;
  *linkList = head;
END:
  return ret;
}

int appendLinkList(LinkList *linkList, LinkListNode *listNode) {
  int ret = 0;
  if (linkList == NULL || listNode == NULL) {
    ret = -1;
    goto END;
  }

  LinkList *tmpList = linkList;
  while (tmpList->next) {
    tmpList = tmpList->next;
  }

  tmpList->next = (Node *)listNode;
  ((Node *)listNode)->next = NULL;
END:
  return ret;
}

int getLinkListLength(LinkList *linkList, int *length) {
  int ret = 0;
  int tmpLength = 0;
  if (linkList == NULL) {
    ret = -1;
    goto END;
  }

  LinkList *tmpList = linkList;
  while (tmpList->next) {
    tmpLength ++;
  }

  *length = tmpLength;
END:
  return ret;
}

int getNodeByIndex(LinkList *linkList, int index, LinkListNode **listNode/**out**/) {
  int ret = -2;
  int tmpInd = 0;
  if (linkList == NULL || listNode == NULL) {
    ret = -1;
    goto END;
  }

  LinkList *tmpList = linkList;
  Node *tmpNode = NULL;
  do {
    tmpNode = (Node *)tmpList->next;
    if (tmpInd == appendIndex) {
      if (tmpNode) {
        *listNode = (LinkListNode *)tmpNode;
        ret = 0;
      }
      break;
    }
    tmpInd++;
  } while (tmpNode)
END:
  return ret;
}

int insertLinkListNode(LinkList *linkList, LinkListNode *listNode, int appendIndex) {
  int ret = -2;
  int tmpInd = 0;
  if (linkList == NULL || listNode == NULL) {
    ret = -1;
    goto END;
  }

  LinkList *tmpList = linkList;
  Node *tmpNode = NULL;
  do {
    tmpNode = (Node *)tmpList->next;
    if (tmpInd == appendIndex) {
      tmpList->next = (Node *)listNode;
      ((Node *)listNode)->next = tmpNode;
      ret = 0;
      break;
    }
    tmpInd++;
  } while (tmpNode)
END:
  return ret;
}

int removeLinkListNode(LinkList *linkList, LinkListNode **listNode/**out**/, int delIndex) {
  int ret = -2;
  int tmpInd = 0;
  if (linkList == NULL || listNode == NULL) {
    ret = -1;
    goto END;
  }

  LinkList *tmpList = linkList;
  Node *tmpNode = (Node *)tmpList->next;
  Node *tmpPre = NULL;
  while (tmpNode) {
    if (tmpInd == appendIndex) {
      if (tmpPre) {
        tmpPre->next = tmpNode->next;
        tmpNode->next = NULL;
        *listNode = (LinkListNode *)tmpNode;
        ret = 0;
      }
      break;
    }
    tmpPre = tmpNode;
    tmpNode = tmpNode->next;
    tmpInd++;
  }
END:
  return ret;
}

int removeAllLinkListNode(LinkList *linkList) {
  int ret = 0;
  int tmpLength = 0;
  if (linkList == NULL) {
    ret = -1;
    goto END;
  }



END:
  return ret;
}

int destroyLinkList(LinkList **linkList) {
  int ret = 0;
  if (linkList == NULL) {
    ret = -1;
    goto END;
  }

  free(*linkList);
  *linkList = NULL;
END:
  return ret;
}
