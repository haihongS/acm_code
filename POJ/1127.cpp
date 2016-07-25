#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;
const double eps = 1e-8;
const double pi = std::acos(-1.0);

class point
{
public:
    double x, y;
    point(){};
    point(double x, double y):x(x),y(y){};

    static int xmult(const point &ps, const point &pe, const point &po)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }

    //相对原点的差乘结果，参数：点[_Off]
    //即由原点和这两个点组成的平行四边形面积
    double operator *(const point &_Off) const
    {
        return x * _Off.y - y * _Off.x;
    }
    //相对偏移
    point operator - (const point &_Off) const
    {
        return point(x - _Off.x, y - _Off.y);
    }
    //点位置相同(double类型)
    bool operator == (const point &_Off) const
    {
        return std::fabs(_Off.x - x) < eps && std::fabs(_Off.y - y) < eps;
    }
    //点位置不同(double类型)
    bool operator != (const point &_Off) const
    {
        return ((*this) == _Off) == false;
    }
    //两点间距离的平方
    double dis2(const point &_Off) const
    {
        return (x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y);
    }
    //两点间距离
    double dis(const point &_Off) const
    {
        return std::sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
    }
};

class pVector
{
public:
    point s, e;//两点表示，起点[s]，终点[e]
    double a, b, c;//一般式,ax+by+c=0

    pVector(){}
    pVector(const point &s, const point &e):s(s),e(e){}

    //向量与点的叉乘,参数：点[_Off]
    //[点相对向量位置判断]
    double operator *(const point &_Off) const
    {
        return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
    }
    //向量与向量的叉乘,参数：向量[_Off]
    double operator *(const pVector &_Off) const
    {
        return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
    }
    //从两点表示转换为一般表示
    bool pton()
    {
        a = s.y - e.y;
        b = e.x - s.x;
        c = s.x * e.y - s.y * e.x;
        return true;
    }

    //-----------点和直线（向量）-----------
    //点在向量左边（右边的小于号改成大于号即可,在对应直线上则加上=号）
    //参数：点[_Off],向量[_Ori]
    friend bool operator<(const point &_Off, const pVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
            < (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    //点在直线上,参数：点[_Off]
    bool lhas(const point &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    //点在线段上,参数：点[_Off]
    bool shas(const point &_Off) const
    {
        return lhas(_Off)
            && _Off.x - std::min(s.x, e.x) > -eps && _Off.x - std::max(s.x, e.x) < eps
            && _Off.y - std::min(s.y, e.y) > -eps && _Off.y - std::max(s.y, e.y) < eps;
    }

    //点到直线/线段的距离
    //参数： 点[_Off], 是否是线段[isSegment](默认为直线)
    double dis(const point &_Off, bool isSegment = false)
    {
        //化为一般式
        pton();

        //到直线垂足的距离
        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);

        //如果是线段判断垂足
        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = std::max(s.x, e.x);
            double yb = std::max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
            if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = std::min(_Off.dis(s), _Off.dis(e));
        }

        return fabs(td);
    }

    //关于直线对称的点
    point mirror(const point &_Off) const
    {
        //注意先转为一般式
        point ret;
        double d = a * a + b * b;
        ret.x = (b * b * _Off.x - a * a * _Off.x - 2 * a * b * _Off.y - 2 * a * c) / d;
        ret.y = (a * a * _Off.y - b * b * _Off.y - 2 * a * b * _Off.x - 2 * b * c) / d;
        return ret;
    }
    //计算两点的中垂线
    static pVector ppline(const point &_a, const point &_b)
    {
        pVector ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        //一般式
        ret.a = _b.x - _a.x;
        ret.b = _b.y - _a.y;
        ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
        //两点式
        if(std::fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x = - ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y = - ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
            }
        }
        return ret;
    }

    //------------直线和直线（向量）-------------
    //直线重合,参数：直线向量[_Off]
    bool equal(const pVector &_Off) const
    {
        return lhas(_Off.e) && lhas(_Off.s);
    }
    //直线平行，参数：直线向量[_Off]
    bool parallel(const pVector &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    //两直线交点，参数：目标直线[_Off]
    point crossLPt(pVector _Off)
    {
        //注意先判断平行和重合
        point ret = s;
        double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
                / ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
        ret.x += (e.x - s.x) * t;
        ret.y += (e.y - s.y) * t;
        return ret;
    }

    //------------线段和直线（向量）----------
    //线段和直线交
    //参数：线段[_Off]
    bool crossSL(const pVector &_Off) const
    {
        double rs = (*this) * _Off.s;
        double re = (*this) * _Off.e;
        return rs * re < eps;
    }

    //------------线段和线段（向量）----------
    //判断线段是否相交(注意添加eps)，参数：线段[_Off]
    bool isCrossSS(const pVector &_Off) const
    {
        //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交
        //2.跨立试验（等于0时端点重合）
        return (
            (std::max(s.x, e.x) >= std::min(_Off.s.x, _Off.e.x)) &&
            (std::max(_Off.s.x, _Off.e.x) >= std::min(s.x, e.x)) &&
            (std::max(s.y, e.y) >= std::min(_Off.s.y, _Off.e.y)) &&
            (std::max(_Off.s.y, _Off.e.y) >= std::min(s.y, e.y)) &&
            ((pVector(_Off.s, s) * _Off) * (_Off * pVector(_Off.s, e)) >= 0.0) &&
            ((pVector(s, _Off.s) * (*this)) * ((*this) * pVector(s, _Off.e)) >= 0.0)
            );
    }
};

pVector num[maxn];

int fa[maxn];

int find(int x);
int uu(int x,int y);

int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		for(int i=0;i<maxn;i++)
			fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			point a,b;
			a.x=x1,a.y=y1;
			b.x=x2,b.y=y2;
			num[i].s=a,num[i].e=b;
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(num[i].isCrossSS(num[j]))
					uu(i,j);
			}
		}

		int u,v;
		while(scanf("%d%d",&u,&v) && u+v)
		{
			int fu=find(u),fv=find(v);
			if(fu==fv)
				printf("CONNECTED\n");
			else
				printf("NOT CONNECTED\n");
		}
		
	}
	return 0;
}

int uu(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	return 0;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

