varying vec4 color;

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}