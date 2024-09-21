/* read.me
 * 구현한 것
 *
 * 과제 목표구현
 * 1) 지붕 삼각형
 * 2) 그라데이션 사각형
 * 3) 점선으로 구성한 사각형
 * 4) 잔디 사각형
 * 
 * 과제 추가구현
 * 5) 팝업메뉴(우클릭) quit 구현
 */

#include <gl/glut.h>
#include <stdio.h>

void init(void);
void draw(void);
void draw_line(void);
void draw_triangle(void);
void draw_rectangle_1(void);
void draw_rectangle_2(void);
void main_menu_function(int option);

// 메인함수
int main(int argc, char** argv) {

	// window 초기화
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("openGL task2");
	init();	 // 사용자 초기화 함수

	// Popup menu 생성 및 추가 <마우스 우클릭시 표시>
	glutCreateMenu(main_menu_function);
	glutAddMenuEntry("Quit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Callback 함수 정의
	glutDisplayFunc(draw);

	// Looping 시작
	glutMainLoop();

	return 0;
}

// 초기화
void init(void){
	/* 화면의 기본색으로 Blue 설정 */
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	/* 화면 좌표 정보 설정 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
}

// 메뉴
void main_menu_function(int option) {
	if (option == 999) {
		exit(0);
	}
}

// 그리기
void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	draw_rectangle_1();
	draw_rectangle_2();
	draw_triangle();
	draw_line();

	glFlush();
}

// 선으로 사각형
void draw_line(void){

	// 선 두께 
	glLineWidth(6.0f);
	glEnable(GL_LINE_STIPPLE);
	
	// 점선
	glLineStipple(1, 0x00FF);

	// 민트색
	glColor3f(0.5f, 2.9f, 2.9f);
	
	glBegin(GL_LINES);
	// 좌
	glVertex2i(160, 220);
	glVertex2i(160, 300);
	
	// 우
	glVertex2i(240, 220);
	glVertex2i(240, 300);

	// 상
	glVertex2i(160, 300);
	glVertex2i(240, 300);

	// 하
	glVertex2i(160, 220);
	glVertex2i(240, 220);
	
	glEnd();
}

// 삼각형
void draw_triangle(void)
{
	// 빨간색
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	
	// 왼쪽
	glVertex2i(50, 350);
	
	// 윗쪽
	glVertex2i(200, 450);
	
	// 오른쪽
	glVertex2i(350, 350);
	glEnd();
}

// 사각형 1
void draw_rectangle_1(void) {
	glColor3f(0.0f, 0.5f, 0.0f); // 초록색
	glBegin(GL_QUADS);

	//좌
	glVertex2i(0, 0); // 하단
	glVertex2i(0, 200); // 상단

	//우
	glVertex2i(500, 200); // 상단
	glVertex2i(500, 0); // 하단

	glEnd();
}
// 사각형 2
void draw_rectangle_2(void){
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 1.0f); // 보라색
	glVertex2i(100, 150); // 좌하단

	glColor3f(1.0f, 1.0f, 0.0f); // 노란색
	glVertex2i(100, 350); // 좌상단
	
	glColor3f(1.0f, 1.0f, 0.0f); // 노란색
	glVertex2i(300, 350); // 우상단
	
	glColor3f(1.0f, 0.0f, 1.0f); // 보라색
	glVertex2i(300, 150); // 우하단
	
	glEnd();
}