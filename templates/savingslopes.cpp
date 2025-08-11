// 1-> make for vertical and horizontal 
// 2-> now save reduced form of dy/dx
// 3-> always use llabs and (int)
// 4-> don;t use abs that will give TLE 

for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        int dy = vpp[i].second - vpp[j].second;
        int dx = vpp[i].first - vpp[j].first;
        if (dx == 0)
        {
            mpl[{1, 0}]++;
        }
        else if (dy == 0)
        {
            mpl[{0, 1}]++;
        }
        else
        {
            int g = __gcd((int)llabs(dy), (int)llabs(dx));
            dy /= g;
            dx /= g;
            if (dx < 0)
            {
                dx = -dx;
                dy = -dy;
            }
            mpl[{dy, dx}]++;
        }
    }
}