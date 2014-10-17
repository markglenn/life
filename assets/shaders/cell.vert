#version 330

//layout (location = 0) in vec2 Position;
//layout (location = 1) in mat4 WVP;

void main( )
{
    gl_Position = /*WVP * */ vec4(0.0, 0.0, 0.0, 1.0);
}
