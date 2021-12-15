#include <stdio.h>
#include <windows.h>

int main(void)
{
    puts("Hello World!");
    MessageBox(NULL, "Hello World!", "Title", 0);
    GetStockObject(0);
    return 0;
}