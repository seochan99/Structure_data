//
//  AVLRebalance.c
//  AVLTree
//
//  Created by 서희찬 on 2021/04/21.
//
#include <stdio.h>
#include "BinaryTree3.h"

BTreeNode * RotateLL(BTreeNode *bst)
{
    BTreeNode * pNode; // parent node
    BTreeNode * cNode; // child Node
    
    // pNode, cNode 가리키기
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    // real LL rotate
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    
    //LL회전으로 cNode가 루트 노드가 됨! 그러므로 변경된 루트노드 주소값 반환
    return cNode;
}

BTreeNode * RotateRR(BTreeNode *bst)
{
    BTreeNode * pNode; // parent node
    BTreeNode * cNode; // child Node
    
    // pNode, cNode 가리키기
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    // real RR rotate
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    
    //RR회전으로 cNode가 루트 노드가 됨! 그러므로 변경된 루트노드 주소값 반환
    return cNode;
}

BTreeNode * RotateLR(BTreeNode*bst) // LR회전을 담당하는 함수
{
    BTreeNode * pNode; // parent Node
    BTreeNode * cNode; // child Node
    
    //pNode, cNode 가 LR회전을 위해 적절한 위치를 가리키게한다.
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    //실제 LR회전을 담당하는 두 개의 문장
    ChangeLeftSubTree(pNode, RotateRR(cNode)); // 부분적 RR회전
    return RotateLL(pNode); // LL회전
}

BTreeNode * RotateRL(BTreeNode*bst) // LR회전을 담당하는 함수
{
    BTreeNode * pNode; // parent Node
    BTreeNode * cNode; // child Node
    
    //pNode, cNode 가 RL회전을 위해 적절한 위치를 가리키게한다.
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    //실제 RL회전을 담당하는 두 개의 문장
    ChangeRightSubTree(pNode, RotateLL(cNode)); // 부분적 LL회전
    return RotateRR(pNode); // LL회전
}

int GetHeight(BTreeNode * bst)
{
    int leftH; // left Height
    int rightH; // right Height
    
    if(bst == NULL)
        return 0;
    
    leftH = GetHeight(GetLeftSubTree(bst)); // 왼쪽 서브 트리 높이 계산
    rightH = GetHeight(GetRightSubTree(bst)); // 오른쪽 서브 트리 높이 계산
    
    // 큰 값의 높이를 반환한다.
    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

//두 서브 트리의 '높이의 차'를 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh; // left sub tree Height
    int rsh; // right sub tree height
    
    if(bst == NULL)
        return 0;
    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode **pRoot)
{
    int hDiff = GetHeightDiff(*pRoot); // 균형 인수 계산
    
    //균형 인수가 +2 이상이면 LL/LR 상태이다.
    if(hDiff>1) // +2이상이면(왼쪽 서브 트리 방향으로 높이가 2 이상 크다면)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot))>0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    //균형 인수가 -2 이하이면 RR/RL 상태이다.
    if(hDiff<-1) // 오른쪽 서브 트리 방향으로 2 이상 크다면,
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot))<0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    
    return *pRoot;
}
