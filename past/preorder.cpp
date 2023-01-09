#include <stdio.h>
#include <stdlib.h>
typedef struct BTNode{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}*BiTree;

void PreOrderPrintLeaf(BiTree p) {
    if(p == NULL) {
        return;
    }
    putchar(p->data);
    PreOrderPrintLeaf(p->lchild);
    PreOrderPrintLeaf(p->rchild);
}
void createBiTree(BiTree *t) {
    char s;
    BiTree q;
    s = getchar();
    getchar();
    if(s == '#'){
        *t = NULL;
        return;
    }
    q = (BiTree)malloc(sizeof(struct BTNode));
    if(q == NULL) {
        return;
    }
    q->data = s;
    *t = q;
    createBiTree(&q->lchild);
    createBiTree(&q->rchild);
}
int main(){
    BiTree  t = NULL;
    createBiTree(&t);
    PreOrderPrintLeaf(t);
    return 0;
}