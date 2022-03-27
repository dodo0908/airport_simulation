typedef struct node
{
int num,name;
struct node *next;
} n;

n* frontdel(n *);
void delay(int);
n* print(n*);
n* queue(n*,int,int);
n* LANDorTAKEOFF(n*,int,int);
void check(n*,int*);
