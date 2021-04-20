#include <stdio.h>
#include "BinaryTree3.h"    
#include "BinarySearchTree3.h"

int main(void)
{
    BTreeNode * avlRoot;
    BTreeNode * clNode;        // current left node
    BTreeNode * crNode;        // current right node
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

    printf("∑Á∆Æ ≥ÎµÂ: %d \n", GetData(avlRoot));

    clNode = GetLeftSubTree(avlRoot);
    crNode = GetRightSubTree(avlRoot);
    printf("øﬁ¬ 1: %d, ø¿∏•¬ 1: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("øﬁ¬ 2: %d, ø¿∏•¬ 2: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("øﬁ¬ 3: %d, ø¿∏•¬ 3: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("øﬁ¬ 4: %d, ø¿∏•¬ 4: %d \n", GetData(clNode), GetData(crNode));
    return 0;
}
