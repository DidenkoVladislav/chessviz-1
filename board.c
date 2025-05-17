#include </home/alex/trpo/test_dir/chesviz.h>

PNT **desk_create(size_t n)
{
    PNT **desk = (PNT **)malloc(n * sizeof(PNT *)); // сначала выделяем память под массив указателей
    control_of_memory(desk);
    for (int i = 0; i < n; i++)
    {
        *(desk + i) = (PNT *)malloc(n * sizeof(PNT));
        control_of_memory(*(desk + i));
    }
    int y = SIZ;
    char x = 'A';

    for (int i = 0; i < n; i++, y--)
    {
        for (int j = 0; j < n; j++, x++)
        {
            (*(desk + i) + j)->x = x;
            (*(desk + i) + j)->y = y;
            (*(desk + i) + j)->figure = calloc(1, sizeof(FIG));
            control_of_memory((*(desk + i) + j)->figure);
            (*(desk + i) + j)->figure->object = '.';
        }
        x = 'A';
    }
    return desk;
}

void desk_init(size_t n, PNT **board, FILE *fptr)
{
    char figure;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fptr, "\n%c", &figure) != 1)
                exit(EXIT_FAILURE);
            (*(board + i) + j)->figure->object = figure;
            (*(board + i) + j)->figure->colour = (i > 1);
        }
    }
}

void desk_show(size_t n, PNT **board)
{
    putchar('\t');
    for (int a = 0; a < SIZ; a++) // вывод букв
    {
        putchar((*(board) + a)->x);
        printf("  ");
    }
    printf("\n\n");

    for (int i = 0; i < SIZ; i++)
    {
        printf("%d\t", (*(board + i))->y); // вывод цифры перед строкой
        for (int j = 0; j < SIZ; j++)
            printf("%c  ", (*(board + i) + j)->figure->object);
        putchar('\n');
    }
}

/*Очистка ячейки доски*/
void pnt_destroy(size_t n, PNT *desk_point)
{
    for (int j = 0; j < n; j++)
        free((desk_point + j)->figure);
    free(desk_point);
}

/*Очистка памяти из-под доски*/
void desk_destroy(size_t n, PNT **board)
{
    for (int i = 0; i < n; i++)
        pnt_destroy(n, *(board + i));
    free(board);
    board = NULL;
}

/*Изменение доски*/
void change_board(PNT **board, FIG *figure, CRD in, CRD res)
{
    board[res.y][(int)res.x].figure->object = figure->object;
    board[res.y][(int)res.x].figure->colour = figure->colour;

    board[in.y][(int)in.x].figure->object = '.';
    board[in.y][(int)in.x].figure->colour = false;
}

/*Сохранение текущего расположения фигур в файл*/
void saving(size_t n, PNT **desk)
{
    FILE *fptr = fopen("save", "w");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(fptr, "%c  ", (*(desk + i) + j)->figure->object);
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}
