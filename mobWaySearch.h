#ifndef MOBWAYSEARCH_H
#define MOBWAYSEARCH_H

void BFS(int** a, int &s,int* status,int* parent,int* distance){
     int queue[1005],head,tail,u;
            queue[1]=s;
            status[s]=1;
            head=1;
            tail=1;
            distance[s]=0;
            queue[0]=1;
            while (queue[0]>0){
                  u=queue[head];
                  head++;
                  queue[0]--;
                  for (int i=1;i<=a[u][0];i++)
                      if (status[a[u][i]]==0){
                                        parent[a[u][i]]=u;
                                        status[a[u][i]]=1;
                                        distance[a[u][i]]=distance[u]+1;
                                        tail++;
                                        queue[tail]=a[u][i];
                                        queue[0]++;
                                        }
                                        }
                                        }

int* PATH (int* parent, int* distance, int s,int v){
     int l,a,b,tmp;
     int* p= new int[s];
     if (distance[v]==INT_MAX) return p;
     l=distance[v];
     p[l]=v;
     while (v!=s){
           v=parent[v];
           l--;
           p[l]=v;
           }
     a=0;
     b=distance[v];
     while (a<b){
           tmp=p[a];
           p[a]=p[b];
           p[b]=tmp;
           a++;
           b--;
           }
     return p;
}

#endif // MOBWAYSEARCH_H
