class Counter : boost::noncopyable
{
    public:
	    Counter() : value_(0) {}
		int64_t value() const;
		int64_t getAndIncrease();
	
    private:
	    int64_t value_;
		mutable MutexLock mutex_;
};

class MutexLock : boost::noncopyable
{
	public:
		MutexLock() : holder_(0) {
			pthread_mutex_init(&mutex_, NULL);
		}
		~MutexLock() {
			assert(holder == 0);
			pthread_mutex_destroy(&mutex_);
		}
		bool isLockedByThisThread() {
			return holder == CurrentThread::tid();
		}
}
