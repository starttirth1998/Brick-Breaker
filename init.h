struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};

static void error_callback(int error, const char* description);
void quit(GLFWwindow *window);

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);

void createRectangle ();
void createBucket ();
void createCannon ();
void createCannonGun();
void createBullet();


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

struct GLMatrices Matrices;

GLuint programID;
struct VAO *rectangle;

float rectangle_rot_dir = 1;
bool rectangle_rot_status = false;

float camera_rotation_angle = 90;
float rectangle_rotation = 0;
//float rectangle_translation = 4;

vector<float> rectangle_translation_y;
vector<float> rectangle_translation_x;
vector<float> block_color;

extern float red_bucket_translation_incr;
extern float green_bucket_translation_incr;

extern float CANNON_CORD_SPEED;
extern float cannon_rotation_dir;
extern float cannon_rotation_increment;
