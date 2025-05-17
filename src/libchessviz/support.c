/*Функции для проверок корректности ходов и запуска программы.*/
#include "chesviz.h"

void control_of_memory(void *ptr)
{
    if (ptr == NULL)
    {
        puts("Ошибка выделения памяти.");
        exit(EXIT_FAILURE);
    }
}

bool is_full_pnt(PNT desk_point)
{
    return (desk_point.figure->object != '.');
}

char translate(char figure)
{
    if (islower(figure))
        return figure;
    else if (isupper(figure))
        return tolower(figure);
    else
    {
        puts("Ошибка считывания фигуры.");
        exit(EXIT_FAILURE);
    }
}

/*Проверка корректности ввода хода*/
bool step_correctness(CRD in, CRD res)
{
    return ((in.x >= 0 && res.x >= 0 && in.y >= 0 && res.y >= 0) && (in.x < 8 && res.x < 8 && in.y < 8 && res.y < 8));
}

/*Проверка, чья фигура стоит на клетке b*/
bool is_opponent(PNT a, PNT b)
{
    return (a.figure->colour != b.figure->colour);
}

/*Проверка: свои ли фигуры двигает игрок?*/
bool is_correct_player(PNT desk_point, int count)
{
    return ((count % 2 == 1) && (desk_point.figure->colour == true)) || ((count % 2 == 0) && (desk_point.figure->colour == false));
}

bool check_of_shakh(PNT **borad, CRD king_point)
{
    return true;
}

void complete_step(size_t n, PNT **board, char *str, int index, int count)
{
    int j, i, res_j, res_i;
    j = str[index] - 'a', i = n - (str[index + 1] - '0'), res_j = str[index + 3] - 'a', res_i = n - (str[index + 4] - '0');
    // printf("%c %c %c %c\n", str[index], str[index + 1], str[index + 3], str[index + 4]);
    if (toupper(board[i][j].figure->object) != (str[index - 1]))
    {
        puts("С этого поля нельзя взять указанную фигуру.");
        exit(EXIT_FAILURE);
    }
    if (!is_correct_player(board[i][j], count))
    {
        puts("Не трогайте чужие фигуры!");
        exit(EXIT_FAILURE);
    }
    CRD in = {j, i}, res = {res_j, res_i};
    if (!step_correctness(in, res))
    {
        puts("Нельзя выходить за пределы поля!");
        exit(EXIT_FAILURE);
    }
    // puts("Не сега complete!");
    char change_pawn = (str[index + 5] == '\0') ? 0 : str[index + 5];
    step(n, board, in.x, in.y, res.x, res.y, str[index + 2], change_pawn);
    desk_show(n, board);
}

void game(INPUT *in, size_t n, PNT **board)
{
    int count = 0;
    for (INPUT *curr = in; curr != NULL; curr = curr->next)
    {
        // puts("Не сега!");
        // printf("%d\n", curr->str[0]);

        for (STR *temp = curr->in; temp != NULL; temp = temp->next)
        {
            count++;
            printf("\n%d. ", curr->num);
            printf("%s\n\n", temp->str);
            complete_step(n, board, temp->str, 1, count);
        }
    }
}
