import gerenate_data1 as gd
import random


def readData(i):
    array = [];
    doc = open(str("data"+str(i)+".out"),"r+")
    s = doc.read()
    list = s.split(" ")
    for num in list[:len(list)-1]:
        array.append(int(num))
    doc.close()
    return array

def gerenateRandint(high):
    i = random.randint(0,high-1)
    j = random.randint(i,high-1)
    return i,j
def mainTest():
    flag = 0
    _n = [10,20,100]
    gd.gerenateData(_n)
    for i in range(len(_n)):
        list  = readData(i+1)
        for times in range(100): # 随机测试次数
            pos1,pos2 = gerenateRandint(len(list)) # pos1 < pos2
            if(list[pos1]>list[pos2]):
                print("ERROR in case {x}: {pos1} {pos2}".format(x=str(i+1),pos1=str(pos1),pos2=str(pos2)))
                flag = 1
    if flag == 1:
        return False
    return True
    

if __name__ == "__main__":
    if mainTest():
        print("All Correct!") 