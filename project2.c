#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct book
{
	struct date
	{
		int day,month,year;
	}dop;
	int id,price,pages;
	char book_name[30],Author_name[30],book_type[30];
	
}book;
void store(book*,int);
void display_id(book*,int);
void display(book*,int);
void greater(book*,int);
void lower(book*,int);
void search_author(book*,int);
void search_book(book*,int);
void search_type(book*,int);
void min_price(book*,int);
void max_price(book*,int);
void change_price(book*,int);
void searchby_date(book*,int);
void second_max(book*,int);
void max_min_pages(book*,int);
void sort(book*,int);
void exit();
void main()
{
	int n,i,ch;
	printf("\t\tEnter the No of book data want to store :");
	scanf("%d",&n);
	book b[n];
	store(b,n);
	while(1)
	{
		printf("\n_______________________________________________________________________________\n");
		printf("\n\t\t\t-----  Menu  -----\n");
		printf("\n 1. Search book : ");
		printf("\n 2. List of all books ");
		printf("\n 3. display book name whose price > 200");
		printf("\n 4. display books name whose price < 200");
		printf("\n 5. Search by author name ");
		printf("\n 6. Search by Book name ");
		printf("\n 7. Search by Book type ");
		printf("\n 8. Search book of minimum price"); 
		printf("\n 9. Search book of maximum price");
		printf("\n 10.update Specific book ");
		printf("\n 11.Search by date of publication ");
		printf("\n 12.find second max-min price book ");
		printf("\n 13.Find max-min pages book ");
		printf("\n 14.sort table of books ");
		printf("\n 15.exit");
		printf("\n_______________________________________________________________________________");
		printf("\n-------------------------------------------------------------------------------\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : display_id(b,n);
			break;
			case 2 : display(b,n);
			break;
			case 3 : greater(b,n);
			break; 
			case 4 : lower(b,n);
			break;
			case 5 : search_author(b,n);
			break;
			case 6 : search_book(b,n);
			break;
			case 7 : search_type(b,n);
			break;
			case 8 : min_price(b,n);
			break;
			case 9 : max_price(b,n);
			break;
			case 10: change_price(b,n);
			break;
			case 11: searchby_date(b,n);
			break; 
			case 12: second_max(b,n);
			break;
			case 13: max_min_pages(b,n);
			break;
			case 14: sort(b,n);
			break;
			case 15: exit(0);
		}
	
	}
}
void store(book* b,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n______________________________________________________________________________\n");
		printf("\t\t\tEnter the details of book -%d",i+1);
		printf("\n------------------------------------------------------------------------------\n");
		printf("Enter the id of book :");
		scanf("%d",&b[i].id);
		printf("Enter the name of book :");
		scanf("%s",&b[i].book_name);
		printf("Enter the Authro name of book :");
		scanf("%s",&b[i].Author_name);
		printf("Enter the pages of book :");
		scanf("%d",&b[i].pages);
		printf("Enter the price of book :");
		scanf("%d",&b[i].price);
		printf("\n\t\t\t1.crime\n\t\t\t2.history\n\t\t\t3.drama\n\t\t\t4.poetry\n\n");
		printf("Enter the type of book :");
		scanf("%s",&b[i].book_type);
		printf("Enter the date of publication of Book : \n");
		printf("\t\t\t Date  ::");
		scanf("%d",&b[i].dop.day);
		printf("\t\t\t Month ::");
		scanf("%d",&b[i].dop.month);
		printf("\t\t\t Year  ::");
		scanf("%d",&b[i].dop.year);
		
	}
}
void display_id(book* b,int n)
{
	int i,s,ch;
	printf("\t\t\t1.display by id\n\t\t\t2.display by Book name\n");
	printf("Enter your choice :");
	scanf("%d",&ch);
	printf("\n_________________________________________________________________________\n");
	if(ch==1)
	{
		int counter=0;
	printf("\nEnter the Book id to Search : ");
	scanf("%d",&s);
	printf("_________________________________________________________________________\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if(b[i].id==s)
		{
			printf("\nBook ID : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nBook Author : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook Price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
			counter ++;
		}
	}
	if(counter==0)
	printf("!!! Sorry No Such book Id found !!!");
	}
	if(ch==2)
	{
		char name[30];int counter=0;
		printf("Enter the name of book :");
		scanf("%s",&name);
		printf("_________________________________________________________________________\n");
		printf("-------------------------------------------------------------------------\n");
		for(i=0;i<n;i++)
		{
			if(strcmp(b[i].book_name,name)==0)
			{
				printf("\nBook ID : %d",b[i].id);
				printf("\nBook Name : %s",b[i].book_name);
				printf("\nBook Author : %s",b[i].Author_name);
				printf("\nBook Pages : %d",b[i].pages);
				printf("\nBook Price : %d",b[i].price);
				printf("\nBook Type : %s",b[i].book_type);
				printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
				counter ++;
			}
		}
		if(counter==0)
		{
			printf("!!! Sorry No Such book name found !!!");
		}	
	}
		
	}

void display(book* b,int n)
{
	int i;
     printf("\nList of All Books:\n");
     printf("_________________________________________________________________________\n");
     printf("-------------------------------------------------------------------------\n");
     printf("Book-Id Book-Name book-author Book-pages book_price Book-type Published-date \n");
     for(i=0;i<n;i++)
     {
          printf("%d\t%s\t  %s\t      %d\t  %d\t    %s\t%d %d %d\n",b[i].id,b[i].book_name,b[i].Author_name,b[i].pages,b[i].price,b[i].book_type,b[i].dop.day,b[i].dop.month,b[i].dop.year);
     }
}
void greater(book* b,int n)
{
	int i,j=0,c,f=0, counter=0;
	printf("\nDetails of book whose price >200 \n");
	printf("___________________________________________________________________\n");
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if(b[i].price>200)
		{
		
			printf("\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
			counter ++;
		}	
	}
		if(counter==0)
		{
			printf("!!! Sorry No Such book name found whose price !!!");
		}
}
void lower(book* b,int n)
{
	int i, counter=0;
	printf("\nDetails of book whose price < 200 \n");
	printf("___________________________________________________________________\n");
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if(b[i].price<200)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
			counter++;
		}
	}
		if(counter==0)
		{
			printf("!!! Sorry No Such book name found whose price lower than 200 !!!");
		}
}
void search_author(book* b,int n)
{
	int i,counter=0;
	char a[30];
	printf("\nDetails of all book of same author \n");
	printf("_________________________________________________________________________\n");
	printf("-------------------------------------------------------------------------\n");
	printf("Enter the name of book author to search : ");
	scanf("%s",&a);
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].Author_name,a)==0)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
			counter++;
		}
		
	}
		if(counter==0)
		{
			printf("!!! Sorry No Such book name author found !!!");
		}
}
void search_book(book* b,int n)
{
	int i,counter=0;
	char a[30];
	printf("\nDetails of book of given name  \n");
	printf("___________________________________________________________________\n");
	printf("-------------------------------------------------------------------\n");
	printf("Enter the name of book  to search : ");
	scanf("%s",&a);
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].book_name,a)==0)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
			counter++;
		}
	}
		if(counter==0)
		{
			printf("!!! Sorry No Such book name found !!!");
		}
}
void search_type(book* b,int n)
{
	int i,counter=0;
	char t[30];
	printf("\nDetails of book of given type  \n");
	printf("___________________________________________________________________\n");
	printf("----------------------------------------------------=--------------\n");
	printf("Enter the type of book  to search : ");
	scanf("%s",&t);
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].book_type,t)==0)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
		}
	}
		if(counter==0)
		{
			printf("!!! Sorry No Such book type found !!!");
		}
}
void min_price(book* b,int n)
{
	int minp,i,j=0;
	printf("\nDetails of book of minimum price :  \n");
	printf("___________________________________________________________________\n");
	printf("-------------------------------------------------------------------\n");
	minp=b[0].price;
	for(i=0;i<n;i++)
	{
		if(b[i].price<minp)
		{
			minp=b[i].price;
			j=i;
		}
	}
		printf("\n\nBook Id : %d",b[j].id);
		printf("\nBook Name : %s",b[j].book_name);
		printf("\nBook Pages : %d",b[j].pages);
		printf("\nBook price : %d",b[j].price);
		printf("\nBook Type : %s",b[j].book_type);
		printf("\nBook Published date :%d %d %d\n",b[j].dop.day,b[j].dop.month,b[j].dop.year);
}
void max_price(book* b,int n)
{
	int maxp,i,j=0;
	printf("\nDetails of book of maximum price :  \n");
	printf("___________________________________________________________________\n");
	printf("-------------------------------------------------------------------\n");
	maxp=b[0].price;
	for(i=0;i<n;i++)
	{
		if(b[i].price>maxp)
		{
			maxp=b[i].price;
			j=i;
		}
	}
		printf("\n\nBook Id : %d",b[j].id);
		printf("\nBook Name : %s",b[j].book_name);
		printf("\nAuthor Name : %s",b[j].Author_name);
		printf("\nBook Pages : %d",b[j].pages);
		printf("\nBook price : %d",b[j].price);
		printf("\nBook Type : %s",b[j].book_type);
		printf("\nBook Published date :%d %d %d\n",b[j].dop.day,b[j].dop.month,b[j].dop.year);
}
void change_price(book* b,int n)
{
	int i,ch,c,u,counter=0;
	printf("\t\t\t1.update price\n\t\t\t2.update book name\n\t\t\t3.update Book Author name\n\t\t\t4.update Book Type");
	scanf("%d",&u);
	if(u==1)
	{
		printf("----------------------------------------------------------------------------------\n");
		printf("\n\tEnter the Id of book whose price you want to change :");
		scanf("%d",&ch);
		for(i=0;i<n;i++)
		{
			if(b[i].id==ch)
			{
				printf("__________________________________________________________________\n");
				printf("\n----------------------------------------------------------------\n");
				printf("\nEnter the price of book want to change :");
				scanf("%d",&c);
				b[i].price=c;
			
				printf("\nDetails of book :");
				printf("__________________________________________________________________\n");
				printf("\n----------------------------------------------------------------\n");
				printf("\n\nBook Id : %d",b[i].id);
				printf("\nBook Name : %s",b[i].book_name);
				printf("\nAuthor Name : %s",b[i].Author_name);
				printf("\nBook Pages : %d",b[i].pages);
				printf("\nBook price : %d",b[i].price);
				printf("\nBook Type : %s",b[i].book_type);
				printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
				counter++;
			}
		}
			if(counter==0)
		{
			printf("!!! Sorry No Such book Id found !!!");
		}
	}
	if(u==2)
	{
		char name[30];
		int d,counter=0;
		printf("------------------------------------------------------------------------------\n");
		printf("\n\tEnter the Id of book whose Name you want to change :");
		scanf("%d",&d);
		{
			for(i=0;i<n;i++)
			{
				if(b[i].id==d)
				{
					printf("Enter the name :");
					scanf("%s",&name);
					
					strcpy(b[i].book_name,name);
					
					printf("\nDetails of book :");
					printf("_______________________________________________________________\n");
					printf("\n-------------------------------------------------------------\n");
					printf("\n\nBook Id : %d",b[i].id);
					printf("\nBook Name : %s",b[i].book_name);
					printf("\nAuthor Name : %s",b[i].Author_name);
					printf("\nBook Pages : %d",b[i].pages);
					printf("\nBook price : %d",b[i].price);
					printf("\nBook Type : %s",b[i].book_type);
					printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
					counter++;
				}
			}
					if(counter==0)
		{
			printf("!!! Sorry No Such book name found !!!");
		}
		}
	
		
	}
	if(u==3)
	{
		{
			char name[30];
			int d,counter=0 ;
			printf("------------------------------------------------------------------------------\n");
			printf("\n\tEnter the Id of book whose  Auhotr Name you want to change :");
			scanf("%d",&d);
			{
				for(i=0;i<n;i++)
				{
					if(b[i].id==d)
					{
						printf("Enter the Author name :");
						scanf("%s",&name);
						
						strcpy(b[i].Author_name,name);
					
						printf("\nDetails of book :");
						printf("_______________________________________________________________\n");
						printf("\n-------------------------------------------------------------\n");
						printf("\n\nBook Id : %d",b[i].id);
						printf("\nBook Name : %s",b[i].book_name);
						printf("\nAuthor Name : %s",b[i].Author_name);
						printf("\nBook Pages : %d",b[i].pages);
						printf("\nBook price : %d",b[i].price);
						printf("\nBook Type : %s",b[i].book_type);
						printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
						counter++;
					}
				}
					if(counter==0)
		{
			printf("!!! Sorry No Such book name found !!!");
		}
			}
		}
	}
	if(u==4)
	{
		char name[30];
		int a,counter=0,flag=0;
		printf("------------------------------------------------------------------------------\n");
		printf("\n\tEnter the Id of book whose Book Type you want to change :");
		scanf("%d",&a);
		for(i=0;i<n;i++)
		{
			if(b[i].id==a)
			{
				printf("Enter the Type of Book :");
				scanf("%s",&name);
				strcpy(b[i].book_type,name);
						printf("\nDetails of book :");
						printf("\n_______________________________________________________________\n");
						printf("\n-------------------------------------------------------------\n");
						printf("\n\nBook Id : %d",b[i].id);
						printf("\nBook Name : %s",b[i].book_name);
						printf("\nAuthor Name : %s",b[i].Author_name);
						printf("\nBook Pages : %d",b[i].pages);
						printf("\nBook price : %d",b[i].price);
						printf("\nBook Type : %s",b[i].book_type);
						printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
						flag++;
						counter++;
			}
				if(flag==0)
		{
			printf("!!! Sorry No Such book type found !!!");
		}
		}
			if(counter==0)
		{
			printf("!!! Sorry No Such Id found !!!");
		}
	}
}

