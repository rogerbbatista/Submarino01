#ifndef LIGHT_H
#define LIGHT_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

#define GL_LIGHT(i) (GL_LIGHT0 + i)

class Light
{
protected:
    int glLight;
    std::vector<float> position;
    std::vector<float> color;
    bool enable;

public:
    Light(int i);
    void setPosition(const std::vector<float> &position);
    void setColor(const std::vector<float> &color);
    virtual void create();
};

class SpotLight : public Light
{
private:
    std::vector<float> direction;
    float exponent;
    float angle;

public:
    SpotLight(int i);
    void setDirection(const std::vector<float> &direction);
    void setExponent(float exponent);
    void setAngle(float angleDegree);
    void create();
};

#endif // LIGHT_H