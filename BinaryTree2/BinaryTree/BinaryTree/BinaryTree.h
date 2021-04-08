//
//  BinaryTree.h
//  BinaryTree

#ifndef BinaryTree_h
#define BinaryTree_h

typedef int BTData;

typedef struct _bTreeNode // 이진 트리의 노드를 표현한 구조체이다.
{
    BTData data; // 가지고 있는 데이터
    struct _bTreeNode * left; // 왼쪽 빈칸
    struct _bTreeNode * right; // 오른쪽 빈칸
} BTreeNode; // 타입뎊!

BTreeNode * MakeBTreeNode(void); // 노드의 생성
BTData GetData(BTreeNode * bt); // 노드에 저장된 데이터 반환
void SetData(BTreeNode * bt, BTData data); // 노드에 데이터 저장

BTreeNode * GetLeftSubTree(BTreeNode * bt); // 왼쪽 서브 트리 주소 값 반환
BTreeNode * GetRightSubTree(BTreeNode * bt); // 오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub); //Main노드가 왼쪽 자식 노드로 sub노드 연결
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub); //Main노드가 오른쪽 자식 노드로 sub노드 연결

typedef void (VisitFuncPtr)(BTData data); // 포인터 함수 

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void DeleteTree(BTreeNode * bt);

#endif /* BinaryTree_h */
