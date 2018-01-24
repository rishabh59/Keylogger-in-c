/* C Program - Decrypt Files */
		
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int Key;
	char ch, choice, fname[20]="Keylogs.txt";
	FILE *fps, *fpt;
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nPress any key to exit...");
		getch();
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		getch();
		exit(9);
	}
	printf("Enter the Key:");
	scanf("%d",&Key);
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-Key;
			fputc(ch, fps);
		}
	}
	printf("File %s decrypted successfully..!!",fname);
	fclose(fps);
	fclose(fpt);
	getch();
}
