#include "Functions.h"

void init(void)
{
    const double pi = GConf::pi;
    
    glClearColor(1.0, 1.0, 1.0, 1.0); //cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 400.0);

    sub.charge("submarine");
    sub.setColor(0, 1, 0);
    sub.setStructure(5, 5, 8);
    sub.setLimits(-150, 150, -200, 2, -150, 150);
    sub.setAngleLimits(-pi / 6, pi / 6, -pi, pi, -pi / 6, pi / 6);

    for (auto &a : astronaut)
    {
        a.charge("astronauta");
        a.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    astronaut[0].setPosition(0, -35, -85);
    astronaut[1].setPosition(-55, -25, -55);
    astronaut[2].setPosition(0, -15, 5);
    astronaut[3].setPosition(55, -20, 85);
    astronaut[4].setPosition(75, -30, 85);

    for (auto &c : coral)
    {
        c.charge("coral");
        c.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    coral[0].setPosition(-85, -20, -85);
    coral[1].setPosition(85, -20, -25);
    coral[2].setPosition(25, -20, 55);
    coral[3].setPosition(-25, -20, 55);
    coral[4].setPosition(-45, -20, 85);

    for (auto &h : horse)
    {
        h.charge("horse");
        h.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    horse[0].setPosition(-5, -20, -25);
    horse[1].setPosition(-45, -15, 35);
    horse[2].setPosition(85, -30, -75);

    for (auto &o : old_ship)
    {
        o.charge("old_ship");
        o.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    old_ship[0].setPosition(10, 0, -10);
    old_ship[1].setPosition(0, 0, 90);

    for (auto &r : rocks)
    {
        r.charge("rocks");
        r.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    rocks[0].setPosition(-45, -20, -85);
    rocks[1].setPosition(85, -20, 55);

    for (auto &s : shark)
    {
        s.charge("shark");
        s.setColor(GConf::getRandom(), GConf::getRandom(), GConf::getRandom());
    }
    shark[0].setPosition(-90, -50, 85);
    shark[1].setPosition(35, -70, -65);
    shark[2].setPosition(25, -30, 25);

    ocean.create(200);
    cam.create();
    // lights.create();

    glEnable(GL_LIGHTING);
    submarine_beacon.setPosition({0, 250, 0, 1});
    submarine_beacon.setDirection({0, -1, 0, 1});
    submarine_beacon.setType(GL_SPECULAR);
    submarine_beacon.setColor({1, 1, 0, 1});
    submarine_beacon.setAngle(15);
    submarine_beacon.setExponent(64);
    submarine_beacon.create();

    help.create();

    glMatrixMode(GL_MODELVIEW);
}