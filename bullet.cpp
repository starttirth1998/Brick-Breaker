#include "header.h"
#include "bullet.h"

void createBullet ()
{
  /* ONLY vertices between the bounds specified in glm::ortho will be visible on screen */
      /* Define vertex array as used in glBegin (GL_TRIANGLES) */
  
    static const GLfloat bullet_data [] = {
      0, BULLET_RADIUS,0, // vertex 0
      -BULLET_RADIUS,-BULLET_RADIUS,0, // vertex 1
      BULLET_RADIUS,-BULLET_RADIUS,0, // vertex 2
    };

    static const GLfloat bullet_data_reverse [] = {
      0, -BULLET_RADIUS - 0.05f ,0, // vertex 0
      -BULLET_RADIUS,BULLET_RADIUS - 0.05f,0, // vertex 1
      BULLET_RADIUS,BULLET_RADIUS - 0.05f,0, // vertex 2
    };

    static const GLfloat bullet_color [] = {
      0,0,1, // color 1
      0,0,1, // color 2
      0,0,1, // color 3

      0,0,1, // color 3
      0,0,1, // color 4
      0,0,1  // color 1
    };

  for(int i=0;i<BULLET.size();i++)
  {
    BULLET[i] = create3DObject(GL_TRIANGLES, 3, bullet_data, bullet_color, GL_FILL); 
    BULLET_REVERSE[i] = create3DObject(GL_TRIANGLES, 3, bullet_data_reverse, bullet_color, GL_FILL);
  }
}