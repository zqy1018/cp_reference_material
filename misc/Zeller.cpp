int weekd(int y, int m, int d){
  int yc = y / 100, yy = y % 100;
  if (m <= 2) m += 12;
  int t = 7 + (yy + (yy >> 2) + (yc >> 2) - (yc << 1) + (26 * (m + 1) / 10) + d - 1) % 7;
  return (t > 7 ? t - 7: t);
}