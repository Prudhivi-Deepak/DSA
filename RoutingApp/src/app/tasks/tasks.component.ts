// import { Component, computed, inject, input, signal } from '@angular/core';

// import { TaskComponent } from './task/task.component';
// import { Task } from './task/task.model';
// import { TasksService } from './tasks.service';
// import { ActivatedRoute, RouterLink } from '@angular/router';

// @Component({
//   selector: 'app-tasks',
//   standalone: true,
//   templateUrl: './tasks.component.html',
//   styleUrl: './tasks.component.css',
//   imports: [TaskComponent, RouterLink],
// })
// export class TasksComponent {
//   userId = input.required<string>();
//   // order = input<'asc' | 'desc'>();
//   // order?: 'asc' | 'desc';
//   order = signal<'asc' | 'desc'>('desc');
//   private activatedRoute = inject(ActivatedRoute);

//   private taskService = inject(TasksService);

//   ngOnInit() {
//     this.activatedRoute.queryParams.subscribe({
//       // next: (params) => { this.order = params['order'] || 'asc'; }
//       next: (params) => { this.order.set(params['order'] || 'asc'); }
//     }

//     )
//   }

//   // userTasks: Task[] = [];
//   userTasks = computed(() => {
//     return this.taskService.allTasks().filter(task => task.userId === this.userId()).sort((a, b)=>{
//       if(this.order() === 'asc'){
//         return a.id > b.id ? -1 : 1;
//       } else {
//         return a.id > b.id ? 1 : -1;
//       }
//     });
//   })
// }

import {
  Component,
  inject,
  input,
} from '@angular/core';
import { ResolveFn, RouterLink } from '@angular/router';

import { TaskComponent } from './task/task.component';
import { TasksService } from './tasks.service';
import { Task } from './task/task.model';

@Component({
  selector: 'app-tasks',
  standalone: true,
  templateUrl: './tasks.component.html',
  styleUrl: './tasks.component.css',
  imports: [TaskComponent, RouterLink],
})
export class TasksComponent {
  userTasks = input.required<Task[]>();
  userId = input.required<string>();
  order = input<'asc' | 'desc' | undefined>();
}