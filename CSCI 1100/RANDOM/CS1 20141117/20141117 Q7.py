class Student(object):
    def __init__(self, name, clubs):
        self.name = name
        self.clubs = clubs
        
    def unenroll(self, club):
        if club in self.clubs:
            self.clubs.remove(club)
            return True
        else:
            return False
        
if __name__=='__main__':
    s1 = Student('Rollins', set(['HYDRA', 'STRIKE']))
    s2 = Student('May', set(['SHIELD']))
    s3 = Student('Pierce', set(['HYDRA', 'SHIELD']))
    s4 = Student('Raina', set(['HYDRA']))
    students = [s1,s2,s3,s4]
    
    x=raw_input('Club ==> ')
    for student in students:
        if student.unenroll(x):
            if len(student.clubs)==0:
                print 'Removed: %s (no longer a student)'%student.name
            else:
                print 'Removed: %s'%student.name

                
            