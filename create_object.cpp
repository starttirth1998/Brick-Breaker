#include "header.h"
#include "create_object.h"

// Creates the rectangle object used in this sample code
void createRectangle ()
{
  // GL3 accepts only Triangles. Quads are not supported
  static const GLfloat vertex_buffer_data [] = {
    -0.15,-0.15,0, // vertex 1
    0.15,-0.15,0, // vertex 2
    0.15, 0.15,0, // vertex 3

    0.15, 0.15,0, // vertex 3
    -0.15, 0.15,0, // vertex 4
    -0.15,-0.15,0  // vertex 1
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

  static const GLfloat color_buffer_data_black [] = {
    0,0,0, // color 1
    0,0,0, // color 2
    0,0,0, // color 3

    0,0,0, // color 3
    0,0,0, // color 4
    0,0,0  // color 1
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  //cout << "createRectangle" << BLOCKS.size() << endl;
  if(!BLOCKS.empty())
  {
    for(int i=0;i<BLOCKS.size();i++)
    {
        if(block_color[i] == 0)
            BLOCKS[i] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_red, GL_FILL);
        if(block_color[i] == 1)
            BLOCKS[i] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_green, GL_FILL);
        if(block_color[i] == 2)
            BLOCKS[i] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_black, GL_FILL);
        //cout << i << "forloop" << endl;
    }
  }
  //rectangle = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_red, GL_FILL);   
}