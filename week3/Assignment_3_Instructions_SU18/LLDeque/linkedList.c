#include "linkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Double link
struct Link {
  TYPE value;
  struct Link *next;
  struct Link *prev;
};

// Double linked list with front and back sentinels
struct LinkedList {
  int size;
  struct Link *frontSentinel;
  struct Link *backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  list->size = 0;
  list->frontSentinel = (struct Link *)malloc(sizeof(struct Link));
  list->backSentinel = (struct Link *)malloc(sizeof(struct Link));
  assert(list->frontSentinel != 0);
  assert(list->backSentinel != 0);
  list->frontSentinel->next = list->backSentinel;
  list->frontSentinel->prev = 0;
  list->backSentinel->prev = list->frontSentinel;
  list->backSentinel->next = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList *list, struct Link *link,
                          TYPE value) {
  // FIXME: you must write this
  assert(list != 0);
  assert(link != 0);
  struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
  newLink->next = link;
  newLink->prev = link->prev;
  newLink->value = value;
  link->prev->next = newLink;
  link->prev = newLink;
  list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList *list, struct Link *link) {
  // FIXME: you must write this
  assert(list != 0);
  assert(link != 0);
  link->prev->next = link->next;
  link->next->prev = link->prev;
  link->prev = link->next = 0; // set these to null
  free(link);
  list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList *linkedListCreate() {
  struct LinkedList *newDeque = malloc(sizeof(struct LinkedList));
  init(newDeque);
  return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList *list) {
  while (!linkedListIsEmpty(list)) {
    linkedListRemoveFront(list);
  }
  free(list->frontSentinel);
  free(list->backSentinel);
  free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList *list, TYPE value) {
  // FIXME: you must write this
  assert(list != 0);
  addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList *list, TYPE value) {
  // FIXME: you must write this
  assert(list != 0);
  addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  assert(list->frontSentinel->next != list->backSentinel);
  return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  assert(list->backSentinel->prev != list->frontSentinel);
  return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  assert(list->frontSentinel->next != list->backSentinel);
  removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  assert(list->backSentinel->prev != list->frontSentinel);
  removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  if (list->size == 0)
    return 1;
  return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList *list) {
  // FIXME: you must write this
  assert(list != 0);
  struct Link *tmp;
  tmp = list->frontSentinel->next;
  while (tmp != list->backSentinel) {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList *list, TYPE value) {
  // FIXME: you must write this
  assert(list != 0);
  addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList *list, TYPE value) {
  // FIXME: you must write this
  assert(list != 0);
  struct Link *tmp;
  tmp = list->frontSentinel->next;
  while (tmp != list->backSentinel) {
    if (tmp->value == value)
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList *list, TYPE value) {
  // FIXME: you must write this
  struct Link *tmp;
  tmp = list->frontSentinel->next;
  while (tmp != list->backSentinel) {
    if (tmp->value == value) {
      removeLink(list, tmp);
      break;
    }
    tmp = tmp->next;
  }
}
