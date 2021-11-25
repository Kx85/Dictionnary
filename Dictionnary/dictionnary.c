#include <stdlib.h>
#include <stdio.h>

#include "dictionnary.h"

void dictionnaryUsage()
{
	printf("ERREUR!");
}

int readDicFile(char* s_dicFile, int length)
{
	return 0;
}

p_dictionnary createNewDictionnary()
{
	dictionnary d = { 0, 1, malloc(sizeof(word)) };
	p_dictionnary p_d = malloc(sizeof(dictionnary));
	*p_d = d;

	return p_d;
}

void freeDictionnary(p_dictionnary d)
{
}

int findWord(p_dictionnary d, const char* key)
{
	return -1;
}

void addWord(p_dictionnary d, const char* key, int value)
{
	if (d->len == d->cap) {
		d->cap *= 2;
		d->w = realloc(d->w, d->cap * sizeof(word));
	}

	d->w[d->len].key = key;
	d->w[d->len].value = value;
	d->len++;
}

void updateWord(p_dictionnary d, const char* key, int value)
{
	int i = findWord(d, key);
	if (i != -1) {
		d->w[i].value = value;
	}
	else {
		addWord(d, key, value);
	}
}

void incWordValue(p_dictionnary d, const char* key)
{
	int i = findWord(d, key);
	if (i != -1) {
		int value = d->w[i].value;
		updateWord(d, key, value++);
	}
}

void displayDictionnary(p_dictionnary d)
{
	for (int i = 0; i < d->len; i++) {
		word w = d->w[i];
		printf("Key-> %s, Value-> %i\n", w.key, w.value);
	}
}
