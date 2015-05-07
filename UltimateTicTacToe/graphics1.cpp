
// ******************************* Erik Bylund ********************************//

#include <cmath>
#include <cstring>
#include <cstdlib>
#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif

#include "Game.h"
# include <iostream>


// Global Variables (Only what you need!)
double screen_x = 500;
double screen_y = 500;
Game game(0, 0, 500);


// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_9_BY_15;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
	
  int len, i;
  glRasterPos2d(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) 
    {
      glutBitmapCharacter(font, string[i]);
    }

  glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  // Test lines that draw all three shapes and some text.
  // Delete these when you get your code working.
//  glColor3d(0,0,1);
//  DrawRectangle(200, 200, 250, 250);
//  DrawTriangle(300, 300, 350, 300, 350, 350);
//  DrawCircle(50, 50, 30);
//
//  glColor3d(0,0,0);
//  DrawText(10,100,"Can you see this black text and 3 blue shapes?");

    game.draw();

  glutSwapBuffers();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
  switch (c) 
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 'b':
      // do something when 'b' character is hit.
      break;
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  screen_x = w;
  screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
  // translate pixel coordinates to display coordinates
  int xdisplay = x;
  int ydisplay = screen_y - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
        if (game.click(xdisplay, ydisplay))
        {
            glutPostRedisplay();
        }
        
    }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
    {
    }
  glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(screen_x, screen_y);
  glutInitWindowPosition(450, 250);

  int fullscreen = 0;
  if (fullscreen) 
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    } 
  else 
    {
      glutCreateWindow("This appears in the title bar");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);


  glClearColor(.8, .8, .8, 0); // background color
  InitializeMyStuff();

  glutMainLoop();

  return 0;
}
