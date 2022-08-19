#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef int element;
typedef struct word
{
    char w[256];
    int index;   // toa do theo cot cua tu
    int arr[10]; // toa do theo hang cua tu
} element;
struct list_data
{
    element data;
    struct list_data *next;
};
typedef struct list_data List;
int main(int argc, char *argv[])
{
    char stopw_ar[17][5];
    char str[256];
    read_vanban(stopw_ar, str);
    return 0;
}
int stopw_check(char stopw_ar[][5], char *str)
{
    for (int i = 0; i < 17; i++)
    {
        if (strcmp(stopw_ar[i], str) == 0)
            return 1;
    }
    return 0;
}
int check_point(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
            count++;
    }
    return count;
}
int check_ch(char *str)
{
    if (str[strlen(str) - 1] >= 97 && str[strlen(str) - 1] <= 122)
        return 1;
    return 0;
}
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
void read_vanban(char stopw_ar[][5], char *str)
{
    read_stopw(stopw_ar);
    FILE *f = fopen("vanban.txt", "r");
    int row = 1, index = 0;
    while (!feof(f))
    {
        index = fscanf(f, "%s", str);
        if (strcmp(str, "\n") == 0)
        {
            row++;
        }
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = tolower(str[i]);
        }
        if (str[0] >= 97 && str[0] <= 122)
        {
            if (stopw_check(stopw_ar, str) == 0)
            {
                if (check_point(str) == 0)
                {
                    if (check_ch(str) == 0)
                    {
                        str[strlen(str) - 1] = '\0';
                    }
                    printf("%s\n", str);
                }
                else if (check_point(str) == 1)
                {
                    str[strlen(str) - 1] = '\0';
                    printf("%s\n", str);
                }
                else
                {
                    printf("%s\n", str);
                }
            }
        }
        index++;
    }
    fclose(f);
}

List *MakeNull(List *First) // Khoi tao list rong
{
    while (!IsEmpty(First))
        First = DeleteHead(First);
    return First;
}
List *InsertMiddle(List *Prev, element X) // Them vao giua list
{
    List *TempNode;
    TempNode = (List *)malloc(sizeof(List));
    TempNode->data = X;
    TempNode->next = Prev->next;
    Prev->next = TempNode;
    return TempNode;
}
element Delete(List *Prev) // Xoa node
{
    element X;
    List *TempNode;
    TempNode = Prev->next;
    Prev->next = Prev->next->next;
    X = TempNode->data;
    free(TempNode);
    return X;
}
List *InsertToHead(List *First, element X) // them vao dau
{
    List *TempNode;
    TempNode = (List *)malloc(sizeof(List));
    TempNode->data = X;
    TempNode->next = First;
    return TempNode;
}
List *InsertToLast(List *First, element X) // Them vao cuoi
{
    List *NewNode;
    List *TempNode;
    NewNode = (List *)malloc(sizeof(List));
    NewNode->data = X;
    NewNode->next = NULL;
    TempNode = First;
    while (TempNode->next != NULL)
        TempNode = TempNode->next;
    TempNode->next = NewNode;
    return First;
}
List *DeleteHead(List *First) // xoa dau
{
    List *TempNode;
    TempNode = First->next;
    free(First);
    return TempNode;
}
List *DeleteLast(List *First) // xoa cuoi
{
    List *root;
    root = First;
    while (root->next->next != NULL)
        root = root->next;
    free(root->next);
    root->next = NULL;
    return First;
}
int IsEmpty(List *First) // Kiem tra list rong
{
    return !First;
}

void Print(List *First)
{
    /*Code tuy vao yeu cau cua tung bai*/
}
