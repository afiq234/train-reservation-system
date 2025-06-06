
//---------------------------train reservation project by using c programming language--------------------------
//---------------------------------------library-----------------------------------------
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
//---------------------------------------header file close-------------------------------------------
//---------------------------------------user define function start----------------------------------
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void searchPassenger();
void viewpassenger();
void addtrain();
void dlttrain();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();
//-----------------------------------------user define function close-----------------------------------

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//-----------------------------------------structure start----------------------------------------------
struct adddata
{
	char si[10];
	char train_number[10];
	char train_name[20];
	char start[10];
	char destination[10];
	char price[10];
	int seat;
	char time[10];
} add[1000];

struct bookticket
{
	char train_number[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
} book[1000];

int found, sizeQuery, loopers, b = 0;

char query[20], fullname[20];

//---------------------------------------structure close----------------------------------------------
//---------------------------------------global variable----------------------------------------------
int k = 0, u = 0;
char trn_nmbr[100], name[100], phn[100];
//---------------------------------------main function start------------------------------------------
int main()
{
	system("cls");

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|             ooOOOO                            |\n");
	printf("\t\t|            oo      _____                      |\n");
	printf("\t\t|           _I__n_n__||_|| ________             |\n");
	printf("\t\t|         >(_________|_7_|-|______|             |\n");
	printf("\t\t|          /o ()() ()() o   oo  oo              |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                  GROUP12                      |\n");
	printf("\t\t|        |  Train Rservation System  |          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");

	printf(" \n Press any key to continue:");

	getch();
	system("cls");

	aread();
	viewpassengers_read();
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t     %s\n", ctime(&currentTime));

	printf("\n\t\t\t======================================\n");
	printf("\t\t\t*******TRAIN RESERVATION SYSTEM*******\n");
	printf("\t\t\t======================================\n");
	printf("\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n");
	printf("\n\n\t\t\t\t      MENU\n");
	printf("\t\t\t             ------");
	printf("\n\t\t\t[1] VIEW INFORMATION\n");
	printf("\n\t\t\t[2] BOOK TICKET\n");
	printf("\n\t\t\t[3] CANCEL TICKET\n");
	printf("\n\t\t\t[4] ADMIN\n");
	printf("\n\t\t\t[5] SEARCH RESERVATION");
	printf("\n\n\t\t\t[6] EXIT\n");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\tENTER YOUR CHOICE: ");

	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		viewinfo();
		break;
	case 2:
		bookticket();
		break;
	case 3:
		cancelticket();
		break;
	case 4:
		password();
		break;
	case 5:
		searchPassenger();
		break;
	case 6:
		system("cls");

		printf("\n\t\t\t =========================================\n");
		printf("\t\t\t *******TRAIN RESERVATION SYSTEM*******\n");
		printf("\t\t\t ===============================================\n");
		printf("\n\n\t\t\tPROJECT BY\n\n");
		printf("\t\t\t\t***GROUP12***\n");
		getch();
		exit(0);
		break;
	default:
		system("cls");
		printf("\n\t\t\t==============================================\n");
		printf("\t\t\t   *******TRAIN RESERVATION SYSTEM*******\n");
		printf("\t\t\t   ==============================================\n");
		printf("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
		printf("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
		getch();
		system("cls");
		main();
	}
	return 0;
}
//---------------------------------------main function close--------------------------------------------------
//---------------------------------------book ticket function-----------------------------------------------
void bookticket()
{
	int c, j, n, i, found = -1;
	char v, train_number[10];
	system("cls");
	aread();
	printf("\n\n\t\t\t============================================");
	printf("\n\t\t\t**********TRAIN RESERVATION SYSTEM**********\n");
	printf("\t\t\t==================================================");
	printf("\n\n\t\t\thow many ticket do you want to buy: ");
	scanf("%d", &n);
	for (j = u; j < u + n; j++)
	{
		printf("\n\n\t\t\tEnter train number: ");
		scanf("%s", book[j].train_number);
		for (i = 0; i < k; i++)
		{
			if (strcmp(book[j].train_number, add[i].train_number) == 0)
			{
				if (add[i].seat == 0)
				{
					printf("\n\n\t\t\tnot available seat");

					getch();
					system("cls");
					main();
				}
				else
				{
					found = 1;
					printf("\n\t\t\tenter book %d no ticket: ", j + 1);
					printf("\n\t\t\tenter date: ");
					scanf("%s", book[j].date);
					printf("\n\t\t\tenter your name: ");
					scanf("%s", book[j].name);
					printf("\n\t\t\tenter your phone number: ");
					scanf("%s", book[j].phone);
					printf("\n\t\t\tseat number : %d", add[i].seat);
					book[j].seat = add[i].seat;

					bookticket_write();
					add[i].seat--;
					awrite();
				}
			}
		}
		if (found == -1)
		{
			printf("\n\n\t\t\ttrain not found!!!");
			getch();
			system("cls");
			main();
		}
	}
	u = j;
	bookticket_write();
	printf("\n\n\t\t\tenter '1' for main menu & press any key to exit: ");
	scanf("%d", &c);
	if (c == 1)
	{
		system("cls");
		main();
	}
	if (c != 1)
	{
		exit;
	}
}
//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
	viewpassengers_read();
	char pnnmbr[100];
	int location = -1, e;
	printf("\n\n\t\t\tenter phone number: ");
	scanf("%s", pnnmbr);
	for (e = 0; e < u; e++)
	{
		if (strcmp(pnnmbr, book[e].phone) == 0)
		{
			location = e;
			break;
		}
	}
	if (location == -1)
	{
		printf("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
		getch();
		system("cls");
		main();
	}
	else
	{
		for (e = location; e < u; e++)
		{
			strcpy(book[e].date, book[e + 1].date);
			strcpy(book[e].train_number, book[e + 1].train_number);
			strcpy(book[e].name, book[e + 1].name);
			strcpy(book[e].phone, book[e + 1].phone);
			bookticket_write();
		}
		u--;
		bookticket_write();
		printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
		getch();
		system("cls");
		main();
	}
}
//-------------------------------------admin portal function----------------------------------------
void admin()
{
	int chhh;
	system("cls");
	printf("\n     ==================================================================");
	printf("\n     ********************TRAIN RESERVATION SYSTEM*******************");
	printf("\n     ====================================================================");
	printf("\n\n");
	printf("           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n");
	printf("\n\n");
	printf("              ************************************\n");
	printf("              ||      CHOOSE YOUR OPERATION     ||\n");
	printf("              ||--------------------------------||\n");
	printf("              ||      [1] VIEW PASSENGERS       ||\n");
	printf("              ||      [2] ADD TRAIN             ||\n");
	printf("              ||      [3] DELETE TRAIN          ||\n");
	printf("              ||      [4] BACK                  ||\n");
	printf("              ||                                ||\n");
	printf("              ************************************\n\n");
	printf("     **********************************************************\n");
	printf("\n\t\tENTER YOUR CHOICE: ");
	scanf("%d", &chhh);

	switch (chhh)
	{
	case 1:
		viewpassenger();
		break;
	case 2:
		addtrain();
		break;
	case 3:
		dlttrain();
		break;
	case 4:
		system("cls");
		getch();
		main();
		break;
	default:
		getch();
		printf("\n\t\t\tyou entered wrong KEY!!!!");
		getch();
		system("cls");
		main();
	}
	getch();
}
//-----------------------------password function----------------------------------
void password()
{

	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "user";
	char pass[10] = "pass";
	do
	{

		printf("\n  =======================  LOGIN FORM  =======================\n  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13)
				break;
			else
				printf("*");
			i++;
		}
		pword[i] = '\0';
		// char code=pword;
		i = 0;
		// scanf("%s",&pword);
		if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
		{
			printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");

			getch(); // holds the screen
			system("cls");
			admin();

			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch(); // holds the screen
			system("cls");
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();
	}
	system("cls");
	main();
}
//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
	aread();
	char train[100];
	int location = -1, f;
	printf("\n\n\tenter train number: ");
	scanf("%s", train);
	for (f = 0; f < k; f++)
	{
		if (strcmp(train, add[f].train_number) == 0)
		{
			location = f;
			break;
		}
	}
	if (location == -1)
	{
		printf("\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
		getch();
		system("cls");
		admin();
	}
	else
	{
		for (f = location; f < k; f++)
		{
			strcpy(add[f].si, add[f + 1].si);
			strcpy(add[f].train_number, add[f + 1].train_number);
			strcpy(add[f].train_name, add[f + 1].train_name);
			strcpy(add[f].start, add[f + 1].start);
			strcpy(add[f].destination, add[f + 1].destination);
			strcpy(add[f].price, add[f + 1].price);

			strcpy(add[f].time, add[f + 1].time);
			awrite();
		}
		k--;
		awrite();
		printf("\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>");
		getch();
		system("cls");
		admin();
	}
}
//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
	int a, j;
	system("cls");
	viewpassengers_read();
	printf("\n\t\t\t       **********************************************************");
	printf("\n\t\t\t       ********************TRAIN RESERVATION SYSTEM********************");
	printf("\n\t\t\t       **********************************************************");
	printf("\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n");
	printf("\n\t\t\t**********************************************************************************\n");

	int n = sizeof(book->seat) / sizeof(book[0].seat);

	for (j = 0; j < u; j++)
	{
		insertionSort(book->seat, n);
		printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d", book[j].train_number, book[j].name, book[j].phone, book[j].date, book[j].seat);
		book[j].seat++;
	}
	printf("\n\t\t\t**********************************************************************************\n");
	printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		main();
	}
	if (a == 0)
	{
		system("cls");
		admin();
	}
}
//--------------------------------------add train function--------------------------------------------
void addtrain()
{
	system("cls");
	int ch;
	aread();
	int i, a;
	printf("\n\t\t     **********************************************************");
	printf("\n\t\t     ********************TRAIN RESERVATION SYSTEM********************");
	printf("\n\t\t     **********************************************************");
	printf("\n\n\t\t\thow many trains do you want to add: ");
	scanf("%d", &a);
	for (i = k; i < k + a; i++)
	{
		printf("\n\t\t\tenter %d train details: ", i + 1);
		printf("\n\t\t\tenter serial number: ");
		scanf("%s", add[i].si);
		printf("\n\t\t\tenter train number: ");
		scanf("%s", add[i].train_number);
		printf("\n\t\t\tenter train name: ");
		scanf("%s", add[i].train_name);
		printf("\n\t\t\tenter start place: ");
		scanf("%s", add[i].start);
		printf("\n\t\t\tenter destination place: ");
		scanf("%s", add[i].destination);
		printf("\n\t\t\t enter price: ");
		scanf("%s", add[i].price);

		printf("\n\t\t\t enter seat: ");
		scanf("%d", &add[i].seat);
		printf("\n\t\t\t enter time: ");
		scanf("%s", add[i].time);
	}

	printf("\n\n\t\t\tconfirm train: (y=1/n=0):- ");
	scanf("%d", &ch);
	if (ch == 1)
	{
		awrite();
		k = i;
		awrite();
		system("cls");

		printf("\n\n\t\t\t**********************************************************");
		printf("\n\t\t\t********************TRAIN RESERVATION SYSTEM********************");
		printf("\n\t\t\t**********************************************************");
		printf("\n\n");
		printf("\n\t\t\t\t   **********************************");
		printf("\n\t\t\t\t   *<<<<<train add successfully>>>>>*");
		printf("\n\t\t\t\t   **********************************");
		getch();
		system("cls");
		main();
	}
	if (ch == 0)
	{
		system("cls");
		admin();
	}
	if ((ch != 1) && (ch != 0))
	{
		system("cls");
		main();
	}
}
//-----------------------------------view information function--------------------------------------
void viewinfo()
{
	int ch, i;
	system("cls");
	aread();
	printf("\n\t\t     **********************************************************");
	printf("\n\t\t     ********************TRAIN RESERVATION SYSTEM********************");
	printf("\n\t\t     **********************************************************");
	printf("\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n");
	for (i = 0; i < k; i++)
	{
		printf("    %s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%d\t%s\n", add[i].si, add[i].train_number, add[i].train_name, add[i].start, add[i].destination, add[i].price, add[i].seat, add[i].time);
	}
	printf("    ***********************************************************************************************\n");
	printf("\n\t\t\tpress '1' for main menu & press any key for exit:  ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		system("cls");
		main();
		break;
	default:
		exit(0);
	}
}

void searchPassenger()
{

	int ch;
	char userReservation[1000];
	char another = 'y';

	// viewpassengers_read2();
	FILE *booklist;
	booklist = fopen("booklist.txt", "rb");

	system("cls");

	while (another == 'y')
	{

		printf("\nEnter user reservation name : ");
		scanf("%s", userReservation);

		rewind(booklist);

		while (fread(&book, sizeof(book), 1, booklist) == 1)
		{
			if (strcmp(book->name, userReservation) == 0)
			{

				printf("\n\n RESERVATION RECORD FOUND!!\n\n");

				// fprintf(booklist, "DATE            : %s \n", sizeof(book), book->train_number);

				printf("NAME            : %s \n", book->name);
				printf("DATE            : %s \n", book->date);
				printf("SEAT            : %d \n", book->seat);
				printf("TRAIN NUMBER    : %s \n", book->train_number);
				break;
			}
			else if (strcmp(book->name, userReservation) >= 0)
			{

				printf("\n\n RESERVATION RECORD FOUND!!\n\n");

				printf("NAME            : %s \n", book->name);
				printf("DATE            : %s \n", book->date);
				printf("SEAT            : %d \n", book->seat);
				printf("TRAIN NUMBER    : %s \n", book->train_number);

				break;
			}
			else
			{
				printf("\n\n RESERVATION RECORD NOT FOUND!!\n\n");
			}
		}

		printf("\n\n");

		system("pause");

		printf("\nDo you want to search another record? (Y/N) :");
		scanf("%s", &another);

		system("cls");
	}

	printf("\nWould you like to proceed to main menu, or exit the system? \n\n[1]Main Menu  [2]Exit\nA: ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		system("cls");
		main();
		break;
	default:
		exit(0);
	}

	printf("\n\n");
}

//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
	FILE *booklist;
	booklist = fopen("booklist.txt", "w");
	fwrite(&book, sizeof(book), 1, booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport = fopen("booklistreport.txt", "w");
	fwrite(&u, sizeof(u), 1, booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist = fopen("booklist.txt", "r");
	fread(&book, sizeof(book), 1, booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport = fopen("booklistreport.txt", "r");
	fread(&u, sizeof(u), 1, booklistreport);
	fclose(booklistreport);
}

void viewpassengers_read2()
{
	FILE *booklist;
	booklist = fopen("booklist.txt", "r");
	rewind(booklist);
	fread(&book, sizeof(book), 1, booklist);
	fclose(booklist);
}
//-----------------------------------------add train file start---------------------------------------------------
void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt", "w");
	fwrite(&add, sizeof(add), 1, train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt", "w");
	fwrite(&k, sizeof(k), 1, train_report);
	fclose(train_report);
}
void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt", "r");
	fread(&add, sizeof(add), 1, train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt", "r");
	fread(&k, sizeof(k), 1, train_report);
	fclose(train_report);
}
//----------------------------------------------------file close----------------------------------------------
//----------------------------------------------------program close----------------------------------------
