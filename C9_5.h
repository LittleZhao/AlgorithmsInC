static int *pq;
static int N;

void PQinit(int);
int PQempty();
void PQinsert(int);
int PQdelmax();
void PQdestroy();
void fixUp(int *, int);
void fixDown(int *, int, int);
