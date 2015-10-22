#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct Element
{
	int val;
	struct Element* nxt;
}Element;

typedef Element* Liste;

Liste vide()
{
	return(NULL);
}

int testvide(Liste l)
{
	if(l == NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void affiche(Liste l)
{
	printf("\n");
	while (l != NULL)
	{
		printf(" - %d \n", l->val);
		l = l->nxt;
	}
	printf("\n");
}

Liste ajoutdebut(int n, Liste l)
{
	Element* elt = malloc(sizeof(Element));
	elt->val = n;
	elt->nxt = l;
	return(elt);
}

void ajoutfin( int n, Liste l)
{
	Element tmp = *l;
	Element* elt = malloc(sizeof(Element));
	elt->val = n;
	elt->nxt = NULL;
	while(tmp.nxt != NULL)
	{
		l = tmp.nxt;
		tmp = *l;
	}
	l->nxt = elt;
}

void liberer(Liste l)
{
	if(l != NULL)
	{
		liberer(l->nxt);
		free(l);
	}
}

int testtri(Liste l)
{
	Liste tmp;
	tmp = l;
	while((tmp != NULL)&&(tmp->nxt != NULL))
	{
		if(tmp->val > tmp->nxt->val)
		{
			return(0);
		}
		tmp = tmp->nxt;
	}
	return(1);
}

Liste ajouttri( int n, Liste l)
{
	if(testtri(l))
	{
		if(( l == NULL)||(n <= l->val))
		{
			return(ajoutdebut(n, l));
		}
		l->nxt = ajouttri( n, l->nxt);
		return(l);
	}
	else
	{
		return(l);
	}
}

int taille(Liste l)
{
	int taille = 0;
	while(l != NULL)
	{
		taille ++;
		l = l->nxt;
	}
	return(taille);
}

int src(Liste l, int n)
{
	while(l != NULL)
	{
		if(l->val == n)
		{
			return(1);
		}
		l = l->nxt;
	}
	return(0);
}

Liste del(Liste l, int n)
{
	if(src(l, n))
	{
		Liste tmp1, tmp2;
		tmp2 = l;
		if(l->val == n)
		{
			tmp1 = l->nxt;
			free(l);
			return(tmp1);
		}
		while(tmp2->nxt != NULL)
		{
			if(tmp2->nxt->val == n)
			{
				tmp1 = tmp2->nxt->nxt;
				free(tmp2->nxt);
				tmp2->nxt = tmp1;
				return(l);
			}
			tmp2 = tmp2->nxt;
		}
	}
	return(l);
}


Liste fin(Liste l)
{
	while(l->nxt != NULL)
	{
		l = l->nxt;
	}
	return(l);
}


Liste concat( Liste l1, Liste l2)
{
	Liste tmp = l1;
	if(tmp == NULL)
	{
		return(l2);
	}
	tmp = fin(l1);
	tmp->nxt = l2;
	return(l1);
}
/*
Liste concattri(Liste l1, Liste l2)
{
	Liste l3 = vide();
	while(l1 != NULL)
	{
		while(l2 != NULL)
		{
			if(l1->val < l2->val)
			{
				l3 = ajoutdebut(l2->val, l3);
				l2 = l2->nxt;
			}
			else
			{
				l3 = ajoutdebut(l1->val, l3);
				l1 = l1->nxt;
			}
		}
		l3 = ajoutdebut(l1->val, l3);
		l1 = l1->nxt;
	}
	while(l2 != NULL)
	{
		l3 = ajoutdebut(l2->val, l3);
		l2 = l2->nxt;
	}
	return(l3);
}
*/

Liste concattri(Liste l1, Liste l2, Liste l3)
{
	Liste tmp;
	if((l1 == NULL)&&(l2 == NULL))
	{
		return(l3);
	}
	if((testtri(l1)&&testtri(l2)))
	{
		if(l1 != NULL)
		{
			if(l2 != NULL)
			{
				if(l1->val > l2->val)
				{
					if(l3 == NULL)
					{
						l3 = l2;
						l2 = l2->nxt;
						l3->nxt = NULL;
					}
					else
					{
						tmp = fin(l3);
						tmp->nxt = l2;
						l2 = l2->nxt;
						tmp->nxt->nxt = NULL;
					}
					return(concattri(l1, l2, l3));
				}
				else
				{
					if(l3 == NULL)
					{
						l3 = l1;
						l1 = l1->nxt;
						l3->nxt = NULL;
					}
					else
					{
						tmp = fin(l3);
						tmp->nxt = l1;
						l1 = l1->nxt;
						tmp->nxt->nxt = NULL;
					}
					return(concattri(l1, l2, l3));
				}
			}
			else
			{
				tmp = fin(l3);
				tmp->nxt = l1;
				return(l3);
			}
		}
		else if(l2 != NULL)
		{
			return(concattri(l2, l1, l3));
		}
	}
	return(concat(l1, l2));
}

void echange(Liste l1, Liste l2)
{
	int tmp;
	tmp = l1->val;
	l1->val = l2->val;
	l2->val = tmp;
}

void triBulle(Liste l)
{
	Liste tmp = l;
	while(!testtri(l))
	{
		while(tmp != NULL)
		{
			if(tmp->val > tmp->nxt->val)
			{
				echange(tmp, tmp->nxt);
			}
			tmp = tmp->nxt;
		}
	}
}

Liste flip(Liste l1, Liste l2)
{
	if(l1 == NULL)
	{
		return(l2);
	}
	else 
	{
		Liste tmp;
		tmp = l1;
		l1 = l1->nxt;
		tmp->nxt = l2;
		return(flip(l1, tmp));
	}
}



Liste triFusion(Liste l)
{
	int i;
	Liste res = vide();
	Liste tmp1 = l;
	Liste tmp2;
	if(l->nxt == NULL)
	{
		return(l);
	}
	for(i = 0; i < taille(l)/2 - 1; i++)
	{
		tmp1 = tmp1->nxt;
	}
	tmp2 = tmp1->nxt;
	tmp1->nxt = NULL;
	affiche(l);
	affiche(tmp2);
	return(concattri(triFusion(l),triFusion(tmp2), res));
}

void main()
{
	srand(time(NULL));
	Liste l = vide();
	Liste m = vide();
	Liste n = vide();
	int t, i;
	for(i = 0; i < 10; i++)
	{
		t = rand()%100;
		l = ajouttri(t, l);
		t = rand()%100;
		m = ajouttri(t, m);
		affiche(l);
		affiche(m);
		t = rand()%100;
		printf("\n %d, %d\n", t, src(l, t));
	}
	triBulle(l);
	affiche(l);
	l = flip(l, vide());
	affiche(l);
	l = triFusion(l);
	affiche(l);
	t = testtri(l);
	printf("\ntri = %d \n", t);
	printf("\ntaille = %d \n", taille(l));
}
