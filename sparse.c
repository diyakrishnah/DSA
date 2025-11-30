#include<stdio.h>
#define MAX 100
struct Terms{
int r,c,v;
};
void readMat(int m,int n, int mat[m][n]){
int i,j;
printf("Enter the elements of %d X %d matrix",m,n);
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
    }
}
}
int compact(int m,int n,int mat[m][n],struct Terms compact[]){
int i,j,k=1;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        if (mat[i][j]!=0){
            compact[k].r=i;
            compact[k].c=j;
            compact[k].v=mat[i][j];
            k++;
        }
    }
}
compact[0].r=m;
compact[0].c=n;
compact[0].v=k-1;
return k;
}
void printc(struct Terms compact[]){
int i,total=compact[0].v;
printf("\n Row Col Value\n");
for (i=0;i<=total; i++){
    printf("%d   %d   %d\n",compact[i].r,compact[i].c,compact[i].v);
    }

}
void add(struct Terms comp1[],struct Terms comp2[],struct Terms sum[]){
    int i=1,j=1,k=1;
    int m= comp1[0].r;
    int n= comp1[0].c;
    sum[0].r=m;
    sum[0].c=n;
    while(i<=comp1[0].v&&j<=comp2[0].v){
        if (comp1[i].r<comp2[j].r||comp1[i].r==comp2[j].r&& comp1[i].c<comp2[j].c){
            sum[k]=comp1[i];
            k++,i++;
        }
        else if (comp2[j].r<comp1[i].r||comp2[j].r==comp1[i].r&& comp2[j].c<comp1[i].c){
            sum[k]=comp2[j];
            k++,j++;
    }
    else{
        int val =comp1[i].v+comp2[j].v;
        if(val!=0){
            sum[k].r=comp1[i].r;
            sum[k].c=comp1[i].c;
            sum[k].v=val;
            k++;
        }
        i++,j++;
    }

}
while(i<=comp1[0].v){
    sum[k++]=comp1[i++];
}
while(j<=comp2[0].v){
    sum[k++]=comp2[j++];
}
sum[0].v=k-1;
}
void trans(struct Terms mat[],struct Terms trans[]){
int i,j,k=1;
int m= mat[0].r;
int n= mat[0].c;
int num =mat[0].v;
trans[0].r=n;
trans[0].c=m;
trans[0].v=num;
for(i=0;i<n;i++){
    for(j=1;j<=num;j++){
        if(mat[j].c==i){
            trans[k].r=mat[j].c;
            trans[k].c=mat[j].r;
            trans[k].v=mat[j].v;
            k++;
        }
    }
}
}
int main(){
    int m,n;
    int mat1[MAX][MAX],mat2[MAX][MAX];
    struct Terms comp1[MAX],comp2[MAX],sum[MAX],transp[MAX];
    printf("Enter the number of rows and colums");
    scanf("%d %d",&m,&n);
    printf("Enter the terms of mat1");
    readMat(m,n,mat1);
    printf("Enter the terms of mat2");
    readMat(m,n,mat2);
    printf("compactForm of mat 1");
    int size1=compact(m,n,mat1,comp1);
    printc(comp1);
    printf("compactForm of mat 2");
    int size2=compact(m,n,mat2,comp2);
    printc(comp2);
    printf("sum");
    add(comp1,comp2,sum);
    printf("compact of sum");
    printc(sum);
    printf("transpose:");
    trans(sum,transp);
    printc(transp);
return 0;
}
