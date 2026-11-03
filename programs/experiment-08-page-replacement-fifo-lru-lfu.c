#include <stdio.h>
int main() {
    int p[30], f[10], t[10], freq[10]={0};
    int n,m,i,j,k,hit,fault;
    char ch;

    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter page reference string: ");
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    printf("Enter number of frames: ");
    scanf("%d",&m);
    printf("Enter F=FIFO, L=LRU, U=LFU: ");
    scanf(" %c",&ch);

    for(i=0;i<m;i++) f[i]=-1,t[i]=0;
    hit=fault=0;

    for(i=0;i<n;i++) {
        for(j=0;j<m && f[j]!=p[i];j++);
        if(j<m) hit++,freq[j]++;
        else {
            fault++;
            for(j=0;j<m && f[j]!=-1;j++);
            if(j==m) {
                j=0;
                for(k=1;k<m;k++)
                    if(ch=='F' ? t[k]<t[j] :
                       ch=='L' ? t[k]<t[j] : freq[k]<freq[j]) j=k;
            }
            f[j]=p[i]; t[j]=i; freq[j]=1;
        }
        printf("%d\t",p[i]);
        for(j=0;j<m;j++) printf("%d ",f[j]);
        printf("\t%s\n",j==m ? " " : "");
    }
    printf("Total Page Faults = %d\n",fault);
    printf("Total Page Hits = %d\n",hit);
    return 0;
}
