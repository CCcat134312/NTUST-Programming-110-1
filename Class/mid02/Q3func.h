#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Apply Caesar cipher to the message.
/// </summary>
/// <param name="msg">The message string for encryption.</param>
/// <param name="shift">The shift amount.</param>
void caesar_cipher(char* msg, int shift)
{
	shift = (shift % 26 + 26) % 26;
	for (int i = 0; msg[i] != '\0'; i++)
	{
		//printf("%c", input[i]);
		if (msg[i] >= 'a' && msg[i] <= 'z')
		{
			msg[i] = (((msg[i] - 'a') + shift) % 26) + 'a';
		}
		else if (msg[i] >= 'A' && msg[i] <= 'Z')
		{
			msg[i] = (((msg[i] - 'A') + shift) % 26) + 'A';
		}
	}
}

/// <summary>
/// Print the result.
/// </summary>
/// <param name="msg">A message string.</param>
void print_result(char* msg)
{
	for (int i = 0; msg[i]; i++)
		putchar(msg[i]);
}
