#include <stdio.h>
#include <iostream>
#include <Windows.h>
 using namespace std;
int main()
{
		COORD coord;
		//˫���崦����ʾ
		DWORD bytes;
		//����̨��Ļ���������

		HANDLE hOutput = CreateConsoleScreenBuffer(
			GENERIC_WRITE,//������̿�����������д����
			FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL
		);
		cout<<"fuck"<<endl;
		string s[3];
		s[0]="0";
		s[1]="1";
		s[2]="2";
		
		coord.X = 0;
		coord.Y = 0;
		bytes = 0;
		for (int i = 0; i < 3; i++)
		{
			coord.Y = i;
			WriteConsoleOutputCharacterA(hOutput, s[i].c_str(), s[i].size(), coord, &bytes);
		}
		SetConsoleActiveScreenBuffer(hOutput);
		Sleep(1000);
		//CloseHandle(hOutput);
		SetConsoleTextAttribute(hOutput, bInfo.wAttributes); // �ָ�ԭ��������
		cout<<"fuck you!"<<endl;
		
}
