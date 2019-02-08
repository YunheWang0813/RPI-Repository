import sys

def dfs(G): 
        global cc_count
        for v in G:
                visited[v]=False      
        for v in G:
                if not visited[v]:
                        cc_count=cc_count+1
                        explore(G, v)
 
def explore(G, v):
        global clock
        visited[v]=True
        ccnum[v]=cc_count
        pre[v]=clock
        clock=clock+1
        for u in G[v]:
                if not visited[u]:
                        explore(G, u)
        post[v]=clock
        clock=clock+1        


if __name__ == '__main__':
        with open('Lab5part2.txt') as req_file:
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

        GR = {}
        for temp in data:
                if temp[0] not in GR:
                        GR[temp[0]]=[]                
                if temp[1] not in GR:
                        GR[temp[1]] = [temp[0]]
                else:
                        GR[temp[1]].append(temp[0])                
                        
        visited={}
        ccnum={}
        pre={}
        post={}

        clock=1
        cc_count=0

        dfs(GR)
        
        postorder=[]
        for i in range(len(post)):
                temp=max(post, key=post.get)
                postorder.append(temp)
                post[temp]=-1
                
        result=[]
        for v in G:
                visited[v]=False
                
        for v in postorder:
                if visited[v]!=-1:
                        explore(G, v)
                        temp=[]
                        for key in visited:
                                if visited[key]==True:
                                        temp.append(key)
                                        visited[key]=-1
                        result.append(temp)
        
        for i in result:
                print i