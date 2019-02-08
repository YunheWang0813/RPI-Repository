def dfs(G):     
        for v in G:
                if not visited[v]:
                        explore(G, v)

def explore(G, v):
        visited[v]=True
        previsit(v)
        for u in G[v]:
                if not visited[u]:
                        explore(G, u)
        postvisit(v)
        
def previsit(v):
        pre[v]+=1

def postvisit(v):
        post[v]+=1
        


if __name__ == '__main__':
        with open('Lab5.txt') as req_file:
                data = []
                for line in req_file:
                        line = line.split()
                        if line:
                                line = [int(i) for i in line]
                                data.append(line)
                                
                                
        G = {}
        for temp in data:
                if temp[1] not in G:
                        G[temp[1]]=[]                  
                if temp[0] not in G:
                        G[temp[0]] = [temp[1]]
                else:
                        G[temp[0]].append(temp[1])                                              
        print G    
        
        
        GR = {}
        for temp in data:
                if temp[0] not in GR:
                        GR[temp[0]]=[]                
                if temp[1] not in GR:
                        GR[temp[1]] = [temp[0]]
                else:
                        GR[temp[1]].append(temp[0])         
        print GR          
                        
        visited={}
        pre={}
        post={}
        
        for v in G:
                visited[v]=False                   
                pre[v]=0
                post[v]=0
        
        
        dfs(G)