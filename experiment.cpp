#include<bits/stdc++.h>
using namespace std;
struct active
{
    int number;  //用于记录编号
    int begin;   //用于记录开始时间
    int end;     //用于记录结束时间
};

bool cmp(active x,active y)
{
    return x.end<y.end;    //重载sort函数
}
int schedule(active* actives,int s,int e) 
{
    int n=0; 
    int i=s+1; 
    if (actives[s].begin > -1){
       n=1;
       
       for(;i<=e;i++)
       if(actives[i].begin- actives[s].end >= 1){
        s=i;
        n++;
        }
       }
       return n;
}
void make_arragement(active* actives,int g,int groupmin)
{
    pair<int,int> sche[g];
    //初始化
    for(int tmp=0;tmp<g;tmp++)
    {
        sche[tmp].first = 0;
        sche[tmp].second= 0;
    }
    
    for(int tmp=0;tmp<=groupmin;tmp++)
    {
        for(int tmp2=0;tmp2<g;tmp2++)
        {
            if(sche[tmp2].second<actives[tmp].begin)
            {
                sche[tmp2].second = actives[tmp].end;
                sche[tmp2].first = actives[tmp].begin;
                cout << "会场号码" << "    " << "开始时间" << "     " << "结束时间" << endl; 
                cout <<  tmp2+1 <<"       "<<  actives[tmp].begin << "          " << actives[tmp].end << endl;
                break;
            }
        }
    }

}
int main( ) 
{
        int *result = new int[1];
        int group;
        cin>>group;
        active *st= new active[group]; 
        for(int i=0;i<group;i++)
        cin>>st[i].begin>>st[i].end;  //
        sort(st,st+group,cmp);
        result[1] = schedule(st,0,group);
        int k = result[1];
        //定义一个pair,前一个记录会场开始时间，后一个记录会场结束时间
        make_arragement(st,k,group-1);
        cout<< result[1] <<endl; 

        return 0;
}
