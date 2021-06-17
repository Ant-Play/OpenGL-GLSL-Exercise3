#include <GL/glut.h>

constexpr const auto Width = 800;
constexpr const	auto Height = 600;

//��ʾ��Դ����λ�ã����ĸ�ֵ��ʾ���ǹ�ԴԶ����0Ϊ����Զ��������x/w��y/w��z/w��ʾ��Դλ��
GLfloat light0_position[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat light1_position[] = { -8.0f,-6.0f,0.0f,1.0f };
GLfloat light2_position[] = { 0.0,4.0,0.0,1.0 };

bool tea_port[] = { true,false,false };

//��Դ��ת�Ƕ�
static GLfloat angle = 0.0f;

//��ת����
GLfloat x0rot = 0;
GLfloat x1rot = 0;
GLfloat x2rot = 0;
GLfloat xold = 0;

void Lighting();

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0,
			0.0, 0.0, 0.0, 
			0.0, 1.0, 0.0);

	glPushMatrix();

	//Lighting();

	//���Ƶ�һ����ת��Դ,glRotatefȷ������ת����glTranslatefʹ���ƶ�
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(9.0f, 0.0f, 0.0f);
	//�׹�Դ
	glColor3f(1.0, 1.0, 1.0);
	//glutSolidSphere��һ������Ϊ����İ뾶���ڶ�����������һ�������������Ŀ��Խ��Խ��ϸ�����ٶȻ���
	glutSolidSphere(0.15, 100, 100);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glEnable(GL_LIGHT0);

	glPopMatrix();
	//��һ����
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 0.0);
	glRotatef(x0rot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	//���Ƶ�һ������ͬʱ�����ư�����һ����ת�Ĺ�Դ
	glTranslatef(2.0f, 4.0f, 0.0f);
	//�ȹرչ�Դ������ֻ������һ����Դ���Ȼ�������ٴ�
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.15, 100, 100);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glEnable(GL_LIGHT2);


	//���Ż��Ƶ�һ����
	glPopMatrix();
	//glut���Ʋ���ĺ���������Ϊ�����С
	glutSolidTeapot(1.0);
	glPopMatrix();

	//���Ƶڶ�����
	glPushMatrix();
	glRotatef(x1rot, 0.0f, 1.0f, 0.0f);
	glutSolidTeapot(1.0);
	glPopMatrix();

	//���Ƶ�������
	glPushMatrix();
	glTranslatef(0.0f, -3.0f, 0.0f);
	glRotatef(x2rot, 0.0f, 1.0f, 0.0f);
	glutSolidTeapot(1.0);
	glPopMatrix();

	//�������һ����Դ
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-8.0, -6.0, 0.0);
	glutSolidSphere(0.15, 100, 100);
	glPopMatrix();
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glEnable(GL_LIGHT1);


	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xold = x;
	}
}
void mouse_motion(int x, int y) {
	if (tea_port[0])
		x0rot += x - xold;
	else if (tea_port[1])
		x1rot += x - xold;
	else if (tea_port[2])
		x2rot += x - xold;

	xold = x;
	glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y) {
	switch (key){
		case '1':
			tea_port[0] = true;
			tea_port[1] = false;
			tea_port[2] = false;
			break;
		case '2':
			tea_port[0] = false;
			tea_port[1] = true;
			tea_port[2] = false; 
			break;
		case '3':
			tea_port[0] = false;
			tea_port[1] = false;
			tea_port[2] = true;
			break;
	default:
		break;
	}
}

void Lighting(){
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat AmbientLight0[4] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight0);
	GLfloat DiffuseLight0[4] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight0);
	GLfloat SpecularLight0[4] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight0);

	glEnable(GL_LIGHT1);
	GLfloat AmbientLight1[4] = { 0.0, 1.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight1);
	GLfloat DiffuseLight1[4] = { 0.0, 1.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight1);
	GLfloat SpecularLight1[4] = { 0.0,1.0,0.0,1.0 };
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight1);


	glEnable(GL_LIGHT2);
	GLfloat AmbientLight2[4] = { 1.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, AmbientLight2);
	GLfloat DiffuseLight2[4] = { 1.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, DiffuseLight2);
	GLfloat SpecularLight2[4] = { 1.0,0.0,0.0,1.0 };
	glLightfv(GL_LIGHT2, GL_SPECULAR, SpecularLight2);

}

void Idle(){
	angle += 0.1f;
	if (angle >= 360.0f)
		angle = 0.0f;

	display();
}


void reshape(int w, int h){
	float aspect = (float)w / ((h) ? h : 1);//ƽ��ͷ����ݺ�ȣ�Ҳ���ǿ�ȳ��Ը߶ȣ�(h)?h:1��˼����h=0����h=1

	glViewport(0, 0, w, h);

	//����ͶӰ�任ǰ�������������������������ı任������Ӱ��ͶӰ����
	//�ڴ��ڸı亯��reshape������glMatrixMode(GL_PROJECTION)������׶,����glMatrixMode(GL_MODELVIEW)��Ϊģ�ͱ任
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, aspect, 1.0f, 100.0f);//
	glViewport(0, 0, w, h);

	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Test");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);            //���ڻ���
	glutIdleFunc(Idle);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);            //ע��������¼�
	glutMotionFunc(mouse_motion);        //ע������϶��¼�
	glutKeyboardFunc(keyboardFunc);    //ע������¼�
	glutMainLoop();


	return 0;
}