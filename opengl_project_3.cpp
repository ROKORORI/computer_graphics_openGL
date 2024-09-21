#include <gl/glut.h>

void draw_point(void);
void draw_line(void);
void draw_triangle(void);
void draw(void);
void idle(void);
void init(void);

// 전역변수
double spin;

int main(int argc, char** argv) {

	/* GLUT 및 Window 초기화 */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("My First GL Program");
	init();	 /* 사용자 초기화 함수 */

	/* Callback 함수 정의 */
	glutDisplayFunc(draw);	/* draw() -> 실제 그리기 함수 */
	glutIdleFunc(idle);
	/* Looping 시작 */
	glutMainLoop();

	return 0;
}
void draw_point(void){
	/* 점의 색상을 빨간색으로 설정 */
	glColor3f(1.0f, 0.0f, 0.0f);
	/* 점의 크기를 설정 (초기값은 1.0) */
	glPointSize(4.0f);

	glBegin(GL_POINTS);
	glVertex2i(5, 5);
	glVertex2i(200, 200);
	glVertex2i(450, 300);
	glEnd();
}

void draw_line(void){
	/* 선의 색상을 노란색으로 설정 */
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_LINES);
	glVertex2i(50, 50);
	glVertex2i(250, 450);
	glVertex2i(300, 450);
	glVertex2i(400, 100);
	glEnd();
}

void draw_triangle(void){
	/* 면의 색상을 노란색으로 설정 */
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2i(50, 50);
	glVertex2i(250, 450);
	glVertex2i(400, 100);
	glEnd();
}

void draw(void){
	/* 화면을 깨끗하게 지우기 */
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// 행렬 변환시 실제 적용 역순으로 사용
	glTranslatef(250, 250, 0); // 평행이동 (x, y, z)
	glRotatef(spin, 0, 0, 1); // 회전 (회전각, x, y, z)
	glTranslatef(-250, -250, 0); // 크기변화 (x, y, z) 

	/* 사용자 그리기 함수 */
	//draw_point();			/* 점 그리기 */
	//draw_line();			/* 선 그리기 */
	draw_triangle();	/* 면 그리기 */

	glFlush();
	glutSwapBuffers();
}

void idle(void) {
	spin = spin + 0.1;
	if (spin > 360) spin -= 360;
	glutPostRedisplay(); // 화면 새로고침 요청
}

void init(void){
	/* 화면의 기본색으로 Blue 설정 */
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	/* 화면 좌표 정보 설정 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
}
