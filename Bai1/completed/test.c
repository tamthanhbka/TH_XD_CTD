#include <stdio.h>
#include <string.h>
#include <ctype.h>
void read_stopw(char stopw_ar[][5])
{
    FILE *fptr;
    char str[5];
    int cnt = 0; // chỉ số của mảng

    fptr = fopen("stopw.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%s", str);
        if (strlen(str) == 0)
            continue;               // xâu đọc được là rỗng thì bỏ qua
        strcpy(stopw_ar[cnt], str); // copy chuỗi str vào mảng
        cnt++;
        fgets(str, 2, fptr); // đọc kí tự xuống dòng
    }
    fclose(fptr);
}

void print_ar(char stopw_ar[][5])
{
    for (int i = 0; i < 17; i++)
    {
        printf("%s\n", stopw_ar[i]);
    }
}
int check_text(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
    {
        return 1;
    }
    if(c == '\n' || c == '\r'){
        return 0;
    }
    if(c>=48 && c <=57){
        return 2;
    }
    if(c=='.'){
        return 3;
    }
    if(c ==' ')
    {
        return 4;
    }
}
int stopw_check(char stopw_ar[][5], char *str) {
	for (int i = 0; i < 17; i++) {
		if (strcmp(stopw_ar[i], str) == 0) return 1;
	}
	return 0;
}
void main()
{
    char stopw_arr[17][5];
    char str[256];
    char c;
    FILE *f;
    f = fopen("vanban.txt", "r");
    read_stopw(stopw_arr);

    while (!feof(f))
    {
        c = fgetc(f);
        if(check_text(c)==1){
            strncat(str,&c,1);
        }
        if(check_text(c)==3){
            if(str[strlen(str)-1]>='A' && str[strlen(str)-1]<='Z'){
                strncat(str, &c,1);
            }
        }if(check_text(c)==4){
            if(stopw_check(stopw_arr,str)==0){
                printf("%s\n",str);
            }
        }
    }
    // print_ar(stopw_arr);
    return 0;
}