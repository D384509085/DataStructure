//问题描述:棋盘里有一个格子被涂黑,要求用L型骨牌覆盖整个棋盘 0代表空,-1代表涂黑,其他数字代表 
#include<stdio.h>
//***************************************
#define MAP_LENGTH 16

int map[MAP_LENGTH][MAP_LENGTH];
//骨牌编号 
static int domino_num = 1;
//棋盘初始化 
static void init ();
//棋盘覆盖操作 
static void operate (int r1, int c1, int length, int dirty_r, int dirty_c);


//*******************************
void init ()
{
	for (int i = 0; i < MAP_LENGTH; i++)
	{
		for (int j = 0; j < MAP_LENGTH; j++)
		{
			map[i][j] = 0;
		}
	}
}
void operate (int r1, int c1, int length, int dirty_r, int dirty_c)
{
	if (1 == length) {
		return;
	}
	//中心靠左上的行列
	int x1 = r1 + length / 2 - 1, y1 = c1 + length / 2 - 1;  
	//中心靠左下 
	int x2 = r1 + length / 2, y2 = c1 + length / 2 - 1;
	//中心靠左上
	int x3 = r1 + length / 2 - 1, y3 = c1 + length / 2;
	//中心靠右下
	int x4 = r1 + length / 2, y4 = c1 + length / 2; 
	//在左上角 
	if (r1 + length / 2 > dirty_r && c1 + length / 2 > dirty_c) 
	{
		map[x2][y2] = domino_num;
		map[x3][y3] = domino_num;
		map[x4][y4] = domino_num;
		domino_num ++;
		operate (r1, c1, length / 2, dirty_r, dirty_c);
		domino_num ++;
		operate (r1 + length / 2, c1, length / 2, r1 + length / 2, c1 + length / 2 -1);
		domino_num ++;
		operate (r1 , c1 + length / 2, length / 2, r1 + length / 2 - 1, c1 + length / 2);
		domino_num ++;
		operate (r1 + length / 2, c1 + length / 2, length / 2, r1 + length / 2, c1 + length / 2);
	}
	//在左下 
	else if (r1 + length / 2 <= dirty_r && c1 + length / 2 > dirty_c)
	{
		map[x1][y1] = domino_num;
		map[x3][y3] = domino_num;
		map[x4][y4] = domino_num;
		domino_num ++;
		operate (r1, c1, length / 2, x1, y1);
		domino_num ++;
		operate (r1 + length / 2, c1, length / 2, dirty_r, dirty_c);
		domino_num ++;
		operate (r1, c1 + length / 2, length / 2, x3, y3);
		domino_num ++;
		operate (r1 + length / 2, c1 + length / 2, length / 2, x4, y4);
	}
	//右上
	else if (r1 + length / 2 > dirty_r && c1 + length / 2 <= dirty_c)
	{
		map[x1][y1] = domino_num;
		map[x2][y2] = domino_num;
		map[x4][y4] = domino_num;
		domino_num ++;
		operate (r1, c1, length / 2 ,x1, y1);
		domino_num ++;
		operate (r1 + length / 2, c1, length / 2, x2, y2);
		domino_num ++;
		operate (r1, c1 + length / 2, length / 2, dirty_r, dirty_c);
		domino_num ++;
		operate (r1 + length / 2, c1 + length / 2, length / 2, x4, y4);
	} 
	//右下
	else if (r1 + length / 2 <= dirty_r && c1 + length / 2 <= dirty_c) 
	{
		map[x1][y1] = domino_num;
		map[x2][y2] = domino_num;
		map[x3][y3] = domino_num;
		domino_num ++;
		operate (r1, c1, length / 2, x1, y1);
		domino_num ++;
		operate (r1 + length / 2, c1, length / 2, x2, y2);
		domino_num ++;
		operate (r1, c1 + length / 2, length / 2, x3, y3);
		domino_num ++;
		operate (r1 + length / 2, c1 + length / 2, length / 2, dirty_r, dirty_c);
	} 
	else return;
} 

int main ()
{
	init();
	operate(0, 0, 16, 3, 3);
	for (int i = 0; i < 16; i ++)
	{
		for (int j = 0; j < 16; j ++)
		{
			printf ("%4d", map[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
