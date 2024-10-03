/* read.me
 * 과제 구현
 * 1) 사용자의 키보드 입력 처리(special key 및 +, -)
 * 2) 수평, 수직방향의 회전
 * 3) 사물과의 거리조절
 * 4) 360도 회전 가능
 */

#include <gl/glut.h>
#include <iostream>
#include <math.h>

 // namespace
using namespace std;

// 함수
void idle(void);
void resize(int width, int height);
void special_keyboard(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void draw_axis(void);
void draw(void);
void init(void);

// 전역변수
int r(20), check(1); // 거리 조절 초기값
double pi(3.141592); // 파이
double elevation(45), azimuth(45); // 각도 조절 초기값

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("openGL_task_4");
	init();

	// Callback 함수
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_keyboard);
	glutIdleFunc(idle);

	// Loop 시작
	glutMainLoop();

	return 0;
}

void resize(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)width / (float)height,
		1, 500);
	glMatrixMode(GL_MODELVIEW);
}

void draw_axis(void) {
	glLineWidth(3);             // 좌표축의 두께
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);   // X축은 red
	glVertex3f(0, 0, 0);
	glVertex3f(4, 0, 0);

	glColor3f(0, 1, 0);   // Y축은 green
	glVertex3f(0, 0, 0);
	glVertex3f(0, 4, 0);

	glColor3f(0, 0, 1);   // Z축은 blue
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 4);
	glEnd();
	glLineWidth(1);             // 두께 다시 환원
}

void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(r * sin(elevation * (pi / 180)) * cos(azimuth * (pi / 180)), // x좌표
		r * cos(elevation * (pi / 180)),  // y좌표
		r * sin(elevation * (pi / 180)) * sin(azimuth * (pi / 180)),  // z좌표
		0, 0, 0, 0, check, 0);

	glColor3f(1, 1, 0);
	glutWireTeapot(4);
	draw_axis();

	glutSwapBuffers();  // double buffering
}

void special_keyboard(int key, int x, int y) {
	switch (key) {
		//LEFT
	case GLUT_KEY_LEFT:
		cout << "LEFT" << endl;
		azimuth -= 1;
		break;
		// RIGHT
	case GLUT_KEY_RIGHT:
		cout << "RIGHT" << endl;
		azimuth += 1;
		break;
		// UP
	case GLUT_KEY_UP:
		cout << "UP" << endl;
		if (elevation == 1) { // elevation이 0이 안되도록 예외처리
			elevation -= 2;
		}
		else {
			elevation -= 1;
		}
		break;
		// DOWN
	case GLUT_KEY_DOWN:
		cout << "DOWN" << endl;
		if (elevation == 179) { // elevation이 180이 안되도록 예외처리
			elevation += 2;
		}
		else {
			elevation += 1;
		}
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		// 확대
	case 43:
		cout << "+" << endl;
		r -= 1;
		break;
		// 축소
	case 45:
		cout << "-" << endl;
		r += 1;
		break;
	}
}

void idle(void) {
	// 각도 초기화
	if (elevation == 360) {
		elevation = 0;
	}
	if (azimuth == 360 || azimuth == -360) {
		azimuth = 0;
	}

	// elevation 음수
	if (elevation < 0) {
		elevation = 360 + elevation;
	}
	// elevation 360 초과
	if (elevation > 360) {
		elevation = elevation - 360;
	}

	// elevation에 따른 360도 회전가능하도록 함
	if ((elevation > 0) && (elevation < 180)) {
		check = 1;
	}
	if ((elevation > 180) && (elevation < 360)) {
		check = -1;
	}

	glutPostRedisplay();
}

void init(void) {
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}
