int evaporator(double content, double evap_per_day, double threshold)
{
    double percent = 1.f;
    int days = 0;

    evap_per_day /= 100.f;
    threshold /= 100.f;

    while (percent > threshold)
    {
        percent = percent - (percent * evap_per_day);
        days++;
    }

    return days;
}

void DoEvaporator()
{
    int i = evaporator(10, 10, 10);
    i = evaporator(10, 10, 5);
}