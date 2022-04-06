#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include "myString.h"
int main(void)
{
	string ori = ReadLine();
	string replace = ReadLine();
	string templete = ReadLine();
	PrintString(StringReplace(ori, replace, templete));
	return 0;
}