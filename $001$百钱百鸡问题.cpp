//��Ǯ�ټ����⣺ 
/*
����������
		�й��Ŵ���ѧ�����������ġ��㾭���������һ�������ġ���Ǯ�ټ����⡱��
	һֻ����ֵ��Ǯ��һֻĸ��ֵ��Ǯ����ֻС��ֵһǮ������Ҫ�ð�Ǯ��ټ�������
	������ĸ����С��������ֻ�� 
*/ 

/**
 * ��ٷ� 
 * ��ٴ�����21*34*101=72114 
 * @author Kdocke
 * @version v1.0
 */
/* 
#include<stdio.h>
main()
{
	int cock,hen,chicken; //�ֱ������������ĸ����С��
	for(cock=0;cock<=20;cock++) //���ѭ�����ƹ�������ȡֵ��Χ 0~20 
	{
		for(hen=0;hen<=33;hen++) //�ڲ�ѭ������ĸ������ȡֵ��Χ 0~33 
		{
			for(chicken=0;chicken<=100;chicken++) //��֤��ĺ����� 
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
 * ��������Լ��������˫��ѭ��
 * ���Դ�����21*34=714 
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
			chicken = 100-cock-hen; //����������ѭ���жϵó�С��������ȡֵ 
			if(cock*5+hen*3+chicken/3.0 == 100)
			{
				printf("cock=%2d,hen=%2d,chicken=%2d\n",cock,hen,chicken); 
			 } 
		}
	}
 } 
