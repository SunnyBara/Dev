#define MAX_STACK_SIZE 255
typedef struct stack
{
    int elt[MAX_STACK_SIZE];
    int size;       
}s_stack;

s_stack *stack_init();
int stack_is_empty(s_stack  *st);
int stack_size(s_stack *st);
void stack_print(s_stack *st);
int stack_push(s_stack *st, int e);
int stack_pop(s_stack *st);
void stack_destroy(s_stack *st);
int stack_top(s_stack *st);

