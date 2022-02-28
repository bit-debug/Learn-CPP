#include <stdio.h>

#include <chrono>
#include <thread>

#include <mutex>
#include <condition_variable>

using namespace std::chrono_literals;

std::mutex mtx;
std::condition_variable cv;

void worker_t()
{
    printf("worker is waiting...\n");
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait_for(lk, 3s);

    printf("worker is awake\n");

    lk.unlock();
}

int main()
{
    std::this_thread::sleep_for(5s);
    
    std::thread worker(worker_t);
    
    std::this_thread::sleep_for(1s);
    {
        std::lock_guard<std::mutex> lk(mtx);
        printf("main is holding the lock\n");
        std::this_thread::sleep_for(5s);
        printf("main is about to release the lock\n");
    }
    
    worker.join();
}