#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Thread {
    pthread_t thread;
    bool deleted;

    void start() {
        deleted = false;
        int s = pthread_create(&thread, NULL, callback, this);
	if (s) {
            fprintf(stderr, "pthread_create: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        
	}
    
    }
    static void *callback(void *ctx) {
        Thread *thread = static_cast<Thread*> (ctx);
        thread->routine();
        return NULL;
    
    }
    ~Thread() {
        pthread_join(thread, NULL);
    
    }

    virtual void routine() {
        if (deleted) {
          puts("my child deleted me");
        }
        puts("Base");
    
    }

};

struct MyThread : public Thread {
	virtual void routine() {
        	puts("Derived");
	}
	~MyThread()
	{
	  deleted = true;
	}

};

int main() {
    const int count = 20;
    int loop = 1000;

    while (loop--) {
        MyThread *thread[count];
        int i;
	for (i=0; i<count; i++) {
            thread[i] = new MyThread;
            thread[i]->start();
        
	}
        for (i=0; i<count; i++)
            delete thread[i];
    
    }

    return 0;

}
