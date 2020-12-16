#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<getch.h>
int main(int argc,const char* argv[])
{
	char map[10][10]=
	{
		{'#','#','#',' ','#','#','#','#','#','#'},
		{'#','@','#',' ','#','#','#','#','#','#'},
		{'#',' ',' ',' ','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
	};//老鼠（1.1） 终点（0.3）

	//定义老鼠的位置
	int m_x =1,m_y = 1;
	//定义开始时间
	time_t start_time = time(NULL);
	//定义终点坐标
	int f_x=0,f_y=3;
	//进入死循环
	for(;;)
	{
		//清理屏幕
		system("clear");
		//打印地图
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				printf("%c ",map[i][j]);
			}
			printf("\n");
		}

		//是否到达终点	
		if(m_x == f_x && m_y == f_y)
		{
			time_t end_time = time(NULL);
			printf("恭喜通过，用时%ds",end_time-start_time);
			exit(0);
		}
		//判断移动
		switch(getch())
		{
			case 183:
				if(map[m_x-1][m_y]==' ')
				{
					map[m_x][m_y] = ' ';
					map[m_x-1][m_y] = '@';
					m_x = m_x-1;
					m_y = m_y;
				}
				break;
			case 184:
				if(map[m_x+1][m_y]==' ')
				{
					map[m_x][m_y] = ' ';
					map[m_x+1][m_y] = '@';
					m_x = m_x+1;
					m_y = m_y;
				}
				break;
			case 185:
				if(map[m_x][m_y+1]==' ')
				{
					map[m_x][m_y] = ' ';
					map[m_x][m_y+1] = '@';
					m_x = m_x;
					m_y = m_y+1;
				}
			break;
			case 186:
				if(map[m_x][m_y-1]==' ')
				{
					map[m_x][m_y] = ' ';
					map[m_x][m_y-1] = '@';
					m_x = m_x;
					m_y = m_y-1;
				}
			break;
		}	

	}
	return 0;
}
