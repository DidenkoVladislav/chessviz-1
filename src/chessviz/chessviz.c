#include <libchessviz/chesviz.h>

// void one_side(size_t n, PNT **board, int count)
// {
//     char x1, x2;
//     int y1, y2;
//     printf("\nВаш ход, участник %d (Ctrl+D для сохранения и выхода): ", who(count));
//     if (scanf("\n%c %d %c %d", &x1, &y1, &x2, &y2) == EOF)
//         exit(EXIT_FAILURE);
//     int j = x1 - 'A', i = n - y1, res_j = x2 - 'A', res_i = n - y2;

//     if (!is_correct_player(board[i][j], count) && is_full_pnt(board[i][j]))
//         puts("Не трогайте чужие фигуры!");
//     if (!is_full_pnt(board[i][j]))
//         puts("С этого поля нельзя взять фитуру.");
//     while (step(n, board, j, i, res_j, res_i, '-') == -1)
//         if (scanf("\n%c %d %c %d", &x1, &y1, &x2, &y2) == EOF)
//             exit(EXIT_FAILURE);
// }

int main()
{
    PNT **board = desk_create(SIZ);
    FILE *fp = fopen("input", "r");
    desk_init(SIZ, board, fp);
    desk_show(SIZ, board);
    INPUT *in = input_create();
    // show_input(in);
    
    game(in, SIZ, board);
    saving(SIZ, board);

    // printf("Победа стороны %s!\n", check_of_shakh(board, king_white) ? "white" : "black");
    input_destroy(in);
    desk_destroy(SIZ, board);
    fclose(fp);

    return 0;
}
