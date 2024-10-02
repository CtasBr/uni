#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
int fd = open("text.txt", O_CREAT|O_RDWR|O_TRUNC, 0666);
if(fd < 0){
	printf("Неудалось открыть");
	return 1;
}
if(dup2(fd, 1) != 1){
	printf("Неудалось перенаправить");
	return 1;
}
printf("Вывод, перенаправлен в txt");
fflush(stdout);
close(fd);
return 0;
}
