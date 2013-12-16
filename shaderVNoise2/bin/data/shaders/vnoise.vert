uniform vec3 LightPosition;
uniform vec4 surfaceColor;
uniform vec3 offset;
uniform float scaleIn;
uniform float scaleOut;
varying vec4 Color;

void main(void)
{
    vec3 normal = gl_Normal;
    vec3 vertex = gl_Vertex.xyz + noise3(offset + gl_Vertex.xyz * scaleIn) * scaleOut;
    
    normal = normalize(gl_NormalMatrix * normal);
    vec3 position = vec3(gl_ModelViewMatrix * vec4(vertex,1.0));
    vec3 lightVec   = normalize(LightPosition - position);
    float diffuse   = max(dot(lightVec, normal), 0.0);
    if (diffuse < 0.125)
        diffuse = 0.125;
    Color = vec4(surfaceColor.rgb * diffuse, 1.0);
    gl_Position = gl_ModelViewProjectionMatrix * vec4(vertex,1.0);
    gl_FrontColor = gl_Color;
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
}