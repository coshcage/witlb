/*
 * Name:        witlb.c
 * Description: Who is the lucky baby?
 * Author:      cosh.cage#hotmail.com
 * File ID:     0424240924J0424240924L00071
 * License:     Public Domain.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "svtree.h"

typedef struct _st_NAME
{
	size_t i;
	char name[16];
} NAME, * P_NAME;

int _grpCBFCompareInteger(const void * px, const void * py);

int main()
{
	FILE * fp;

	if (NULL != (fp = fopen("propernames.txt", "r")))
	{
		int c;
		size_t i = 0, j = 0;
		char buffer[BUFSIZ] = { 0 };
		P_BST pt = treCreateBST();
		NAME stn;
		P_BSTNODE pnode = NULL;

		srand(time(NULL));
		
		while (EOF != (c = fgetc(fp)))
		{
			switch (c)
			{
			case '\n':
			case '\r':
				i = 0;
				++j;
				stn.i = j;
				strcpy(stn.name, buffer);
				*pt = treBSTInsertAA(*pt, &stn, sizeof(NAME), _grpCBFCompareInteger);
				break;
			default:
				buffer[i++] = (char)c;
				buffer[i] = '\0';
			}
		}

		fclose(fp);

		j = 1 + rand() / ((RAND_MAX + 1u) / j);

		if (NULL != (pnode = treBSTFindData_A(*pt, &j, _grpCBFCompareInteger)))
			printf("%s\n", ((P_NAME)pnode->knot.pdata)->name);
		else
			printf("Devil\n");

		treDeleteBST(pt);
	}
	else
		fprintf(stderr, "Open database error.\n");

	return 0;
}
