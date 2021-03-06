// @Title: Print FooBar Alternately
// @Author: colinjxc
// @Date: 2022-02-11T02:33:19+08:00
// @URL: https://leetcode-cn.com/problems/print-foobar-alternately


class FooBar {
private:
    int n;
    int foo_cnt_;
    int bar_cnt_;
    std::mutex mu_;
    std::condition_variable cv_;
public:
    FooBar(int n) {
        this->n = n;
        this->foo_cnt_ = 0;
        this->bar_cnt_ = 0;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 0; i < n; i++) {
          if (i > 0) lk.lock();
          cv_.wait(lk, [this]{
            return foo_cnt_ == bar_cnt_;
          });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
          foo_cnt_++;
          lk.unlock();
          cv_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lk(mu_);
        for (int i = 0; i < n; i++) {
          if (i > 0) lk.lock();
          cv_.wait(lk, [this]{
            return foo_cnt_ == bar_cnt_ + 1;
          });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
          bar_cnt_++;
          lk.unlock();
          cv_.notify_one();
        }
    }
};
