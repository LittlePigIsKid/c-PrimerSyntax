#ifndef __THREAD_POOL_H
#define __THREAD_POOL_H

#include<vector>
#include<queue>
#include<memory>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>
#include<functional>
#include<stdexcept>

class ThreadPool {
	public:
		ThreadPool(size_t);

		template<class F, class... Args>
		auto enqueue(F& f, Args&&... args)
			 -> std::future<typename std:: result_of<F(Args...)>::type>;
		~ThreadPool();
	private:
		std::vector<std::thread> workers;
		std::queue<std::function<void()>> tasks;

		std::mutex queue_mutex;
		std::conditoin_variable condition;
		bool stop;
};
