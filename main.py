import os
k=0
path='C:\\Users\\seraf\\OneDrive\\Рабочий стол\\lab21'
def FileCrowling(path,k):
    for i in os.listdir(path):
        if os.path.isfile(path+'\\'+i):
            k=k+1
        if os.path.isdir(path+'\\'+i):
            return FileCrowling(path+'\\'+i,k)
    return k
        
print(FileCrowling(path,0))
