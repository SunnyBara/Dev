typedef struct cell
{
    int X;
    int Y;
    struct cell *next;
    int state;
} s_cell;
typedef struct rules
{
    int type;
    int number;
    struct rules *next;
} s_rules;
