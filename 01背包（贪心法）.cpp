#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, vo; //��Ʒ��Ŀ�Լ���������
int v[maxn], w[maxn]; //ÿ����Ʒ�ļ�ֵ������
int maxV;  //��ȡ������ֵ
int vis[maxn]; //��ǵ�ǰ��Ʒ�Ƿ�ѡȡ
int ave[maxn]; //���ڴ洢ÿ����Ʒ�ĵ�λ�����ļ�ֵ
struct item { //������Ʒ�ṹ�壬������������������Ϣ
    int id;
    int w;
    int v;
    int ave;
    int vis;  //����ȷ���ü���Ʒ�Ƿ�ѡȡ 
} items[maxn];
bool cmp(item a, item b) { //�����ض�������������sort���� 
    return a.ave > b.ave;
}
void init() {  //���ڳ�ʼ�������������
    printf("�������ѡȡ����Ʒ��n������vo��");
    scanf("%d%d", &n, &vo);
    printf("�����������Ӧ����Ʒ����wi: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("�����������Ӧ����Ʒ��ֵvi: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i <= n; i++) { //�ֱ�Ϊÿ����ƷԪ�ظ�ֵ
        items[i].id = i;
        items[i].w = w[i];
        items[i].v = v[i];
        items[i].ave = v[i] / w[i];
    }
}

void ansbygreedy_alg() {//̰�ķ�
    sort(items + 1, items + n + 1, cmp); //����ave˳��Ӵ�С���� 
    int i = 0, W = 0; //���嵱ǰ��ź͵�ǰ���� 
    while (W < vo && i <= n) {  
        i++;
        if (W + items[i].w < vo) { //�ж��Ƿ����ѡȡ����Ʒ 
            W += items[i].w;
            maxV += items[i].v;
            items[i].vis = 1;
        }
    }

}
void print() {  //��ӡ���
    printf("��������ֵΪ %d\n��ʱѡȡ����Ʒ�ֱ�Ϊ��\n", maxV);
    for (int i = 1; i <= n; ++i) {
        if (items[i].vis == 1)  //���ѡȡ�������� 
            cout << items[i].id << " ";
    }
    printf("\n\n");
}
int main() {
    init(); //������������
    ansbygreedy_alg(); //���õ�ǰ�㷨�������
    print(); //��ӡ����
    return 0;
}
