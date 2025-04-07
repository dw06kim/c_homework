// splash.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(seconds) sleep(seconds)
#endif

#define WIDTH 80

void print_triangle_lines();
void splash_screen(const char *name, const char *date);

int main(void) {
    char name[100];
    char date[20];

    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%19s", date);

    printf("[당신의 이름을 입력하세요]: ");
    scanf(" %[^\n]", name);

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    SLEEP(3);
    system(CLEAR);

    splash_screen(name, date);

    return 0;
}

void print_triangle_lines() {
    const int lines = 5;
    for (int i = 0; i < lines; i++) {
        // 왼쪽 정직삼각형
        for (int j = 0; j <= i; j++)
            printf("*");

        // 가운데 여백
        for (int j = 0; j < WIDTH - 2 * (i + 1); j++)
            printf(" ");

        // 오른쪽 역직삼각형
        for (int j = 0; j <= i; j++)
            printf("*");

        printf("\n");
    }
}

void splash_screen(const char *name, const char *date) {
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    print_triangle_lines();
    printf("*                         [마그라테아 ver 0.1]                               *****\n");
    printf("**   풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,            ****\n");
    printf("***   사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,       ***\n");
    printf("****    마그라테아에 오신걸 환영합니다.                                         **\n");
    printf("*****                                                                          *\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 날짜 형식 바꾸기: yyyy-mm-dd -> yyyy년 mm월 dd일
    int yyyy, mm, dd;
    sscanf(date, "%d-%d-%d", &yyyy, &mm, &dd);
    printf("[사용자]: %s                                   [실행 시간]:%d년 %d월 %d일\n", name, yyyy, mm, dd);
    printf("================================================================================\n");
}
