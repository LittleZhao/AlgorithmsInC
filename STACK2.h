typedef struct stack *point;
struct stack {
    int data;
    int len;
};
point STACKinit(int);
void STACKpush(point, int);
int STACKpop(point);
void STACKfree(point);

