#include <iostream>

#include <base/run_loop.h>
#include <base/task/single_thread_task_executor.h>
#include <base/threading/thread_task_runner_handle.h>

int main(int argc, char** argv) {
    std::unique_ptr<base::SingleThreadTaskExecutor> main_thread_task_executor
            = std::make_unique<base::SingleThreadTaskExecutor>(base::MessagePumpType::DEFAULT);

    base::RunLoop rl;
    base::ThreadTaskRunnerHandle::Get()->PostTask(FROM_HERE,
                                                  base::BindOnce([]() {
                                                      std::cout << "asdf" << std::endl;
                                                  }));
    rl.Run();
}
