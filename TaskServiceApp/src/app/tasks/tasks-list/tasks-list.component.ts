import { Component, computed, inject, signal } from '@angular/core';

import { TaskItemComponent } from './task-item/task-item.component';
import { TasksService } from '../tasks.service';
// import { TokenServiceToken } from 'src/main';
import { TASK_STATUS_OPTIONS, TaskStatusOptions, taskStatusOptionsProvider } from '../task.model';
import { TokenServiceToken } from 'src/app/app.module';

@Component({
  selector: 'app-tasks-list',
  // standalone: true,
  templateUrl: './tasks-list.component.html',
  styleUrl: './tasks-list.component.css',
  // imports: [TaskItemComponent],
  providers: [taskStatusOptionsProvider],
})
export class TasksListComponent {
  // private tasksService = inject(TasksService);
  private tasksService = inject(TokenServiceToken);

  // inject values from providers service
  taskStatusOptions = inject(TASK_STATUS_OPTIONS);


  selectedFilter = signal<string>('all');
  // tasks = this.tasksService.allTasks;
  tasks = computed(() => {
    switch(this.selectedFilter()){
      case 'open':
        console.log('filtering open tasks', this.selectedFilter());
        return this.tasksService.allTasks().filter(task => task.status === 'OPEN');
      case 'in-progress':
        console.log('filtering in_progress tasks', this.selectedFilter());
        return this.tasksService.allTasks().filter(task => task.status === 'IN_PROGRESS');
      case 'done':
        console.log('filtering done tasks', this.selectedFilter());
        return this.tasksService.allTasks().filter(task => task.status === 'DONE');
      default:
        console.log('no filter, all tasks', this.selectedFilter());
        return this.tasksService.allTasks();
    }
  });

  onChangeTasksFilter(filter: string) {
    console.log(filter);
    this.selectedFilter.set(filter);
  }
}
