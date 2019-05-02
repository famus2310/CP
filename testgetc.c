#define cls system("clear")
#include <termios.h>
#include <unistd.h>
#include<conio.h>
#include<stdio.h>
int getch();
int getch()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt= oldt;
	newt.c_lflag &= ~(ICANON| ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch= getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
int main(){
	char c = getch();
	printf("%c\n", c);
	return 0;
}