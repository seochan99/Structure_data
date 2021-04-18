//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by 서희찬 on 2021/04/17.
//
#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL; //parent Node
    BTreeNode * cNode = *pRoot; // Current Node
    BTreeNode * nNode = NULL; // New Node
    
    // 새노드 저장될 위치 찾는다.
    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return; // 데이터 중복 허용 x
        
        pNode = cNode; // 매번 while 문을 돌때마다 초기화가 된다.
        
        if(GetData(cNode)>data)
        {
            cNode = GetLeftSubTree(cNode);
        }
        else
            cNode = GetRightSubTree(cNode);
    
    }
    
    //pNode의 자식 노드로 추가할 새 노드의 생성
    nNode = MakeBTreeNode(); // 새 노드 생성
    SetData(nNode, data);
    
    // pNode 의 자식 노드로 추가할 새 노드의 생성
    if(pNode != NULL) // 새  노드가 루트노드아니라면
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else{ //새노드가 루트노라면
        *pRoot = nNode;
    }
    

}

BTreeNode *BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst; // current Node
    BSTData cd; // current Data
    
    while(cNode != NULL)
    {
        cd = GetData(cNode);
        
        if(target == cd)
            return cNode;
        else if(target<cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    return NULL;
}
