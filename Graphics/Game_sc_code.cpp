#include <GL/glut.h>
#include <math.h>
#include <string>
#include <iostream>

float xPos = 0.0f;  //Initial x-position
float yPos = -0.95f;  //Initial y-position 
float yVelocity = 0.0f;   //Initial y-velocity
float gravity = -0.0006f;   //Gravity value
bool isKeyPressed = false;  //Flag to track if any arrow key is pressed
float objectSize = 0.05f; // Size of the object
bool firstLevelDone = false;
bool restart = false;
int timer = 1200;
bool start = false;
bool hehe = false;

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r':
		restart = true;
		break;
	case 's':
		start = true;
		break;
	case 27: // esc key
		exit(0);
		break;
	}
}

void drawString(float x, float y, std::string text, void* font, float r, float g, float b) {
	glColor3f(r, g, b);
	glRasterPos2f(x, y);

	for (unsigned int i = 0; i < text.length(); i++) {
		glutBitmapCharacter(font, text[i]);
	}
}

void drawgameover() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	gluOrtho2D(0, 400, 0, 400);
	drawString(150, 200, "game over", GLUT_BITMAP_9_BY_15, 1.0f, 0.0f, 0.0f);
	drawString(150, 150, "Press ESC to exit", GLUT_BITMAP_9_BY_15, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//start = true;
	firstLevelDone = false;
	glutKeyboardFunc(keyboard);

}

