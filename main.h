
//Tirth Maniar
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector< VI > VVI;    	// 2-d array
typedef pair<int,int> PII;
typedef vector<PII> VPII;

struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};

struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

GLFWwindow* window;
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
void createRectangle ();
void draw ();
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
static void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);
void draw3DObject (struct VAO* vao);


void createRectangle ();
void createBullet ();
void collision ();
void outside_board();
void score();
void mirror_reflect();
void DrawMirror();
void DrawBlocks();
void DrawBucket();
void DrawCannon();
void DrawBullet();

vector<struct VAO *> BLOCKS;

extern struct VAO *rectangle;

extern float rectangle_rot_dir;
extern bool rectangle_rot_status;


extern float camera_rotation_angle;
extern float rectangle_rotation;
//extern float rectangle_translation;
extern vector<float> rectangle_translation_y;
extern vector<float> rectangle_translation_x;
extern vector<float> block_color;

VAO *bucket[2];
float red_bucket_translation_y = -3.5f;
float red_bucket_translation_x = -2.5f;
float green_bucket_translation_x = 2.5f;
float green_bucket_translation_y = -3.5f;
float red_bucket_translation_incr = 0;
float green_bucket_translation_incr = 0;
float rectangle_translation_incr = 0.01;
int RED_STATUS = 0;
int GREEN_STATUS = 0;

VAO *bucket_line;
vector<VAO *> CANNON;
float CANNON_RADIUS = 0.50f;
float CANNON_CORD_X = -4.05f;
float CANNON_CORD_Y = 0.0f;
VAO *CANNON_GUN;
int CANNON_STATUS = 0;

float CANNON_CORD_SPEED = 0.0f;
float cannon_rotation = 0.0f;
float cannon_rotation_increment = 0;
float cannon_rotation_dir = 1;

vector<VAO *> BULLET;
vector<VAO *> BULLET_REVERSE;
vector<float> BULLET_CORD_X;
vector<float> BULLET_CORD_Y;
float BULLET_RADIUS = 0.075f;
float bullet_rotation = 0.0f;
float bullet_rotation_increment = 20.0f;
float bullet_rotation_dir = 1;
vector<float> BULLET_XCORD_SPEED;
vector<float> BULLET_YCORD_SPEED;
float BULLET_SPEED = 0.1f;
vector<int> BULLET_FLAG_1;
vector<int> BULLET_FLAG_2;


float LOWER_LIMIT = -4.0f;
float UPPER_LIMIT = 4.0f;
float RIGHT_LIMIT = 4.0f;
float LEFT_LIMIT = -4.0f;

long long GAME_SCORE = 0;
int GAME_FLAG = 0;
long long MISS = 0;
long long MAX_MISS = 200;

GLfloat zoom = 1.0f;

VAO *MIRROR_1;
VAO *MIRROR_BACK_1;
float MIRROR_LENGTH = 0.6f;
float MIRROR_ANGLE_1 = 20;

VAO *MIRROR_2;
VAO *MIRROR_BACK_2;
float MIRROR_ANGLE_2 = 90;

int width = 800;
int height = 600;
float pan_x = 0.0f;
float pan_y = 0.0f;

double posx = 0.0f;
double posy = 0.0f;

int PAN_STATUS = 0;

VAO *STAR1;
VAO *STAR1_REVERSE;