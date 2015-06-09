
#include <stdio.h>
#include <stdlib.h>
#include "memo.h"
#include "arv.h"

//criação da arv
arv_t* arv_cria(op_t op)
{
   arv_t* arv  = (arv_t*) memoaloca(sizeof(arv_t));
   arv->dir = NULL;
   arv->esq = NULL;
   arv->dado = op;
   return arv;
}
//fim da arv
void arv_destroi(arv_t* arbor)
{
    if(arbor != NULL)
    {
        arv_destroi(arbor->esq);
        arv_destroi(arbor->dir);
        memo_libera(arbor);
    }
}
//impressao pré-ordem (raiz, esquerda, e direita)
void arv_imprime_pre_ordem(arv_t* arbor)
{
    if(arbor == NULL)
        return;
    if(arbor->dado.tipo == OPERANDO)
        printf(" %.2f ", arbor->dado.u.operando);
    else
        printf(" %c ", arbor->dado.u.operador);
    arv_imprime_pre_ordem(arbor->esq);
    arv_imprime_pre_ordem(arbor->dir);
}

//impressao em-ordem (esquerda, raiz, direita)
void arv_imprime_em_ordem(arv_t* arbor)
{
    if(arbor == NULL)
        return;
    arv_imprime_em_ordem(arbor->esq);

    if(arbor->dado.tipo == OPERANDO)
        printf(" %.2f ", arbor->dado.u.operando);

    else
        printf(" %c ", arbor->dado.u.operador);
    arv_imprime_em_ordem(arbor->dir);
}

//impressao pós-ordem (esquerda, direia, raiz)
void arv_imprime_pos_ordem(arv_t* arbor) // esquerda - direita - raiz
{
    if(arbor == NULL)
        return;
    arv_imprime_pos_ordem(arbor->esq);
    arv_imprime_pos_ordem(arbor->dir);

    if(arbor->dado.tipo == OPERANDO)
        printf(" %.2f ", arbor->dado.u.operando);

    else
        printf(" %c ", arbor->dado.u.operador);
}

arv_t* arv_insere(arv_t* arv, op_t op)
{
    if(arv == NULL)
    {
        arv = (arv_t*) memo_aloca(sizeof(arv_t));
        arv->dado = op;
        arv->dir= arv->esq = NULL;
    }

    else if( op.u.operando < arv->dado.u.operando)
            arv->esq = arv_insere(arv->esq, op);

    else
           arv->dir = arv_insere(arv->dir, op);

    return arv;
}
