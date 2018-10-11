def parse_line(string):
    if string.count('/')<=2:
        return None
    else:
        W=string.split('/',3)
        if W[0].isdigit() and W[1].isdigit() and W[2].isdigit():
            W[0]=int(W[0])
            W[1]=int(W[0])
            W[2]=int(W[0])
            line = ((W[0],W[1],W[2],W[3]))
            return line
        else:
            return None
    
if __name__=='__main__':
    print parse_line("12/12/12/ Again some spaces\n")