/*
 * LICENSE ???
 */
const char* ccLabelOutline_frag = STRINGIFY(
\n#ifdef GL_ES\n
precision lowp float; 
\n#endif\n

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec4 u_effectColor;
uniform vec4 u_textColor;

\n#ifdef GL_ES\n
uniform lowp int u_effectType; // 0: None (Draw text), 1: Outline, 2: Shadow \n
\n#else\n
uniform int u_effectType;
\n#endif\n

void main()
{
    vec4 sample = texture2D(CC_Texture0, v_texCoord);
    // fontAlpha == 1 means the area of solid text (without edge) \n
    // fontAlpha == 0 means the area outside text, including outline area \n
    // fontAlpha == (0, 1) means the edge of text \n
    float fontAlpha = sample.a;

    // outlineAlpha == 1 means the area of 'solid text' and 'solid outline' \n
    // outlineAlpha == 0 means the transparent area outside text and outline \n
    // outlineAlpha == (0, 1) means the edge of outline \n
    float outlineAlpha = sample.r;

    if (u_effectType == 0) // draw text \n
    {
        gl_FragColor = v_fragmentColor * vec4(u_textColor.rgb, u_textColor.a * fontAlpha);
    }
    else if (u_effectType == 1) // draw outline \n
    {
        // multipy (1.0 - fontAlpha) to make the inner edge of outline smoother and make the text itself transparent. \n
        gl_FragColor = v_fragmentColor * vec4(u_effectColor.rgb, u_effectColor.a * outlineAlpha * (1.0 - fontAlpha));
    }
    else // draw shadow \n
    {
        gl_FragColor = v_fragmentColor * vec4(u_effectColor.rgb, u_effectColor.a * outlineAlpha);
    }
}
);
