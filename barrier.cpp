#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

const int N = 8;
std::mutex m;
std::condition_variable cv;
int cnt = 0;

void worker_thread()
{
    std::unique_lock<std::mutex> lock(m);
    cnt += 1;

    if (cnt == N) {
        lock.unlock();
        cv.notify_all();
    }
    else {
        std::cout << "worker-" << cnt << " waits" << std::endl;
        cv.wait(lock, [] { return cnt == N; });
        lock.unlock();
    }
    
    std::cout << "Passing the barrier" << std::endl;
}

int main()
{
    std::vector<std::thread> workers;

    for (int i = 0; i < N; ++i) {
        int id = i;
        workers.emplace_back(std::thread(worker_thread));
    }

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [=] { return cnt == N; });
    }

    cv.notify_all();

    for (int i = 0; i < N; ++i) {
        workers[i].join();
    }

}