void firstLevel() {
	 
	glClear(GL_COLOR_BUFFER_BIT);
 
	//background color
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0, 0.3);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	gluOrtho2D(0, 400, 0, 400); // Set the orthographic projection
	drawString(185, 200, "JUMP!", GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
	drawString(90, 380, "<-- Go to the flag", GLUT_BITMAP_9_BY_15, 1.0f, 0.0f, 0.0f);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	//two lines of border on left and right
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.8, -1);//left down border point
	glVertex2f(-0.8, 1);//left upper border point
	glVertex2f(0.8, -1);//right buttom border point
	glVertex2f(0.8, 1); //right upper border point
	glEnd();

	//----------------left bricks-------------------------------------

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -0.8);
	glVertex2f(-0.8, -0.8);
	glVertex2f(-0.8, -1);
	glVertex2f(-1, -1);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.95, -0.8);
	glVertex2f(-0.95, -1);
	glVertex2f(-0.87, -0.8);
	glVertex2f(-0.87, -1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -0.59);
	glVertex2f(-0.8, -0.59);
	glVertex2f(-0.8, -0.79);
	glVertex2f(-1, -0.79);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.97, -0.79);
	glVertex2f(-0.97, -0.59);
	glVertex2f(-0.9, -0.79);
	glVertex2f(-0.9, -0.59);
	glVertex2f(-0.83, -0.79);
	glVertex2f(-0.83, -0.59);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -0.38);
	glVertex2f(-0.8, -0.38);
	glVertex2f(-0.8, -0.58);
	glVertex2f(-1, -0.58);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.95, -0.38);
	glVertex2f(-0.95, -0.58);
	glVertex2f(-0.87, -0.38);
	glVertex2f(-0.87, -0.58);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -0.17);
	glVertex2f(-0.8, -0.17);
	glVertex2f(-0.8, -0.37);
	glVertex2f(-1, -0.37);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.97, -0.17);
	glVertex2f(-0.97, -0.37);
	glVertex2f(-0.9, -0.17);
	glVertex2f(-0.9, -0.37);
	glVertex2f(-0.83, -0.17);
	glVertex2f(-0.83, -0.37);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.8, 0.14);
	glVertex2f(-1, 0.14);
	glVertex2f(-1, -0.16);
	glVertex2f(-0.8, -0.16);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.14);
	glVertex2f(-0.95, -0.16);
	glVertex2f(-0.87, 0.14);
	glVertex2f(-0.87, -0.16);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.8, 0.35);
	glVertex2f(-1, 0.35);
	glVertex2f(-1, 0.15);
	glVertex2f(-0.8, 0.15);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.97, 0.35);
	glVertex2f(-0.97, 0.15);
	glVertex2f(-0.9, 0.35);
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.83, 0.35);
	glVertex2f(-0.83, 0.15);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.8, 0.56);
	glVertex2f(-1, 0.56);
	glVertex2f(-1, 0.36);
	glVertex2f(-0.8, 0.36);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.56);
	glVertex2f(-0.95, 0.36);
	glVertex2f(-0.87, 0.56);
	glVertex2f(-0.87, 0.36);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.8, 0.77);
	glVertex2f(-1, 0.77);
	glVertex2f(-1, 0.57);
	glVertex2f(-0.8, 0.57);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.97, 0.77);
	glVertex2f(-0.97, 0.57);
	glVertex2f(-0.9, 0.77);
	glVertex2f(-0.9, 0.57);
	glVertex2f(-0.83, 0.77);
	glVertex2f(-0.83, 0.57);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.8, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, 0.78);
	glVertex2f(-0.8, 0.78);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 1);
	glVertex2f(-0.95, 0.78);
	glVertex2f(-0.87, 1);
	glVertex2f(-0.87, 0.78);
	glEnd();

	//----------------right bricks-------------------------------------
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, -1);
	glVertex2f(0.8, -0.8);
	glVertex2f(1, -0.8);
	glVertex2f(1, -1);
	glVertex2f(0.8, -1);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.95, -0.8);
	glVertex2f(0.95, -1);
	glVertex2f(0.87, -0.8);
	glVertex2f(0.87, -1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(1, -0.59);
	glVertex2f(0.8, -0.59);
	glVertex2f(0.8, -0.79);
	glVertex2f(1, -0.79);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.97, -0.79);
	glVertex2f(0.97, -0.59);
	glVertex2f(0.9, -0.79);
	glVertex2f(0.9, -0.59);
	glVertex2f(0.83, -0.79);
	glVertex2f(0.83, -0.59);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(1, -0.38);
	glVertex2f(0.8, -0.38);
	glVertex2f(0.8, -0.58);
	glVertex2f(1, -0.58);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.95, -0.38);
	glVertex2f(0.95, -0.58);
	glVertex2f(0.87, -0.38);
	glVertex2f(0.87, -0.58);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(1, -0.17);
	glVertex2f(0.8, -0.17);
	glVertex2f(0.8, -0.37);
	glVertex2f(1, -0.37);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.97, -0.17);
	glVertex2f(0.97, -0.37);
	glVertex2f(0.9, -0.17);
	glVertex2f(0.9, -0.37);
	glVertex2f(0.83, -0.17);
	glVertex2f(0.83, -0.37);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0.5, 0);
	glVertex2f(0.8, -0.05);
	glVertex2f(1, -0.05);
	glVertex2f(1, -0.16);
	glVertex2f(0.8, -0.16);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, 0.04);
	glVertex2f(1, 0.04);
	glVertex2f(1, -0.05);
	glVertex2f(0.8, -0.05);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(0.8, 0.04);
	glVertex2f(1, 0.04);
	glVertex2f(1, 0.15);
	glVertex2f(0.8, 0.15);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.8, 0.15);
	glVertex2f(0.8, -0.16);
	glVertex2f(0.9, -0.005);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, 0.35);
	glVertex2f(1, 0.35);
	glVertex2f(1, 0.15);
	glVertex2f(0.8, 0.15);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.97, 0.35);
	glVertex2f(0.97, 0.15);
	glVertex2f(0.9, 0.35);
	glVertex2f(0.9, 0.15);
	glVertex2f(0.83, 0.35);
	glVertex2f(0.83, 0.15);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, 0.56);
	glVertex2f(1, 0.56);
	glVertex2f(1, 0.36);
	glVertex2f(0.8, 0.36);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.56);
	glVertex2f(0.95, 0.36);
	glVertex2f(0.87, 0.56);
	glVertex2f(0.87, 0.36);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, 0.77);
	glVertex2f(1, 0.77);
	glVertex2f(1, 0.57);
	glVertex2f(0.8, 0.57);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.97, 0.77);
	glVertex2f(0.97, 0.57);
	glVertex2f(0.9, 0.77);
	glVertex2f(0.9, 0.57);
	glVertex2f(0.83, 0.77);
	glVertex2f(0.83, 0.57);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0.8, 1);
	glVertex2f(1, 1);
	glVertex2f(1, 0.78);
	glVertex2f(0.8, 0.78);
	glEnd();
	glColor3f(0.0, 0, 0.3);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.95, 1);
	glVertex2f(0.95, 0.78);
	glVertex2f(0.87, 1);
	glVertex2f(0.87, 0.78);
	glEnd();

	//----------------blocks 1-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.79, -0.8);
	glVertex2f(-0.25, -0.8);
	glEnd();

	//----------------blocks 2-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.5);
    glVertex2f(0.3, -0.5);
    glEnd();

	//----------------blocks 3-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(0.6, -0.1);
	glVertex2f(0.79, -0.1);
	glEnd();

	//----------------blocks 4-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(0.7, 0.3);
	glVertex2f(0.79, 0.3);
	glEnd();

	//----------------blocks 5-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.5);
	glVertex2f(0.2, 0.5);
	glEnd();

	//----------------blocks 6-------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.79, 0.7);
	glVertex2f(-0.3, 0.7);
	glEnd();

	//-----------------flag-------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-0.7, 0.95);
	glVertex2f(-0.7, 0.7);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(-0.7, 0.95);
	glVertex2f(-0.6, 0.95);
	glVertex2f(-0.6, 0.85);
	glVertex2f(-0.7, 0.85);
	glEnd();

	glFlush();
}

