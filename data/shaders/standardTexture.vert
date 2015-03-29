uniform sampler2D texture;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}