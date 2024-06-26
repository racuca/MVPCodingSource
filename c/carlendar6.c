	/* This is a program which accepts any month and year,
	   displays the calendar.
	   Created By: Debabrata Das
	   Dated: 04/05/2004
	   Last Modified: 04/01/2005				*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define LEAP_YEAR ((Year%4==0 && Year%100 != 0)||Year%400==0)
#define TRUE 1
#define CH '-'
#define MAX_NO 91

int MonthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *MonthName[]={"January","February","March","April","May","June","July",
		"August","September","October","November","Decembeer"};
char *MonthName1[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP",
			"OCT","NOV","DEC"};

/*=======================================================================*/
/*==================== FUNCTION TO GET KEY CODE =========================*/
getkey()
{
    return getchar();
	/*union REGS i,o;
	while(!kbhit())
		;
	i.h.ah = 0;
	int86(22,&i,&o);
	return (o.h.ah);*/
}
/*=======================================================================*/
/*================ FUNCTION TO CALCULATE ZELLER'S ALGORITHM =============*/
int getZeller(int Month,int Year)
{
	int Day = 1, ZMonth, ZYear, Zeller;
	if(Month < 3)
		ZMonth = Month+10;
	else
		ZMonth = Month-2;
	if(ZMonth > 10)
		ZYear = Year-1;
	else
		ZYear = Year;
	Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
			(int)((ZYear%100)/4)-2*(int)(ZYear/100)+
			(int)(ZYear/400)+77)%7;

    printf("input %d %d => %d", Month, Year, Zeller);
	return Zeller;
}
/*=======================================================================*/
void PrintFile(int M,int Y, int Z)
{
	int i,j;
	char filename[12];
	char stryear[5];
	FILE *stream;

	strcpy(filename,MonthName1[M-1]);
	itoa(Y,stryear,10);
	strcat(filename,stryear);
	strcat(filename,".txt");

	if((stream=fopen(filename,"w"))==NULL)
	{
		printf("\nError-cannot create file.");
		getch();
		exit(1);
	}
	fprintf(stream,"\n\t\t\t%s %d\n\n\t",MonthName[M-1],Y);
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");
	fprintf(stream,"\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\t");
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");
	/* setting starting position */
	fprintf(stream,"\n");
	for(i = 1; i <= Z; i++)
		fprintf(stream,"\t -");
	j = Z;
	/* printing dates */
	for(i = 1; i <= MonthDay[M-1]; i++)
	{
		if(j++ % 7 == 0)
			fprintf(stream,"\n");
		fprintf(stream,"\t%2d",i);
	}
	fprintf(stream,"\n\t");
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");
	fprintf(stream,"\n\n\t\tCreated by: Debabrata Das [debabrata.dd@gmail.com]");
	fclose(stream);
}
void printchar(char c)
{
	int i=1;
	printf("\n\t");
	for(i=1;i<=51;i++)
		printf("%c",c);
	printf("\n");

}

/*======================= MAIN FUNCTION =================================*/
void main(void)
{
	int Month, Year, Zeller;
	int i, j, KeyCode;


Top:    /* goto statement */
	//textcolor(WHITE);
	//clrscr();
	printf("\n\tThis program shows calendar of \n");
	printf("\n\ta given month. Enter month, year...format is mm-yyyy.\n");
			/* taking input */
	while(TRUE)
	{
		fflush(stdin);
		printf("\n\n\tEnter mm-yyyy: ");
		scanf("%d-%d", &Month, &Year);
		if(Year < 0)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Year < 100)
			Year += 1900;
		if(Year < 1582 || Year > 4902)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Month < 1 || Month > 12)
		{
			printf("\nInvalid month value...");
			continue;
		}
		break;
	}	/* End of while loop */
	do
	{
		/* calculating day of 1st date of given month */
		Zeller = getZeller(Month,Year);
		//clrscr();
		printf("\n\n\t\t\t");

		/* printing the corresponding month name */
		//textbackground(Month);
		printf("%s %d\n",MonthName[Month-1],Year);
		//textbackground(BLACK);

		/* adjusting February in case of Leap Year */
		MonthDay[1] = LEAP_YEAR ? 29 : 28;

		/* giving output */
		printchar(CH);

		//textcolor(12); /* LIGHTRED */
		printf("\t"); printf("SUN");
		//textcolor(LIGHTGREEN);
		printf("     MON     TUE     WED     THU     FRI    SAT");
		//textcolor(7);

		printchar(CH);

		/* setting starting position */
		for(i = 1; i <= Zeller; i++)
			printf("\t -");
		j = Zeller;
		/* printing dates */
		for(i = 1; i <= MonthDay[Month-1]; i++)
		{
			if(j++ % 7 == 0)
			{
				printf("\n\t");
				//textcolor(12);
				printf("%2d",i);
				//textcolor(WHITE);
			}
			else
				printf("      %2d",i);
		}

		printchar(CH);
		printf("\n\n\t\t(*) Use Left,Right,Up & Down Arrow.");
		printf("\n\n\t\t(*) Press I for New Month & Year.");
		printf("\n\n\t\t(*) Press P for Print to File.");
		printf("\n\n\t\t(*) Press ESC for Exit.\n\n\n\t\t");

		//textcolor(11);
		//textbackground(9);
		printf("Created by: Debabrata Das [debabrata.dd@gmail.com]");
		//textcolor(WHITE);
		//textbackground(BLACK);

		KeyCode = getkey();         /* getting Key Code */
		if(KeyCode == 72)           /* Up Arrow */
			Year++;
		if(KeyCode == 80)           /* Down Arrow */
			Year--;
		if(KeyCode == 77)           /* Right Arrow */
		{
			Month++;
			if(Month > 12)
			{
				Month = 1;
				Year++;
			}
		}
		if(KeyCode == 75)            /* Left Arrow */
		{
			Month--;
			if(Month < 1)
			{
				Month = 12;
				Year--;
			}
		}
		if(KeyCode == 25)             /* Code of P */
			PrintFile(Month,Year,Zeller);
		if(KeyCode == 23)             /* Code of I */
			goto Top;
	}while(KeyCode != 1);	/* End of do-while loop */
	exit(0);
}		/* End of main() */
/*=======================================================================*/