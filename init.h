struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};

static void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
void scroll_callback(GLFWwindow* window, double x, double y);
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void createRectangle ();
void createBucket ();
void createCannon ();
void createCannonGun();
void createBullet();
void createMirror();


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

struct GLMatrices Matrices;

extern GLfloat zoom;
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
extern float CANNON_CORD_X;
extern float CANNON_CORD_Y;
extern float cannon_rotation;

extern vector<VAO *> BULLET;
extern vector<VAO *> BULLET_REVERSE;
extern vector<float> BULLET_CORD_X;
extern vector<float> BULLET_CORD_Y;
extern vector<float> BULLET_XCORD_SPEED;
extern vector<float> BULLET_YCORD_SPEED;
extern float BULLET_SPEED;
extern vector<int> BULLET_FLAG_1;
extern vector<int> BULLET_FLAG_2;

extern int width;
extern int height;
