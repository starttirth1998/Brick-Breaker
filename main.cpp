#include "header.h"
#include "main.h"

extern struct GLMatrices Matrices;
extern GLuint programID;

/**************************
 * Customizable functions *
 **************************/

void score()
{
    vector<int> DELETE;
    for(int i=0;i<BLOCKS.size();i++)
    {      
        if(abs(rectangle_translation_x[i] - red_bucket_translation_x) < 0.875f && 
            abs(rectangle_translation_x[i] - green_bucket_translation_x) < 0.875f)
            GAME_SCORE = GAME_SCORE + 0;
        else if(block_color[i] == 0 && abs(rectangle_translation_x[i] - red_bucket_translation_x) < 0.875f &&
                rectangle_translation_y[i] - red_bucket_translation_y < 0.45f &&
                rectangle_translation_y[i] - red_bucket_translation_y > 0.40f)
        {
            GAME_SCORE = GAME_SCORE + 10;            
            DELETE.push_back(i);
        }
        else if(block_color[i] == 1 && abs(rectangle_translation_x[i] - green_bucket_translation_x) < 0.875f &&
                rectangle_translation_y[i] - green_bucket_translation_y < 0.45f &&
                rectangle_translation_y[i] - green_bucket_translation_y > 0.40f)
        {
            GAME_SCORE = GAME_SCORE + 10;            
            DELETE.push_back(i);
        }
        //cout << GAME_SCORE << endl;
        
    }
    for(int i=0;i<DELETE.size();i++)
    {
        BLOCKS.erase(BLOCKS.begin() + DELETE[i]);
        rectangle_translation_x.erase(rectangle_translation_x.begin() + DELETE[i]);
        rectangle_translation_y.erase(rectangle_translation_y.begin() + DELETE[i]);
        block_color.erase(block_color.begin() + DELETE[i]);
    }
    DELETE.clear();
}

void collision()
{
    vector< pair<int,int> > DELETE;
    for(int i=0;i<BULLET.size();i++)
    {
        for(int j=0;j<BLOCKS.size();j++)
        {
            if(abs(BULLET_CORD_X[i] - rectangle_translation_x[j]) < 2*BULLET_RADIUS+0.04f 
            && abs(BULLET_CORD_Y[i] - rectangle_translation_y[j]) < 2*BULLET_RADIUS+0.04f)
            {
                if(block_color[j] == 2)
                    GAME_SCORE = GAME_SCORE + 10;
                DELETE.push_back({i,j});
            }
        }
    }
    for(int i=0;i<DELETE.size();i++)
    {
        BULLET.erase(BULLET.begin() + DELETE[i].first);
        BULLET_REVERSE.erase(BULLET_REVERSE.begin() + DELETE[i].first);
        BULLET_CORD_X.erase(BULLET_CORD_X.begin() + DELETE[i].first);
        BULLET_CORD_Y.erase(BULLET_CORD_Y.begin() + DELETE[i].first);
        BULLET_XCORD_SPEED.erase(BULLET_XCORD_SPEED.begin() + DELETE[i].first);
        BULLET_YCORD_SPEED.erase(BULLET_YCORD_SPEED.begin() + DELETE[i].first);
        BULLET_FLAG.erase(BULLET_FLAG.begin() + DELETE[i].first);
        BLOCKS.erase(BLOCKS.begin() + DELETE[i].second);
        rectangle_translation_x.erase(rectangle_translation_x.begin() + DELETE[i].second);
        rectangle_translation_y.erase(rectangle_translation_y.begin() + DELETE[i].second);
        block_color.erase(block_color.begin() + DELETE[i].second);
    }
    DELETE.clear();
}

void outside_board()
{
    vector<int> DELETE;
    for(int i=0;i<BULLET.size();i++)
    {
        if(BULLET_CORD_X[i] > RIGHT_LIMIT || BULLET_CORD_X[i] < LEFT_LIMIT || 
            BULLET_CORD_Y[i] < LOWER_LIMIT || BULLET_CORD_Y[i] > UPPER_LIMIT)
        {
            GAME_SCORE = GAME_SCORE - 5;
            DELETE.push_back(i);
        }
    }
    for(int i=0;i<DELETE.size();i++)
    {
        BULLET.erase(BULLET.begin() + DELETE[i]);
        BULLET_REVERSE.erase(BULLET_REVERSE.begin() + DELETE[i]);
        BULLET_CORD_X.erase(BULLET_CORD_X.begin() + DELETE[i]);
        BULLET_CORD_Y.erase(BULLET_CORD_Y.begin() + DELETE[i]);
        BULLET_XCORD_SPEED.erase(BULLET_XCORD_SPEED.begin() + DELETE[i]);
        BULLET_YCORD_SPEED.erase(BULLET_YCORD_SPEED.begin() + DELETE[i]);
        BULLET_FLAG.erase(BULLET_FLAG.begin() + DELETE[i]);
    }
    DELETE.clear();
    for(int i=0;i<BLOCKS.size();i++)
    {      
        if(rectangle_translation_y[i] < LOWER_LIMIT)
        {
            MISS++;
            DELETE.push_back(i);
        }
    }
    for(int i=0;i<DELETE.size();i++)
    {
        BLOCKS.erase(BLOCKS.begin() + DELETE[i]);
        rectangle_translation_x.erase(rectangle_translation_x.begin() + DELETE[i]);
        rectangle_translation_y.erase(rectangle_translation_y.begin() + DELETE[i]);
        block_color.erase(block_color.begin() + DELETE[i]);
    }
    DELETE.clear();
}

