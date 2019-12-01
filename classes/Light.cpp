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

    position = {0, 0, 0, 1};
    color = {1, 1, 1, 1};
    on = true;
    last = false;
}

void Light::enable(bool on)
{
    if (last != on)
    {
        this->on = !(this->on ^ on);
    }
    last = on;

    if (this->on)
    {
        glEnable(glLight);
    }
    else
    {
        glDisable(glLight);
    }
}

void Light::setPosition(const std::vector<float> &position)
{
    this->position = position;
}

void Light::setColor(const std::vector<float> &color)
{
    this->color = color;
}

void Light::update()
{
    glLightfv(glLight, GL_POSITION, position.data());
    glLightfv(glLight, GL_AMBIENT, color.data());
    glLightfv(glLight, GL_DIFFUSE, color.data());
    glLightfv(glLight, GL_SPECULAR, color.data());
}

void Light::create()
{
    update();

    glEnable(glLight);
}

int Light::getLightId()
{
    return glLight;
}

SpotLight::SpotLight(int i) : Light(i)
{
    direction = {0., 0., -1., 1.};
    exponent = 0;
    angle = 180;
}

void SpotLight::update()
{
    glLightfv(glLight, GL_POSITION, position.data());
    glLightfv(glLight, GL_SPOT_DIRECTION, direction.data());
    glLightfv(glLight, GL_SPOT_EXPONENT, &exponent);
    glLightfv(glLight, GL_SPOT_CUTOFF, &angle);
    glLightfv(glLight, GL_AMBIENT, color.data());
    glLightfv(glLight, GL_DIFFUSE, color.data());
    glLightfv(glLight, GL_SPECULAR, color.data());
}

void SpotLight::create()
{
    update();

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