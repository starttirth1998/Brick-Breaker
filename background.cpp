#include "header.h"
#include "background.h"

// Creates the rectangle object used in this sample code
void createBackground ()
{
  // GL3 accepts only Triangles. Quads are not supported

  static const GLfloat vertex_buffer_data[] = {
    -4,-4,0, // vertex 1
    4,-4,0, // vertex 2
    4, -3,0, // vertex 3

    4, -3,0, // vertex 3
    -4, -3,0, // vertex 4
    -4,-4,0  // vertex 1
  };

  static const GLfloat color_buffer_data_green [] = {
    0.6,1,0.6, // color 1
    0.6,1,0.6, // color 2
    0.6,1,0.6, // color 3

    0.6,1,0.6, // color 3
    0.6,1,0.6, // color 4
    0.6,1,0.6  // color 1
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  //cout << "createRectangle" << BLOCKS.size() << endl;
 
  background = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_green, GL_FILL);  
  //background1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_1, color_buffer_data_light, GL_FILL);    
}