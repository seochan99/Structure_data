//
//  main.c
//  ExpressionTree
//
//  Created by 서희찬 on 2021/04/08.
//

#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("전위: ");
    ShowPrefixTypeExp(eTree); printf("\n");

    printf("중위: ");
    ShowInfixTypeExp(eTree); printf("\n");

    printf("후위: ");
    ShowPostfixTypeExp(eTree); printf("\n");

    printf("연산결과˙: %d \n", EvaluateExpTree(eTree));

    return 0;
}

