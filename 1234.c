#include <stdio.h>
#include <string.h>

const char abc[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int is_bukva(const char c)
{
for(int x = 0; x < strlen(abc); x++)
if(c == abc[x]) return 1;
return 0;
}

int main()
{
const int size = 100;
char s[size];
fgets(s,size,stdin);
printf("Всі символи після !\n");
int find_simbol = 0;
for(int x = 0; x < strlen(s); x++)
{
if(find_simbol) putchar(s[x]);
else if(s[x] == '!') find_simbol = 1;
}
printf("\n\n");

int count_words = 0;
for(int x = 0; x < strlen(s); x++)
{
if(x > 0)
{
if( is_bukva(s[x-1]) && ! is_bukva(s[x]) ) count_words++;
else if( ( x == strlen(s) - 1 ) && is_bukva(s[x]) ) count_words++;
}
}

printf("Кількість слів -- %d.\n", count_words);

return 0;
}
