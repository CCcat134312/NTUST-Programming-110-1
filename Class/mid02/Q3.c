// 凱薩密碼 n = 整數
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include "Q3func.h"

#define LEN 100

int main()
{
    char msg[LEN] = "Hello world!";
    int shift = 4;

    // Apply Caesar Cipher
    caesar_cipher(msg, shift);

    // Print the shifted result
    print_result(msg);

    return 0;
}
