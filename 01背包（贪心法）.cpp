#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, vo; //物品数目以及背包容量
int v[maxn], w[maxn]; //每件物品的价值和重量
int maxV;  //获取的最大价值
int vis[maxn]; //标记当前物品是否选取
int ave[maxn]; //用于存储每件物品的单位质量的价值
struct item { //定义物品结构体，方便在排序后保留序号信息
    int id;
    int w;
    int v;
    int ave;
    int vis;  //用以确定该件物品是否被选取 
} items[maxn];
bool cmp(item a, item b) { //定义特定的排序函数用以sort排序 
    return a.ave > b.ave;
}
void init() {  //用于初始传入待计算数据
    printf("请输入待选取的物品数n与容量vo：");
    scanf("%d%d", &n, &vo);
    printf("请依次输入对应的物品重量wi: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("请依次输入对应的物品价值vi: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i <= n; i++) { //分别为每个物品元素赋值
        items[i].id = i;
        items[i].w = w[i];
        items[i].v = v[i];
        items[i].ave = v[i] / w[i];
    }
}

void ansbygreedy_alg() {//贪心法
    sort(items + 1, items + n + 1, cmp); //按照ave顺序从大到小排序 
    int i = 0, W = 0; //定义当前序号和当前重量 
    while (W < vo && i <= n) {  
        i++;
        if (W + items[i].w < vo) { //判断是否可以选取该物品 
            W += items[i].w;
            maxV += items[i].v;
            items[i].vis = 1;
        }
    }

}
void print() {  //打印结果
    printf("求解得最大价值为 %d\n此时选取的物品分别为：\n", maxV);
    for (int i = 1; i <= n; ++i) {
        if (items[i].vis == 1)  //如果选取则输出序号 
            cout << items[i].id << " ";
    }
    printf("\n\n");
}
int main() {
    init(); //输入待求解数据
    ansbygreedy_alg(); //采用当前算法解决问题
    print(); //打印求解答案
    return 0;
}
