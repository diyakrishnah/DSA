#include<stdio.h>
struct poly{
int c;
int e;
};
int main(){
struct poly p1[100];
struct poly p2[100];
struct poly r[200];
int n1, n2,i,j,k=0;
printf("enter the no of terms of p1");
scanf("%d",&n1);
printf("of p2:");
scanf("%d",&n2);
printf("Enter the terms of p1 in descending order of expo\n");
for(i=0;i<n1;i++){
        printf("enter the coefficient and exponent of %d :",i+1);
        scanf("%d %d",&p1[i].c,&p1[i].e);
}
printf("Enter the terms of p2 in descending order of expo\n");
for(j=0;j<n2;j++){
        printf("enter the coefficient and exponent of %d :",j+1);
        scanf("%d %d",&p2[j].c,&p2[j].e);
}
i=0,j=0;
while(i<n1&& j<n2){
    if(p1[i].e==p2[j].e){
        r[k].c=p1[i].c+p2[j].c;
        r[k].e=p1[i].e;
        i++,j++,k++;
    }
    else if(p1[i].e>p2[j].e){
        r[k].c=p1[i].c;
        r[k].e=p1[i].e;
        i++,k++;
    }
    else{
        r[k].c=p2[j].c;
        r[k].e=p2[j].e;
        j++,k++;
    }

}
while(i<n1){
    r[k]=p1[i];
    i++,k++;
}
while(j<n2){
    r[k]=p2[j];
    j++,k++;
}

printf("the resultend polynomial is:");
for(int l=0;l<k;l++){
    printf("%d x ^%d",r[l].c,r[l].e);
    if(l!=k-1){
        printf("+");
}
}
return 0;
}
