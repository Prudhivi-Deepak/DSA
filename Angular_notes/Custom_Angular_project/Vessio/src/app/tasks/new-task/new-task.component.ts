import { Component, EventEmitter, inject, Input, Output } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { newTaskType } from '../task/task.model';
import { TasksService } from '../tasks.service';

@Component({
  selector: 'app-new-task',
  // standalone: true,
  standalone: false,
  // imports: [FormsModule],
  templateUrl: './new-task.component.html',
  styleUrl: './new-task.component.css'
})
export class NewTaskComponent {

  @Input() selectedUserId!: string;

  @Output() newTaskCancelEventEmitter = new EventEmitter<boolean>();
  // @Output() newTaskAddEventEmitter = new EventEmitter<newTaskType>();
  @Output() newCloseTaskEventEmitter = new EventEmitter();

  private tasksService = inject(TasksService);

  Etitle: string = '';
  Edescription: string = '';
  Etime: string = '';

  onClickCancel(){
    this.newTaskCancelEventEmitter.emit(); 
  }

  onClickAddTask(){
    // Logic to add the new task 
    this.tasksService.addTask({
      title: this.Etitle,
      description: this.Edescription,
      time: this.Etime
    }, this.selectedUserId);
    this.newCloseTaskEventEmitter.emit();
    // this.newTaskAddEventEmitter.emit({
    //   title: this.Etitle,
    //   description: this.Edescription,
    //   time: this.Etime
    // });
  }

}
