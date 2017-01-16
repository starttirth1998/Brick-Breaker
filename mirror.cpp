#include "header.h"
#include "mirror.h"

void createMirror ()
{
  
  static const GLfloat line_data [] = {
    -MIRROR_LENGTH,-0.02,0, // vertex 1
    MIRROR_LENGTH,-0.02,0, // vertex 2
    MIRROR_LENGTH, 0.02,0, // vertex 3

    MIRROR_LENGTH, 0.02,0, // vertex 3
    -MIRROR_LENGTH, 0.02,0, // vertex 4
    -MIRROR_LENGTH,-0.02,0  // vertex 1
  };

  static const GLfloat line_color [] = {
    0,0.5,0.8, // color 1
    0,0.5,0.8, // color 2
    0,0.5,0.8, // color 3

    0,0.5,0.8, // color 3
    0,0.5,0.8, // color 4
    0,0.5,0.8  // color 1
  };


  // create3DObject creates and returns a handle to a VAO that can be used later
  //cout << "createRectangle" << BLOCKS.size() << endl; 

  MIRROR = create3DObject(GL_TRIANGLES, 6, line_data, line_color, GL_FILL); 
}