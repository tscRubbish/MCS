#include<iostream>
#include<cstring>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
using namespace std;
int N[3],latin[10][10];
void dfs(int n,int x,int y){
    if (x==n&&y==n) {
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (latin[latin[latin[y][x]][y]][y]!=x)
                    return;
            }
        }
        FILE* fp=fopen("QG5.txt","a");
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                fprintf(fp,"%d ",latin[i][j]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp,"\n");
        fclose(fp);
        return;
    }
    if (x==y) {
        dfs(n,x,y+1);
        return;
    }
    for (int i=1;i<=n;i++){
        //printf("%d %d %d\n",i,x,y);
        int flag=1;
        for (int j=1;j<x;j++)
            if (latin[j][y]==i) {
                flag=0;break;
            }
        for (int j=1;j<y;j++)
            if (latin[x][j]==i) {
                flag=0;break;
            }
        if (flag==0) continue;
        if (latin[i][x]==0||latin[latin[i][x]][x]==y||latin[latin[i][x]][x]==0){
            latin[x][y]=i;
            dfs(n,x+y/n,y%n+1);
            latin[x][y]=0;
        }
    }
}
int main(){
    int n;
    N[0]=5;N[1]=7;N[2]=8;
    for (int i=2;i<3;i++){
        memset(latin,0,sizeof(latin));
        n=N[i];
        for (int j=1;j<=n;j++){
            latin[j][j]=j;
        }
        printf("n= %d\n",n);
        dfs(n,1,2);
    }
}