void mirror_reflect()
{
    for(int i=0;i<BULLET.size();i++)
    {
        if( BULLET_FLAG[i] == 0 &&
            BULLET_CORD_Y[i] - tan(MIRROR_ANGLE*M_PI/180.0f)*BULLET_CORD_X[i] >= 0.0f &&
            abs( BULLET_CORD_Y[i] - tan(MIRROR_ANGLE*M_PI/180.0f)*BULLET_CORD_X[i]) < 0.08f &&          
            BULLET_CORD_X[i] > -(MIRROR_LENGTH) &&
            BULLET_CORD_X[i] < (MIRROR_LENGTH) )
            {
                BULLET_FLAG[i] = 1;
                float angle = 2*MIRROR_ANGLE*M_PI/180.0f + 2*atan(-BULLET_YCORD_SPEED[i]/BULLET_XCORD_SPEED[i]);
                cout << angle*180.0f/M_PI << endl;
                BULLET_XCORD_SPEED[i] = BULLET_XCORD_SPEED[i]*cos(angle)-BULLET_YCORD_SPEED[i]*sin(angle);
                BULLET_YCORD_SPEED[i] = BULLET_XCORD_SPEED[i]*sin(angle)+BULLET_YCORD_SPEED[i]*cos(angle);
                //BULLET_YCORD_Y[i] = BULLET_CORD_Y[i]*cos(90*M_PI/180.0f) - BULLET_CORD_Y[i]*sin(90*M_PI/180.0f); 
            }
    }
}

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
  

  collision();
  score();
  outside_board();
  mirror_reflect();

  /* -------------------------------- FALLING BLOCK CODE STARTS HERE ----------------------------------*/


  // draw3DObject draws the VAO given to it using current MVP matrix
  //cout << "Block Size" << BLOCKS.size() << endl;
  for(int i=0;i<BLOCKS.size();i++)
  {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translateRectangle = glm::translate (glm::vec3(rectangle_translation_x[i], rectangle_translation_y[i], 0.0));        // glTranslatef
    //glm::mat4 rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    Matrices.model *= (translateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(BLOCKS[i]);
    //cout << "draw" << " " << i << endl;
    //draw3DObject(rectangle);
    rectangle_translation_y[i] = rectangle_translation_y[i] - rectangle_translation_incr;
  }

  /*-------------------------------------- FALLING BLOCK ENDS HERE -----------------------------------*/

  /*------------------------------------ BUCKET CODE STARTS HERE ------------------------------------*/

  Matrices.model = glm::mat4(1.0f);
    glm::mat4 translateRectangle = glm::translate (glm::vec3(red_bucket_translation_x, red_bucket_translation_y, 0));        // glTranslatef
    Matrices.model *= (translateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(bucket[0]);

  Matrices.model = glm::mat4(1.0f);
    translateRectangle = glm::translate (glm::vec3(green_bucket_translation_x, green_bucket_translation_y, 0));        // glTranslatef
    //rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    Matrices.model *= (translateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(bucket[1]);

  
  red_bucket_translation_x = red_bucket_translation_x + red_bucket_translation_incr;
  if(red_bucket_translation_x < LEFT_LIMIT+0.8f || red_bucket_translation_x > RIGHT_LIMIT-0.8f)
    red_bucket_translation_x = red_bucket_translation_x - red_bucket_translation_incr;
  green_bucket_translation_x = green_bucket_translation_x + green_bucket_translation_incr;
  if(green_bucket_translation_x < LEFT_LIMIT+0.8f || green_bucket_translation_x > RIGHT_LIMIT-0.8f)
    green_bucket_translation_x = green_bucket_translation_x - green_bucket_translation_incr;

  /* ---------------------------------------- BUCKET CODE ENDS HERE ------------------------------------*/

  //camera_rotation_angle++; // Simulating camera rotation
  //rectangle_rotation = rectangle_rotation + increments*rectangle_rot_dir*rectangle_rot_status;
  //rectangle_translation = rectangle_translation - rectangle_translation_incr;

  /* ----------------------------------------- LINE ABOVE BUCKET CODE STARTS HERE -------------------------*/

    Matrices.model = glm::mat4(1.0f);
    translateRectangle = glm::translate (glm::vec3(0, -3, 0));        // glTranslatef
    //rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    Matrices.model *= (translateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(bucket_line);

   /* ----------------------------------------- LINE ABOVE BUCKET CODE ENDS HERE -------------------------*/


   /* ----------------------------------------- CANNON CODE STARTS HERE ----------------------------------*/
    for(int i=0;i<180;i++)
    {
        //CANNON.push_back(new VAO());
        Matrices.model = glm::mat4(1.0f);
        translateRectangle = glm::translate (glm::vec3(CANNON_CORD_X, CANNON_CORD_Y, 0));        // glTranslatef
        //rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
        Matrices.model *= (translateRectangle);
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(CANNON[i]);
    }

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translateCannonGun = glm::translate (glm::vec3(CANNON_CORD_X, CANNON_CORD_Y, 0));        // glTranslatef
    //glm::mat4 translateCannonGunToOrigin = glm::translate (glm::vec3(-CANNON_CENTER_X ,-CANNON_CENTER_Y, 0)); 
    glm::mat4 rotateCannonGun = glm::rotate((float)(cannon_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    //glm::mat4 translateCannonGunToOriginal = glm::translate (glm::vec3(CANNON_CENTER_X ,CANNON_CENTER_Y, 0));
    Matrices.model *= (translateCannonGun*rotateCannonGun );
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(CANNON_GUN);    
    CANNON_CORD_Y = CANNON_CORD_Y + CANNON_CORD_SPEED;
    if(CANNON_CORD_Y > UPPER_LIMIT-1.0f || CANNON_CORD_Y < LOWER_LIMIT+1.0f)
        CANNON_CORD_Y = CANNON_CORD_Y - CANNON_CORD_SPEED;
    cannon_rotation = cannon_rotation + cannon_rotation_increment*cannon_rotation_dir;
    if(cannon_rotation > 80 || cannon_rotation < -80)
        cannon_rotation = cannon_rotation - cannon_rotation_increment*cannon_rotation_dir;
        
  /* ------------------------------------------ CANNON CODE ENDS HERE -----------------------------------*/


  /* ----------------------------------------- BULLET CODE STARTS HERE -----------------------------------*/
  if(!BULLET.empty())
  {
    createBullet();
    for(int i=0;i<BULLET.size();i++)
    {
        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translateBullet = glm::translate (glm::vec3(BULLET_CORD_X[i], BULLET_CORD_Y[i], 0));        // glTranslatef
        glm::mat4 rotateBullet = glm::rotate((float)(bullet_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
        Matrices.model *= (translateBullet*rotateBullet );
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(BULLET[i]);
        draw3DObject(BULLET_REVERSE[i]);
        BULLET_CORD_X[i] = BULLET_CORD_X[i] + BULLET_XCORD_SPEED[i];
        BULLET_CORD_Y[i] = BULLET_CORD_Y[i] + BULLET_YCORD_SPEED[i];
        bullet_rotation = bullet_rotation + bullet_rotation_increment*bullet_rotation_dir;
    }
  }
    /* ----------------------------------------- BULLET CODE ENDS HERE ------------------------------------*/


    /* ----------------------------------------- MIRROR CODE STARTS HERE ----------------------------------*/

    Matrices.model = glm::mat4(1.0f);
    translateRectangle = glm::translate (glm::vec3(0, 0, 0));        // glTranslatef
    glm::mat4 rotateRectangle = glm::rotate((float)(MIRROR_ANGLE*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
    Matrices.model *= (translateRectangle*rotateRectangle);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(MIRROR);

    /* ----------------------------------------- MIRROR CODE ENDS HERE ---------------------------------------*/
}

int main (int argc, char** argv)
{
	int width = 800;
	int height = 600;

    GLFWwindow* window = initGLFW(width, height);

    for(int i=0;i<180;i++)
    {
        CANNON.push_back(new VAO());
    }
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


        /* FALLING BLOCK RENDERING CODE STARTS HERE */

        // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
        current_time = glfwGetTime(); // Time in seconds
        if ((current_time - last_update_time) >= 1.0) { // atleast 1.0s elapsed since last frame
            // do something every 0.5 seconds ..
            BLOCKS.push_back(new VAO());
            float temp_y = 4.0f;
            //float temp_x = -2.0f;
            float temp_x = -2.5f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/6.0f));
            rectangle_translation_x.push_back(temp_x);
            rectangle_translation_y.push_back(temp_y);
            block_color.push_back(rand()%3);
            //rectangle_translation_y[rectangle_translation_y.size()-1] = 4.0f;
            createRectangle();
            //cout << BLOCKS.size()-1 << endl;
            last_update_time = current_time;
        }

        /* FALLING BLOCK RENDERING CODE ENDS HERE */
    }

    glfwTerminate();
    //    exit(EXIT_SUCCESS);
}
