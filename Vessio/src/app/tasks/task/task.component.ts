import { Component, EventEmitter, inject, Input, Output } from '@angular/core';
import { type TaskType } from './task.model';
import  {DatePipe } from '@angular/common';
import { TasksService } from '../tasks.service';
@Component({
  selector: 'app-task',
  // standalone: true,
  standalone: false,
  // imports: [DatePipe],
  templateUrl: './task.component.html',
  styleUrl: './task.component.css',
  providers: []
})
export class TaskComponent {
  @Input({required: true}) task! : TaskType;
  // @Output() taskCompleted = new EventEmitter<string>();

  private tasksService = inject(TasksService);

  onComplete(){
    this.tasksService.removeTask(this.task.id);
    // this.taskCompleted.emit(this.task.id);
  }
  
}
