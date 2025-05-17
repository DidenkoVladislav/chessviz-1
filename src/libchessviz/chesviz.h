#ifndef CHESSVIZ_H
#define CHESSVIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define SIZ 8
#define MAXSTR 7
#define WHITE true
#define BLACK false

typedef struct coord
{
    char x;
    int y;
} CRD;

typedef struct figure
{
    char object;
    bool colour;
} FIG;

typedef struct desk_point
{
    int x, y;
    FIG *figure;
} PNT;

typedef struct strings
{
    char *str;
    struct strings *next;
} STR;

typedef struct input
{
    int num;
    STR *in;
    struct input *next;
} INPUT;

void control_of_memory(void *ptr);
PNT **desk_create(size_t n);
void desk_init(size_t n, PNT **board, FILE *fptr);
void desk_show(size_t n, PNT **board);
void pnt_destroy(size_t n, PNT *desk_point);
void desk_destroy(size_t n, PNT **board);
bool is_full_pnt(PNT desk_point);
char translate(char figure);
bool step_correctness(CRD in, CRD res);
void change_board(PNT **board, FIG *figure, CRD in, CRD res);
bool is_opponent(PNT a, PNT b);
void pawn_move(PNT *pawn_pos, char figure);
void pawn(PNT **board, FIG *figure, CRD in, CRD res, char step, char change_pawn);
void bishop(PNT **board, FIG *figure, CRD in, CRD res, char step);
void rook(PNT **board, FIG *figure, CRD in, CRD res, char step);
void king(PNT **board, FIG *figure, CRD in, CRD res, char step);
void queen(PNT **board, FIG *figure, CRD in, CRD res, char step);
void knight(PNT **board, FIG *figure, CRD in, CRD res, char step);
int step(size_t n, PNT **board, int j, int i, int res_j, int res_i, char step, char change_pawn);
bool is_correct_player(PNT desk_point, int count);
bool check_of_shakh(PNT **borad, CRD king_point);
STR *str_construct();
void add_str(STR *in, char *str);
void show_strs(STR *in);
STR *copy_str(STR *in);
STR *input_data();
void str_destroy(STR *in);
INPUT *input_construct();
INPUT *input_create();
void input_destroy(INPUT *in);
void show_input(INPUT *in);
void complete_step(size_t n, PNT **board, char *str, int index, int count);
void game(INPUT *in, size_t n, PNT **board);
void saving(size_t n, PNT **desk);

#endif