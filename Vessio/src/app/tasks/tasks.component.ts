import { Component, Input } from '@angular/core';
import { DUMMY_USERS } from '../dummy-users';
import { TaskComponent } from './task/task.component';
import { NewTaskComponent } from './new-task/new-task.component';
import { type newTaskType } from './task/task.model';
import { TasksService } from './tasks.service';


@Component({
  selector: 'app-tasks',
  // standalone: true,
  standalone: false,
  // imports: [TaskComponent, NewTaskComponent],
  templateUrl: './tasks.component.html',
  styleUrl: './tasks.component.css'
})
export class TasksComponent {
  // @Input() selectedUserId!: string | null;
  // @Input() selectedUserId?: string;
  @Input() selectedUserId!: string;
  users = DUMMY_USERS;
  isAddingNewTask: boolean = false;
  // private tasksService = new TasksService();
  constructor(private tasksService: TasksService){}

  get userIDIndex(){
    return this.users.findIndex(user => user.id === this.selectedUserId);
  }

  get selectedUserTasks(){
    // return this.tasks.filter(task => task.userId === this.selectedUserId);
    return this.tasksService.getUserTasks(this.selectedUserId!);
  }

  // onTaskCompleted(completedTaskId: string){
  //   // this.tasks = this.tasks.filter(task => task.id !== completedTaskId);
  //   this.tasksService.removeTask(completedTaskId);
  // }

  onClickAddTasks(){
    this.isAddingNewTask = true;
  }

  OnClickCancelButton(){
    this.isAddingNewTask = false;
  }

  returnNewTaskId(){
    return this.tasksService.getTaskLength() + 1;
  }

  OnClickAddTask(){
    this.isAddingNewTask = false;
  }

}
