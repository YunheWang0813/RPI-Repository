import heapdict

def dijkstra(G,data2,s):
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
        with open('A.txt') as req_file:
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
                                
        G = {}
        for temp in data1:
                if temp[1] not in G:
                        G[temp[1]]=[]                  
                if temp[0] not in G:
                        G[temp[0]] = [temp[1]]
                else:
                        G[temp[0]].append(temp[1])                                              

        dist={}
        prev={}
        
        for u in G:
                dist[u]=9999           
                prev[u]='nil'
                
        prev[0]=0
        dijkstra(G,data2,min(G))
                
        for i in sorted(dist):
                print str(i)+': '+str(dist[i])+',',
                temp=[]
                temp.append(prev[i])
                temp.append(i)
                a=prev[i]
                while a!=0:
                        temp.insert(0, prev[a])
                        a=prev[a]
                print temp