#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct _employee {
  char name[32];
  unsigned char age;
} Employee;

void displayEmployee(Employee *employee) {
  printf("%s\t%d\n", employee->name, employee->age);
}

int compareEmployee(Employee *e1, Employee *e2) {
  return strcmp(e1->name, e2->name);
}

typedef void (*DISPLAY)(void *);

typedef int (*COMPARE)(void *, void *);

typedef struct _node {
  void *data;
  struct _node *next;
} Node;

typedef struct _linkedList {
  Node *head;
  Node *tail;
  Node *current;
} LinkedList;

void initializeList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
}

void addHead(LinkedList *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void addTail(LinkedList *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

Node *getNode(LinkedList *list, COMPARE compare, void *data) {
  Node *node = list->head;

  while (node != NULL) {
    if (compare(node->data, data) == 0) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

void delete (LinkedList *list, Node *node) {
  if (node == list->head) {
    if (list->head->next == NULL) {
      list->head = list->tail = NULL;
    } else {
      list->head = list->head->next;
    }
  } else {
    Node *tmp = list->head;
    while (tmp != NULL && tmp->next != node) {
      tmp = tmp->next;
    }

    if (tmp != NULL) {
      tmp->next = node->next;
    }

    tmp->next = node->next;
    if (node == list->tail) {
      list->tail = tmp;
    }
  }
  free(node);
}

void displayLinkedList(LinkedList *list, DISPLAY display) {
  printf("\nLinked List\n");
  Node *current = list->head;
  while (current != NULL) {
    display(current->data);
    current = current->next;
  }
}
void linkedListfunc() {
  LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));

  Employee *samuel = (Employee *)malloc(sizeof(Employee));
  strcpy(samuel->name, "Samuel");
  samuel->age = 32;

  Employee *sally = (Employee *)malloc(sizeof(Employee));
  strcpy(sally->name, "Sally");
  sally->age = 28;

  Employee *susan = (Employee *)malloc(sizeof(Employee));
  strcpy(susan->name, "Susan");
  susan->age = 45;

  initializeList(linkedList);

  addHead(linkedList, samuel);
  addHead(linkedList, sally);
  addHead(linkedList, susan);

  /* Node *node = */
  /*     getNode(linkedList, (int (*)(void *, void *))compareEmployee, sally);
   */

  /* delete (linkedList, node); */

  displayLinkedList(linkedList, (DISPLAY)displayEmployee);
}

typedef LinkedList Queue;

void initializeQueue(Queue *queue) { initializeList(queue); }

void enqueue(Queue *queue, void *node) { addHead(queue, node); }

void *dequeue(Queue *queue) {
  Node *tmp = queue->head;
  void *data;
  if (queue->head == NULL) {
    data = NULL;
  } else if (queue->head == queue->tail) {
    queue->head = queue->tail = NULL;
    data = tmp->data;
    free(tmp);
  } else {
    while (tmp->next != queue->tail) {
      tmp = tmp->next;
    }
    queue->tail = tmp;
    tmp = tmp->next;
    queue->tail->next = NULL;
    data = tmp->data;
    free(tmp);
  }
  return data;
}

void queuefunc() {
  Employee *samuel = (Employee *)malloc(sizeof(Employee));
  strcpy(samuel->name, "Samuel");
  samuel->age = 32;

  Employee *sally = (Employee *)malloc(sizeof(Employee));
  strcpy(sally->name, "Sally");
  sally->age = 28;

  Employee *susan = (Employee *)malloc(sizeof(Employee));
  strcpy(susan->name, "Susan");
  susan->age = 45;

  Queue *queue = (Queue *)malloc(sizeof(Queue));
  initializeQueue(queue);

  enqueue(queue, samuel);
  enqueue(queue, sally);
  enqueue(queue, susan);

  void *data = dequeue(queue);

  printf("Dequeued %s\n", ((Employee *)data)->name);

  data = dequeue(queue);

  printf("Dequeued %s\n", ((Employee *)data)->name);

  data = dequeue(queue);

  printf("Dequeued %s\n", ((Employee *)data)->name);
}

typedef LinkedList Stack;

void initializeStack(Stack *stack) { initializeList(stack); }

void push(Stack *stack, void *data) { addHead(stack, data); }

void *pop(Stack *stack) {
  Node *node = stack->head;
  if (node == NULL) {
    return NULL;
  } else if (node == stack->tail) {
    stack->head = stack->tail = NULL;
    void *data = node->data;
    free(node);
    return data;
  } else {
    stack->head = stack->head->next;
    void *data = node->data;
    free(node);
    return data;
  }
}

void stackfunc() {
  Employee *samuel = (Employee *)malloc(sizeof(Employee));
  strcpy(samuel->name, "Samuel");
  samuel->age = 32;

  Employee *sally = (Employee *)malloc(sizeof(Employee));
  strcpy(sally->name, "Sally");
  sally->age = 28;

  Employee *susan = (Employee *)malloc(sizeof(Employee));
  strcpy(susan->name, "Susan");
  susan->age = 45;

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  initializeStack(stack);

  push(stack, samuel);
  push(stack, sally);
  push(stack, susan);

  Employee *employee;

  for (int i = 0; i < 4; i++) {
    employee = (Employee *)pop(stack);
    printf("Popped %s\n", employee->name);
  }
}

typedef struct _tree {
  void *data;
  struct _tree *left;
  struct _tree *right;
} TreeNode;

void insertNode(TreeNode **realRoot, COMPARE compare, void *data) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  TreeNode *root = *realRoot;

  if (root == NULL) {
    *realRoot = node;
    return;
  }

  while (1) {
    if (compare((root)->data, data) > 0) {
      if ((root)->left != NULL) {
        root = (root)->left;
      } else {
        (root)->left = node;
        break;
      }
    } else {
      if ((root->right) != NULL) {
        root = (root)->right;
      } else {
        (root)->right = node;
        break;
      }
    }
  }
}

void inOrder(TreeNode *root, DISPLAY display) {
  if (root != NULL) {
    inOrder(root->left, display);
    display(root->data);
    inOrder(root->right, display);
  }
}

void postOrder(TreeNode *root, DISPLAY display) {
  if (root != NULL) {
    postOrder(root->left, display);
    postOrder(root->right, display);
    display(root->data);
  }
}

void preOrder(TreeNode *root, DISPLAY display) {
  if (root != NULL) {
    display(root->data);
    postOrder(root->left, display);
    postOrder(root->right, display);
  }
}

void nodefunc() {
  Employee *samuel = (Employee *)malloc(sizeof(Employee));
  strcpy(samuel->name, "Samuel");
  samuel->age = 32;

  Employee *sally = (Employee *)malloc(sizeof(Employee));
  strcpy(sally->name, "Sally");
  sally->age = 28;

  Employee *susan = (Employee *)malloc(sizeof(Employee));
  strcpy(susan->name, "Susan");
  susan->age = 45;

  TreeNode *tree = NULL;

  insertNode(&tree, (COMPARE)compareEmployee, samuel);
  insertNode(&tree, (COMPARE)compareEmployee, sally);
  insertNode(&tree, (COMPARE)compareEmployee, susan);

  printf("preOrder-----------\n");
  preOrder(tree, (DISPLAY)displayEmployee);

  printf("inOrder------------\n");
  inOrder(tree, (DISPLAY)displayEmployee);

  printf("postOrder-----------\n");
  postOrder(tree, (DISPLAY)displayEmployee);
}

int main() {
  /* linkedListfunc(); */
  /* queuefunc(); */
  /* stackfunc(); */
  nodefunc();

  return 0;
}
