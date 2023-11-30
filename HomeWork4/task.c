#include "task.h"

int main(void)
{
    setlocale(LC_ALL, "Rus");
    Abonent arr_abonents[COUNT_ABONENTS] = {0};
    int command = -1, current_count = 0;

    while(command != EXIT_CODE)
    {
        fprintf(stdout, "1 - Добавить абонента\n2 - Удалить абонента\n3 - Поиск абонентов по имени\n4 - Вывод всех записей\n5 - Выход\n");
        if(scanf("%d", &command) != 1) exit(EXIT_FAILURE);
        switch (command)
        {
        case 1:
            add_abonent(arr_abonents, &current_count);
            break;

        case 2:
            delete_abonent(arr_abonents, &current_count);
            break;

        case 3:
            find_abonent(arr_abonents, &current_count);
            break;

        case 4:
            print_all_abonents(arr_abonents, &current_count);
            break;

        case EXIT_CODE:
            fprintf(stdout, "Closing program...\n");
            break;
        
        default:
            fprintf(stderr, "Unknown command!\n");
            break;
        }
    }

    exit(EXIT_SUCCESS);
}

void add_abonent(Abonent *parr_abonents, int *current_count)
{
    for(int i = 0; i < COUNT_ARG_STRUCT; i++)
    {
        switch (i)
        {
        case 0:
            fprintf(stdout, "Enter the name of abonent\n");
            break;
        case 1:
            fprintf(stdout, "Enter the surname of abonent\n");
            break;

        case 2:
            fprintf(stdout, "Enter the phone of abonent\n");
            break;
        
        default:
            fprintf(stderr, "Error with elements of struct!");
            break;
        }
        if(scanf("%s", ((char*)(parr_abonents + *current_count)) + i * DELTA) != 1) exit(EXIT_FAILURE);
    }
    *current_count += 1;
}

void delete_abonent(Abonent *parr_abonents, int *current_count)
{
    char name[10];
    char second_name[10];
    char tel[10];

    fprintf(stdout, "Enter the name of abonent which you want to delete\n");
    if(scanf("%s", name) != 1) exit(EXIT_FAILURE);
    fprintf(stdout, "Enter the second_name of abonent which you want to delete\n");
    if (scanf("%s", second_name) != 1) exit(EXIT_FAILURE);
    fprintf(stdout, "Enter the tel of abonent which you want to delete\n");
    if (scanf("%s", tel) != 1) exit(EXIT_FAILURE);

    for(int i = 0; i < *current_count; i++)
    {
        if ((strcmp(name, parr_abonents[i].name) == 0) && (strcmp(second_name, parr_abonents[i].second_name) == 0) && (strcmp(tel, parr_abonents[i].tel) == 0))
        {
            strcpy(parr_abonents[i].name, "");
            strcpy(parr_abonents[i].second_name, "");
            strcpy(parr_abonents[i].tel, "");
            offset_abonents(parr_abonents, current_count, i);
            *current_count -= 1;
            return;
        }
    }
    fprintf(stdout, "Undefined abonent!\n");
}

void offset_abonents(Abonent* parr_abonents, int* current_count, int position)
{
    for (int i = position; i < *current_count; i++)
    {
        if (strcmp(parr_abonents[i + 1].name, "") != 0)
        {
            strcpy(parr_abonents[i].name, parr_abonents[i + 1].name);
            strcpy(parr_abonents[i].second_name, parr_abonents[i + 1].second_name);
            strcpy(parr_abonents[i].tel, parr_abonents[i + 1].tel);

            strcpy(parr_abonents[i + 1].name, "");
            strcpy(parr_abonents[i + 1].second_name, "");
            strcpy(parr_abonents[i + 1].tel, "");
        }
    }
}

void find_abonent(Abonent *parr_abonents, int *current_count)
{
    char name[10];
    fprintf(stdout, "Enter the name of abonent which you want to find\n");
    if (scanf("%s", name) != 1) exit(EXIT_FAILURE);

    fprintf(stdout, "List with abonents with name: %s\n", name);
    for (int i = 0; i < *current_count; i++)
    {
        if (strcmp(name, parr_abonents[i].name) == 0) print_abonent(&parr_abonents[i]);
    }
}

void print_abonent(Abonent* parrAbonent)
{
    fprintf(stdout, "Name: %s\n", parrAbonent->name);
    fprintf(stdout, "Second name: %s\n", parrAbonent->second_name);
    fprintf(stdout, "Tel: %s\n", parrAbonent->tel);
}

void print_all_abonents(Abonent *parr_abonents, int *current_count)
{
    fprintf(stdout, "List with all abonents\n");
    for (int i = 0; i < *current_count; i++) {
        print_abonent(&parr_abonents[i]);
        if (i != *current_count - 1) putc('\n', stdout);
    }
}