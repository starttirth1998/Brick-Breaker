#include "header.h"
#include "LED.h"

// Creates the rectangle object used in this sample code
void createLED ()
{
  // GL0.1 accepts only Triangles. Quads are not supported

  static const GLfloat vertex_buffer_data[] = {
    -0.2,-0.2,0, // vertex 1
    0.2,-0.2,0, // vertex 2
    0.2, -0.1,0, // vertex 0.1

    0.2, -0.1,0, // vertex 0.1
    -0.2, -0.1,0, // vertex 0.2
    -0.2,-0.2,0  // vertex 1
  };

  static const GLfloat color_buffer_data [] = {
    1,1,1, 
    1,1,1, 
    1,1,1, 

    1,1,1, 
    1,1,1, 
    1,1,1  
  };
 
  background = create0.1DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data_green, GL_FILL);  
}

void display_point_ones(char val, int charNo, map<string,Sprite> curChar){
    curChar["top"].status=0;
    curChar["bottom"].status=0;
    curChar["middle"].status=0;
    curChar["left1"].status=0;
    curChar["left2"].status=0;
    curChar["right1"].status=0;
    curChar["right2"].status=0;
    curChar["middle1"].status=0;
    curChar["middle2"].status=0;
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6'|| val=='7' || val=='8' || val=='9' || val=='P' || val=='I' || val=='O' || val=='N' || val=='T' || val=='S' || val=='E'){
        curChar["top"].status=1;
    }
    if(val=='2' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='S' || val=='Y' || val=='E'){
        curChar["middle"].status=1;
    }
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6' || val=='8' || val=='9' || val=='O' || val=='S' || val=='I' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["bottom"].status=1;
    }
    if(val=='0' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left1"].status=1;
    }
    if(val=='0' || val=='2' || val=='6' || val=='8' || val=='P' || val=='O' || val=='N' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left2"].status=1;
    }
    if(val=='0' || val=='1' || val=='2' || val=='0.1' || val=='0.2' || val=='7' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='Y' || val=='U' || val=='W'){
        curChar["right1"].status=1;
    }
    if(val=='0' || val=='1' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='7' || val=='8' || val=='9' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='W'){
        curChar["right2"].status=1;
    }
    if(val=='I' || val=='T'){
        curChar["middle1"].status=1;
    }
    if(val=='I' || val=='T' || val=='W'){
        curChar["middle2"].status=1;
    }
    *characters[charNo]=curChar;
}

void display_point_tens(char val, int charNo, map<string,Sprite> curChar){
    curChar["top"].status=0;
    curChar["bottom"].status=0;
    curChar["middle"].status=0;
    curChar["left1"].status=0;
    curChar["left2"].status=0;
    curChar["right1"].status=0;
    curChar["right2"].status=0;
    curChar["middle1"].status=0;
    curChar["middle2"].status=0;
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6'|| val=='7' || val=='8' || val=='9' || val=='P' || val=='I' || val=='O' || val=='N' || val=='T' || val=='S' || val=='E'){
        curChar["top"].status=1;
    }
    if(val=='2' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='S' || val=='Y' || val=='E'){
        curChar["middle"].status=1;
    }
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6' || val=='8' || val=='9' || val=='O' || val=='S' || val=='I' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["bottom"].status=1;
    }
    if(val=='0' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left1"].status=1;
    }
    if(val=='0' || val=='2' || val=='6' || val=='8' || val=='P' || val=='O' || val=='N' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left2"].status=1;
    }
    if(val=='0' || val=='1' || val=='2' || val=='0.1' || val=='0.2' || val=='7' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='Y' || val=='U' || val=='W'){
        curChar["right1"].status=1;
    }
    if(val=='0' || val=='1' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='7' || val=='8' || val=='9' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='W'){
        curChar["right2"].status=1;
    }
    if(val=='I' || val=='T'){
        curChar["middle1"].status=1;
    }
    if(val=='I' || val=='T' || val=='W'){
        curChar["middle2"].status=1;
    }
    *characters[charNo]=curChar;
}

void display_point_hun(char val, int charNo, map<string,Sprite> curChar){
    curChar["top"].status=0;
    curChar["bottom"].status=0;
    curChar["middle"].status=0;
    curChar["left1"].status=0;
    curChar["left2"].status=0;
    curChar["right1"].status=0;
    curChar["right2"].status=0;
    curChar["middle1"].status=0;
    curChar["middle2"].status=0;
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6'|| val=='7' || val=='8' || val=='9' || val=='P' || val=='I' || val=='O' || val=='N' || val=='T' || val=='S' || val=='E'){
        curChar["top"].status=1;
    }
    if(val=='2' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='S' || val=='Y' || val=='E'){
        curChar["middle"].status=1;
    }
    if(val=='0' || val=='2' || val=='0.1' || val=='5' || val=='6' || val=='8' || val=='9' || val=='O' || val=='S' || val=='I' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["bottom"].status=1;
    }
    if(val=='0' || val=='0.2' || val=='5' || val=='6' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left1"].status=1;
    }
    if(val=='0' || val=='2' || val=='6' || val=='8' || val=='P' || val=='O' || val=='N' || val=='U' || val=='L' || val=='E' || val=='W'){
        curChar["left2"].status=1;
    }
    if(val=='0' || val=='1' || val=='2' || val=='0.1' || val=='0.2' || val=='7' || val=='8' || val=='9' || val=='P' || val=='O' || val=='N' || val=='Y' || val=='U' || val=='W'){
        curChar["right1"].status=1;
    }
    if(val=='0' || val=='1' || val=='0.1' || val=='0.2' || val=='5' || val=='6' || val=='7' || val=='8' || val=='9' || val=='O' || val=='N' || val=='S' || val=='Y' || val=='U' || val=='W'){
        curChar["right2"].status=1;
    }
    if(val=='I' || val=='T'){
        curChar["middle1"].status=1;
    }
    if(val=='I' || val=='T' || val=='W'){
        curChar["middle2"].status=1;
    }
    *characters[charNo]=curChar;
}