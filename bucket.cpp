#include "header.h"
#include "bucket.h"

// Creates the rectangle object used in this sample code
void createBucket ()
{
  // GL3 accepts only Triangles. Quads are not supported
  static const GLfloat vertex_buffer_data_red [] = {
    -0.5,-0.35,0, // vertex 1
    0.5,-0.35,0, // vertex 2
    0.5, 0.35,0, // vertex 3

    0.5, 0.35,0, // vertex 3
    -0.5, 0.35,0, // vertex 4
    -0.5,-0.35,0  // vertex 1
  };

  static const GLfloat vertex_buffer_data_green [] = {
    -0.5,-0.35,0, // vertex 1
    0.5,-0.35,0, // vertex 2
    0.5, 0.35,0, // vertex 3

    0.5, 0.35,0, // vertex 3
    -0.5, 0.35,0, // vertex 4
    -0.5,-0.35,0  // vertex 1
  };

  static const GLfloat color_buffer_data_red [] = {
    1,0,0, // color 1
    1,0,0, // color 2
    1,0,0, // color 3

    1,0,0, // color 3
    1,0,0, // color 4
    1,0,0  // color 1
  };

  static const GLfloat color_buffer_data_green [] = {
    0,1,0, // color 1
    0,1,0, // color 2
    0,1,0, // color 3

    0,1,0, // color 3
    0,1,0, // color 4
    0,1,0  // color 1
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  //cout << "createRectangle" << BLOCKS.size() << endl;
  bucket[0] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_red, color_buffer_data_red, GL_FILL);
  bucket[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_green, color_buffer_data_green, GL_FILL);  
}