/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

#define qt 11
struct vetor
{
	int x;
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */

};

vetor_t* vetor_cria(void)
{
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->x = 0;
	vet->n = 0;
	int cont;
    vet->baralho = (carta*)memo_aloca(qt*sizeof(carta));
    for(cont=0;cont<qt;cont++){
        vet->baralho[i]=NULL;
    }
	return vet;
}

void vetor_destroi(vetor_t* vet)
{
	memo_libera(vet->baralho);
	memo_libera(vet);
}

int vetor_numelem(vetor_t *vet)
{
	return vet->n;
}

void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
	int cont = (vet->n), j;

	if((vet->n+1)%50==0 && vet->x!=-1)
    {
        vet->baralho = (vetor_t*) memo_realoca(vet->baralho,((vet->n)+1+qt)*sizeof(carta));
        for(j=vet->n;j<vet->n+qt;j++)
        {
            vet->baralho[j]=NULL;
        }
	}
    while(cont>indice)
    {
        vet->baralho[cont] = vet->baralho[cont-1];
        cont--;
    }
	vet->n++;
	vet->baralho[indice] = c;
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
	carta cont = vet->baralho[indice];
    if(cont==NULL)
    {
        return NULL;
    }
    vet->x=-1;
    while(vet->baralho[indice]!=NULL)
    {
        vet->baralho[indice] = vet->baralho[indice+1];
        indice++;
    }
	vet->n--;
	return cont;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
	return vet->baralho[indice];
}

bool vetor_valido(vetor_t *vet)
{
	return true;
}
