#version 330 core
    uniform vec4 colorUniform;
    out vec4 fragColor;

    in vec3 color;
    in vec2 TexCoord;

    uniform sampler2D myTexture;

    void main()
    {
        fragColor = texture(myTexture,TexCoord)*vec4(color.x,colorUniform.y,color.z, 0.5);
        // fragColor = mix(texColor, texColor * vec4(color, 1.0), colorUniform.r);
    }
