typedef struct stack
{
    int elt;
    struct stack *next;       
}s_stack;

s_stack *stack_init(int elt);
int stack_is_empty(s_stack  *st);
int stack_size(s_stack *st);
void stack_print(s_stack *st);
s_stack *stack_push(s_stack *st, int elt);
s_stack *stack_pop(s_stack *st);
void stack_destroy(s_stack *st);
int stack_top(s_stack *st);
s_stack *stack_first(s_stack *st);

