#include "stdio.h"
#include "stdlib.h"
#include <Windows.h>
#define LENGTH 15

HANDLE hOutput, hOutBuf;//����̨��Ļ���������
COORD coord = { 0,0 };
//˫���崦����ʾ
DWORD bytes = 0;
char data[LENGTH][LENGTH];

int main()
{
    //�����µĿ���̨������
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //���������������Ĺ��
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);

    while (1)
    {
            int i, j;
    for (i = 0; i < LENGTH; i++)
    {
        for (j = 0; j < LENGTH; j++)
        {
            data[i][j]='*';
        }
    }
    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutBuf, data[i], LENGTH, coord, &bytes);
    }
    //�����µĻ�����Ϊ���ʾ����
    SetConsoleActiveScreenBuffer(hOutBuf);
    Sleep(500);
    for (i = 0; i < LENGTH; i++)
    {
        for (j = 0; j < LENGTH; j++)
        {
            data[i][j] = '-';
        }
    }
    for (i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutput, data[i], LENGTH, coord, &bytes);
    }
    �����µĻ�����Ϊ���ʾ����
    SetConsoleActiveScreenBuffer(hOutput);
    Sleep(500);
    }
}
