# Zlin的板子大全



## 数据结构

### 基础

#### 优先队列

不标注默认大根堆，pair内容先比较第一个元素，然后比较第二个元素

```c++
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;
```

#### set

Set 自动排序，去重
multiset 自动排序，不去重

代码	含义
s.begin()	返回set容器的第一个元素的地址（迭代器）
s.end()	返回set容器的最后一个元素的地址（迭代器）
s.rbegin()	返回逆序迭代器，指向容器元素最后一个位置
s.rend()	返回逆序迭代器，指向容器第一个元素前面的位置
s.clear()	删除set容器中的所有的元素,返回unsigned int类型O ( N ) O(N)O(N)
s.empty()	判断set容器是否为空
s.insert()	插入一个元素 O ( N l o g N ) O(NlogN)O(NlogN)
s.size()	返回当前set容器中的元素个数O ( 1 ) O(1)O(1)
erase(iterator)	删除定位器iterator指向的值
erase(first,second）	删除定位器first和second之间的值
erase(key_value)	删除键值key_value的值O ( N l o g N ) O(NlogN)O(NlogN)	
s.find(元素)	查找set中的某一元素，有则返回该元素对应的迭代器，无则返回结束迭代器
s.lower_bound(k)	返回大于等于k的第一个元素的迭代器
s.upper_bound(k)	返回大于k的第一个元素的迭代器

### 并查集(DSU)

##### 普通并查集

>路径压缩
>
>```c++
>inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
>```
>
>无路径压缩
>
>```c++
>inline int find(int x)
>{
>    if (f[x] == x)
>           return x;
>    find(f[x]);
>}
>```

##### 种类并查集

>根据不同种类开n倍的空间，每个空间存一种关系
>每个不同的空间表示一种对立关系

### ST表

> 常用来处理RMQ问题
>
> 预处理
> 时间复杂度:nlog^n^

> ```c++
> inline void ST_prework()
>{
>   for (int i = 1; i <= n; i++)
>         f[i][0] = a[i];
>   int t = log(n) / log(2) + 1;
>      for (int j = 1; j < t; j++)
>            for (int i = 1; i <= n - (1 << j) + 1; i++)
>                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
>    }
>    ```
>    
> 查询
> 时间复杂度:O(1)
>
> ```c++
> inline int ST_query(int l, int r)
>{
>   int k = log(r - l + 1) / log(2);
>   return max(f[l][k], f[r - (1 << k) + 1][k]);
> }
>    ```

### 树状数组

>宏定义
>
>```c++
>#define lowbit(x) (x & (-x))
>```
>
>修改操作
>
>```c++
>inline void add(int i, int k)
>{
>        for (; i <= n; i += lowbit(i))
>             t[i] += k;
>        return;
>}
>```
>
>查询操作
>
>```c++
>inline int ask(int l, int r)
>{
>        int sum = 0;
>        for (; r; r -= lowbit(r))
>             sum += t[r];
>        --l;
>        for (; l; l -= lowbit(l))
>             sum -= t[l];
>        return sum;
>}
>```

### 线段树

#### 普通线段树

>build操作
>
>```c++
>inline void build(int l, int r, int u)
>{
>        T[u].l = l, T[u].r = r;
>        if (l == r)
>             return;
>        int mid = l + r >> 1;
>        build(l, mid, u << 1);
>        build(mid + 1, r, u << 1 | 1);
>}
>```
>

#### 扫描线

>扫描线记得开八倍空间
>
>pushup回传标记
>
>```c++
>inline void pushup(int u)
>{
>        int l = T[u].l, r = T[u].r;
>        if (T[u].cnt)
>             T[u].len = X[r + 1] - X[l];
>        else
>             T[u].len = T[u << 1].len + T[u << 1 | 1].len;
>}
>```
>
>修改操作
>
>```c++
>inline void add(int l, int r, int u, int tag)
>{
>        if (T[u].l > r || T[u].r < l)
>             return;
>        if (T[u].l >= l && T[u].r <= r)
>        {
>             T[u].cnt += tag;
>             pushup(u);
>             return;
>        }
>        add(l, r, u << 1, tag);
>        add(l, r, u << 1 | 1, tag);
>        pushup(u);
>}
>```

### 左偏树/可并堆

更适合处理合并工作，合并最坏复杂度 logn



### 平衡树(Splay)

适合用来维护有序队列

>准备工作
>
>```c++
>struct Node
>{
>        int s[2]; // 左右儿子
>        int p;    // 父节点
>        int val;
>        int cnt;
>        int size;
>        void init(int p1, int val1)
>        {
>             p = p1, val = val1;
>             cnt = size = 1;
>        }
>} tr[N];
>int root = 0, tot = 0;
>```
>
>更新节点大小
>
>```c++
>inline void pushup(int x) // 更新点x的大小
>{
>        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + tr[x].cnt;
>}
>```
>
>旋转操作
>
>```c++
>inline void rotate(int x) // 旋转x
>{
>        int y = tr[x].p, z = tr[y].p;
>        int k = tr[y].s[1] == x;
>        tr[z].s[tr[z].s[1] == y] = x;
>        tr[x].p = z;
>        tr[y].s[k] = tr[x].s[k ^ 1];
>        tr[tr[x].s[k ^ 1]].p = y;
>        tr[x].s[k ^ 1] = y;
>        tr[y].p = x;
>        pushup(x), pushup(y);
>}
>```
>
>旋转节点x到它的父节点为k，如果父节点为0，说明是根节点
>
>```c++
>inline void splay(int x, int k)
>{
>        while (tr[x].p != k)
>        {
>             int y = tr[x].p, z = tr[y].p;
>             if (z != k)
>                 (tr[y].s[0] == x) ^ (tr[z].s[0] == y) ? rotate(x) : rotate(y);
>             rotate(x);
>        }
>        if (k == 0)
>             root = x;
>}
>```
>
>查找操作，把查找的点转换为根
>
>```c++
>inline void find(int val) // 找到权值等于val的点并把它转为根
>{
>        int x = root;
>        while (tr[x].s[val > tr[x].val] && tr[x].val != val)
>             x = tr[x].s[val > tr[x].val];
>        splay(x, 0);
>}
>```
>
>查找前驱和后继
>
>```c++
>inline int get_pre(int val) // 求前驱
>{
>        find(val);
>        int x = root;
>        if (tr[x].val < val)
>             return x;
>        x = tr[x].s[0];
>        while (tr[x].s[1])
>             x = tr[x].s[1];
>        return x;
>}
>
>inline int get_suc(int val) // 求后继
>{
>        find(val);
>        int x = root;
>        if (tr[x].val > val)
>             return x;
>        x = tr[x].s[1];
>        while (tr[x].s[0])
>             x = tr[x].s[0];
>        return x;
>}
>```
>
>删除操作
>先把前驱转为根，后继转为前驱的儿子，这样val节点只有它自身，没有儿子节点，可以直接删除
>
>```c++
>inline void del(int val)
>{
>        int pre = get_pre(val);
>        int suc = get_suc(val);
>        splay(pre, 0);
>        splay(suc, pre);
>        int del = tr[suc].s[0];
>        if (tr[del].cnt > 1)
>             --tr[del].cnt, splay(del, 0);
>        else
>             tr[suc].s[0] = 0, splay(suc, 0);
>}
>```
>
>查询排名
>
>```c++
>// 因为预处理插入了两个无穷大和无穷小的数，所以排名不需要+1
>inline int get_rank(int val) // 查询val的排名
>{
>        find(val);
>        if (tr[root].val < val) // 如果val没有出现过，要判断根节点和val的大小关系
>             return tr[tr[root].s[0]].size + tr[root].cnt;
>        return tr[tr[root].s[0]].size;
>}
>```
>
>查询排名为k的val
>
>```c++
>// 因为插入了无穷大和无穷小，所以传入k时要+1,k为实际情况的k+1
>inline int get_val(int k) // 查询排名为k的val
>{
>        int x = root;
>        while (1)
>        {
>             int y = tr[x].s[0];
>             if (tr[x].cnt + tr[y].size < k)
>             {
>                 k -= tr[x].cnt + tr[y].size;
>                 x = tr[x].s[1];
>             }
>             else
>             {
>                 if (tr[y].size >= k)
>                     x = tr[x].s[0];
>                 else
>                     break;
>             }
>        }
>        splay(x, 0);
>        return tr[x].val;
>}
>```
>
>插入操作
>
>```c++
>inline void insert(int val)
>{
>        int x = root, p = 0;
>        while (x && tr[x].val != val)
>             p = x, x = tr[x].s[val > tr[x].val];
>        if (x)
>             ++tr[x].cnt;
>        else
>        {
>             x = ++tot;
>             tr[p].s[val > tr[p].val] = x;
>             tr[x].init(p, val);
>        }
>        splay(x, 0);
>}
>```

### 字典树

```
void insert(string s)//建立字典树
{
    int p = 0;//根结点是0
    for(auto it : s)
    {
        ll j;
        if(it >= '0' && it <= '9') j = it - '0';
        else if(it < 'a') j = it - 'A' + 10;
        else j = it - 'a' + 26 + 10;//A从26开始
        // 上面三行是映射字符，将字符变为数字好处理
        if(!ch[p][j]) ch[p][j] = ++ idx;//没有找到
        p = ch[p][j];
        cnt[p] ++;
    }
 
}
 
ll query(string s)//查询函数
{
    int p = 0;
    for(auto it : s)
    {
        ll j;
        if(it >= '0' && it <= '9') j = it - '0';//数字
        else if(it < 'a') j = it - 'A' + 10;//A从10开始
        else j = it - 'a' + 26 + 10;//小写字母
        if(!ch[p][j]) return 0;//字节点的编号不是0，如果是0则没有这条边
        p = ch[p][j];
    }
    return cnt[p];
}
```



### 分块

>初始化操作，做好分块的左边界和右边界，大小一般为sqrt(n)
>
>```c++
>inline void init()
>{
>        int len = sqrt(n), tot = (n - 1) / len + 1;
>        for (int i = 1; i <= tot; i++)
>             l[i] = r[i - 1] + 1, r[i] = i * len;
>        r[tot] = n;
>        for (int i = 1; i <= tot; i++)
>             for (int j = l[i]; j <= r[i]; j++)
>                 belong[j] = i;
>}
>```
>
>单点修改
>
>区间修改
>利用tag数组存整个区块的修改情况

#### 时间分块

>
>
>

## 数学

### 基础

>2ab = (a+b)^2^-a^2^-b^2^ 
>2ab+2ac+2bd = (a+b+c)^2^-a^2^-b^2^-c^2^
>
>多元同理
>
>大数不能直接用sqrt，要自己用二分查找求值

### FFT/NTT

快速计算多项式乘法

```c++
/*
 * 做 FFT
 * len 必须是 2^k 形式
 * on == 1 时是 DFT，on == -1 时是 IDFT
 */
typedef complex<double> Complex;
void fft(Complex y[], int len, int on) {
    // 位逆序置换
    change(y, len);
    // 模拟合并过程，一开始，从长度为一合并到长度为二，一直合并到长度为 len。
    for (int h = 2; h <= len; h <<= 1) {
        // wn：当前单位复根的间隔：w^1_h
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        // 合并，共 len / h 次。
        for (int j = 0; j < len; j += h) {
            // 计算当前单位复根，一开始是 1 = w^0_n，之后是以 wn 为间隔递增： w^1_n
            // ...
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                // 左侧部分和右侧是子问题的解
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                // 这就是把两部分分治的结果加起来
                y[k] = u + t;
                y[k + h / 2] = u - t;
                // 后半个 「step」 中的ω一定和 「前半个」 中的成相反数
                // 「红圈」上的点转一整圈「转回来」，转半圈正好转成相反数
                // 一个数相反数的平方与这个数自身的平方相等
                w = w * wn;
            }
        }
    }
    // 如果是 IDFT，它的逆矩阵的每一个元素不只是原元素取倒数，还要除以长度 len。
    if (on == -1) {
        for (int i = 0; i < len; i++) {
            y[i].x /= len;
        }
    }
}
```

### 几何

#### 旋转卡壳

旋转卡壳，求凸包的直径，可以处理三点共线

```c++
struct Point
{
    double x, y;
};
// 计算两点之间的欧几里得距离
double distance(const Point &p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// 计算向量叉积
double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// 使用旋转卡壳算法求凸包的直径（最远点对距离）
double rotatingCalipers(const vector<Point> &hull)
{
    int n = hull.size();
    if (n == 1)
        return 0.0;
    if (n == 2)
        return distance(hull[0], hull[1]);
    int k = 1;
    double maxDist = 0.0;
    for (int i = 0; i < n; ++i)
    {
        while (abs(cross(hull[i], hull[(i + 1) % n], hull[(k + 1) % n])) > abs(cross(hull[i], hull[(i + 1) % n], hull[k])))
        {
            k = (k + 1) % n;
        }
        maxDist = max(maxDist, distance(hull[i], hull[k]));
        maxDist = max(maxDist, distance(hull[(i + 1) % n], hull[k]));
    }
    return maxDist;
}
```



### 线性基

可以插入也可以删除

#### 异或线形基

最后求出来k个答案，要注意0的情况，如果k!=n+1说明存在0

##### 贪心算法

```c++

```

##### 高斯消元法

```c++
inline void gauss() {
    for (int i = 63; ~i && k <= n; i--) {
        for (int j = k; j <= n; j++)
            if (a[j] & (1ll << i)) {
                swap(a[j], a[k]);
                break;
            }
        if (!(a[k] & (1ll << i))) continue;
        for (int j = 1; j <= n; j++)
            if (j != k && (a[j] & (1ll << i))) a[j] ^= a[k];
        ++k;
    }
}
```

##### 区间线性基

```c++
inline void insert(int x, int id) {
    int t = id;
    for (int i = 30; ~i; i--) {
        p[id][i] = p[id - 1][i];
        pos[id][i] = pos[id - 1][i];
    }
    for (int i = 30; ~i; i--) {
        if (!(x & (1 << i))) continue;
        if (!p[id][i]) {
            p[id][i] = x;
            pos[id][i] = t;
            return;
        } else if (pos[id][i] < t) {
            swap(p[id][i], x);
            swap(pos[id][i], t);
        }
        x ^= p[id][i];
    }
}
// 最大值高位可能与地位冲突，要比较是否更大
int query_max(int l, int r)
{
    int ans = 0;
    for(int i = 30; ~i; i--)
        if(pos[r][i] >= l && (ans ^ p[r][i]) > ans)
            ans ^= p[r][i];
    return ans;
}

int query_min(int l, int r)
{
    for(int i = 0; i <= 30; i++)
        if(pos[r][i] >= l && p[r][i])
            return p[r][i];
    return 0;
}
```

### 高精度

#### 加法

>存储数据
>lenc = max(lena,lenb)，字符串读取输入，翻转存入数组
>
>```
>int a[N], b[N], c[N];
>int lena, lenb, lenc;
>```
>
>相加操作
>
>```c++
>vector<int> add(vector<int>& A, vector<int>& B)
>{
>	//如果B更大，因为下面代码都是以第一个形参作为for结束条件，所以要让大的是第一个形参
>	if (A.size() < B.size()) return add(B, A);
> 
>	vector<int> C;
>	int t = 0; //用来判断是否进位
>	//注意这里是逆序的数从前往后加的
>	for (int i = 0; i < A.size(); ++i)
>	{//for循环是以大的数来作为循环结束条件的
>		t += A[i];//for循环以A为结束条件，这里不用格外判断
>		if (i < B.size()) t += B[i];//因没以B为结束条件，故这里要格外判断是否可以加
>		C.push_back(t % 10);//加出来的数要的是余数
>		t /= 10; //判断是否有进位
>	}
>	if (t) C.push_back(t);//有可能最后加完还有进位
> 
>	return C;
>}
>```

#### 减法

>a - b
>
>```c++
>
>vector<int> sub(vector<int>& A, vector<int>& B)
>{//利用cmp函数比较，使大的数一定是A，与for循环代码相符
> 
>	vector<int> C;
>	int t = 0;//判断借位
>	for (int i = 0; i < A.size(); ++i)
>	{
>		t = A[i] - t;//每次都会减掉借位
>		if (i < B.size()) t -= B[i];
>		//关于(t+10)%10（t是减出来的数）
>		//t若为正数(但<=9)其=t%10+10%10=t
>		//t若为负数，正好可以借位+10然后取余数即可
>		C.push_back((t + 10) % 10);
>		if (t >= 0) t = 0;
>		else t = 1; //<0肯定有借位了
>	}
>	//因为两个数相减会导致有多余的0出现，故去除前导0
>    //size()>1是因为可能真的相减出现0，这种0不算前导0
>	while (C.size() > 1 && C.back() == 0) C.pop_back();
> 
>	return C;
>}
>```

#### 乘法

>从低位到高位，先累加乘积，然后进位，存余
>
>```c++
>vector<int> mul(vector<int>& A, int b)
>{
>	vector<int> C;
>	for (int i = 0, t = 0; i < A.size() || t; ++i)
>	{
>		if (i < A.size()) t += A[i] * b;//加上t是因为上一次可能有乘出来的进位
>		C.push_back(t % 10);
>		t /= 10;//计算进位
>	}
>	//当b是0时，会出现前导0
>	while (C.size() > 1 && C.back() == 0) C.pop_back();
> 
>	return C;
>}
>```

#### 除法

>***从高位到低位***
>大数a除以小数b，r保存余数
>
>```c++
>vector<int> div(vector<int>& A, int b, int& r)
>{
>	vector<int> C;
>	for (int i = A.size() - 1; i >= 0; --i)
>	{
>		r = r * 10 + A[i];
>		C.push_back(r / b);
>		r %= b; //计算余数
>	}
>	//逆置:因为我们是正常求，但最后是倒着读的，且便于去除前导0
>	reverse(C.begin(), C.end());
>	while (C.size() > 1 && C.back() == 0) C.pop_back();
> 
>	return C;
>}
>```

#### 比较大小

```
//比较哪个数大，注意这里的数是从倒序存的，故后面的才是高位
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; --i)
		if (A[i] != B[i]) 
			return A[i] > B[i];//不等从高位开始比
 
	return true;//相等
}
```



### 快速幂

>快速求a^n^的值
>
>```c++
>inline int quick_pow(int a, int n)
>{
>        int res = 1;
>        while (n)
>        {
>             if (n & 1)
>                 res *= a;
>             a = a * a;
>             n >>= 1;
>        }
>        return res;
>}
>```

### 快速GCD

> 利用更减相损术和builtin内置函数，二进制运算速度更快
>
> ```c++
> int qGCD(int a, int b)
> {
>        int az = __builtin_ctz(a), bz = __builtin_ctz(b); // 如果数据ll，用函数ctzll
>        int z = min(az, bz), dif;
>        b >>= bz;
>        while (a)
>        {
>            a >>= az;
>            dif = abs(b - a);
>            az = __builtin_ctz(dif);
>            if (a < b)
>                b = a;
>            a = dif;
>        }
>        return b << z;
> }
> ```

### 逆元

>*费马定理*
>给定两个数a,p，p为质数，a^p-2^为a模p的乘法逆元
>
>*扩展欧几里得算法*
>ax+by=gcd(a,b)

### 组合数

#### 杨辉三角

> C(n,m)= C(n,n-m)= C(n-1,m-1)+C(n-1,m)
> 适合n<5e3的情况 
>
> ```c++
> // c[n][m]表示从n个元素中取m个的方案数
> inline void prework()
> {
>  for (int i = 0; i <= 5001; i++)
>      for (int j = 0; j <= i; j++)
>          if (!j)
>              c[i][j] = 1;
>          else
>              c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % q;
> }
> ```

#### 预处理法,乘法逆元

**适用范围**：n，m在1e5以内，且取模的数mod为素数时
利用快速幂求逆元

>```c++
>inline void init() // 预处理，fac[]表示阶乘, inf[]表示阶乘的逆元
>{
>fac[0] = inf[0] = 1;
>for (int i = 1; i <= N; i++)
>{
>fac[i] = fac[i - 1] * i % mod;
>inf[i] = inf[i - 1] * quick_pow(i, mod - 2) % mod;
>}
>}
>```

## 图论

### 找环思路

#### 无向图找环

DFS

DSU

#### 判断奇数环和偶数环

##### 二分图染色法

### 最短路算法

#### Dijkstra

>主体，优先队列为小根堆
>时间复杂度:nlog^m^ 
>
>```c++
>inline void dijkstra()
>{
>        dis[s] = 0;
>        q.push({0, s});
>        while (!q.empty())
>        {
>             node u = q.top();
>             q.pop();
>             int x = u.pos;
>             if (vis[x])
>                 continue;
>             vis[x] = 1;
>             for (int i = head[x]; i; i = a[i].next)
>             {
>                 int y = a[i].to;
>                 if (dis[y] > dis[x] + a[i].w)
>                 {
>                     dis[y] = dis[x] + a[i].w;
>                     if (!vis[y])
>                         q.push({dis[y], y});
>                 }
>             }
>        }
>}
>```

#### Bellman-Ford

>堆优化版——SPFA
>时间复杂度:最好O(m)，最坏O(nm)，菊花图的情况
>
>```c++
>inline void spfa()
>{
>   dis[s] = 0;
>   vis[s] = 1;
>   queue<int> q;
>   q.push(s);
>   int x;
>   while (!q.empty())
>   {
>        x = q.front();
>        q.pop();
>        vis[x] = 0;
>        for (int i = head[x]; i; i = e[i].next)
>        {
>            int y = e[i].to, d = e[i].dis;
>            if (dis[y] > dis[x] + d)
>            {
>                dis[y] = dis[x] + d;
>                if (!vis[y])
>                    vis[y] = 1, q.push(y);
>            }
>        }
>   }
>}
>```

#### Johnson

>Johnson优化，能有处理负权值和有负环的情况
>时间复杂度:n^2^log^m^
>
>预处理:先给每条边新添加一条0边
>
>```c++
>for (int i = 1; i <= n; i++)
>        add_edge(0, i, 0);
>```
>
>然后利用SPFA来判断负环，同时创建h数组（等同于势能，处理负权值）
>
>```c++
>inline bool spfa(int s)
>{
>        for (int i = 1; i <= n; i++)
>             h[i] = 63, vis[i] = 0;
>        h[s] = 0;
>        vis[s] = 1;
>        queue<int> q;
>        q.push(s);
>        int x;
>        while (!q.empty())
>        {
>             x = q.front();
>             q.pop();
>             vis[x] = 0;
>             for (int i = head[x]; i; i = e[i].next)
>             {
>                 int y = e[i].to, d = e[i].w;
>                 if (h[y] > h[x] + d)
>                 {
>                     h[y] = h[x] + d;
>                     if (!vis[y])
>                     {
>                         ++num[y]; // 说明经过当前点，次数加1
>                         if (num[y] > n) // n为自己设定的上限，如果循环次数超过n，说明存在负环，直接返回
>                             return false;
>                         vis[y] = 1, q.push(y);
>                     }
>                 }
>             }
>        }
>        return true;
>}
>```
>
>SPFA预处理完成后利用h数组更新权重
>
>```c++
> for (int j = 1; j <= n; j++)
>        for (int i = head[j]; i; i = e[i].next)
>            e[i].w = e[i].w + h[j] - h[e[i].to];
>```
>
>更新完成后可以保证权值全为正数，随后根据题意运行Dijkstra，最终输出答案要注意减去h数组差值

### LCA/最近公共祖先

> 数组类型
>
> ```c++
> int dep[N], fa[N][22];
> ```
>
> DFS预处理
>
> ```C++
> inline void dfs(int u, int f)
> {
>  dep[u] = dep[f] + 1;
>  fa[u][0] = f;
>  for (int i = 1; i <= 19; i++)
>      fa[u][i] = fa[fa[u][i - 1]][i - 1];
>  for (int v : e[u])
>      if (v != f)
>          dfs(v, u);
> }
> ```
>
> LCA本体
>
> ```c++
> inline int lca(int u, int v)
> {
>  if (dep[u] < dep[v])
>      swap(u, v);
>  for (int i = 19; i >= 0; i--)
>      if (dep[fa[u][i]] >= dep[v])
>          u = fa[u][i]; // 让u，v处于同一层
>  if (u == v)
>      return u;
>  for (int i = 19; i >= 0; i--)
>      if (fa[u][i] != fa[v][i])
>          u = fa[u][i], v = fa[v][i]; // 返回祖先的下一层
>  return fa[u][0];
> }
> ```

### Tarjan算法

>时间戳 dfn[x] 节点x第一次被访问的顺序
>
>追溯值 low[x] 从x节点出发，能到的最早的时间戳
>
>```c++
>vector<int> e[N];
>int dfn[N], low[N], tot;
>int stk[N], instk[N], top;
>int scc[N], siz[N], cnt;
>inline void tarjan(int x)
>{
>    // 入X点，盖时间戳，入栈
>    dfn[x] = low[x] = ++tot;
>    stk[++top] = x, instk[x] = 1;
>    for (int y : e[x])
>    {
>        // 未访问
>        if (!dfn[y])
>        {
>            tarjan(y);
>            low[x] = min(low[x], low[y]);
>        }
>        else if (instk[y])
>            low[x] = min(low[x], dfn[y]);
>    }
>    // X为强连通图的根,输出分量图
>    if (dfn[x] == low[x])
>    {
>        int y;
>        ++cnt;
>        do
>        {
>            y = stk[top--];
>            instk[y] = 0;
>            scc[y] = cnt;
>            siz[cnt]++;
>        } while (y != x);
>    }
>}
>```
>
>

### 点双连通分量

>基础性质：
>**1、** 除了一种比较特殊的点双，其他的点双都满足：任意两点间都存在至少两条点不重复路径。
>**2、** 图中任意一个割点都在至少两个点双中。
>**3、** 任意一个不是割点的点都只存在于一个点双中。
>
>注意点：要在tarjan基础上加特判起点没有祖先的情况
>
>```c++
>bool cut[N];
>inline void tarjan(int x)
>{
>    int ss = 0;
>    dfn[x] = low[x] = ++tot;
>    stk[++top] = x, instk[x] = 1;
>    for (int y : e[x])
>    {
>        if (!dfn[y])
>        {
>            ++ss;
>            tarjan(y);
>            low[x] = min(low[x], low[y]);
>            if (low[y] >= dfn[x])
>                cut[x] = 1;
>        }
>        else if (instk[y])
>            low[x] = min(low[x], dfn[y]);
>    }
>    if (ss == 1 && x == 1) // ss表示是否在环内，x表示是否为起点
>        cut[x] = 0;
>}
>```

### 边双连通分量

>基础性质:
>**1、** 割边不属于任意边双，而其它非割边的边都属于且仅属于一个边双。
>**2、** 对于一个边双中的任意两个点，它们之间都有至少两条**边不重复**的路径。
>
>```c++
>int dfn[N], low[N], cnt, tot;
>struct edge {
>    int u, v;
>};
>vector<edge> e;
>vi h[N];
>struct bridge {
>    int x, y;
>} bri[N];
>
>inline void add(int x, int y) {
>    e.push_back({x, y});
>    h[x].push_back(e.size() - 1);
>}
>
>inline void tarjan(int x, int in_edg) {
>    dfn[x] = low[x] = ++tot;
>    for (int i = 0; i < h[x].size(); i++) {
>        int j = h[x][i], y = e[j].v;
>        if (!dfn[y]) {
>            tarjan(y, j);
>            low[x] = min(low[x], low[y]);
>            if (low[y] > dfn[x]) //如果low值大于dfn值，说明只能从x到y，为割边
>                bri[++cnt] = {x, y};
>        } else if (j != (in_edg ^ 1)) //判断是否为反边
>            low[x] = min(low[x], dfn[y]);
>    }
>}
>```
>

### 拓扑排序

有向无环图（DAG），可以判断有向图中是否有环

#### DFS算法

>通过c数组来存放颜色，表示不同的状态
>
>```c++
>vector<int> e[N], tp; // e[N]类似邻接表，存放有向边，tp存拓扑排序
>int c[N];             // 存放颜色，0表示为经过，1表示已经被经过，-1表示正在被经过
>bool dfs(int u)
>{
>    c[u] = -1;
>    for (auto v : e[u])
>    {
>        if (~c[v]) // 说明有环存在
>            return 0;
>        if (!c[v] && !dfs(v)) // 递归，说明v下面有环
>            return 0;
>    }
>    c[u] = 1;
>    tp.push_back(u);
>    return 1;
>}
>bool toposort()
>{
>    memset(c, 0, sizeof c);
>    for (int i = 1; i <= n; i++) // 遍历每个点，如果颜色没被标记，进行搜索
>        if (!c[i] && !dfs(i))
>            return 0;
>    reverse(tp.begin(), tp.end());
>    return 1;
>}
>```
>
>
>

#### 卡恩算法（Kahn）

通过队列来维护入度为0的集合

>```c++
>vector<int> e[N], tp; // e[N]类似邻接表，存放有向边，tp存拓扑排序
>int din[N];           // 存放每个点的入度
>bool toposort()
>{
>queue<int> q;
>for (int i = 1; i <= n; i++)
>       if (!din[i])
>           q.push(i);
>     while (!q.empty())
>     {
>       int u = q.front();
>       q.pop();
>        tp.push_back(u);
>        for (auto v : e[u])
>            if (--din[v] == 0)
>                q.push(v);
>     }
>     return tp.size() == n;
>    }
>    ```

### 最小生成树

**稀疏图一般选择 prim
稠密图一般选择 Kruskal**

#### Prim

```c++
struct edge
{
    int v, w;
};
vector<edge> e[N];
int d[N], vis[N];
priority_queue<pair<int, int>> q;

bool prim(int s)
{
    for (int i = 0; i <= n; i++)
        d[i] = inf;
    d[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        ans += d[u];
        ++cnt;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > w)
            {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
    return cnt == n;
}
```

#### Kruskal



### 二分图



## 字符串

### 字符串哈希

#### 自然溢出

hash[i]=hash[i−1]∗Base+idx(s[i])

数据结构要求ull，不能用ll

#### 单哈希

hash[i]=(hash[i−1]∗Base+idx(s[i]))%MOD

数据结构无要求，可以用ll

#### 双哈希

Base，MOD不同，进行两遍hash

### KMP



## 博弈论

### Nim game

题目描述：通常涉及两名玩家轮流从几堆物品（如石子或饼干）中取走一定数量的物品。每个玩家每次可以从任意一堆中取走任意数量的物品，但必须至少取走一个。最后无法进行操作的玩家输掉游戏。
如果异或和为0，对后手玩家有利。如果异或和不为零，对先手玩家有利。

