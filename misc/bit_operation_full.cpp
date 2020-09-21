// 枚举 S 的子集
for (int T = S; T > 0; T = (T - 1) & S) ;
// 格雷码：i ^ (i >> 1)
__builtin_popcount(unsigned int x) // x 中 1 的个数
__builtin_ctz(unsigned int x) // x 末尾 0 的个数
__builtin_clz(unsigned int x) // x 前导 0 的个数
__builtin_ffs(unsigned int x) // log2(lowbit(x)) + 1
// 三进制向量运算，x0 记录 x 为 1 的位，x1 记录 x 为 2 的位
res_0 = (x1 & y1) | (~(x1 | y1) & (x0 ^ y0)); 
res_1 = (x0 & y0) | (~(x0 | y0) & (x1 ^ y1)); // 不进位加
dot(x, y) = (2 * __builtin_popcount((x0 & y1) | (x1 & y0)) + __builtin_popcount((x0 & y0) | (x1 & y1))) % 3  // 内积