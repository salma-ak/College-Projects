//


#include <windows.h>
#include <MMSystem.h>
#include <glut.h>
#include <math.h>
GLUquadricObj* gl = gluNewQuadric();
bool enemy = false;
bool boss = false;
int level = 1;
bool win = false;
bool lose = false;
int movePlayer = 0;
bool bantloon = false;
int bantloonX = 0;
int enemyX = 0;
int health = 100;
int enemyHealth = 100;
bool gazma = true;
bool gazmaShoot = false;
int bantloonMarw7a = 0;
int gazmaX = 0;
int reglRotate = 0;
bool jumping = false;
bool falling = false;
bool powerUp = false;
int jump = 0;
int blackBar = 0;
int blackbarEnemy = 0;
int blackbarEnemy1 = 0;
int powerUpFalling = 0;
int powerUpX = 0;
bool shield = false;
int shieldHealth = -1;
int blackBarShield = 0;

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (win) {
		glClearColor(0, 0, 0, 0);

		glPushMatrix();
		glScaled(2.4, 2.4, 1);
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(50, 0, 0);

		glVertex2d(200, 200); //t7t 4mal
		glVertex2d(175, 250); //
		glVertex2d(215, 235);
		glVertex2d(205, 300); //felnos 4mal
		glVertex2d(270, 235);
		glVertex2d(257, 300); // a5er 4mal
		glVertex2d(280, 225); // elfar2 benhm

		glVertex2d(270, 335); // 1 felnos 
		glVertex2d(320, 275);
		glVertex2d(325, 360); // nos elnos 
		glVertex2d(368, 275);
		glVertex2d(374, 335); // a5er elnos
		glVertex2d(390, 225); // elfar2

		glVertex2d(400, 300); // 1 ymen
		glVertex2d(400, 200);
		glVertex2d(444, 290); //nos ymen
		glVertex2d(415, 200);
		glVertex2d(465, 250); // a5er ymen
		glVertex2d(437, 200);





		glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glBegin(GL_TRIANGLES);
		glVertex2d(380, 300);
		glVertex2d(360, 230);
		glVertex2d(390, 300);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2d(247, 320);
		glVertex2d(280, 235);
		glVertex2d(255, 320);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(240, 180, 0);
		glColor3ub(0, 0, 0);
		gluDisk(gl, 0, 40, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslated(395, 180, 0);
		glColor3ub(0, 0, 0);
		gluDisk(gl, 0, 40, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex2d(340, 180);
		glVertex2d(300, 180);
		glVertex2d(300, 220);
		glVertex2d(340, 220);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3ub(255, 255, 255);
		glVertex2d(325, 130);
		glVertex2d(315, 130);
		glVertex2d(315, 190);
		glVertex2d(325, 190);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(240, 160, 0);
		glColor3ub(255, 255, 255);
		gluDisk(gl, 0, 35, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslated(245, 160, 0);
		glColor3ub(0, 0, 0);
		gluDisk(gl, 0, 32, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslated(395, 160, 0);
		glColor3ub(255, 255, 255);
		gluDisk(gl, 0, 35, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslated(400, 160, 0);
		glColor3ub(0, 0, 0);
		gluDisk(gl, 0, 32, 50, 50);
		glPopMatrix();
		glPopMatrix();

	}
	else if (lose) {
		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(1500, 0);
		glVertex2f(1500, 1500);
		glVertex2f(0, 1500);
		glEnd();
		glColor3f(0, 0, 0);
		glRasterPos2d(650, 800);
		char scorecounter[] = "game over";
		for (int i = 0; i < strlen(scorecounter); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorecounter[i]);
		}
	}
	else {
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex2f(0, 1400);
		glVertex2f(1500, 1400);
		glVertex2f(1500, 1450);
		glVertex2f(0, 1450);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(1500 - blackBar, 1400);
		glVertex2f(1500, 1400);
		glVertex2f(1500, 1450);
		glVertex2f(1500 - blackBar, 1450);
		glEnd();	
		glPopMatrix();
		if (shield) {
			glPushMatrix();
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex2f(0, 1300);
			glVertex2f(1500, 1300);
			glVertex2f(1500, 1250);
			glVertex2f(0, 1250);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex2f(1500 - blackBarShield, 1300);
			glVertex2f(1500, 1300);
			glVertex2f(1500, 1250);
			glVertex2f(1500 - blackBarShield, 1250);
			glEnd();
			glPopMatrix();
		}


		glPushMatrix();
		glTranslated(movePlayer, 0, 0);

		if (bantloon) {
			glPushMatrix();
			glTranslated(bantloonX, 0, 0);
			glTranslated(310, 100, 0);
			glScaled(0.7, 0.7, 1);
			glTranslated(150, 175, 0);
			glRotated(bantloonMarw7a, 0, 0, 1);
			glTranslated(-150, -175, 0);
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex2f(100, 100);
			glVertex2f(200, 100);
			glVertex2f(200, 250);
			glVertex2f(100, 250);
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(255, 255, 255);
			glVertex2f(130, 100);
			glVertex2f(170, 100);
			glVertex2f(150, 220);
			glEnd();
			glPopMatrix();
		}
		//player
		glPushMatrix();
		glTranslated(0, jump, 0);
		glTranslated(-40, -90, 0);
		glScaled(1.1, 1.1, 0);
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3ub(0, 102, 102); //body
		glVertex2f(210, 200);
		glVertex2f(270, 200);
		glVertex2f(270, 315);
		glVertex2f(210, 315);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(200, 102, 102);
		glVertex2f(230, 315);
		glVertex2f(250, 315);
		glVertex2f(250, 340);//r2ba
		glVertex2f(230, 340);
		glEnd();



		glPushMatrix();



		glBegin(GL_QUADS); //regl shmal
		glColor3ub(255, 204, 153);
		glVertex2f(210, 100);
		glVertex2f(230, 100);
		glVertex2f(230, 200);
		glVertex2f(210, 200);
		glEnd();

		glBegin(GL_QUADS); //gzma shmal
		glColor3ub(255, 204, 153);
		glVertex2f(190, 85);
		glVertex2f(230, 85);
		glVertex2f(230, 100);
		glVertex2f(190, 100);
		glEnd();



		glBegin(GL_QUADS);
		glColor3ub(0, 102, 102);
		glVertex2f(100, 300);
		glVertex2f(210, 300);//2ed shmal
		glVertex2f(210, 315);
		glVertex2f(100, 315);
		glEnd();






		glPopMatrix();

		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3ub(255, 204, 153); //regl ymen
		glVertex2f(250, 100);
		glVertex2f(270, 100);
		glVertex2f(270, 200);
		glVertex2f(250, 200);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(255, 204, 153); //gzma ymen
		glVertex2f(250, 85);
		glVertex2f(290, 85);
		glVertex2f(290, 100);
		glVertex2f(250, 100);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(0, 102, 102);
		glVertex2f(270, 300);
		glVertex2f(380, 300);//2ed ymen
		glVertex2f(380, 315);
		glVertex2f(270, 315);
		glEnd();

		glPopMatrix();


		glPushMatrix(); //head
		glColor3ub(200, 100, 100);
		glTranslated(239, 370, 0);
		gluDisk(gl, 0, 32, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 1
		glColor3f(0, 0, 0);
		glTranslated(225, 375, 0);
		gluDisk(gl, 0, 6.5, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 2
		glColor3f(0, 0, 0);
		glTranslated(255, 375, 0);
		gluDisk(gl, 0, 6.5, 50, 50);
		glPopMatrix();

		glPushMatrix(); //Mouth
		glColor3f(0, 0, 0);
		glTranslated(239, 355, 0);
		gluDisk(gl, 3, 6, 60, 40);
		glPopMatrix();




		glPopMatrix();
		glPopMatrix();
		if (shield) {
			glPushMatrix();
			glTranslated(110, -45, 0);
			glScaled(0.76, 0.7, 1);
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex2f(100, 100);
			glVertex2f(200, 100);
			glVertex2f(200, 250);
			glVertex2f(100, 250);
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(255, 255, 255);
			glVertex2f(130, 100);
			glVertex2f(170, 100);
			glVertex2f(150, 220);
			glEnd();
			glPopMatrix();
		}

		glPopMatrix();
		if (powerUp) {
			glPushMatrix();
			glTranslated(powerUpX, powerUpFalling, 0);
			glTranslated(110, 1500, 0);
			glScaled(0.76, 0.7, 1);
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex2f(100, 100);
			glVertex2f(200, 100);
			glVertex2f(200, 250);
			glVertex2f(100, 250);
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(255, 255, 255);
			glVertex2f(130, 100);
			glVertex2f(170, 100);
			glVertex2f(150, 220);
			glEnd();
			glPopMatrix();
		}
		switch (level)
		{
		case 1:
			enemy = true;

			glPushMatrix();
			glTranslated(enemyX, 0, 0);
			glPushMatrix();
			glTranslated(250, -100, 0);
			glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex2f(900, 500);
			glVertex2f(1200, 500);
			glVertex2f(1200, 550);
			glVertex2f(900, 550);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex2f(1200 - blackbarEnemy1, 500);
			glVertex2f(1200, 500);
			glVertex2f(1200, 550);
			glVertex2f(1200 - blackbarEnemy1, 550);
			glEnd();
			glPopMatrix();
			glTranslated(1050, -10, 0);
			glBegin(GL_QUADS);
			glColor3ub(0, 130, 0);// eyd ymen
			glVertex2d(150, 270);
			glVertex2d(150, 300);
			glVertex2d(200, 300);
			glVertex2d(200, 270);
			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(0, 130, 0);// eyd 4mal
			glVertex2d(315, 270);
			glVertex2d(315, 300);
			glVertex2d(420, 300);
			glVertex2d(420, 270);
			glEnd();
			glBegin(GL_QUADS);
			glColor3ub(0, 130, 0);// gsm
			glVertex2d(200, 100);
			glVertex2d(200, 300);
			glVertex2d(315, 300);
			glVertex2d(315, 100);
			glEnd();
			glBegin(GL_QUADS);
			glColor3ub(0, 130, 0); //r2ba
			glVertex2d(240, 300);
			glVertex2d(240, 320);
			glVertex2d(280, 320);
			glVertex2d(280, 300);
			glEnd();

			glBegin(GL_POLYGON); //raas
			glColor3ub(0, 130, 0);
			glVertex2f(220, 320);
			glVertex2f(210, 330);
			glVertex2f(210, 370);
			glVertex2f(220, 377);
			glVertex2f(290, 377);
			glVertex2f(300, 370);
			glVertex2f(300, 330);
			glVertex2f(290, 320);
			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(200, 0, 0); //bo2
			glVertex2d(240, 340);
			glVertex2d(240, 345);
			glVertex2d(270, 345);
			glVertex2d(270, 340);
			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(200, 0, 0); //3en 4mal
			glVertex2d(230, 350);
			glVertex2d(230, 360);
			glVertex2d(245, 360);
			glVertex2d(245, 350);
			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(200, 0, 0); //3en ymen
			glVertex2d(265, 350);
			glVertex2d(265, 360);
			glVertex2d(280, 360);
			glVertex2d(280, 350);
			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(105, 105, 105); //rgl 4mal
			glVertex2d(210, 30);
			glVertex2d(210, 100);
			glVertex2d(240, 100);
			glVertex2d(240, 30);
			glEnd();

			glBegin(GL_QUADS);// rgl ymen 
			glColor3ub(105, 105, 105);
			glVertex2d(265, 0);
			glVertex2d(265, 100);
			glVertex2d(310, 100);
			glVertex2d(310, 0);
			glEnd();

			glPopMatrix();
			break;
		case 2:


			boss = true;
			glPushMatrix();
			glTranslated(1050, -100, 0);
			glScaled(0.7, 0.7, 1);
			glPushMatrix();
			glBegin(GL_QUADS);//ra2aba
			glColor3ub(0, 102, 51);
			glVertex2f(335, 700);
			glVertex2f(365, 700);
			glVertex2f(365, 730);
			glVertex2f(335, 730);
			glEnd();
			glBegin(GL_QUADS);//body
			glColor3ub(100, 0, 0);


			glVertex2f(250, 450);

			glVertex2f(450, 450);
			glColor3ub(0, 0, 51);
			glVertex2f(450, 700);
			glVertex2f(250, 700);
			glEnd();
			glPopMatrix();
			glTranslated(350, 575, 0);
			glTranslated(-350, -575, 0);
			glPushMatrix();
			glPushMatrix(); // face
			glColor3ub(0, 102, 51);
			glTranslated(350, 800, 0);
			gluDisk(gl, 0, 90, 50, 50);
			glPopMatrix();
			glPushMatrix(); // left 3en
			glColor3ub(204, 0, 0);
			glTranslated(315, 805, 0);
			gluDisk(gl, 0, 15, 50, 50);
			glPopMatrix();
			glPushMatrix(); // right 3en
			glColor3ub(204, 0, 0);
			glTranslated(385, 805, 0);
			gluDisk(gl, 0, 8, 50, 50);
			glPopMatrix();
			glPushMatrix();
			glBegin(GL_LINES);//bo2
			glColor3f(0, 0, 0);
			glVertex2f(325, 820);
			glVertex2f(300, 790);
			glEnd();
			glBegin(GL_LINES);//bo2
			glColor3f(0, 0, 0);
			glVertex2f(325, 790);
			glVertex2f(300, 820);
			glEnd();
			glPopMatrix();
			glLineWidth(4);
			glBegin(GL_LINES);//bo2
			glColor3f(204, 0, 0);
			glVertex2f(315, 747);
			glVertex2f(390, 747);
			glEnd();




			glBegin(GL_TRIANGLES); //nose
			glColor3ub(204, 0, 0);
			glVertex2f(340, 767);
			glVertex2f(360, 767);
			glVertex2f(350, 787);
			glEnd();




			glPopMatrix();

			glPushMatrix();
			glBegin(GL_QUADS);//right leg
			glColor3ub(0, 0, 0);
			glVertex2f(360, 200);
			glVertex2f(450, 200);
			glVertex2f(450, 450);
			glVertex2f(360, 450);
			glEnd();
			glBegin(GL_QUADS);//right kadam
			glColor3ub(0, 0, 0);
			glVertex2f(360, 150);
			glVertex2f(500, 150);
			glVertex2f(500, 200);
			glVertex2f(360, 200);
			glEnd();
			glBegin(GL_QUADS);//right hand
			glColor3ub(0, 0, 51);
			glVertex2f(450, 650);
			glVertex2f(600, 650);
			glVertex2f(600, 700);
			glVertex2f(450, 700);
			glEnd();

			glPopMatrix();

			glPushMatrix();
			glPushMatrix();
			glTranslated(250, 450, 0);
			glRotated(reglRotate, 0, 0, 1);
			glTranslated(-250, -450, 0);
			glBegin(GL_QUADS);//left leg
			glColor3ub(0, 0, 0);
			glVertex2f(250, 200);
			glVertex2f(340, 200);
			glVertex2f(340, 450);
			glVertex2f(250, 450);
			glEnd();
			glBegin(GL_QUADS);//left kadam
			glColor3ub(0, 0, 0);
			glVertex2f(200, 150);
			glVertex2f(340, 150);
			glVertex2f(340, 200);
			glVertex2f(200, 200);
			glEnd();
			glPopMatrix();



			glBegin(GL_QUADS);//left hand
			glColor3ub(0, 0, 51);
			glVertex2f(100, 650);
			glVertex2f(250, 650);
			glVertex2f(250, 700);
			glVertex2f(100, 700);
			glEnd();


			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			if (gazma) {
				glPushMatrix();
				if (gazmaShoot) {
					glTranslated(gazmaX, 0, 0);
				}
				glTranslated(1238, -90, 0);
				glTranslated(50, 0, 0);
				glScaled(-1, 1, 1);
				glTranslated(-50, 0, 0);

				glBegin(GL_POLYGON);
				glColor3f(0.5f, 0, 0);
				glVertex2d(50, 95);
				glVertex2d(150, 95);
				glVertex2d(150, 130);
				glVertex2d(113, 130);
				glVertex2d(113, 200);
				glVertex2d(50, 200);
				glEnd();
				glPopMatrix();
			}
			glPushMatrix();
			glTranslated(280, -300, 0);
			glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex2f(800, 850);
			glVertex2f(1200, 850);
			glVertex2f(1200, 900);
			glVertex2f(800, 900);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex2f(1200 - blackbarEnemy, 850);
			glVertex2f(1200, 850);
			glVertex2f(1200, 900);
			glVertex2f(1200 - blackbarEnemy, 900);
			glEnd();
			glPopMatrix();
			break;
		default:
			break;
		}

	}

	glFlush();
}

void takeDamage(int damage) {
	if (!win && !lose) {
		if (shield && shieldHealth >= 0) {
			shieldHealth -= damage;
			blackBarShield += (damage * 1500) / 100;
		}
		if (shieldHealth == 0) {
			shield = false;
		}
		if (shieldHealth < 0) {

			health -= damage;
			blackBar += (damage * 1500) / 100;
			if (health <= 0) {
				lose = true;
				win = false;
			}
		}


	}
	glutPostRedisplay();
}
void giveDamage(int damage) {
	if (!win && !lose) {
		enemyHealth -= damage;
		if (boss)
			blackbarEnemy += (damage * 400) / 100;
		if (enemy)
			blackbarEnemy1 += (damage * 300) / 100;
		if (enemyHealth <= 0 && level == 1) {
			level = 2;
			enemyHealth = 100;
			enemy = false;
			boss = true;
		}
		if (enemyHealth <= 0 && level == 2) {
			win = true;
			lose = false;
			boss = false;
			enemy = false;
		}
	}

	glutPostRedisplay();

}
void specialInput(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		movePlayer += 10;
		break;
	case GLUT_KEY_LEFT:
		movePlayer -= 10;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void enemyShoot(int val) {
	if (gazma && gazmaShoot) {
		gazmaX -= 25;
	}
	glutPostRedisplay();
	glutTimerFunc(40, enemyShoot, 0);
}
void rotateLeg(int val) {
	if (reglRotate <= -50) {
		reglRotate = 0;
	}
	else {
		reglRotate -= 5;
		glutTimerFunc(30, rotateLeg, 0);
	}
}
void enemyShootTimer(int val) {
	if (!gazmaShoot) {
		gazmaShoot = true;
		rotateLeg(0);
	}
	glutPostRedisplay();
	glutTimerFunc(2500, enemyShootTimer, 0);
}
void powerup(int value) {
	if (shield)
		powerUp = false;
	if (powerUp && !shield) {
		powerUp = false;
		powerUpFalling = 0;
		powerUpX = 0;
	}
	else if (!shield) {
		powerUpX = -100 + (rand() % 500);
		powerUp = true;
	}
	glutPostRedisplay();
	glutTimerFunc(7000, powerup, 0);
}
void timer(int value) {
	if (jumping && !falling) {
		jump += 15;
		if (jump > 300) {
			falling = true;
			jumping = false;
		}
	}
	if (falling && !jumping) {
		jump -= 15;
		if (jump <= 0) {
			falling = false;
			jumping = false;
		}
	}
	if (powerUp && powerUpFalling > -1545) {
		powerUpFalling -= 10;
	}
	glutTimerFunc(20, timer, 0);
}
void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'z':
		if (!bantloon && !falling && !jumping) {
			bantloon = true;
		}
		break;
	case ' ':
		if (!jumping && !falling) {
			jumping = true;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void bantloonfight(int val) {
	if (bantloon) {
		bantloonX += 20;

	}
	if (enemy) {
		enemyX -= 5;
	}
	glutPostRedisplay();
	glutTimerFunc(30, bantloonfight, 0);
}
void bantloonLef(int val) {
	if (bantloon) {
		bantloonMarw7a -= 5;

	}
	glutPostRedisplay();
	glutTimerFunc(10, bantloonLef, 0);
}
void update() {
	if (bantloon && bantloonX >= (1500 - movePlayer)) {
		bantloon = false;
		bantloonX = 0;
	}
	if (enemy && bantloon && bantloonX >= (950 + enemyX - movePlayer)) {
		bantloon = false;
		bantloonX = 0;
		giveDamage(50);
	}
	if (boss && bantloon && bantloonX >= (950 - movePlayer)) {
		bantloon = false;
		bantloonX = 0;
		giveDamage(20);
	}
	if (enemy && enemyX <= (-1000 + movePlayer)) {
		takeDamage(50);
		enemyX = 0;
	}
	if (boss && gazmaShoot && gazmaX <= (-1000 + movePlayer) && !jumping && !falling && gazmaX >= (-1200 + movePlayer)) {
		gazmaX = 0;
		gazmaShoot = false;
		takeDamage(50);
	}
	if (boss && gazmaShoot && gazmaX <= -1300) {
		gazmaX = 0;
		gazmaShoot = false;
	}
	if (movePlayer >= (20 + powerUpX) && movePlayer <= (80 + powerUpX) && powerUpFalling <= -1300 && powerUp) {
		powerUp = false;
		shieldHealth = 100;
		blackBarShield = 0;
		powerUpFalling = 0;
		shield = true;
	}
	glutPostRedisplay();
}
void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 2D Template");
	glutDisplayFunc(Display);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(255, 255, 255, 0.0f);
	glutSpecialFunc(specialInput);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);
	glutTimerFunc(1500, enemyShootTimer, 0);

	glutTimerFunc(30, bantloonfight, 0);
	glutTimerFunc(1000, powerup, 0);
	glutTimerFunc(40, enemyShoot, 0);
	glutTimerFunc(10, bantloonLef, 0);
	glutTimerFunc(20, timer, 0);
	gluOrtho2D(0.0, 1500, 0.0, 1500);

	glutMainLoop();
}
