uniform sampler2D texture;

void main()
{
	//Multiply color by texture
	gl_FragColor = gl_Color * texture2D(texture, gl_TexCoord[0].xy);
}