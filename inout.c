#include </home/alex/trpo/test_dir/chesviz.h>

STR *str_construct()
{
    STR *res = calloc(1, sizeof(STR));
    res->str = NULL;
    res->next = NULL;
    return res;
}

void add_str(STR *in, char *str)
{
    // char*new_str=calloc(MAXSTR + 1, sizeof(char));
    if (in->str == NULL)
    {
        in->str = calloc(MAXSTR + 1, sizeof(char));
        strcpy(in->str, str);
    }
    else
    {
        STR *insert = str_construct();
        insert->str = calloc(MAXSTR + 1, sizeof(char));
        strcpy(insert->str, str);
        STR *curr = in;
        while (curr != NULL && curr->next != NULL)
            curr = curr->next;
        curr->next = insert;
    }
}

void show_strs(STR *in)
{
    for (STR *curr = in; curr != NULL; curr = curr->next)
        printf("%s\t", curr->str);
}

STR *copy_str(STR *in)
{
    STR *res = str_construct();
    for (STR *curr = in; curr != NULL; curr = curr->next)
        add_str(res, curr->str);
    return res;
}

STR *input_data()
{
    STR *in = str_construct();
    char ch;
    char str[MAXSTR];
    int i = 0;
    while ((ch = getchar()) != EOF)
    {
        str[i] = ch;
        if (ch == '\n' || ch == ' ')
        {
            str[i] = '\0';
            if (strlen(str) > 1)
            {
                // puts("yeah");
                add_str(in, str);
            }
            i = -1;
        }
        i++;
    }
    return in;
}

void str_destroy(STR *in)
{
    STR *temp = NULL;
    for (STR *curr = in; curr != NULL;)
    {
        temp = curr;
        curr = curr->next;
        free(temp->str);
        free(temp);
    }
}

INPUT *input_construct()
{
    INPUT *res = (INPUT *)calloc(1, sizeof(INPUT));
    res->num = 0;
    res->next = NULL;
    res->in = str_construct();
    return res;
}

INPUT *input_create()
{
    INPUT *input = input_construct();
    STR *strs = input_data();
    INPUT *temp = input;
    for (STR *curr = strs; curr != NULL; curr = curr->next)
    {
        if (isdigit(curr->str[0]))
        {
            if (temp->num == 0)
                temp->num = curr->str[0] - '0';
            else
            {
                temp->next = input_construct();
                temp = temp->next;
                temp->num = curr->str[0] - '0';
            }
        }
        else
        {
            add_str(temp->in, curr->str);
        }
    }
    str_destroy(strs);
    return input;
}

void input_destroy(INPUT *in)
{
    INPUT *temp;
    for (INPUT *curr = in; curr != NULL;)
    {
        temp = curr;
        curr = curr->next;
        str_destroy(temp->in);
        temp->num = 0;
        free(temp);
    }
}

void show_input(INPUT *in)
{
    for (INPUT *curr = in; curr != NULL; curr = curr->next)
    {
        printf("%d: ", curr->num);
        show_strs(curr->in);
    }
    putchar('\n');
}
