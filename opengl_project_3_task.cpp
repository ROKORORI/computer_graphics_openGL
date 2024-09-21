/* read.me
 * 
 * 과제목표
 * 1) 평행 이동 함수 사용 o
 * 2) 회전 이동 함수 사용 o
 * 3) 크기 변화 함수 사용 o
 * 4) 간단한 애니메이션 구현 o
 * 
 * 추가구현
 * 회전축을 기준으로 회오리를 그리며 크기변화 되도록 구현
 * 크기 1.5 ~ 0배까지 커졌다 작아졌다 반복
 */ 
#include <gl/glut.h>

// 함수
void draw_triangle(void);
void draw(void);
void idle(void);
void init(void);

// 전역변수
double spin(0); // 회전 전역변수
double scale(1), scale_con(0.01); // 크기 전역변수

int main(int argc, char** argv) {

	/* GLUT 및 Window 초기화 */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("openGL_task_3");
	init();	 /* 사용자 초기화 함수 */

	/* Callback 함수 정의 */
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	/* Looping 시작 */
	glutMainLoop();

	return 0;
}

void draw_triangle(void) {
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 1.0f); // 민트
	glVertex2i(350, 200);
	glColor3f(1.0f, 1.0f, 0.0f); // 노랑
	glVertex2i(350, 300);
	glColor3f(1.0f, 0.0f, 1.0f); // 빨강
	glVertex2i(425, 250);
	glEnd();
}

void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(250, 250, 0); // 평행이동 (x, y, z)
	glRotatef(spin, 0, 0, 1); // 회전 (회전각, x, y, z)
	glScalef(scale, scale, scale); // 크기변화 (x, y, z)
	glTranslatef(-250, -250, 0); // 평행이동 (x, y, z)
	
	draw_triangle(); // 삼각형 그리기
	
	glutSwapBuffers();
}

void idle(void) {
	// 회전
	spin = spin + 2.5;
	if (spin > 360) {
		spin -= 360;
	}
	
	// 크기
	scale = scale - scale_con;
	if (scale > 1.5) {
		scale_con = -scale_con;
	}
	
	if (scale < 0) {
		scale_con = -scale_con;
	}
	glutPostRedisplay();
}

void init(void) {
	/* 화면의 기본색으로 Blue 설정 */
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	/* 화면 좌표 정보 설정 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
}
