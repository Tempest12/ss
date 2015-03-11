varying vec4 color;

void main()
{
    gl_position = gl_ModelViewProjectionMatrix * gl_Vertex;
}