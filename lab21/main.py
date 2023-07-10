#рекурсивный обход и посчет числа выполнимых файлов в каталоге и поддиректориях
import os

k=0

def FileCrowling(path,k):
    for i in os.listdir(path):
        if os.path.isfile(path+'\\'+i):
            k=k+1
        if os.path.isdir(path+'\\'+i):
            return FileCrowling(path+'\\'+i,k)
    return k
a=input()
if(a[0] == '?'):
    print('You must enter the path to the folder for which you want to perform the action')
    print('Do you want to enter a path? Yes or No?')
    b=input()
    if(b[0] == 'N'):
        path='C:\\Users\\seraf\\OneDrive\\Рабочий стол\\lab21'
        print(FileCrowling(path,0))
    else:
        path=input()
        print(FileCrowling(path,0))
    
