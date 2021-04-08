//
//  main.c
//  BinaryTree
//


#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    BTreeNode * bt1 = MakeBTreeNode(); // 노드 1 생성
    BTreeNode * bt2 = MakeBTreeNode(); // 노드 2 생성
    BTreeNode * bt3 = MakeBTreeNode(); // 노드 3 생성
    BTreeNode * bt4 = MakeBTreeNode(); // 노드 4 생성
    BTreeNode * bt5 = MakeBTreeNode(); // 노드 5 생성
    BTreeNode * bt6 = MakeBTreeNode(); // 노드 6 생성

    
    
    SetData(bt1, 1); //bt1 에 1 저장
    SetData(bt2, 2); //bt2 에 2 저장
    SetData(bt3, 3); //bt3 에 3 저장
    SetData(bt4, 4); //bt4 에 4 저장
    SetData(bt5, 5); //bt4 에 5 저장
    SetData(bt6, 6); //bt4 에 6 저장
    
    MakeLeftSubTree(bt1, bt2); // bt2를 bt1의 왼쪽 자식 노드로
    MakeRightSubTree(bt1, bt3); // bt3를 bt1의 오른쪽 자식 노드로
    MakeLeftSubTree(bt2, bt4); // bt4를 bt2의 왼쪽 자식 노드로
    MakeRightSubTree(bt2, bt5); // bt5를 bt2의 오른쪽 자식 노드로
    MakeRightSubTree(bt3, bt6);
    
    DeleteTree(bt1); //bt1 이 가리키는 노드를 루트노드로 모두 소멸 ! 
    
}
