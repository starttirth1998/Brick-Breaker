#include "header.h"
#include "main.h"

extern struct GLMatrices Matrices;
extern GLuint programID;

/**************************
 * Customizable functions *
 **************************/

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw ()
{
  // clear the color and depth in the frame buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // use the loaded shader program
  // Don't change unless you know what you are doing
  glUseProgram (programID);

  // Eye - Location of camera. Don't change unless you are sure!!
  glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  glm::vec3 target (0, 0, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  glm::vec3 up (0, 1, 0);

  // Compute Camera matrix (view)
  // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
  //  Don't change unless you are sure!!
  Matrices.view = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0)); // Fixed camera for 2D (ortho) in XY plane

  // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
  //  Don't change unless you are sure!!
  glm::mat4 VP = Matrices.projection * Matrices.view;

  // Send our transformation to the currently bound shader, in the "MVP" uniform
  // For each model you render, since the MVP will be different (at least the M part)
  //  Don't change unless you are sure!!
  glm::mat4 MVP;	// MVP = Projection * View * Model

  /* Render your scene */

  // Pop matrix to undo transformations till last push matrix instead of recomputing model matrix
  // glPopMatrix ();  
  // Load identity to model matrix
  


  float rectangle_translation_incr = 0.01;
  // draw3DObject draws the VAO given to it using current MVP matrix
  //cout << "Block Size" << BLOCKS.size() << endl;
  for(int i=0;i<BLOCKS.size();i++)
  {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translateRectangle = glm::translate (glm::vec3(rectangle_translation_x[i], rectangle_translation_y[i], 0));        // glTranslatef
    glm::mat4 rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    Matrices.model *= (translateRectangle * rotateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(BLOCKS[i]);
    //cout << "draw" << " " << i << endl;
    //draw3DObject(rectangle);
    rectangle_translation_y[i] = rectangle_translation_y[i] - rectangle_translation_incr;
  }

  
  // Increment angles
  float increments = 1;
  

  //camera_rotation_angle++; // Simulating camera rotation
  rectangle_rotation = rectangle_rotation + increments*rectangle_rot_dir*rectangle_rot_status;
  //rectangle_translation = rectangle_translation - rectangle_translation_incr;
}

int main (int argc, char** argv)
{
	int width = 600;
	int height = 600;

    GLFWwindow* window = initGLFW(width, height);

	initGL (window, width, height);

    double last_update_time = glfwGetTime(), current_time;

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

        // OpenGL Draw commands
        draw();
        // Swap Frame Buffer in double buffering
        glfwSwapBuffers(window);

        // Poll for Keyboard and mouse events
        glfwPollEvents();

        // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
        current_time = glfwGetTime(); // Time in seconds
        if ((current_time - last_update_time) >= 1.0) { // atleast 0.5s elapsed since last frame
            // do something every 0.5 seconds ..
            BLOCKS.push_back(new VAO());
            float temp_y = 4.0f;
            //float temp_x = -2.0f;
            float temp_x = -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/8.0f));
            rectangle_translation_x.push_back(temp_x);
            rectangle_translation_y.push_back(temp_y);
            block_color.push_back(rand()%3);
            //rectangle_translation_y[rectangle_translation_y.size()-1] = 4.0f;
            createRectangle();
            //cout << BLOCKS.size()-1 << endl;
            last_update_time = current_time;
        }
    }

    glfwTerminate();
//    exit(EXIT_SUCCESS);
}
