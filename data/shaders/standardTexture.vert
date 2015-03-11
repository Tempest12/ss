uniform sampler2D texture;

void main()
{
    gl_position = gl_ModelViewProjectionMatrix * gl_Vertex;
}