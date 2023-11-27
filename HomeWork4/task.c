#include "task.h"

int main(void)
{
    Abonent arr_abonents[COUNT_ABONENTS];
    int command = -1, current_count = 0;

    while(command != 5)
    {
        fprintf(stdin, "1 - Добавить абонента\n2 - Удалить абонента\n3 - Поиск абонентов по имени\n4 - Вывод всех записей\n5 - Выход\n");
        if(scanf("%d", &command) != 1) exit(EXIT_FAILURE);
        switch (command)
        {
        case 1:
            add_abonent();
            break;

        case 2:
            delete_abonent();
            break;

        case 3:
            find_abonent();
            break;

        case 4:
            print_abonents();
            break;

        case 5:
            fprintf(stdin, "Closing program...\n");
            break;
        
        default:
            fprintf(stderr, "Unknown command!\n");
            break;
        }
    }

    return 0;
}

void add_abonent(Abonent *parr_abonents, int *current_count)
{
    for(int i = 0; i < COUNT_ARG_STRUCT; i++)
    {
        fprintf(stdin, "Enter the ");
        switch (i)
        {
        case 0:
            fprintf(stdin, "name of abonent\n");
            break;
        case 1:
            fprintf(stdin, "surname of abonent\n");
            break;

        case 2:
            fprintf(stdin, "phone of abonent\n");
            break;
        
        default:
            fprintf(stderr, "Error with elements of struct!");
            break;
        }
        if(scanf("%s", (&parr_abonents[*current_count] + DELTA * i)) != 1) exit(EXIT_FAILURE);
    }
    *current_count++;
}

void delete_abonent(Abonent *parr_abonents, int *current_count)
{
    char name[10];
    fprintf(stdin, "Enter the name of abonent which you want to delete\n");
    if(scanf("%s", name) != 1) exit(EXIT_FAILURE);
    for(int i = 0; i < *current_count; i++)
    {
        if(parr_abonents[i].name )
    }
}

void find_abonent(Abonent *parr_abonents, int *current_count)
{

}

void print_abonents(Abonent *parr_abonents, int *current_count)
{

}

int isEqualNames(char *name1, char *name2)
{
    while()
}