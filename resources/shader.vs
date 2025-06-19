#version 330

// Input vertex attributes
in vec3 vertexPosition; // vertex position relative to origin
in vec2 vertexTexCoord; // texture coord of vertex
in mat4 instanceTransform; // model transformation matrix

uniform mat4 mvp; 
uniform float time;

out vec2 fragTexCoord;

void main()
{
    fragTexCoord = vertexTexCoord;

    mat4 mvpi = mvp*instanceTransform;

    vec3 modifiedPosition = vertexPosition;
    modifiedPosition.y += vertexPosition.y * sin(time)/cos(time);

    gl_Position = mvpi*vec4(modifiedPosition, 1.0);
}