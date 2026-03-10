#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 1000

void show_vector(int *v, int v_size) {
	for (int i = 0; i < v_size; i++)
		printf("v[%d] = %d\n", i, v[i]);
}

int *min_element(int *v, int v_size) {
	int minim = INT_MAX, index_min = 0;

	for (int i = 0; i < v_size; i++)
		if (v[i] < minim) minim = v[i], index_min = i;

	printf("Elementu minim e %d\n", v[index_min]);
	return &v[index_min];
}

void delete_min(int **v, int v_size, int *element) {
	for (int i = 0; i < v_size; i++)
		if (*v + i == element) {
			for (int j = i; j < v_size - 1; j++)
				*v[i] = *v[i + 1];
			break;
		}
	*v = realloc(*v, (v_size - 1) * sizeof(int));
	if (*v == NULL)
		exit(-1);
}

int *init_vector() {
	int *v = (int *)malloc(MAXSIZE * sizeof(int));
	if (v == NULL)
		exit(-1);

	int d = -1;
	int i = 0;
	for (; ;) {
		scanf("%d", &d);
		if (i > MAXSIZE)
			v = realloc(v, MAXSIZE * 2 * sizeof(int));
		if (v == NULL)
			exit(-1);
		if (d == 0)
			break;
		v[i++] = d;
	}
	show_vector(v, i);
	delete_min(&v, i, min_element(v, i));
	i--;
	show_vector(v, i);
	return v;
}


int main(void) {
	int *v = init_vector();
	free(v);
	v = NULL;
	return 0;
}