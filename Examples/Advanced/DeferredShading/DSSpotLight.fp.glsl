#version 120

#extension GL_ARB_texture_rectangle : require
#extension GL_ARB_texture_rectangle : enable

// compute spot light INDEX for fragment at POS with normal NORM
// and diffuse material color MDIFF
vec4 computeSpotLight(int index, vec3 pos, vec3 norm, vec4 mDiff)
{
    vec4  color      = vec4(0., 0., 0., 0.);

    vec3  lightDirUN = gl_LightSource[index].position.xyz - pos;
    vec3  lightDir   = normalize(lightDirUN);
    float spotEffect = dot(-lightDir, gl_LightSource[index].spotDirection);

    if(spotEffect > gl_LightSource[index].spotCosCutoff)
    {
        float NdotL = max(dot(lightDir, norm), 0.);
        
        if(NdotL > 0.)
        {
            float lightDist = length(lightDirUN);
            float att       = dot(vec3(gl_LightSource[index].constantAttenuation,
                                       gl_LightSource[index].linearAttenuation,
                                       gl_LightSource[index].quadraticAttenuation),
                                  vec3(1., lightDist, lightDist * lightDist)       );
            spotEffect = pow(spotEffect, gl_LightSource[index].spotExponent);
            att        = spotEffect / att;

            color = att * NdotL * mDiff * gl_LightSource[index].diffuse;
        }
    }
    
    return color;
}

// DS input buffers
uniform sampler2DRect     texBufPos;
uniform sampler2DRect     texBufNorm;
uniform sampler2DRect     texBufDiff;

// DS pass
void main(void)
{
    vec3  norm  = texture2DRect(texBufNorm, gl_FragCoord.xy).xyz;

    if(dot(norm, norm) < 0.95)
    {
        discard;
    }
    else
    {
        vec4  posAmb = texture2DRect(texBufPos,  gl_FragCoord.xy);
        vec3  pos    = posAmb.xyz;
        float amb    = posAmb.w;
        vec4  mDiff  = texture2DRect(texBufDiff, gl_FragCoord.xy);

        gl_FragColor = computeSpotLight(0, pos, norm, mDiff);
    }
}
