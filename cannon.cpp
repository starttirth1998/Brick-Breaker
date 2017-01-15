#include "header.h"
#include "cannon.h"

void createCannon ()
{
  /* ONLY vertices between the bounds specified in glm::ortho will be visible on screen */

  for(int i=0;i<180;i++)
  {
      /* Define vertex array as used in glBegin (GL_TRIANGLES) */
      GLfloat line_data [] = {
      CANNON_RADIUS*(float)cos((i-90)*M_PI/180),CANNON_RADIUS*(float)sin((i-90)*M_PI/180),0, // vertex 1
      0,0,0, // vertex 2
      CANNON_RADIUS*(float)cos((i-90)*M_PI/180),CANNON_RADIUS*(float)sin((i-90)*M_PI/180) + 0.05f,0, // vertex 3

      CANNON_RADIUS*(float)cos((i-90)*M_PI/180),CANNON_RADIUS*(float)sin((i-90)*M_PI/180) + 0.05f,0, // vertex 3
      0,0,0, // vertex 4
      CANNON_RADIUS*(float)cos((i-90)*M_PI/180),CANNON_RADIUS*(float)sin((i-90)*M_PI/180),0  // vertex 1
    };

    static const GLfloat line_color [] = {
      0,0,1, // color 1
      0,0,1, // color 2
      0,0,1, // color 3

      0,0,1, // color 3
      0,0,1, // color 4
      0,0,1  // color 1
    };

      // create3DObject creates and returns a handle to a VAO that can be used later
    CANNON[i] = create3DObject(GL_TRIANGLES, 6, line_data, line_color, GL_FILL); 
  }
}

void createCannonGun()
{
  /* Define vertex array as used in glBegin (GL_TRIANGLES) */
      GLfloat line_data [] = {
      0 ,0.10f,0, // vertex 1
      0 ,-0.05f,0, // vertex 2
      1.0f,-0.05f,0, // vertex 3

      1.0f,-0.05f,0, // vertex 3
      1.0f,0.10f,0, // vertex 4
      0 ,0.10f,0  // vertex 1
    };

    static const GLfloat line_color [] = {
      0,0,1, // color 1
      0,0,1, // color 2
      0,0,1, // color 3

      0,0,1, // color 3
      0,0,1, // color 4
      0,0,1  // color 1
    };

      // create3DObject creates and returns a handle to a VAO that can be used later
    CANNON_GUN = create3DObject(GL_TRIANGLES, 6, line_data, line_color, GL_FILL);
}
