class Time(object):
    def __init__(self,hr,min,sec):
        if hr>24:
            hr=hr%24
        self.seconds=hr*60*60+min*60+sec
        
    def convert(self):
        hr=self.seconds/3600
        min=(self.seconds-hr*3600)/60
        sec=self.seconds-hr*3600-min*60
        return hr,min,sec         
    
    def __str__(self):
        hr,min,sec=self.convert()
        return '%02d:%02d:%02d'%(hr,min,sec)
    
    def __add__(self,other):
        total=self.seconds+other.seconds
        hr=total/3600
        min=(total-hr*3600)/60
        sec=total-hr*3600-min*60
        return Time(hr,min,sec) 
    
    def __sub__(self,other):
        total=self.seconds-other.seconds
        if total<0:
            total+=24*3600
        hr=total/3600
        min=(total-hr*3600)/60
        sec=total-hr*3600-min*60
        return Time(hr,min,sec)       
        