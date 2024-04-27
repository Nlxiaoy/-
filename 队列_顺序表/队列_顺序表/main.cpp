#include"标头.h"

int main()
{
	SqQueue Q;
	Init_SqQueue(&Q);
	Empty_SqQueue(&Q);
	Enter_SqQueue(&Q,22);
	Enter_SqQueue(&Q, 23);
	Enter_SqQueue(&Q, 24);
	Out_SqQueue(&Q);
	Print_SqQueue(&Q);
	return 0;
}