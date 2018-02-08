//百钱百鸡问题： 
/*
问题描述：
		中国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱百鸡问题”：
	一只公鸡值五钱，一只母鸡值三钱，三只小鸡值一钱，现在要用百钱买百鸡，请问
	公鸡、母鸡、小鸡各多少只？ 
*/ 

/**
 * 穷举法 
 * 穷举次数：21*34*101=72114 
 * @author Kdocke
 * @version v1.0
 */
/* 
#include<stdio.h>
main()
{
	int cock,hen,chicken; //分别定义变量公鸡，母鸡和小鸡
	for(cock=0;cock<=20;cock++) //外层循环控制公鸡数量取值范围 0~20 
	{
		for(hen=0;hen<=33;hen++) //内层循环控制母鸡数量取值范围 0~33 
		{
			for(chicken=0;chicken<=100;chicken++) //验证解的合理性 
			{
				if(cock*5+hen*3+chicken/3.0==100 && cock+hen+chicken==100)
				{
					printf("cock=%2d,hen=%2d,chicken=%2d\n",cock,hen,chicken);
				 } 
			}
		}
	} 
}
*/

/**
 * 进行条件约束，采用双重循环
 * 尝试次数：21*34=714 
 * @author Kdocke
 * @version v2.0
 */ 
#include<stdio.h>
main()
{
	int cock,hen,chicken;
	for(cock=0;cock<=20;cock++)
	{
		for(hen=0;hen<=33;hen++)
		{
			chicken = 100-cock-hen; //根据内外层的循环判断得出小鸡数量的取值 
			if(cock*5+hen*3+chicken/3.0 == 100)
			{
				printf("cock=%2d,hen=%2d,chicken=%2d\n",cock,hen,chicken); 
			 } 
		}
	}
 } 
