import { Injectable } from "@angular/core";
import { newTaskType } from "./task/task.model";

@Injectable({ providedIn: 'root'})
export class TasksService {
    private tasks = [
        {
            id: 't1',
            userId: '1',
            title: 'Task One',
            time: '2024-06-01 10:00',
            description: 'This is the first task.'
        },
        {
            id: 't2',
            userId: '2',
            title: 'Task Two',
            time: '2024-06-02 11:00',
            description: 'This is the second task.'
        },
        {
            id: 't3',
            userId: '1',
            title: 'Task Three',
            time: '2024-06-03 12:00',
            description: 'This is the third task.'
        }
    ]

    constructor(){
        const tasks = localStorage.getItem('tasks');
        if(tasks){
            this.tasks = JSON.parse(tasks);
        }
    }

    getTaskLength() {
        return this.tasks.length;
    }

    getUserTasks(userId: string) {
        return this.tasks.filter(task => task.userId === userId);
    }

    addTask(newTask: newTaskType, userId: string) {
        const newTaskId = 't' + (this.tasks.length + 1).toString();
        this.tasks.unshift({
            id: newTaskId,
            userId: userId,
            title: newTask.title,
            description: newTask.description,
            time: newTask.time
        });
        this.saveTaskToLocalStorage();
    }

    removeTask(taskId: string) {
        this.tasks = this.tasks.filter(task => task.id !== taskId);
        this.saveTaskToLocalStorage();
    }

    saveTaskToLocalStorage(){
        localStorage.setItem('tasks', JSON.stringify(this.tasks));
    }

}