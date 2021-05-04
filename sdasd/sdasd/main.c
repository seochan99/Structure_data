#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0

typedef struct node {
    struct node* left;
    int win;
    int lose;
    struct node* right;
}Node;

typedef struct {
    Node* link;
}nodeHead;

nodeHead* createHead(void) {
    nodeHead* L;
    L = (nodeHead*)malloc(sizeof(nodeHead));
    L->link = NULL;
    return L;
}

void insertNode(nodeHead* head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->win = 0;
    newNode->lose = 0;
    newNode->right = NULL;

    if (head->link == NULL) {
        head->link = newNode;
        newNode->right = newNode;
        newNode->left = newNode;
    }
    else {
        Node* p;
        p = head->link;
        while (p->right != head->link) {
            p = p->right;
        }
        p->right = newNode;
        newNode->left = p;
        newNode->right = head->link;
        head->link->left = newNode;
    }
}

int countNode(nodeHead* head) {
    Node* L = head->link;
    if (L == NULL) {
        return 0;
    }
    int cnt = 1;
    while (L->right != head->link) {
        L = L->right;
        cnt++;
    }
    return cnt;
}

void printNode(nodeHead* head) {
    Node* L = head->link;
    if (L == NULL) {
        return;
    }
    while (L->right != head->link) {
        printf("<->node:win=%d,lose=%d", L->win, L->lose);
        L = L->right;
    }
    printf("\n");
}

void insertTwoNode(Node* computer_ptr) {
    Node*newNode1 = (Node*)malloc(sizeof(Node));
    Node*newNode2 = (Node*)malloc(sizeof(Node));
    newNode1->win = 0;
    newNode1->lose = 0;
    newNode2->win = 0;
    newNode2->lose = 0;

    newNode1->right = computer_ptr;
    computer_ptr->left->right = newNode1;
    newNode1->left = computer_ptr->left;
    computer_ptr->left = newNode1;
    
    newNode2->left = computer_ptr;
    computer_ptr->right->left = newNode2;
    newNode2->right = computer_ptr->right;
    computer_ptr->right = newNode2;
}

void deleteNode(Node* tmp) {
    tmp->left->right = tmp->right;
    tmp->right->left = tmp->left;
    free(tmp);
}

void gameWin(Node* computer_ptr) {
    computer_ptr->win = computer_ptr->win + 1;
    if (computer_ptr->win >= 2) {
        computer_ptr->win = 0;
        insertTwoNode(computer_ptr);
        computer_ptr = computer_ptr->left;
    }
}

void gameLose(Node* computer_ptr) {
    Node* tmp = computer_ptr;
    computer_ptr = computer_ptr->right;
    tmp->lose = tmp->lose + 1;
    if (tmp->lose >= 2) {
        deleteNode(tmp);
    }
}

int main(int argc, char* argv[]) {
    int a;
    a = atoi(argv[0]);
    nodeHead* head = createHead();
    Node* computer_ptr;
    
    for (int i = 0; i < a; i++) {
        insertNode(head);
    }
    
    computer_ptr = &head;

    while (true) {
        srand((unsigned)time(NULL));
        int num;
        int com_num = rand() % 3 + 1;
        printf("> 선택하세요 (1.가위, 2.바위, 3.보, 4.끝내기)?");
        scanf("%d", &num);
        
        if (num == 1) {
            if (com_num == 1) {
                printf("비겼습니다.\n");
                continue;
            }
            else if (com_num == 2) {
                printf("컴퓨터가 이겼습니다. 오른쪽 노드로 이동하겠습니다.\n");
                gameLose(computer_ptr);
                printf("총 노드 개수:%d\n",countNode(head));
                printNode(head);
            }
            else if (com_num == 3) {
                printf("컴퓨터가 졌습니다. 왼쪽 노드로 이동하겠습니다.\n");
                gameWin(computer_ptr);
                printf("총 노드 개수:%d\n", countNode(head));
                printNode(head);
            }
        }
        else if (num == 2) {
            if (com_num == 2) {
                printf("비겼습니다.\n");
                continue;
            }
            else if (com_num == 3) {
                printf("컴퓨터가 이겼습니다. 오른쪽 노드로 이동하겠습니다.\n");
                gameLose(computer_ptr);
                printf("총 노드 개수:%d\n", countNode(head));
                printNode(head);
            }
            else if (com_num == 1) {
                printf("컴퓨터가 졌습니다. 왼쪽 노드로 이동하겠습니다.\n");
                gameWin(computer_ptr);
                printf("총 노드 개수:%d\n", countNode(head));
                printNode(head);
            }
        }
        else if (num == 3) {
            if (com_num == 3) {
                printf("비겼습니다.\n");
                continue;
            }
            else if (com_num == 1) {
                printf("컴퓨터가 이겼습니다. 오른쪽 노드로 이동하겠습니다.\n");
                gameLose(computer_ptr);
                printf("총 노드 개수:%d\n", countNode(head));
                printNode(head);
            }
            else if (com_num == 2) {
                printf("컴퓨터가 졌습니다. 왼쪽 노드로 이동하겠습니다.\n");
                gameWin(computer_ptr);
                printf("총 노드 개수:%d\n", countNode(head));
                printNode(head);
            }
        }
        else if (num == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }
}
