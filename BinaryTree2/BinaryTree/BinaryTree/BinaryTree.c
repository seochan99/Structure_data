//
//  BinaryTree.c
//  BinaryTree
//
//
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode *)malloc(sizeof(BTreeNode)); //nd 노드 동적할당
    nd->left = NULL;
    nd ->right = NULL; //왼쪽 오른쪽 Null 가리키게한다.
    return nd;
}

BTData GetData(BTreeNode * bt)
{
    return bt->data; //bt에 저장된 data 값을 반환해서 보여준다
}

void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data; //bt의 data값을 전달받은 data로 넣는다.
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left; // 왼쪽 서브 트리 주소 값 반환
}

BTreeNode * GetRighttSubTree(BTreeNode * bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != NULL)
        free(main->left); // 만약 main의 left가 이미 차져있다면 그 쪽 데이터를 지운다 !
    
    main->left = sub; // sub로 넣는다 !
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != NULL)
        free(main->right); // 만약 main의 left가 이미 차져있다면 그 쪽 데이터를 지운다 !
    
    main->right = sub; // sub로 넣는다 !
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action) //전위 함수
{
    if(bt ==NULL)
        return; // 탈출 ~!
    
    action(bt->data); // 루트 노드 방문
    InorderTraverse(bt -> left,action); // 왼쪽 서브트리 순회
    InorderTraverse(bt -> right, action); // 오른쪽 서브트리 순회
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt ==NULL)
        return; // 탈출 ~!
    
    InorderTraverse(bt -> left, action); // 왼쪽 서브트리 순회
    InorderTraverse(bt -> right, action); // 오른쪽 서브트리 순회
    action(bt->data); // 루트 노드 방문
}

void InorderTraverse(BTreeNode * bt,VisitFuncPtr action)
{
    if(bt ==NULL)
        return; // 탈출 ~!
    
    InorderTraverse(bt -> left, action); // 왼쪽 서브트리 순회
    action(bt->data); // 루트 노드 방문
    InorderTraverse(bt -> right, action); // 오른쪽 서브트리 순회
}

void DeleteTree(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    
    printf("del tree data: %d\n",bt->data);
    free(bt);
}