void searchby_date(book* b,int n)
{
	int i,j[3];
	printf("_________________________________________________________________________\n");
	printf("\n-----------------------------------------------------------------------\n");
	printf("Enter the date :");
	scanf("%d",&j[0]);
	printf("Enter the month :");
	scanf("%d",&j[1]);
	printf("Enter the year :");
	scanf("%d",&j[2]);
	for(i=0;i<n;i++)
	{
		if(b[i].dop.day==j[0] && b[i].dop.month==j[1] && b[i].dop.year==j[2])
		{
			printf("\nDetails of book :");
			printf("_________________________________________________________________\n");
			printf("\n---------------------------------------------------------------\n");
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
		}
		
	}
}
void second_max(book* b,int n)
{
	int max,sec_max=0,i,ch,min,sec_min=0;
	printf("____________________________________________________________________\n");
	printf("\n-------------------------------------------------------------------\n");
	printf("Enter your choice :\n1.second maximum price of book\n2.second minimum price of book :");
	scanf("%d",&ch);
	if(ch==1)
	{
		max=b[0].price;
		for(i=0;i<n;i++)
		{
				if(b[i].price>max)
			{
				sec_max=max;
				max=b[i].price;
			}
			else if(b[i].price!=sec_max && b[i].price>max)
			{
				sec_max=b[i].price;
			}
		}

	printf("The Book whose price is second maximum :");
	for(i=0;i<n;i++)
	{
		if(b[i].price==sec_max)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
		}
	}
}

	if(ch==2)
	{
		min=b[0].price;
		for(i=0;i<n;i++)
		{
			if(b[i].price<min)
			{
				sec_min=min;
				min=b[i].price;
			}
			else if(b[i].price!=min && b[i].price<sec_min)
			{
				sec_min=b[i].price;
			}
		}
	printf("The Book whose price is second maximum :");
	for(i=0;i<n;i++)
	{
		if(b[i].price==sec_min)
		{
			printf("\n\nBook Id : %d",b[i].id);
			printf("\nBook Name : %s",b[i].book_name);
			printf("\nAuthor Name : %s",b[i].Author_name);
			printf("\nBook Pages : %d",b[i].pages);
			printf("\nBook price : %d",b[i].price);
			printf("\nBook Type : %s",b[i].book_type);
			printf("\nBook Published date :%d %d %d\n",b[i].dop.day,b[i].dop.month,b[i].dop.year);
		}
	}
}
}
void max_min_pages(book* b,int n)
{
	int ch,i,j=0,maxp,minp;
	printf("\n1.max pages book \n2.min pages book \n");
	scanf("%d",&ch);
	if(ch==1)
	{
		maxp=b[0].pages;
		for(i=0;i<n;i++)
		{
			if(b[i].pages>maxp)
			{
				maxp=b[i].pages;
				j=i;
			}
		}
		printf("\t\t\tMinimum pages of book ");
		printf("\n\nBook Id : %d",b[j].id);
		printf("\nBook Name : %s",b[j].book_name);
		printf("\nAuthor Name : %s",b[j].Author_name);
		printf("\nBook Pages : %d",b[j].pages);
		printf("\nBook price : %d",b[j].price);
		printf("\nBook Type : %s",b[j].book_type);
		printf("\nBook Published date :%d %d %d\n",b[j].dop.day,b[j].dop.month,b[j].dop.year);
		
	}
	if(ch==2)
	{
		minp=b[0].pages;
		for(i=0;i<n;i++)
		{
			if(b[i].pages<minp)
			{
				minp=b[i].pages;
				j=i;
			}
		}
		printf("\t\tMinimum pages of book ");
		printf("\n\nBook Id : %d",b[j].id);
		printf("\nBook Name : %s",b[j].book_name);
		printf("\nAuthor Name : %s",b[j].Author_name);
		printf("\nBook Pages : %d",b[j].pages);
		printf("\nBook price : %d",b[j].price);
		printf("\nBook Type : %s",b[j].book_type);
		printf("\nBook Published date :%d %d %d\n",b[j].dop.day,b[j].dop.month,b[j].dop.year);	
	}	
}
void sort(book* b,int n)
{
	int c,j,i;
	book temp;
	printf("\nEnter your choice:\n\t\t1.Descending order\n\t\t2.Assinding order\t");
	scanf("%d",&c);
	if(c==1)
	{
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[i].id<b[j].id);
				{
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
	 printf("-------------------------------------------------------------------------\n");
     printf("Book-Id Book-Name book-author Book-pages book_price Book-type Published-date \n");
     for(i=0;i<n;i++)
     {
          printf("%d\t%s\t  %s\t      %d\t  %d\t    %s\t%d %d %d\n",b[i].id,b[i].book_name,b[i].Author_name,b[i].pages,b[i].price,b[i].book_type,b[i].dop.day,b[i].dop.month,b[i].dop.year);
     }
	}
	if(c==2)
	{
			for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[i].id>b[j].id); 
				{
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
	 printf("-------------------------------------------------------------------------\n");
     printf("Book-Id Book-Name book-author Book-pages book_price Book-type Published-date \n");
     for(i=0;i<n;i++)
     {
          printf("%d\t%s\t  %s\t      %d\t  %d\t    %s\t%d %d %d\n",b[i].id,b[i].book_name,b[i].Author_name,b[i].pages,b[i].price,b[i].book_type,b[i].dop.day,b[i].dop.month,b[i].dop.year);
     }
	}
}





