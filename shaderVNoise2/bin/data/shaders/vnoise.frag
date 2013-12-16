varying vec4 Color;
//uniform sampler2D Texture; // (Unused)
uniform float Freq, Width, StripeShift;

void main (void)
{
    // Fragment coords
    vec2 xy = gl_TexCoord[0].xy;
    
    // Waveform phase
    float phase = fract((xy.y + StripeShift) / Freq);
    
    // Discard fragments
    if (phase > Width)
        discard;
    
    // Output
    gl_FragColor = Color;  
}