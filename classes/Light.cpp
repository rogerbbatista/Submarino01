#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "Light.h"

Light::Light(int i)
{
    this->glLight = GL_LIGHT(i);

    if (i > GL_MAX_LIGHTS)
    {
        std::cerr << "Número de luzes excedido" << std::endl;
    }

    position = {0., 0., 0., 1.};
    color = {1., 1., 1., 1.,};
    type = GL_AMBIENT;
    enable = true;
}

void Light::setPosition(const std::vector<float> &position)
{
    this->position = position;
}

void Light::setColor(const std::vector<float> &color)
{
    this->color = color;
}

void Light::setType(int type)
{
    this->type = type;
}

void Light::create()
{
    glLightfv(glLight, GL_POSITION, position.data());
    glLightfv(glLight, type, color.data());
    glEnable(glLight);
}

SpotLight::SpotLight(int i) : Light(i)
{
    direction = {0., 0., -1., 1.};
    exponent = 0;
    angle = 180;
}

void SpotLight::create()
{
    glLightfv(glLight, GL_POSITION, position.data());
    glLightfv(glLight, GL_SPOT_DIRECTION, direction.data());
    glLightfv(glLight, GL_SPOT_EXPONENT, &exponent);
    glLightfv(glLight, GL_SPOT_CUTOFF, &angle);
    glLightfv(glLight, type, color.data());
    glEnable(glLight);
}

void SpotLight::setDirection(const std::vector<float> &direction)
{
    this->direction = direction;
}

void SpotLight::setExponent(float exponent)
{
    this->exponent = exponent;
}

void SpotLight::setAngle(float angleDegree)
{
    this->angle = angleDegree;
}


#endif // LIGHT_CPP