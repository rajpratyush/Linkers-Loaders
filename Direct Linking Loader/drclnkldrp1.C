#include<stdio.h>
#include<conio.h>
#include<string.h>
struct estab
{
  char csname[10];
  char extsym[10];
  int address;
  int length;
}es[20];
void main()
{
  char input[10],name[10],symbol[10],ch;  int count=0,progaddr,csaddr,add,len;
  FILE *fp1,*fp2;
  clrscr();
  fp1=fopen("LINP.DAT","r");
  fp2=fopen("LOADMAP.DAT","w");
  printf("\n\nEnter the address where the program has to be loaded : ");
  scanf("%x",&progaddr);
  csaddr=progaddr;
  fprintf(fp2,"CS_NAME\tEXT_SYM_NAME\tADDRESS\tLENGTH\n");
  fprintf(fp2,"--------------------------------------\n");
  fscanf(fp1,"%s",input);
  while(strcmp(input,"END")!=0)
  {
   if(strcmp(input,"H")==0)
   {
    fscanf(fp1,"%s",name);
    strcpy(es[count].csname,name);
    strcpy(es[count].extsym,"  ");
    fscanf(fp1,"%x",&add);
    es[count].address=add+csaddr;
    fscanf(fp1,"%x",&len);
    es[count].length=len;
    fprintf(fp2,"%s\t%s\t\t%x\t%x\n\n",es[count].csname,es[count].extsym,es[count].address,es[count].length);
    count++;
   }
   else if(strcmp(input,"D")==0)
   {
    fscanf(fp1,"%s",input);
    while(strcmp(input,"R")!=0)
    {
     strcpy(es[count].csname,"  ");
     strcpy(es[count].extsym,input);
     fscanf(fp1,"%x",&add);
     es[count].address=add+csaddr;
     es[count].length=0;
     fprintf(fp2,"%s\t%s\t\t%x\t%x\n\n",es[count].csname,es[count].extsym,es[count].address,es[count].length);
     count++;
     fscanf(fp1,"%s",input);
    }
    csaddr=csaddr+len;
   }
   else if(strcmp(input,"T")==0)
   {
    while(strcmp(input,"E")!=0)
      fscanf(fp1,"%s",input);
   }
   fscanf(fp1,"%s",input);
  }
  fprintf(fp2,"--------------------------------------");
  fcloseall();
  printf("\n The contents of output file:\n\n");
  fp2=fopen("LOADMAP.DAT","r");
  ch=fgetc(fp2);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp2);
  }
  fclose(fp2);
  getch();
}