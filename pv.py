import queue,random,threading
from threading import Thread
from time import sleep
#python中，引入threading进程来表示p,v操作原语，其中，acquire为p操作，release为v操作 
orderSignal = threading.Semaphore(1)  # r订票者互斥信号量
searchSignal = threading.Semaphore(1)  # w查询者互斥信号量
orderMutexSingal = threading.Semaphore(1)  #实现订票者优先
searchMutexSingal = threading.Semaphore(1)
rcount = 0
wcount = 0

# 创建5个查询者
  
def Searcher():
    print("模拟查询操作")
    while True:
        orderSignal.acquire() #先行检查有无订票者的进程存在
        orderMutexSingal.acquire()  #rmutex进行P操作
        if rcount==0:
            searchSignal.acquire()
        rcount = rcount + 1
        orderMutexSingal.release() #V操作
        orderSignal.release()
        #在此进行数据的查询
        print("模拟查询操作")
        SearcherSystem()
        orderMutexSingal.acquire()
        rcount = rcount - 1
        if rcount==0:
            searchSignal.release()
        orderMutexSingal.release()

def Order():
    while True:
        searchMutexSingal.acquire
        if wcount==0:
            orderSignal.acquire()
        wcount = wcount + 1
        searchMutexSingal.release()
        searchSignal.acquire()
        #订票系统
        print("模拟订票操作")
        
        searchSignal.release()
        wcount = wcount - 1
        if wcount==0:
            orderSignal.release()
        searchMutexSingal.release()


for i in range(5):
        print("查询者进程工作中")
        t = Thread(target=Searcher)
        t.start()
        
 
# 创建5个购票者
for i in range(5):
        x = Thread(target=Order)
        x.start()
        print("购票者进程工作中")  
