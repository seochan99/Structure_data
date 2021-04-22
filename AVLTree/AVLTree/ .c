#include <stdio.h>
#include "BinaryTree3.h" // 트리구조 확인을 위해
#include "BinarySearchTree3.h"

int main(void)
{
    BTreeNode * avlRoot;
    BTreeNode * clNode; // current left Node
    BTreeNode * crNode; // current right Node
    
    BTreeNode * clNode2;
    BTreeNode * crNode2;

    BTreeNode * clNode3;
    BTreeNode * crNode3;
    
    BSTMakeAndInit(&avlRoot);
    
    BSTInsert(&avlRoot, 1);
    BSTInsert(&avlRoot, 2);
    BSTInsert(&avlRoot, 3);
    BSTInsert(&avlRoot, 4);
    BSTInsert(&avlRoot, 5);
    BSTInsert(&avlRoot, 6);
    BSTInsert(&avlRoot, 7);
    BSTInsert(&avlRoot, 8);
    BSTInsert(&avlRoot, 9);
    
    printf("루트 노드 : %d \n",GetData(avlRoot)); //4
    
    clNode = GetLeftSubTree(avlRoot); // 2
    crNode = GetRightSubTree(avlRoot); // 6
    printf("왼쪽 1 : %d, 오른쪽 1 : %d \n",GetData(clNode),GetData(crNode));
    
    clNode2 = GetLeftSubTree(clNode); // 1, 2의 왼쪽 노드
    crNode2 = GetRightSubTree(clNode);// 3, 2의 오른쪽 노드
    printf("왼쪽 1-1 : %d, 왼쪽 1-2 : %d \n",GetData(clNode2),GetData(crNode2));
    
    clNode2 = GetLeftSubTree(crNode); // 5, 6의 왼쪽 노드
    crNode2 = GetRightSubTree(crNode); // 8, 6의 오른쪽 노드
    printf("오른쪽 1-1 : %d, 오른쪽 1-2 : %d \n",GetData(clNode2),GetData(crNode2));
    
    clNode3 = GetLeftSubTree(crNode2); //7, 8의 왼쪽 노드
    crNode3 = GetRightSubTree(crNode2); // 9, 8의 오른쪽 노드
    printf("오른쪽 1-2-1 : %d, 오른쪽 1-2-2 : %d \n",GetData(clNode3),GetData(crNode3));
    
    return 0;
}
