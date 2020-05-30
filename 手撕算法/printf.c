#include <stdio.h>
#include <stdlib.h>


void Itoa(int num, char* pStr){
    if(NULL == pStr){
        return;
    }
    int ntmp = num;
    int size = 0;
    while(0 != ntmp/10){
        size++;
        ntmp /= 10;
    }
    size++;

    for(int i = size-1; i >= 0; i--){
        pStr[i] = ntmp%10+'0';
        ntmp /= 10;
    }
    pStr[size] = '\0';
}

void print(const char* pFormat,...)
{
    char **pTemp = (char**)&pFormat;
    while('\0' != *pFormat){
        if('%' == *pFormat){
            pFormat++;
            pTemp++;
            switch(*pFormat){
                case 'd':
                case 'D':
                {
                    int ntmp = *((int*)pTemp);
                    char szBuf[255] = "";
                    Itoa(ntmp,szBuf);
                    for(int i = 0; '\0' != szBuf[i]; i++){
                        putchar(szBuf[i]);
                    }
                    break;
                }
                case 'c':
                case 'C':
                {
                    char ch = *((char*)pTemp);
                    putchar(ch);
                    break;
                }
                case 's':
                case 'S':
                {
                    char *ptmp = (char*)pTemp;
                    for(int i = 0; '\0' != ptmp[i]; i++){
                        putchar(ptmp[i]);
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }else{
            putchar(*pFormat);
        }
        pFormat++;
    }
}

int main(){
    print("number:%d",10);
}