void endScene() {
	glColor3f(0.0f, 0.0f, 0.0f); // Set color to white
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    gluOrtho2D(0, 400, 0, 400); // Set the orthographic projection
	drawString(175, 300, "Awesome!", GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
	drawString(175, 275, "You NAILED it in time", GLUT_BITMAP_HELVETICA_18, 0.5f, 0.5f, 1.0f);
	drawString(175, 250, "Thank you for playing ICYJUMPS", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 225, "Credits:", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 200, "Ali Hisham;", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 175, "Mostafa Nabil;", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 150, "Omar Gamal;", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 125, "if you have questions don't hesitate to", GLUT_BITMAP_9_BY_15, 0.99f, 0.99f, 0.99f);
	drawString(175, 115, "contact us alihisham26m@gmail.com", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);
	drawString(175, 95, "Press ESC key to exit the game, only if you want to :-[", GLUT_BITMAP_9_BY_15, 0.9f, 0.9f, 0.9f);

    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}



void drawStickman() {

	//head as a circle
	const float radius = 0.015f;
	const int numSegments = 50;
	glBegin(GL_POLYGON);
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);
		glVertex2f(x, y + 0.015f);
	}
	glEnd();

	glColor3f(1 , 0 , 0);
	glBegin(GL_LINES);
	// body
	glVertex2f(0.0f, 0.015f);
	glVertex2f(0.0f, -0.035f);

	// arms
	glVertex2f(0.0f, -0.015f);
	glVertex2f(0.03f, 0.0f);
	glVertex2f(0.0f, -0.015f);
	glVertex2f(-0.03f, 0.0f);

	// legs
	glVertex2f(0.0f, -0.035f);
	glVertex2f(0.03f, -0.05f);
	glVertex2f(0.0f, -0.035f);
	glVertex2f(-0.03f, -0.05f);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (!hehe) {
		if (firstLevelDone) {
			endScene();

			//heart
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glBegin(GL_LINE_LOOP);
			glVertex2f(-0.55f, -0.2f);
			glVertex2f(-0.8f, 0.2f);
			glVertex2f(-0.7f, 0.4f);
			glVertex2f(-0.55f, 0.2f);
			glVertex2f(-0.55f, 0.2f);
			glVertex2f(-0.4f, 0.4f);
			glVertex2f(-0.3f, 0.2f);
			glEnd();
			glutPostRedisplay();

		}
		else if (restart) {
			float xPos = 0.0f;
			float yPos = -0.95f;
			float yVelocity = 0.0f;
			float gravity = -0.0006f;
			bool isKeyPressed = false;
			float objectSize = 0.05f;
			bool firstLevelDone = false;
			bool restart = false;
			int timer = 10000;
			bool start = false;
		}
		else if (firstLevelDone == false && start) {
			firstLevel();

			glColor3f(1.0f, 1.0f, 1.0f); 
			glRasterPos2f(0.58f, 0.9f);
			std::string timerText = "Timer: " + std::to_string(timer); //convert the time to string
			for (char& c : timerText) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
			if (timer < 500) {
				glPushMatrix();
				gluOrtho2D(0, 400, 0, 400);
				drawString(320, 360, "Hurry up", GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 0.0f, 0.0f);
				glPopMatrix();
				glMatrixMode(GL_MODELVIEW);
			}


			glColor3f(1, 0, 0);
			glTranslatef(xPos, yPos, 0.0f);
			drawStickman();
		}
		else {
			glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			gluOrtho2D(0, 400, 0, 400); // Set the orthographic projection
			drawString(140, 250, "WELCOME. to the greatest game ever", GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 1.0f, 1.0f);
			drawString(170, 225, "ICYYYYYY JUMPS!", GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 0.0f, 0.0f);
			drawString(140, 200, "You know the controls. just keep it in time", GLUT_BITMAP_HELVETICA_18, 0.5f, 0.5f, 1.0f);
			drawString(180, 180, "Press s to start", GLUT_BITMAP_HELVETICA_18, 1.0f, 1.0f, 1.0f);
			drawString(145, 165, "or ESC to exit (you don't want to do that)", GLUT_BITMAP_HELVETICA_18, 0.5f, 0.0f, 0.0f);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		}
	}
	else if(hehe)
		drawgameover();
	glFlush();
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		yPos += 0.1f;
		break;
	case GLUT_KEY_LEFT:
		xPos -= 0.02f;
		break;
	case GLUT_KEY_RIGHT:
		xPos += 0.02f;
		break;
	default:
		break;
	}

	yVelocity += gravity;
	yPos += yVelocity;
	isKeyPressed = true;  //Set flag when any arrow key is pressed
	glutPostRedisplay();  //redraw the scene
}

void releaseKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		isKeyPressed = false;  //Reset flag when any arrow key is released
		break;
	default:
		break;
	}
}

void update(int value) {
     //Apply gravity when no arrow keys are pressed
	if (!isKeyPressed) {
		yVelocity += gravity;
		yPos += yVelocity;
	}

	// Check boundaries to prevent object from going outside the window
	if (xPos - objectSize < -0.8f) {
		xPos = -0.8f + objectSize;
	}
	if (xPos + objectSize > 0.8f) {
		xPos = 0.8f - objectSize;
	}
	if (yPos - objectSize < -1.0f) {
		yPos = -1.0f + objectSize;
		yVelocity = 0.0f;  //Stop vertical movement
	}
	if (yPos + objectSize > 1.0f) {
		yPos = 1.0f - objectSize;
		yVelocity = 0.0f;  //Stop vertical movement
	}

	//-----------------------------------------1-----------------------------------------------
	//if the character is above, land on the object
	if (yPos < -0.75) {
		if (yPos > -0.8 && xPos > -0.79 && xPos < -0.25) {
			yPos = -0.85f;
			yVelocity = 0.0f;
		}
	}//if the character is down, it cant go up
	else if (yPos > -0.75) {
		if (yPos > -0.8 && yPos < -0.6 && xPos > -0.79 && xPos < -0.25) {
			yPos = -0.66f;
			yVelocity = 0.0f;
		}
	}

	//-----------------------------------------2-----------------------------------------------
	if (yPos < -0.45) {
		if (yPos > -0.5 && xPos > -0.3 && xPos < 0.3) {
			yPos = -0.55f;
			yVelocity = 0.0f;
		}
	}
	else if (yPos > -0.45) {
		if(yPos > -0.5f && yPos < -0.3f && xPos > -0.3 && xPos < 0.3) {
			yPos = -0.39f;
			yVelocity = 0.0f;
		}
	}

	//-----------------------------------------3-----------------------------------------------
	
	if (yPos < -0.05) {
		if (yPos > -0.10 && xPos > 0.6 && xPos < 0.79) {
			yPos = -0.15f;
			yVelocity = 0.0f;
		}
	}
	else if (yPos > -0.05) {
		if (yPos > -0.1f && yPos < 0.0f && xPos > 0.6 && xPos < 0.79) {
			yPos = 0.0f;
			yVelocity = 0.0f;
		}
	}

	//-----------------------------------------4-----------------------------------------------
	
	if (yPos < 0.45) {
		if (yPos > 0.3 && xPos > 0.7 && xPos < 0.79) {
			yPos = 0.4f;
			yVelocity = 0.0f;
		}
	}
	else if (yPos > 0.35) {
		if (yPos < 0.3f && yPos < 0.4f && xPos > 0.7 && xPos < 0.79) {
			yPos = 0.25f;
			yVelocity = 0.0f;
		}
	}

	//-----------------------------------------5-----------------------------------------------
	
	if (yPos < 0.65) {
		if (yPos > 0.5 && xPos > -0.2 && xPos < 0.2) {
			yPos = 0.57;
			yVelocity = 0.0f;
		}
	}
	else if (yPos < 0.66) {
		if (yPos > 0.5 && yPos < 0.7 && xPos > -0.2 && xPos < 0.2) {
			yPos = 0.59f;
			yVelocity = 0.0f;
		}
	}

	//-----------------------------------------6-----------------------------------------------
	
	if (yPos < 0.85) {
		if (yPos > 0.7 && xPos > -0.79 && xPos < -0.3) {
			yPos = 0.77;
			yVelocity = 0.0f;
		}
	}
	else if (yPos < 0.66) {
		if (yPos > 0.5 && yPos < 0.7 && xPos > -0.2 && xPos < 0.2) {
			yPos = 0.59f;
			yVelocity = 0.0f;
		}
	}

	timer--;
	if (timer <= 0) {
		hehe = true;
	}
	//-----------------if it gets to the flag---------------------
	if (yPos > 0.85 && xPos < -0.6) {
		firstLevelDone = true;
		glutDisplayFunc(display);
	}
	else {
		glutPostRedisplay(); //redraw the scene
		glutTimerFunc(16, update, 0); // Update at 60 FPS (1000ms/60 = 16ms)

	}
}

void main(int argc, char** argv)
{
		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1200, 700);
		glutInitWindowPosition(100, 50);
		glutCreateWindow("IcyJumps");

		glutDisplayFunc(display);
		glutSpecialFunc(specialKeys);  
		glutSpecialUpFunc(releaseKeys); 
		glutKeyboardFunc(keyboard);
		glutTimerFunc(0, update, 0);

		glutMainLoop();
	
}