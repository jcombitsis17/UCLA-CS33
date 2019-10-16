static float u2f(unsigned u)
{
  union
  {
    unsigned my_u;
    float my_f;
  } temp;
  temp.my_u = u;
  return temp.my_f;
}

float fpwr4(int x)
{
  unsigned exp, frac;
  unsigned u;
  if (x < -74)
  {
    /* Too small. Return 0.0 */
    exp = 0;
    frac = 0;
  } else if (x < -63)
  {
    /* Denormalized result. */
    exp = 0;
    frac = 1 << (2*x + 149);
  } else if (x < 64)
  {
    /* Normalized result. */
    exp = 2*x + 127;
    frac = 0;
  } else
  {
    /* Too big. Return +inf */
    exp = 255;
    frac = 0;
  }

  u = exp << 23 | frac;
  return u2f(u);
}
