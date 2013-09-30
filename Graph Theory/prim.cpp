#include <iostream> 
#include <cmath> 
#include <cstdio> 
using namespace std; 
double sum, arr_list[101][101], min; 
int i, j, k=0, n; 
struct struct_a 
{ 


 float x; 
float y; 
}; 
struct_a arr_xy[101]; 
struct struct_b 
{ 
int point; 
float lowcost; 
}; 
struct_b closedge[101]; 
void prim(int n) //prim 需要准备：n顶点数 arr_list[][]顶点的邻接矩阵也是从0开始计数 
{ 
int i,j,k; 
float min;
k=0; 
for(j=0; j<n ;j++) { 
if(j != k) { 
closedge[j].point = k; 
closedge[j].lowcost = arr_list[k][j]; 
} 
} 
closedge[k].lowcost=0; 
for(i=0; i<n ;i++) { 
min=10000; 
for(j=0; j<n ;j++) { 
if (closedge[j].lowcost != 0 && closedge[j].lowcost < min) { 
k = j; 
min = closedge[j].lowcost; 
} 
} 
sum += closedge[k].lowcost; //不要改成sum+=min; sum即为所求值 
closedge[k].lowcost = 0; 
for(j=0; j<n ;j++) { 
if(arr_list[k][j] < closedge[j].lowcost) { 
closedge[j].point = k; 
closedge[j].lowcost = arr_list[k][j]; 
} 
} 
} 
} 
