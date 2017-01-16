#include "header.h"
#include "init.h"

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void scroll_callback(GLFWwindow* window, double x, double y)
{
    zoom += (float) y / 4.f;
    if (zoom < 0)
        zoom = 0;
}

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
     // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        switch (key) {
            /*case GLFW_KEY_LEFT_CONTROL || GLFW_KEY_RIGHT_CONTROL:
                red_flag = 0;*/
            case GLFW_KEY_LEFT_CONTROL:
                if(red_bucket_translation_incr < 0.0f)
                    red_bucket_translation_incr = 0.0f;
                break;
            case GLFW_KEY_RIGHT_CONTROL:
                if(red_bucket_translation_incr > 0.0f)
                    red_bucket_translation_incr = 0.0f;
                break;
            case GLFW_KEY_LEFT_ALT:
                if(green_bucket_translation_incr < 0.0f)
                    green_bucket_translation_incr = 0.0f;
                break;
            case GLFW_KEY_RIGHT_ALT:
                if(green_bucket_translation_incr > 0.0f)
                    green_bucket_translation_incr = 0.0f;
                break;
            case GLFW_KEY_S:
                if(CANNON_CORD_SPEED > 0.0f)
                    CANNON_CORD_SPEED = 0.0f;
                break;
            case GLFW_KEY_F:
                if(CANNON_CORD_SPEED < 0.0f)
                    CANNON_CORD_SPEED = 0.0f;
                break;
            case GLFW_KEY_A:
                if(cannon_rotation_dir > 0)
                    cannon_rotation_dir = 0;
                    cannon_rotation_increment = 0;
                break;
            case GLFW_KEY_D:
                if(cannon_rotation_dir < 0)
                    cannon_rotation_dir = 0;
                    cannon_rotation_increment = 0;
                break;
            case GLFW_KEY_X:
                // do something ..
                break;
            default:
                break;
        }
    }
    else if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_LEFT_CONTROL:
                red_bucket_translation_incr = -0.05f;
                break;
            case GLFW_KEY_RIGHT_CONTROL:
                red_bucket_translation_incr = 0.05f;
                break;
            case GLFW_KEY_LEFT_ALT:
                green_bucket_translation_incr = -0.05f;
                break;
            case GLFW_KEY_RIGHT_ALT:
                green_bucket_translation_incr = 0.05f;
                break;
            case GLFW_KEY_S:
                CANNON_CORD_SPEED = 0.05f;
                break;
            case GLFW_KEY_F:
                CANNON_CORD_SPEED = -0.05f;
                break;
            case GLFW_KEY_A:
                cannon_rotation_dir = 1;
                cannon_rotation_increment = 1;
                break;
            case GLFW_KEY_SPACE:
                BULLET.push_back(new VAO());
                BULLET_REVERSE.push_back(new VAO());
                BULLET_CORD_X.push_back(CANNON_CORD_X+cos(cannon_rotation*M_PI/180));
                BULLET_CORD_Y.push_back(CANNON_CORD_Y+sin(cannon_rotation*M_PI/180));
                BULLET_XCORD_SPEED.push_back(BULLET_SPEED*cos(cannon_rotation*M_PI/180));
                BULLET_YCORD_SPEED.push_back(BULLET_SPEED*sin(cannon_rotation*M_PI/180));
                BULLET_FLAG.push_back(0);
                break;
            case GLFW_KEY_D:
                cannon_rotation_dir = -1;
                cannon_rotation_increment = 1;
                break;
            case GLFW_KEY_DOWN:
                zoom -= 0.25f;
                if (zoom < 0.f)
                    zoom = 0.f;
                break;
            case GLFW_KEY_UP:
                zoom += 0.25f;
                break;
            case GLFW_KEY_ESCAPE:
                quit(window);
                break;
            default:
                break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
	switch (key) {
		case 'Q':
		case 'q':
            quit(window);
            break;
		default:
			break;
	}
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
        case GLFW_MOUSE_BUTTON_RIGHT:
            if (action == GLFW_RELEASE) {
                rectangle_rot_dir *= -1;
            }
            break;
        default:
            break;
    }
}


/* Executed when window is resized to 'width' and 'height' */
/* Modify the bounds of the screen here in glm::ortho or Field of View in glm::Perspective */
void reshapeWindow (GLFWwindow* window, int width, int height)
{
    int fbwidth=width, fbheight=height;
    /* With Retina display on Mac OS X, GLFW's FramebufferSize
     is different from WindowSize */
    glfwGetFramebufferSize(window, &fbwidth, &fbheight);

	GLfloat fov = 90.0f;

	// sets the viewport of openGL renderer
	glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

	// set the projection matrix as perspective
	/* glMatrixMode (GL_PROJECTION);
	   glLoadIdentity ();
	   gluPerspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1, 500.0); */
	// Store the projection matrix in a variable for future use
    // Perspective projection for 3D views
    // Matrices.projection = glm::perspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1f, 500.0f);

    // Ortho projection for 2D views
    Matrices.projection = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f, 0.1f, 500.0f);
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void quit(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
//    exit(EXIT_SUCCESS);
}


/* Initialise glfw window, I/O callbacks and the renderer to use */
/* Nothing to Edit here */
GLFWwindow* initGLFW (int width, int height)
{
    GLFWwindow* window; // window desciptor/handle

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
//        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Sample OpenGL 3.3 Application", NULL, NULL);

    if (!window) {
        glfwTerminate();
//        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval( 1 );

    /* --- register callbacks with GLFW --- */

    /* Register function to handle window resizes */
    /* With Retina display on Mac OS X GLFW's FramebufferSize
     is different from WindowSize */
    glfwSetFramebufferSizeCallback(window, reshapeWindow);
    glfwSetWindowSizeCallback(window, reshapeWindow);

    glfwSetScrollCallback(window, scroll_callback);

    /* Register function to handle window close */
    glfwSetWindowCloseCallback(window, quit);

    /* Register function to handle keyboard input */
    glfwSetKeyCallback(window, keyboard);      // general keyboard input
    glfwSetCharCallback(window, keyboardChar);  // simpler specific character handling

    /* Register function to handle mouse click */
    glfwSetMouseButtonCallback(window, mouseButton);  // mouse button clicks

    return window;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL (GLFWwindow* window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
	// Create the models
    // Generate the VAO, VBOs, vertices data & copy into the array buffer

	createRectangle ();
    createBucket ();
    createCannon ();
    createCannonGun();
    createMirror();

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


	reshapeWindow (window, width, height);

    // Background color of the scene
	glClearColor (1.0f, 1.0f, 1.0f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}