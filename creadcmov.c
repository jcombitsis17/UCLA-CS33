long creadcmov(long *xp) {
  long* res = (long*) -1;
  if (xp)
    res = &xp[-1];
  return *res;
}
