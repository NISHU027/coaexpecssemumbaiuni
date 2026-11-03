#include <stdio.h>
#include <string.h>

int main() {
    char d[10][10], s1[10][10], s2[10][10];
    int n,i,j;

    printf("Enter number of instructions: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Instruction %d (dest src1 src2): ",i+1);
        scanf("%9s%9s%9s",d[i],s1[i],s2[i]);
    }

    printf("\n--- DATA HAZARD ANALYSIS ---\n");
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++) {
        if(!strcmp(d[i],s1[j]) || !strcmp(d[i],s2[j]))
          printf("RAW: I%d -> I%d\n",i+1,j+1);
        if(!strcmp(s1[i],d[j]) || !strcmp(s2[i],d[j]))
          printf("WAR: I%d -> I%d\n",i+1,j+1);
        if(!strcmp(d[i],d[j]))
          printf("WAW: I%d -> I%d\n",i+1,j+1);
      }
    return 0;
}
