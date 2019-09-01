/*
    You throw a ball vertically upwards with an initial speed v (in km per hour). The height h of the ball at each time t is given by h = v*t - 0.5*g*t*t where g is Earth's gravity (g ~ 9.81 m/s**2). A device is recording at every tenth of second the height of the ball. For example with v = 15 km/h the device gets something of the following form: (0, 0.0), (1, 0.367...), (2, 0.637...), (3, 0.808...), (4, 0.881..) ... where the first number is the time in tenth of second and the second number the height in meter.

    Task
    Write a function max_ball with parameter v (in km per hour) that returns the time in tenth of second of the maximum height recorded by the device.

    Examples:
    max_ball(15) should return 4

    max_ball(25) should return 7

    Notes
    Remember to convert the velocity from km/h to m/s or from m/s in km/h when necessary.
    The maximum height recorded by the device is not necessarily the maximum height reached by the ball.
*/

/*
- ball has v and h
- every 1/10 sec, recalc h
*/

#include <cmath>

const double g = 9.81;

unsigned int max_ball(int v0)
{
    unsigned int t = 0;
    double now = 0, h = 0, max = 0;
    double v = v0 * 1000.f / 3600.f;

    for(;;)
    {
        now = (double) t / 10.f;
        h = (v*now) - (0.5 * g * now * now);

        if (h > max) max = h;

        if(h < max) break;

        t++;
    }

    return t-1;
}

void DoBallUpwards()
{
    double t = std::round((15.f / 3.6f) / .981f);
    t = std::round((25.f / 3.6f) / .981f);
    t = std::round((37.f / 3.6f) / .981f);
    unsigned int m = max_ball(15.f);
    m = max_ball(25.f);
    m = max_ball(37.f);
    m = max_ball(45.f);
}