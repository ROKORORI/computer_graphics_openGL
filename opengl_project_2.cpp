#include <gl/glut.h>
#include <stdio.h>

/*
void init(void);

void draw(void);
void draw_point(void);
void draw_line(void);
void draw_triangle(void);

void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void keyboard(unsigned char key, int x, int y);

void idle(void);

void main_menu_function(int option);
void sub_menu_function(int option);
*/
/*
int main(int argc, char** argv) {
	
	int submenu1;

	// window 초기화
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("My First GL Program");
	init();	 /* 사용자 초기화 함수 */ 

/*
	// Popup menu 생성 및 추가 <마우스 우클릭시 표시>
	submenu1 = glutCreateMenu(sub_menu_function);
	glutAddMenuEntry("Sub1", 1);
	glutAddMenuEntry("Sub2", 2);
	glutAddMenuEntry("Sub3", 3); // 3개의 항목이 있는 메뉴 생성

	glutCreateMenu(main_menu_function);
	glutAddMenuEntry("Quit", 999);
	glutAddMenuEntry("Go!", 11);
	glutAddSubMenu("Sub Menu", submenu1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Callback 함수 정의
	glutDisplayFunc(draw);

	// Callback 함수 등록
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	// 추후 사용 Callback 함수
	// glutIdleFunc(idle); -> 임시로 off 처리

	// Looping 시작
	glutMainLoop();

	return 0;
}

void init(void)
{
	/* 화면의 기본색으로 Blue 설정 */
/*
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	/* 화면 좌표 정보 설정 */
/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
}

void mouse(int button, int state, int x, int y) {
	// 인자들을 해석해서 원하는 기능을 구현
	printf("Mouse button is clicked! (%d, %d, %d, %d)\n",
		button, state, x, y);
}

void motion(int x, int y) {
	// 인자들을 해석해서 원하는 기능을 구현
	printf("Mouse is moving! (%d, %d)\n", x, y);
}

void keyboard(unsigned char key, int x, int y) {
	// 인자들을 해석해서 원하는 기능을 구현
	printf("You pressed %c\n", key);
}

void idle(void) {
	// 추후 물체의 움직임(animation) 구현에 이용될 것임
	printf("%d second has elapsed since the system was started\n",
		GetTickCount() / 1000);
}

void main_menu_function(int option) {
	printf("Main menu %d has been selected\n", option);
	if (option == 999) {
		exit(0);
	}
}

void sub_menu_function(int option) {
	printf("Submenu %d has been selected\n", option);
}
void draw(void)
{
	/* 화면을 깨끗하게 지우기 */
/*
	glClear(GL_COLOR_BUFFER_BIT);

	/* 사용자 그리기 함수 */
	//draw_point();			/* 점 그리기 */
/*
	draw_line();			/* 선 그리기 */
/*
	draw_triangle();	/* 면 그리기 */
/*
	glFlush();
}

void draw_point(void)
{
	/* 점의 색상을 빨간색으로 설정 */
/*
	glColor3f(1.0f, 0.0f, 0.0f);
	/* 점의 크기를 설정 (초기값은 1.0) */
/*
	glPointSize(4.0f);

	glBegin(GL_POINTS);
	glVertex2i(5, 5);
	glVertex2i(200, 200);
	glVertex2i(450, 300);
	glEnd();
}

void draw_line(void)
{
	/* 기존 코드 위에 추가 */
/*
	glLineWidth(2.0f);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 0xAAAA);

	/* 선의 색상을 노란색으로 설정 */
/*
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_LINES);
	glVertex2i(50, 50);
	glVertex2i(250, 450);
	glVertex2i(300, 450);
	glVertex2i(400, 100);
	glEnd();
}

void draw_triangle(void)
{
	/* 면의 색상을 노란색으로 설정 */
/*
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(50, 50);
	glVertex2i(250, 450);
	glVertex2i(400, 100);
	glEnd();
}
*/