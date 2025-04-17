#include<stdio.h>
#include<termios.h>
#include<sys/ioctl.h>

#define SIZE_LINE 4096
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"
#define YELLOW_COLOR "\033[1;33m"
#define MANJETA_COLOR "\033[1;35m"
int main(int argc, char* argv[]) {
  char buffer[SIZE_LINE];
  FILE *fc = fopen(argv[1], "r");
  struct winsize ws;
  int width, rc, fd = 0;
  rc = ioctl(fd, TIOCGWINSZ, &ws);
  if(rc < 0) {
    printf("%s[ERROR]%s We can't get width terminal%s\n", YELLOW_COLOR, RED_COLOR, RESET_COLOR);
    width = 80;
  } else {
    width = ws.ws_col;
  } 
  int count_line = 1;
  printf("%s", GREEN_COLOR);
  for(int i = 0; i < width; i++) {
    printf("-");
  }
  printf("%s\n", RESET_COLOR);

  printf("%s    File: %s%s\n", MANJETA_COLOR, argv[1], RESET_COLOR);
  printf("%s", GREEN_COLOR);
  for(int i = 0; i < width; i++) {
    printf("-");
  }
  printf("%s\n", RESET_COLOR);

  if (!fc) {
    printf("%s[ERROR]%s File not found or don't read this file%s\n", YELLOW_COLOR, RED_COLOR, RESET_COLOR);
  }
  else {
    while((fgets(buffer, SIZE_LINE, fc)) != NULL) {
      printf("%s%i", GREEN_COLOR, count_line);
      if(count_line < 10) {
        printf("  |%s", RESET_COLOR);
      } else {
        printf(" |%s",RESET_COLOR);
      }
      printf("%s", buffer);
      count_line++;
    }
    printf("%s", GREEN_COLOR);
    for(int i = 0; i < width; i++) {
      printf("-");
    }
    printf("%s\n", RESET_COLOR);
    
  }

}
