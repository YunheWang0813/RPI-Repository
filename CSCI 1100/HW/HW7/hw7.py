import json

def information(month,data):
    result=[]
    for i in range(len(data)):
        info={}
        if data[i].get('month')==month:
            info['year']=data[i].get('year')
            info['EMXT']=data[i].get('EMXT')
            info['EMNT']=data[i].get('EMNT')
            info['DT90']=data[i].get('DT90')
            info['DX32']=data[i].get('DX32')
            info['TPCP']=data[i].get('TPCP')
            info['TSNW']=data[i].get('TSNW')
            info['MNTM']=data[i].get('MNTM')
            result.append(info)
    return result

if __name__ == '__main__':
    data = json.loads(open("tempdata.json").read())
    month=int(raw_input('Enter a month (1-12) => '))
    print month
    htemp=[]
    ltemp=[]
    abo90=[]
    bel32=[]
    prec=[]
    snow=[]
    mtemp=[]
    mtemp2=[]
    for i in range(len(information(month,data))):
        if information(month,data)[i]['EMXT']!=-9999 and information(month,data)[i]['EMXT']!=0:
            htemp.append((information(month,data)[i]['EMXT'],information(month,data)[i]['year']))
        if information(month,data)[i]['EMNT']!=-9999 and information(month,data)[i]['EMNT']!=0:
            ltemp.append((information(month,data)[i]['EMNT'],information(month,data)[i]['year']))
        if information(month,data)[i]['DT90']!=-9999 and information(month,data)[i]['DT90']!=0:
            abo90.append((information(month,data)[i]['DT90'],information(month,data)[i]['year']))
        if information(month,data)[i]['DX32']!=-9999 and information(month,data)[i]['DX32']!=0:
            bel32.append((information(month,data)[i]['DX32'],information(month,data)[i]['year']))
        if information(month,data)[i]['TPCP']!=-9999 and information(month,data)[i]['TPCP']!=0:
            prec.append((information(month,data)[i]['TPCP'],information(month,data)[i]['year']))
        if information(month,data)[i]['TSNW']!=-9999 and information(month,data)[i]['TSNW']!=0:
            snow.append((information(month,data)[i]['TSNW'],information(month,data)[i]['year']))
        if information(month,data)[i]['MNTM']!=-9999 and information(month,data)[i]['MNTM']!=0:
            mtemp.append((information(month,data)[i]['year'],information(month,data)[i]['MNTM']))
            mtemp2.append(information(month,data)[i]['MNTM'])
    htemp.sort(reverse=True)
    ltemp.sort()
    abo90.sort(reverse=True)
    bel32.sort(reverse=True)
    prec.sort(reverse=True)
    snow.sort(reverse=True)
    mtemp.sort()
    avgall=sum(mtemp2)/len(mtemp2)
    f10=mtemp[:10]
    l10=mtemp[::-1][:10]
    f10temp=[]
    l10temp=[]
    for i in range(10):
        f10temp.append(f10[i][1])
        l10temp.append(l10[i][1])
    avgf10=sum(f10temp)/10
    avgl10=sum(l10temp)/10
    temp10=[]
    
    print 'Temperatures'
    print '--------------------------------------------------'
    print 'Highest max  value => %d: %.1f, %d: %.1f, %d: %.1f'%(htemp[0][1],htemp[0][0],htemp[1][1],htemp[1][0],htemp[2][1],htemp[2][0])
    print 'Lowest min value => %d: %.1f, %d: %.1f, %d: %.1f'%(ltemp[0][1],ltemp[0][0],ltemp[1][1],ltemp[1][0],ltemp[2][1],ltemp[2][0])
    if len(abo90)>=3:
        print 'Highest days with max >= 90 => %d: %.1f, %d: %.1f, %d: %.1f'%(abo90[0][1],abo90[0][0],abo90[1][1],abo90[1][0],abo90[2][1],abo90[2][0])
    else:
        print 'Highest days with max >= 90 => Not enough data'
    if len(bel32)>=3:
        print 'Highest days with max <= 32 => %d: %.1f, %d: %.1f, %d: %.1f'%(bel32[0][1],bel32[0][0],bel32[1][1],bel32[1][0],bel32[2][1],bel32[2][0])
    else:
        print 'Highest days with max <= 32 => Not enough data'
    print
    print 'Precipitation'
    print '--------------------------------------------------'
    print 'Highest total => %d: %.1f, %d: %.1f, %d: %.1f'%(prec[0][1],prec[0][0],prec[1][1],prec[1][0],prec[2][1],prec[2][0])
    print 'Lowest total => %d: %.1f, %d: %.1f, %d: %.1f'%(prec[-1][1],prec[-1][0],prec[-2][1],prec[-2][0],prec[-3][1],prec[-3][0])
    if len(snow)>=3:
        print 'Highest snow depth => %d: %.1f, %d: %.1f, %d: %.1f'%(snow[0][1],snow[0][0],snow[1][1],snow[1][0],snow[2][1],snow[2][0])
        print 'Lowest snow depth => %d: %.1f, %d: %.1f, %d: %.1f'%(snow[-1][1],snow[-1][0],snow[-2][1],snow[-2][0],snow[-3][1],snow[-3][0])
    else:
        print 'Highest snow depth => Not enough data'
        print 'Lowest snow depth => Not enough data'
    print
    print 'Average temperatures'
    print '--------------------------------------------------'
    print 'Overall: %.1f'%avgall
    print 'First 10 years: %.1f'%avgf10
    print 'Last 10 years: %.1f'%avgl10
    print
    for i in range(len(mtemp)):
        temp10.append(mtemp[i][1])
        if i%10==9:
            print '%d-%d: %s'%(mtemp[i-9][0],mtemp[i][0],'*'*int(sum(temp10)/10))
            temp10=[]
        if i==len(mtemp)-1:
            ini=len(mtemp)/10*10
            print '%d-%d: %s'%(mtemp[ini][0],mtemp[i][0],'*'*int(sum(temp10)/(len(mtemp)-ini)))