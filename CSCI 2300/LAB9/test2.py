import heapdict
from copy import deepcopy

def dijkstra(G,data2,s):
        for u in G:
                dist[u]=9999           
                prev[u]='nil'        
        dist[s]=0
        
        H=heapdict.heapdict()
        for i in dist:
                H[i]=dist[i]
        while len(H)!=0:
                u=H.popitem()
                key=u[0]
                temp={}
                for i in data2:
                        if key==i[0][0]:
                                temp[i[0][1]]=i[1]
                for v in temp:
                        if dist[v]>dist[key]+temp[v]:
                                dist[v]=dist[key]+temp[v]
                                prev[v]=u[0]
                                H[v]=dist[key]+temp[v]
                

if __name__ == '__main__':
        with open('C.txt') as req_file:
                data1 = []
                data2 = []
                for line in req_file:
                        line = line.split()
                        if line:
                                line = [int(i) for i in line]
                                temp = line.pop()
                                data1.append(line)
                                line = [line]
                                line.append(temp)
                                data2.append(line)
               
        editdata=deepcopy(data2)       
        
        for i in data2:
                i[1]=1
                i[0]=tuple(i[0])
                                
        G = {}
        for temp in data1:
                if temp[1] not in G:
                        G[temp[1]]=[]                  
                if temp[0] not in G:
                        G[temp[0]] = [temp[1]]
                else:
                        G[temp[0]].append(temp[1])
                        
        GF = {}
        for i in editdata:
                GF[tuple(i[0])]=i[1]

        dist={}
        prev={}       

        source=min(G)
        target=max(G)
        maxflow=0   
        waygraph={}
                
        for i in dist:
                waygraph[i]='initialize'
                        
        while True:
                
                dijkstra(G,data2,source)
                            
                for i in sorted(dist):
                        temp=[]
                        temp.append(prev[i])
                        temp.append(i)
                        a=prev[i]
                        if a!='nil':
                                while a!=source:
                                        temp.insert(source, prev[a])
                                        a=prev[a]
                                waygraph[i]=temp
                        else:
                                waygraph[i]='cannot reach'
                
                way=waygraph[target]
                if way=='cannot reach':
                        break
                
                targetlen=len(way)
                waysplit=[]
                for i in range(targetlen-1):
                        temp=[]
                        temp.append(way[i])
                        temp.append(way[i+1])
                        waysplit.append(tuple(temp))
                        
                for i in waysplit:
                        if i in GF:
                                GF[i]=GF[i]-1
                                temp=(i[1],i[0])
                                if temp in GF:
                                        GF[temp]+=1
                                else:
                                        GF[temp]=1
                                        data2.append([temp,1])
                        
                maypop=[]
                for i in GF:
                        if GF[i]==0:
                                maypop.append(i)
                for i in maypop:
                        GF.pop(i,None)
                        temp=[i,1]
                        if temp in data2:
                                data2.remove(temp)
                        
                maxflow+=1
                
        cutL=[]
        cutR=[]
        for i in waygraph:
                if waygraph[i]=='cannot reach':
                        cutR.append(i)
                else:
                        cutL.append(i)
        cutR.remove(source)
        cutL.append(source)
        
        print 'Maximum flow: %d'%maxflow
        print 'Left: %s'%sorted(cutL)
        print 'Right: %s'%sorted(cutR)