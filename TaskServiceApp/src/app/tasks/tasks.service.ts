import { inject, Injectable, signal } from "@angular/core";
import { type Task, type TaskStatus } from "./task.model";
import { LoggingService } from "../logging.service";


// @Injectable({
//     providedIn: 'root'
// })
export class TasksService {
    private tasks = signal<Task[]>([]);

    private logService = inject(LoggingService);

    allTasks = this.tasks.asReadonly();


    addTasks(taskData: { title: string; description: string }) {
        const newTask: Task = {
            id: Math.random().toString(),
            title: taskData.title,
            description: taskData.description,
            status: 'OPEN'
        };

        this.tasks.update(tasks => [...tasks, newTask]);
        this.logService.log(`Added new task: ${newTask.title}`);
    }

    updateTaskStatus(taskId: string, newStatus: TaskStatus) {
        // this.tasks.update(oldtasks => {
        //     const updatedTasks = oldtasks.map(task => {
        //         if (task.id === taskId) {
        //             return { ...task, status: newStatus };
        //         }
        //         return task;
        //     });
        //     return updatedTasks;
        // });

        this.tasks.update((oldTasks) =>
            oldTasks.map((task) =>
                task.id === taskId ? { ...task, status: newStatus } : task
            )
        );
        this.logService.log(`Updated task ${taskId} to status: ${newStatus}`);
    }
}