#ifndef TASKH
#define TASKH

#include <stdio.h>
#include <stdlib.h>
#inclide <string.h>
#define COUNT_ABONENTS 100
#define COUNT_ARG_STRUCT 3
#define DELTA 10

typedef struct
{
    char name[10];
    char second_name[10];
    char tel[10];
} Abonent;

void add_abonent(Abonent *, int *);
void delete_abonent(Abonent *, int *);
void find_abonent(Abonent *, int *);
void print_abonents(Abonent *, int *);

#endif