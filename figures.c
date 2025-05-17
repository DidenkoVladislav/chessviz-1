// /*Файл для разбиения проверок ходов фигур*/
#include </home/alex/trpo/test_dir/chesviz.h>

/*Пешка меняется на другую фигуру*/
void pawn_move(PNT *pawn_pos, char figure)
{
    if (figure != 'k' && figure != 'K')
        pawn_pos->figure->object = figure;
}

void pawn(PNT **board, FIG *figure, CRD in, CRD res, char step, char change_pawn)
{
    int pawn_step = (in.y == 6 && board[in.y][(int)in.x].figure->colour == true) || (in.y == 1 && board[in.y][(int)in.x].figure->colour == false) ? 2 : 1;
    if (step == '-')
    {
        if (figure->colour == true)
        {
            if ((in.x == res.x) && ((in.y - res.y) == 1 || (in.y - res.y) == pawn_step) && !is_full_pnt(board[res.y][(int)res.x]))
                change_board(board, figure, in, res);
            if (res.y == 0)
            {
                pawn_move(&(board[res.y][(int)res.x]), change_pawn);
            }
        }
        else
        {
            if (((res.y - in.y) == 1 || (res.y - in.y) == pawn_step) && !is_full_pnt(board[res.y][(int)res.x]))
                change_board(board, figure, in, res);
            if (res.y == 7)
            {
                pawn_move(&(board[res.y][(int)res.x]), tolower(change_pawn));
            }
        }
    }
    else if (step == 'x')
    {
        if (figure->colour == true)
        {
            if ((abs(in.x - res.x) == 2) && ((in.y - res.y) == 2) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
                change_board(board, figure, in, res);
            if (res.y == 0)
            {
                pawn_move(&(board[res.y][(int)res.x]), change_pawn);
            }
        }
        else
        {
            if ((abs(in.x - res.x) == 2) && ((res.y - in.y) == 2) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
                change_board(board, figure, in, res);
            if (res.y == 7)
            {
                pawn_move(&(board[res.y][(int)res.x]), tolower(change_pawn));
            }
        }
    }
    else
    {
        printf("Неверный аргумент хода. Ожидалось \"x\" или \"-\", получено: %c\n", step);
        exit(EXIT_FAILURE);
    }
}

void bishop(PNT **board, FIG *figure, CRD in, CRD res, char step)
{
    if (step == '-')
    {
        if (abs(in.x - res.x) == abs(in.y - res.y) && !is_full_pnt(board[res.y][(int)res.x]))
            change_board(board, figure, in, res);
    }
    else if (step == 'x')
    {
        if (abs(in.x - res.x) == abs(in.y - res.y) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
            change_board(board, figure, in, res);
    }
    else
    {
        printf("Неверный аргумент хода. Ожидалось \"x\" или \"-\", получено: %c\n", step);
        // exit(EXIT_FAILURE); // ?
    }
}

void rook(PNT **board, FIG *figure, CRD in, CRD res, char step)
{
    if (step == '-')
    {
        if (((in.x == res.x) || (in.y == res.y)) && !is_full_pnt(board[res.y][(int)res.x]))
            change_board(board, figure, in, res);
    }
    else if (step == 'x')
    {
        if (((in.x == res.x) || (in.y == res.y)) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
            change_board(board, figure, in, res);
    }
    else
    {
        printf("Неверный аргумент хода. Ожидалось \"x\" или \"-\", получено: %c\n", step);
        // exit(EXIT_FAILURE); // ?
    }
}

void king(PNT **board, FIG *figure, CRD in, CRD res, char step)
{
}

void queen(PNT **board, FIG *figure, CRD in, CRD res, char step)
{
    if (step == '-')
    {
        if (((((in.x == res.x) || (in.y == res.y))) || (abs(in.x - res.x) == abs(in.y - res.y))) && !is_full_pnt(board[res.y][(int)res.x]))
            change_board(board, figure, in, res);
    }
    else if (step == 'x')
    {
        if (((((in.x == res.x) || (in.y == res.y))) || (abs(in.x - res.x) == abs(in.y - res.y))) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
            change_board(board, figure, in, res);
    }
    else
    {
        printf("Неверный аргумент хода. Ожидалось \"x\" или \"-\", получено: %c\n", step);
        // exit(EXIT_FAILURE); // ?
    }
}

void knight(PNT **board, FIG *figure, CRD in, CRD res, char step)
{
    if (step == '-')
    {
        if (((abs(in.x - res.x) == 1 && abs(in.y - res.y) == 2) || (abs(in.y - res.y) == 1 && abs(in.x - res.x == 2))) && !is_full_pnt(board[res.y][(int)res.x]))
            change_board(board, figure, in, res);
    }
    else if (step == 'x')
    {
        if (((abs(in.x - res.x) == 1 && abs(in.y - res.y) == 2) || (abs(in.y - res.y) == 1 && abs(in.x - res.x == 2))) && is_full_pnt(board[res.y][(int)res.x]) && is_opponent(board[res.y][(int)res.x], board[in.y][(int)in.x]))
            change_board(board, figure, in, res);
    }
    else
    {
        printf("Неверный аргумент хода. Ожидалось \"x\" или \"-\", получено: %c\n", step);
        // exit(EXIT_FAILURE); // ?
    }
}

int step(size_t n, PNT **board, int j, int i, int res_j, int res_i, char step, char change_pawn)
{
    CRD in = {j, i}, res = {res_j, res_i};

    switch (translate(board[i][j].figure->object))
    {
    case 'p':
        // printf("%c\n", board[i][j].figure->object);
        pawn(board, board[i][j].figure, in, res, step, change_pawn);
        break;
    case 'b':
        bishop(board, board[i][j].figure, in, res, step);
        break;
    case 'r':
        rook(board, board[i][j].figure, in, res, step);
        break;
    case 'k':
        king(board, board[i][j].figure, in, res, step);
        break;
    case 'q':
        queen(board, board[i][j].figure, in, res, step);
        break;
    case 'n':
        knight(board, board[i][j].figure, in, res, step);
        break;
    }
    return 0;
}
