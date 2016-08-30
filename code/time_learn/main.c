#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main ()
{
	time_t time_1, time_2;
	struct tm *tm_1, *tm_2, *tm_3;
	struct tm tm_4, tm_5;
	
	printf("-------------------- PART I -------------------\n");
	
	time_1 = time(NULL);
	sleep(3);
	time_2 = time(NULL);
	printf("time1:%ld time2:%ld\n",time_1,time_2);
	
	tm_1 = (struct tm*)localtime(&time_1);
	tm_2 = (struct tm*)localtime(&time_2);
	tm_3 = (struct tm*)localtime(&time_1);
	
	printf("tm_1 ptr:%p tm_2 ptr:%p tm_3 ptr:%p\n",tm_1,tm_2,tm_3);
	printf("asctime(tm_1):%s",asctime(tm_1));
	printf("asctime(tm_2):%s",asctime(tm_2));
	printf("asctime(tm_3):%s",asctime(tm_3));


	printf("-------------------- PART II -------------------\n");

	time_1 = time(NULL);
	sleep(3);
	time_2 = time(NULL);
	printf("time1:%ld time2:%ld\n",time_1,time_2);

	tm_4 = *((struct tm*)localtime(&time_1));
	tm_5 = *((struct tm*)localtime(&time_2));

	printf("tm_4 ptr:%p tm_5 ptr:%p\n",&tm_4,&tm_5);
	printf("tm_4 sec:%d tm_5 sec:%d\n",tm_4.tm_sec,tm_5.tm_sec);

	printf("asctime(&tm_4):%s asctime(&tm_5):%s",asctime(&tm_4),asctime(&tm_5));
	printf("asctime(&tm_4) ptr:%p asctime(&tm_5) ptr:%p\n",asctime(&tm_4),asctime(&tm_5));

	printf("asctime(&tm_4):%s",asctime(&tm_4));
	printf("asctime(&tm_5):%s",asctime(&tm_5));
}
