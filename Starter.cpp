//ʹ���������飬һ���������飬һ���Ǹ�������
//ԭ�����ø�������洢�������Ԫ���±�
//�Ӷ��ﵽ�����Ĳ��ظ����Ч������ʵ�����ö���������ʾ
//˵�����ֻ�ǵ���ʹ��rand()��������Ļ�����ôʵ���������ظ�����Ĵ���Ҳ��һ����
// T.aoyan 2022.2.20 00:34
#include <iostream>
#include <cstdlib>  //ȡ�����Ҫ�õ�
#include <windows.h> //�������ܵ�ͷ�ļ�
#include <time.h>    //�ó���ÿ��ִ��ʱ�������������ʱ��䶯����ǿ�����

//���ظ��������
void randomWithoutRepeat()
{
	//��¼�㷨���ĵ�ʱ��
	DWORD time_start, time_end;
	time_start = GetTickCount();
	//�����������ϵͳʱ��仯
	srand((unsigned)time(0));
	//����һ������������֤�������ܹ������1600��
	int proof = 0;
	//����һ�����������ڱ�ʾ��������ĳ��ȣ����ֵÿ������������1
	int length = 1600;
	//�����������飬������͸������飬Ԥ�����1600��
	int mainArray[1600];
	int supportArray[1600];
	//�������鸳ֵ��һ��ʼȫ������0
	for (int i = 0; i < 1600; i++) { mainArray[i] = 0; }
	//���������鸳ֵ���������������Ԫ�ص��±꣬��0-1599
	for (int i = 0; i < 1600; i++) { supportArray[i] = i; }
	//�㷨��ʼ
	while (true)
	{
		//���ж�����ӡ
		for (int i = 0; i < 1600; i++)
		{
			if (mainArray[i] == 0) { std::cout << "��"; }//δ��������Ĵ�ӡ��
			else { std::cout << "��"; }//�Ѿ���������Ĵ�ӡ��
									  //ÿ���40�Σ�����һ�λ��У���Ϊ����һ�������Σ����ڹ۲�
			if (i % 40 == 39) { std::cout << std::endl; }
		}
		//�Ƚ����ж������length��ֵС��1����ô�㷨���̽���
		if (length >= 1)
		{
			//ÿ�δ�ӡ���֮��,����һ�����
			int random = rand() % length;
			//ÿ���һ�Σ�proof��1
			proof = proof + 1;
			//���������ֵ,����Ӧ���±��ڸ��������Ӧ��Ԫ�ص��Ǹ�ֵ
			//�븨�����������Ǹ�Ԫ��ֵ���н���
			int temp = supportArray[random];
			supportArray[random] = supportArray[length - 1];
			supportArray[length - 1] = temp;
			//֮��Ѹ�������ĩβ���Ǹ�����������������±���в�������
			mainArray[supportArray[length - 1]] = 1;
			//����������������ȼ�1
			length = length - 1;
		}
		else { break; }//���length����Ϊ0����ô�㷨ִ����ϣ��˳�
					   //ÿ��ͼ�������ɺ���Ϣ50���룬��������
		//Sleep(50);
		system("cls");
	}
	time_end = GetTickCount();
	std::cout << "���㷨�Ѿ���ɣ�һ�������" << proof << "�Σ�" << std::endl;
	std::cout << "���㷨���ĵ�ʱ��Ϊ:" << (time_end - time_start)<<"���룡" <<std::endl;
	system("pause");//����ִ�����֮��һ����ͣ�����ڹ۲���ۣ�

}
//�ظ��������
void randomRepeat()
{
	//��¼�㷨���ĵ�ʱ��
	DWORD time_start, time_end;
	time_start = GetTickCount();
	//�����������ϵͳʱ��仯
	srand((unsigned)time(0));
	//��Ч�����һ����1600��,��0��ʼ
	int length = 1600;
	//����һ�����������ڼ�¼�����ܹ�����˶��ٴ�
	int proof = 0;
	//����һ�����飬�������
	int mainArray[1600];
	//�����鸳ֵ��һ��ʼȫ������0
	for (int i = 0; i < 1600; i++) { mainArray[i] = 0; }
	
	//�㷨��ʼ
	while (true)
	{
		//���ж�����ӡ
		for (int i = 0; i < 1600; i++)
		{
			if (mainArray[i] == 0) { std::cout << "��"; }//δ��������Ĵ�ӡ��
			else { std::cout << "��"; }//�Ѿ���������Ĵ�ӡ��
									  //ÿ���40�Σ�����һ�λ��У���Ϊ����һ�������Σ����ڹ۲�
			if (i % 40 == 39) { std::cout << std::endl; }
		}
		    //�����жϣ������Ч������Ѿ�Ϊ0����ô�㷨����
		if (length == 0 ) { break; }
			//ÿ�δ�ӡ���֮��,����һ�����
			int random = rand() % 1600;
			//ÿ���һ�Σ�proof��1
			proof = proof + 1;
			//���������ĸ��±�Ԫ����1��˵���ظ�����������0����ô����Ч���
			if (mainArray[random] != 1) { mainArray[random] = 1;  length--; }
			//Sleep(50);
			system("cls");
	}
	time_end = GetTickCount();
	std::cout << "���㷨�Ѿ���ɣ�һ�������" << proof << "�Σ�" << std::endl;
	std::cout << "���㷨���ĵ�ʱ��Ϊ:" << (time_end - time_start) << "���룡" << std::endl;
	system("pause");//����ִ�����֮��һ����ͣ�����ڹ۲���ۣ�
		
}

int main()
{   
	randomWithoutRepeat();//���ظ������ʾ
	//randomRepeat();//�ظ������ʾ

	return 0;
}
